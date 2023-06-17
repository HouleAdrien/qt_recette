//! Definition de la classe mainwindow.
//!\file mainwindow.cpp
//!\author HOULE Adrien - FERRE Rohan
//!\version 3
//!\date 9 juin 2020*/
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnOuvrir, SIGNAL(clicked()), this, SLOT(lireFichier()));
    connect(this, SIGNAL(loadRecette()), this, SLOT(loadUiRecette()));
    recetteStocke = new recetteStock;
}


MainWindow::~MainWindow()
{
    delete ui;
    delete recette;
    delete imgCtrl;
    delete suivant;
    delete machine;
    delete recetteStocke;
}

void MainWindow::lireFichier()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Ouvrir fichier"),"",tr("Fichiers json (*.json)"));
    QFile fichier(fileName);
    QJsonParseError error;
    if(fichier.open(QFile::ReadOnly))
    {
       QByteArray donnees = fichier.readAll();
       QJsonDocument doc = QJsonDocument::fromJson(donnees, &error);
          if(error.error != QJsonParseError::NoError)
              qCritical() << "Impossible d’interpréter le fichier : " << error.errorString();
          else
              obj=doc.object();
      }
       else
           qCritical() << "Impossible de lire le fichier : " << error.errorString();
     emit loadRecette();
}

void MainWindow::afficherRecette()
{
    recetteStocke->setUrl("<a href="+obj.value("url").toString().toStdString()+"> Lien vers la recette !</a>");
    recetteStocke->setNom(obj.value("name").toString().toStdString());
    recetteStocke->setNbpers(obj.value("recipeYield").toInt());
    recetteStocke->setDescription(obj.value("description").toString().toStdString());
    recetteStocke->setCategorie(obj.value("recipeCategory").toString().toStdString());
    recetteStocke->setTotalTime(obj.value("totalTime").toString().toStdString());
    recetteStocke->setKeyword(obj.value("keywords").toString().toStdString());
    recetteStocke->setPreparationTime(obj.value("prepTime").toString().toStdString());
    recetteStocke->setCuisineTime(obj.value("cookTime").toString().toStdString());
    recetteStocke->setImg(obj.value("image").toString().toStdString());
    recetteStocke->setNumPage(obj.value("recipeInstructions").toArray().first().toInt());

    recetteStocke->setInstructions(obj.value("recipeInstructions").toArray().first().toString().toStdString());

    recette->url->setText(QString::fromStdString(recetteStocke->getUrl()));

    recette->nom->setText(QString::fromStdString(recetteStocke->getNom()));

    recette->description->setText("Description : " + QString::fromStdString(recetteStocke->getDescription()));

    recette->totaltime->setText("Temps de préparation : "+ QString::fromStdString(recetteStocke->getPreparationTime()) + "\nTemps de cuisine : " + QString::fromStdString(recetteStocke->getCuisineTime()) + "\nTemps total : " + QString::fromStdString(recetteStocke->getTotalTime()));

    recette->categorie->setText("Catégorie : " + QString::fromStdString(recetteStocke->getCategorie()) + ".\nPour " + QString::number(recetteStocke->getNbpers()) + " personnes.");

    recette->keyword->setText("Mots clés : " + QString::fromStdString(recetteStocke->getKeyword()));

    QJsonValue val = obj.value("recipeIngredient");
    QJsonArray valArray = val.toArray();
    QString ingredient;
    for (auto value: valArray)
    {
        ingredient += value.toString();
        ingredient += "\n";
    }
    recetteStocke->setIngredients(ingredient.toStdString());

    val = obj.value("recipeInstructions");
    valArray = val.toArray();
    recetteStocke->setNbInstructions(valArray.size()-1);

    recette->ingredients->setText("Ingrédients : \n " + QString::fromStdString(recetteStocke->getIngredients()));

    QUrl imageUrl(QString::fromStdString(recetteStocke->getImg()));
    imgCtrl = new FileDownloader(imageUrl, this);
    connect(imgCtrl, SIGNAL (downloaded()), this, SLOT (loadImage()));

    connect(recette->btnInstruction, SIGNAL(clicked()), this, SLOT(chargerInstruction()));

    connect(recette->btnChange, SIGNAL(clicked()), this, SLOT(changeFichier()));
}

void MainWindow::loadImage()
{
       QPixmap pix;
       pix.loadFromData(imgCtrl->downloadedData());
       if(QSslSocket::supportsSsl())
           recette->image->setPixmap(pix); //on affiche l'image télechargée
       else
           recette->image->setText("L'image n'a pas pu être chargé !");
}

void MainWindow::loadUiRecette()
{
    this->hide();
    recette = new Ui::Recette;
    affichage = new QWidget;
    recette->setupUi(affichage);
    affichage->show();
    afficherRecette();
}

void MainWindow::changeFichier()
{
    delete affichage;
    this->show();
}

void MainWindow::chargerInstruction()
{
    uiInstruction = new Ui::Instruction;
    QDialog *dialogInstruction = new QDialog;
    uiInstruction->setupUi(dialogInstruction);
    machine = new QStateMachine(this);

    QState *etatPremier= new QState();
    QState *etatMilieu= new QState();
    QState *etatDernier= new QState();

    etatPremier->assignProperty(uiInstruction->instruction, "text", QString::fromUtf8("Commencer les instructions."));
    etatMilieu->assignProperty(uiInstruction->instruction, "text", QString::fromUtf8("État Milieu"));
    etatDernier->assignProperty(uiInstruction->instruction, "text", QString::fromUtf8("État Dernier"));

    machine->addState(etatPremier);
    machine->addState(etatMilieu);
    machine->addState(etatDernier);

    etatPremier->addTransition(uiInstruction->btnSuivant, SIGNAL(clicked()), etatMilieu);
    etatMilieu->addTransition(uiInstruction->btnSuivant, SIGNAL(clicked()), etatMilieu);
    etatMilieu->addTransition(uiInstruction->btnPrecedent, SIGNAL(clicked()), etatMilieu);
    etatMilieu->addTransition(this, SIGNAL(etatFinal()), etatDernier);
    etatMilieu->addTransition(this, SIGNAL(etatPremier()), etatPremier);
    etatDernier->addTransition(uiInstruction->btnPrecedent, SIGNAL(clicked()), etatMilieu);

    connect(uiInstruction->btnSuivant, SIGNAL(clicked()), this, SLOT(incrementationNumPage()));
    connect(uiInstruction->btnPrecedent, SIGNAL(clicked()), this, SLOT(decrementationNumPage()));
    connect(etatMilieu, SIGNAL(entered()), this, SLOT(loadInstructions()));
    connect(etatDernier, SIGNAL(entered()), this, SLOT(derniereInstruction()));
    connect(etatPremier, SIGNAL(entered()), this, SLOT(premiereInstruction()));

    machine->setInitialState(etatPremier);
    machine->start();


    dialogInstruction->exec();
}

void MainWindow::loadInstructions()
{
    if (recetteStocke->getNumPage()== 0)
        emit etatPremier();
    if (recetteStocke->getNumPage()!= recetteStocke->getNbInstructions())
    {
        uiInstruction->btnPrecedent->setEnabled(true);
        uiInstruction->btnSuivant->setEnabled(true);
        recetteStocke->setInstructions(obj.value("recipeInstructions").toArray().at(recetteStocke->getNumPage()).toString().toStdString());
        uiInstruction->instruction->setText(QString::fromStdString(recetteStocke->getInstructions()));
    }
    else if (recetteStocke->getNumPage() == recetteStocke->getNbInstructions())
        emit etatFinal();
}

void MainWindow::incrementationNumPage()
{
    recetteStocke->setNumPage(recetteStocke->getNumPage()+1);
}

void MainWindow::decrementationNumPage()
{
    recetteStocke->setNumPage(recetteStocke->getNumPage()-1);
}

void MainWindow::derniereInstruction()
{
     uiInstruction->btnPrecedent->setEnabled(true);
    uiInstruction->btnSuivant->setEnabled(false);
    recetteStocke->setInstructions(obj.value("recipeInstructions").toArray().at(recetteStocke->getNbInstructions()).toString().toStdString());
    uiInstruction->instruction->setText(QString::fromStdString(recetteStocke->getInstructions()));
}

void MainWindow::premiereInstruction()
{

    recetteStocke->setNumPage(0);
    recetteStocke->setInstructions(obj.value("recipeInstructions").toArray().first().toString().toStdString());
    uiInstruction->instruction->setText(QString::fromStdString(recetteStocke->getInstructions()));
    uiInstruction->btnPrecedent->setEnabled(false);
}

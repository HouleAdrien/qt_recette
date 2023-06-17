//! Declaration de la classe mainwindow.
//!\file mainwindow.h
//!\author HOULE Adrien - FERRE Rohan
//!\version 2
//!\date 9 juin 2020
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filedownloader.h"
#include <QStateMachine>
#include "ui_choix_recette.h"
#include "recettestock.h"
#include "ui_instruction.h"

#if QT_VERSION >= 0x050100 //on inclut toutes les classes de Qt
#include <QtWidgets> /* tous les widgets de Qt5 /
#else
#include <QtGui> / tous les widgets de Qt4 */
#endif



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     //!\brief constructeur de mainwindow
    MainWindow(QWidget *parent = nullptr);
    //!\brief desctructeur de mainwindow
    ~MainWindow();
    //!\brief fonction permettant d'afficher les différentes du fichier recette .json
    void afficherRecette();

public slots:
     //!\brief permet de charger l'image de la recette
    void loadImage();
    //!\brief permet de changer le texte de l'étape(texte de la page)
    void loadInstructions();
    //!\brief permet creer le qwidget qui affiche la recette
    void loadUiRecette();
    //!\brief permet d'ouvrir une boite de dialogue afin de lire un fichier json de recette
    void lireFichier();
   //!\brief  permet de changer la recette affichée
    void changeFichier();
     //!\brief créer le qwidget qui affiche les étapes d'instructions
    void chargerInstruction();
    //!\brief permet d'incrémenté le numéro de la page et passer à l'instruction suivante
    void incrementationNumPage();
    //!\brief  permet de décrémenté le numéro de la page et passer à l'instruction précédente
    void decrementationNumPage();
   //!\brief permet de charger la dernière étape et est appelé par etatFinal() lors de l'entrée en état dernier
    void derniereInstruction();
    //!\brief permet de charger la première étape et est appélé par etatPremier() lors de l'entrée en état premier
    void premiereInstruction();


private:
    Ui::MainWindow *ui;
    Ui::Recette *recette;
    QJsonObject obj;
    FileDownloader* imgCtrl;
    //Ui::Form * form;
    QPushButton *suivant;
    QStateMachine *machine;
    QWidget * affichage;
    recetteStock * recetteStocke;
    Ui::Instruction * uiInstruction;

signals:
    //!\brief permet de charger la recette
    void loadRecette();
    //!\brief permet de rentrer dans l'état dernier
    void etatFinal();
    //!\brief permet de rentrer dans l'état premier
    void etatPremier();
};
#endif // MAINWINDOW_H

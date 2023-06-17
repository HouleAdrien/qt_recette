//!\mainpage Lecteur de recettes
//!
//!\section intro_sec Présentation
//! Un lecteur de fichier qui permet de lire des fichiers de recette au format json ,sur l'écran
//!\section how_sec comment faire ?
//!\subsection open_ssec ouvrir une recette
//! Pour ouvrir une recette il faut cliquer ouvrir et sélectionner un ficher de recette en .json afin que l'application l'ouvre.
//! On peut également changer de recette depuis une recette déja ouverte avec le bouton changer de fichier
//!\subsection start_ssec commencer la recette
//!afin de démarrer la recette il faut simplement cliquer sur le bouton démarrer les instructions , on peut passer à une instruction suivant en cliquant sur le bouton suivant
//! et revenir a une étape précédente avec le bouton précédent
//!\section ori_sec La recette est lisible sur internet
//! les recettes ont une url cliquable qui permet de les lire sur internet :)
//!\section ask_sec Plus de questions?
//! vous pouvez nous contactez ici:
//! FERRE Rohan:rohan.ferre@etu.univ-amu.fr
//! HOULE Adrien:adrien.houle@etu.univ-amu.fr
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    //w.RecupFichier("mousse.json");
    return a.exec();
}

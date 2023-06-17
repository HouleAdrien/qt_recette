//!Declaration de la classe recettestock.
//!\file recettestock.h
//!\author HOULE Adrien - FERRE Rohan
//!\version 2
//!\date 9 juin 2020
#ifndef RECETTESTOCK_H
#define RECETTESTOCK_H

#include <string>

class recetteStock
{
private:
    std::string nom;
    std::string description;
    std::string keyword;
    std::string categorie;
    int nbpers;
    std::string ingredients;
    std::string instructions;
    int nbInstructions;
    std::string url;
    std::string totalTime;
    std::string img;
    std::string preparationTime;
    std::string cuisineTime;
    int numPage;
public:
    recetteStock();
    //!accesseur du temps de prépration (permet de récuperer le temps de prépartion)
    std::string getPreparationTime() const;
    //!mutateur du temps de prépration (permet de modifier le temps de prépartion)
    void setPreparationTime(const std::string &value);
    //!accesseur du nom (permet de récuperer le nom)
    std::string getNom() const;
    //!mutateur du nom (permet de modifier le nom)
    void setNom(const std::string &value);
    //!accesseur de la description (permet de récupérer la description)
    std::string getDescription() const;
    //!mutateur de la description (permet de modifier la description)
    void setDescription(const std::string &value);
    //!accesseur des mots clé(permet de récupérer les mots clé)
    std::string getKeyword() const;
    //!mutateur des mots clé(permet de modifier les mots clé)
    void setKeyword(const std::string &value);
    //!accesseur de la catégorie (permet de récupérer la catégorie)
    std::string getCategorie() const;
    //!mutateur de la catégorie (permet de modifier la catégorie)
    void setCategorie(const std::string &value);
    //!accesseur du nombre de personne (permet de récupérer le nombre de personne)
    int getNbpers() const;
    //!mutateur du nombre de personne (permet de modifier le nombre de personne)
    void setNbpers(int value);
    //!accesseur des ingredients (permet de récupérer les ingredients)
    std::string getIngredients() const;
    //!mutateur des ingredients (permet de modifer les ingredients)
    void setIngredients(const std::string &value);
    //!accesseur des instructions (permet de récupérer les inscructions)
    std::string getInstructions() const;
    //!mutateur des instructions (permet de modifier les inscructions)
    void setInstructions(const std::string &value);
    //!accesseur de l'url (permet de récupérer l'url)
    std::string getUrl() const;
    //!mutateur de l'url (permet de modifier l'url)
    void setUrl(const std::string &value);
    //!accesseur du temp total (permet de récuperer le temp total)
    std::string getTotalTime() const;
    //!mutateur du temp total (permet de modifier le temp total)
    void setTotalTime(const std::string &value);
    //!accesseur de l'image (permet de récuperer l'image)
    std::string getImg() const;
    //!mutateur de l'image (permet de modifier l'image)
    void setImg(const std::string &value);
    //!accesseur du temp de cuisson (permet de récuperer le temp de cuisson )
    std::string getCuisineTime() const;
    //!mutateur du temp de cuisson (permet de modifier le temp de cuisson )
    void setCuisineTime(const std::string &value);
    //!accesseur des nombres d'instructions (permet de récuperer le nombre d'instructions)
    int getNbInstructions() const;
    //!mutateur des nombres d'instructions (permet de modifier le nombre d'instructions)
    void setNbInstructions(int value);
    //!accesseur du nombre de pages (permet de récuperer le nombre de pages)
    int getNumPage() const;
     //!mutateur du nombre de pages (permet de modifier le nombre de pages)
    void setNumPage(int value);
};

#endif // RECETTESTOCK_H

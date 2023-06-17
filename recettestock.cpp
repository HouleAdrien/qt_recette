//!Definition de la classe recettestock.
//!\file recettestock.cpp
//!\author HOULE Adrien - FERRE Rohan
//!\version 2
//!\date 9 juin 2020
#include "recettestock.h"

std::string recetteStock::getPreparationTime() const
{
    return preparationTime;
}

void recetteStock::setPreparationTime(const std::string &value)
{
    preparationTime = value;
}

std::string recetteStock::getNom() const
{
    return nom;
}

void recetteStock::setNom(const std::string &value)
{
    nom = value;
}

std::string recetteStock::getDescription() const
{
    return description;
}

void recetteStock::setDescription(const std::string &value)
{
    description = value;
}

std::string recetteStock::getKeyword() const
{
    return keyword;
}

void recetteStock::setKeyword(const std::string &value)
{
    keyword = value;
}

std::string recetteStock::getCategorie() const
{
    return categorie;
}

void recetteStock::setCategorie(const std::string &value)
{
    categorie = value;
}

int recetteStock::getNbpers() const
{
    return nbpers;
}

void recetteStock::setNbpers(int value)
{
    nbpers = value;
}

std::string recetteStock::getIngredients() const
{
    return ingredients;
}

void recetteStock::setIngredients(const std::string &value)
{
    ingredients = value;
}

std::string recetteStock::getInstructions() const
{
    return instructions;
}

void recetteStock::setInstructions(const std::string &value)
{
    instructions = value;
}

std::string recetteStock::getUrl() const
{
    return url;
}

void recetteStock::setUrl(const std::string &value)
{
    url = value;
}

std::string recetteStock::getTotalTime() const
{
    return totalTime;
}

void recetteStock::setTotalTime(const std::string &value)
{
    totalTime = value;
}

std::string recetteStock::getImg() const
{
    return img;
}

void recetteStock::setImg(const std::string &value)
{
    img = value;
}

std::string recetteStock::getCuisineTime() const
{
    return cuisineTime;
}

void recetteStock::setCuisineTime(const std::string &value)
{
    cuisineTime = value;
}

int recetteStock::getNbInstructions() const
{
    return nbInstructions;
}

void recetteStock::setNbInstructions(int value)
{
    nbInstructions = value;
}

int recetteStock::getNumPage() const
{
    return numPage;
}

void recetteStock::setNumPage(int value)
{
    numPage = value;
}

recetteStock::recetteStock()
{

}

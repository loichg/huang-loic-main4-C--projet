#include "Etoile.hh"

Etoile::Etoile(std::string nom, float masse, float luminosite, float temperatureSurface) : nom(nom), masse(masse), luminosite(luminosite), temperatureSurface(temperatureSurface) {}

//simule la fluctuation de l'intensité lumineuse de l'étoile
void Etoile::briller(){
    float luminositeCalculee = luminosite; 

    std::cout << nom << " brille avec une luminosité de " << luminositeCalculee << " watts.\n";
    
    float fluctuation = (std::rand() % 10) - 5;  //valeur aléatoire pour la fluctuation de luminosité
    luminositeCalculee += luminositeCalculee * (fluctuation / 100.0f); //nouvelle luminosité

    std::cout << "La luminosité fluctue de " << fluctuation << "%, nouvelle luminosité : " << luminositeCalculee << " watts.\n";
}

//calcul l'énergie fournit par l'étoile 
float Etoile::fournirEnergie(float distance){
    return luminosite / (distance * distance);  //loi de l'inverse du carré
}

//affichage des détails
void Etoile::afficherDetails(){
    std::cout << "Etoile: " << nom << "\nMasse: " << masse << " kg\n"
              << "Luminosité: " << luminosite << " unités\n"
              << "Température de surface: " << temperatureSurface << " K\n";
}

//getteurs pour le nom
std::string Etoile::obtenirNom(){
    return nom;
}

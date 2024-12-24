#include "Meteoroide.hh"
#include <iostream>
#include <cmath>
#include <cstdlib>

Meteoroide::Meteoroide(std::string nom, float masse, float vitesse, float taille) : ObjetSpatial(nom, masse, vitesse), taille(taille){}

//simule la transformation du météoroïde lors de l'entrée dans l'atmosphère
void Meteoroide::entrerAtmosphere(std::string nomPlanete) {
    std::cout << nom << " entre dans l'atmosphère de " << nomPlanete << ".\n";
    
    //calcul de l'énergie cinétique du météoroïde
    float energieCinetique = 0.5f * masse * std::pow(vitesse, 2);
    std::cout << "Energie cinétique du météoroïde : " << energieCinetique << " joules.\n";

    //energie dissipée sous forme de chaleur
    float energieChaleur = energieCinetique * 0.6f;
    std::cout << "Energie dissipée sous forme de chaleur : " << energieChaleur << " joules.\n";
    
    //calcul de la température du météoroïde lors de l'entrée dans l'atmosphère
    float capaciteThermique = 1000.0f;  //capacité thermique pour des matériaux rocheux
    float temperature = energieChaleur / (masse * capaciteThermique);  //température en
    std::cout << "Température du météoroïde lors de l'entrée : " << temperature << " °C.\n";

    //simulation de la perte de taille due à la chaleur
    float taillePerdue = std::min(energieChaleur / 1e5f, taille * 0.1f);  //perte de taille proportionnelle à la chaleur
    taille -= taillePerdue;  //mise à jour de la taille
    std::cout << "Le météoroïde perd " << taillePerdue << " mètres de taille. Nouvelle taille : " << taille << " m.\n";
}

//affichage des détails
void Meteoroide::afficherDetails(){
    ObjetSpatial::afficherDetails();
    std::cout << "Taille du météoroïde: " << taille << " m\n";
}

//mise à jour de la position et de la trajectoire du météoroïde
void Meteoroide::mettreAJourPosition(int cycles) {
    //calcul de la distance parcourue
    float distanceParcourue = vitesse * cycles;

    //simule un changement de trajectoire
    std::cout << nom << " met à jour sa position après " << cycles << " cycles.\n";
    if (vitesse > 20){
        float angleDeviation = rand() % 30; //déviation si vitesse élevée
        std::cout << "Trajectoire déviée de " << angleDeviation << "°.\n";
    } 
    else{
        //sinon rectiligne
        std::cout << nom << " se déplace directement sur une trajectoire rectiligne avec une distance parcourue de " << distanceParcourue << " km.\n";
    }
}

//determine la trajectoire
void Meteoroide::calculerTrajectoire() {
    //trajectoire erratique avec un angle de déviation aléatoire
    float angleErratique = (vitesse * 0.05f) + (rand() % 10);  
    std::cout << "Le météoroïde " << nom << " a une trajectoire erratique avec un angle de " << angleErratique << "°.\n";
}

#include "Comete.hh"
#include <iostream>
#include <cmath>

Comete::Comete(std::string nom, float masse, float vitesse, std::string composition, float distancePerihelie, float periodeOrbital): ObjetSpatial(nom, masse, vitesse), composition(composition), distancePerihelie(distancePerihelie), periodeOrbital(periodeOrbital) {}

void Comete::passerProcheDuSoleil() {
    const float G = 6.67430e-11;  //constante gravitationnelle
    const float masseSoleil = 1.989e30; //masse du Soleil
    const float distanceSoleil = 1.496e11; //distance Terre au Soleil

    float distancePerihelieM = distancePerihelie * distanceSoleil;  //distance au périhélie de la comète

    //calcul de l'énergie potentielle gravitationnelle
    float energiePotentielle = -G * masseSoleil * masse / distancePerihelieM; 

    //calcul de l'énergie cinétique initiale
    float energieCinetiqueInitiale = 0.5f * masse * std::pow(vitesse*1000, 2); 

    //calcul de l'énergie totale 
    float energieTotale = energieCinetiqueInitiale + energiePotentielle;

    //calcul de la vitesse à la distance du périhélie
    float vitesseMaximale = std::sqrt((2*(energieTotale + G * masseSoleil * masse / distancePerihelieM))/masse);

    //affichage du résultat
    std::cout << nom << " approche du périhélie à une distance de " << distancePerihelie << " AU.\n";
    std::cout << "La vitesse de " << nom << " augmente à " << vitesseMaximale / 1000 << " km/s en raison de l'attraction gravitationnelle du Soleil.\n";

    //mise à jour 
    vitesse = vitesseMaximale/1000;

    //mise à jour de la position de la comète
    mettreAJourPosition(1); 
}

//affichage des détails
void Comete::afficherDetails() {
    ObjetSpatial::afficherDetails();
    std::cout << "Composition de la comète: " << composition << "\n";
    std::cout << "Distance au périhélie: " << distancePerihelie << " AU\n";
    std::cout << "Période orbitale: " << periodeOrbital << " jours\n";
}

//mettre a jour la position sur son orbite elliptique
void Comete::mettreAJourPosition(int cycles) {
    //calcul de l'angle orbital en fonction de la période 
    float angle = cycles * (360.0f / periodeOrbital); 
    //approximations de la distance avec l'angle
    float distance = distancePerihelie * (1 + 0.5 * cos(angle));  
    std::cout << nom << " a mis à jour sa position. Distance actuelle au soleil: " << distance << " AU.\n";
}

//détermine la trajectoire de l'asteroide
void Comete::calculerTrajectoire() {
    float angleOrbital = std::fmod((vitesse * distanceSoleil) / 1000, 360); 
    std::cout << "La comète " << nom << " suit une trajectoire elliptique avec un angle orbital de " << angleOrbital << "°.\n";
}

std::string Comete::getNom() const {
    return nom;
}

float Comete::getMasse() const {
    return masse;
}

float Comete::getVitesse() const {
    return vitesse;
}

std::string Comete::getComposition() const {
    return composition;
}

float Comete::getDistancePerihelie() const {
    return distancePerihelie;
}

float Comete::getPeriodeOrbital() const {
    return periodeOrbital;
}

#include "Asteroide.hh"
#include <iostream>

Asteroide::Asteroide(std::string nom, float masse, float vitesse, std::string composition): ObjetSpatial(nom, masse, vitesse), composition(composition){}

//détermination de l'impact d'un asteroide en donnant un energie de comparaison (par exemple 6e13J correspond à une explosion nucléaire)
void Asteroide::calculerImpact(float energie){
    //calcul de l'énergie cinétique
    float energieCinetique = 0.5f * masse * std::pow(vitesse, 2);
    
    std::cout << "Calcul de l'impact de l'astéroïde " << nom << ":\n";
    std::cout << "Énergie cinétique: " << energieCinetique << " J.\n";
    
    if (energieCinetique>energie)
        std::cout << "Impact important\n";
    else
        std::cout << "Impact faible\n";
}

//affichage des détails de l'asteroide
void Asteroide::afficherDetails(){
    ObjetSpatial::afficherDetails();
    std::cout << "Composition de l'astéroïde: " << composition << "\n";
}

//détermine la trajectoire de l'asteroide
void Asteroide::calculerTrajectoire() {
    vitesse = vitesse * 1000; //conversion de la vitesse
    const float G = 6.67430e-11; //constante gravitationnelle
    const float masseSoleil = 1.989e30; //masse du Soleil

    //calcul de la force gravitationnelle entre l'astéroïde et le Soleil
    float forceGravitationnelle = G * (masse * masseSoleil) / std::pow(distanceSoleil, 2);

    //calcul de l'angle de déviation
    float angleRadian = forceGravitationnelle / (masse * std::pow(vitesse, 2));

    //conversion de l'angle en degrés
    float angleDegres = angleRadian * (180.0 / M_PI);

    //affichage du résultat
    std::cout << "L'astéroïde " << nom << " a une trajectoire modifiée par un angle de " << angleDegres << " degrés.\n";
}

std::string Asteroide::getNom() const {
    return nom;
}

float Asteroide::getMasse() const {
    return masse;
}

float Asteroide::getVitesse() const {
    return vitesse;
}

std::string Asteroide::getComposition() const {
    return composition;
}
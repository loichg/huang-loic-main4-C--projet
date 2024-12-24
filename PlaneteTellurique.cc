#include "PlaneteTellurique.hh"
#include <iostream>

PlaneteTellurique::PlaneteTellurique(std::string nom, float masse, float distanceSoleil, float periodeOrbitale, float temperature, float rayon, std::string compositionSolide, bool presenceEau): Planete(nom, masse, distanceSoleil, periodeOrbitale, temperature, rayon),compositionSolide(compositionSolide), presenceEau(presenceEau) {}

//simule l'exploration de la surface de la planete
void PlaneteTellurique::explorerSurface(){
    std::cout << "Exploration de la surface de " << nom << ".\n";
    std::cout << "Composition du sol: " << compositionSolide << "\n";
    if (presenceEau){
        std::cout << "De l'eau est présente sur la planète.\n";
    } 
    else {
        std::cout << "Aucune trace d'eau détectée sur cette planète.\n";
    }
}

//calcul de la température
float PlaneteTellurique::calculerTemperatureMoyenne() {
    // Exemple simple pour simuler la variation de température
    float variation = (std::rand() % 10) - 5; // Variation aléatoire de -5°C à +5°C
    float temperatureMoyenne = temperature + variation;
    std::cout << "La température moyenne calculée pour " << nom << " est de " << temperatureMoyenne << " °C.\n";
    return temperatureMoyenne;
}

//affichage des details
void PlaneteTellurique::afficherDetails() {
    Planete::afficherDetails();
    std::cout << "Composition du sol: " << compositionSolide << "\n";
    std::cout << "Présence d'eau: " << (presenceEau ? "Oui" : "Non") << "\n";
}

//operateur + pour fusionner deux planetes
PlaneteTellurique PlaneteTellurique::operator+(const PlaneteTellurique& autre) const {
    std::string nouveauNom = nom + "-" + autre.nom;
    float nouvelleMasse = masse + autre.masse;
    float nouvelleDistanceSoleil = (distanceSoleil + autre.distanceSoleil) / 2;
    float nouvellePeriodeOrbitale = (periodeOrbitale + autre.periodeOrbitale) / 2;
    float nouvelleTemperature = (temperature + autre.temperature) / 2;
    std::string nouvelleCompositionSolide = compositionSolide + " + " + autre.compositionSolide;
    bool nouvellePresenceEau = presenceEau || autre.presenceEau;  
    return PlaneteTellurique(nouveauNom, nouvelleMasse, nouvelleDistanceSoleil, nouvellePeriodeOrbitale, nouvelleTemperature, 6371e3, nouvelleCompositionSolide, nouvellePresenceEau);  // Exemple de rayon
}

#include "PlaneteGazeuse.hh"
#include <iostream>

PlaneteGazeuse::PlaneteGazeuse(std::string nom, float masse, float distanceSoleil, float periodeOrbitale, float temperature, float rayon, std::string compositionAtmosphere, int nombreAnneaux): Planete(nom, masse, distanceSoleil, periodeOrbitale, temperature, rayon),compositionAtmosphere(compositionAtmosphere), nombreAnneaux(nombreAnneaux) {}

//affiche composition de l'atmosphère
void PlaneteGazeuse::analyserAtmosphere(){
    std::cout << "Analyse de l'atmosphère de " << nom << ": " << compositionAtmosphere << "\n";
}

//getteur anneaux
int PlaneteGazeuse::compterAnneaux(){
    return nombreAnneaux;
}

//affiche les details
void PlaneteGazeuse::afficherDetails() {
    Planete::afficherDetails();  
    std::cout << "Composition de l'atmosphère: " << compositionAtmosphere << "\n";
    std::cout << "Nombre d'anneaux: " << nombreAnneaux << "\n";
}

//opérateur + pour fusionner des planètes
PlaneteGazeuse PlaneteGazeuse::operator+(const PlaneteGazeuse& autre) const {
    std::string nouveauNom = nom + "-" + autre.nom;
    float nouvelleMasse = masse + autre.masse;
    float nouvelleDistanceSoleil = (distanceSoleil + autre.distanceSoleil) / 2;
    float nouvellePeriodeOrbitale = (periodeOrbitale + autre.periodeOrbitale) / 2;
    float nouvelleTemperature = (temperature + autre.temperature) / 2;
    std::string nouvelleCompositionAtmosphere = compositionAtmosphere + " + " + autre.compositionAtmosphere;
    int nouveauNombreAnneaux = nombreAnneaux + autre.nombreAnneaux;
    float nouveauRayon = (rayon + autre.rayon) / 2;
    return PlaneteGazeuse(nouveauNom, nouvelleMasse, nouvelleDistanceSoleil, nouvellePeriodeOrbitale, nouvelleTemperature, nouveauRayon, nouvelleCompositionAtmosphere, nouveauNombreAnneaux); 
}

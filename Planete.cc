#include "Planete.hh"

Planete::Planete(std::string nom, float masse, float distanceSoleil, float periodeOrbitale, float temperature, float rayon): nom(nom), masse(masse), distanceSoleil(distanceSoleil), periodeOrbitale(periodeOrbitale), temperature(temperature), rayon(rayon) {}

//simule l'orbite d'une planete autour du Soleil
void Planete::orbiter(int cycles) {
    //calculer l'angle orbital
    float periodeOrbitaleEnAnnees = periodeOrbitale / 365.25f;
    float angleOrbital = (360.0f / periodeOrbitaleEnAnnees) * cycles;
    //calcul de la distance qui varie car orbite elliptique
    float distanceActuelle = distanceSoleil * (1.0f + 0.1f * std::sin(angleOrbital * M_PI / 180.0f));
    std::cout << nom << " orbite autour du soleil, distance actuelle : " << distanceActuelle << " AU.\n";
    distanceSoleil = distanceActuelle; //mise a jour de la distance
}

//energie recue par une planete du Soleil
void Planete::recevoirEnergie(){
    const float luminositeSoleil = 3.846e26;  //luminosité du Soleil
    
    //calcul de l'énergie reçue en fonction de la distance au Soleil
    float distanceSoleilEnMetres = distanceSoleil * 1.496e11;  //1AU = 1.496e11m
    float energieRecue = luminositeSoleil / (4 * M_PI * std::pow(distanceSoleilEnMetres, 2));  //loi de l'inverse du carré
    
    //calcul de l'énergie en prenant compte de l'albedo
    float albedo = 0.3;  //albédo typique pour une planète rocheuse
    energieRecue *= (1 - albedo);  
    
    //calcul de la température à partir de l'énergie reçue
    float capaciteThermique = 1000.0; //capacité thermique pour les matériaux rocheux
    float massePlanete = masse; //masse de la planète
    
    //augmentation de température proportionnelle à l'énergie reçue
    float temperatureAugmentee = (energieRecue / (massePlanete * capaciteThermique)) * 1000;
    
    //mise a jour de temperature
    temperature += temperatureAugmentee;
    
    //affichage du résultat
    std::cout << nom << " reçoit une énergie de " << energieRecue << " W, température actuelle : " << temperature << " °C.\n";
}

//affichage des détails
void Planete::afficherDetails(){
    std::cout << "Planète: " << nom << "\nMasse: " << masse << " kg\n"
              << "Distance au soleil: " << distanceSoleil << " AU\n"
              << "Période orbitale: " << periodeOrbitale << " jours\n"
              << "Température: " << temperature << " °C\n"
              << "Rayon: " << rayon << " m\n";  
}

//calcul de la gravité
float Planete::calculerGravite(){
    return 6.67430e-11 * masse / (rayon * rayon); //loi gravitationnelle 
}

//getteur pour le nom
std::string Planete::obtenirNom(){
    return nom;
}

//opérateur pour fusionner deux planetes
Planete Planete::operator+(const Planete& autre) const {
    //fusionner tous les attributs
    std::string nouveauNom = nom + "-" + autre.nom;
    float nouvelleMasse = masse + autre.masse;
    float nouvelleDistanceSoleil = (distanceSoleil + autre.distanceSoleil) / 2;
    float nouvellePeriodeOrbitale = (periodeOrbitale + autre.periodeOrbitale) / 2;
    float nouvelleTemperature = (temperature + autre.temperature) / 2;
    float nouveauRayon = (rayon + autre.rayon) / 2; 
    return Planete(nouveauNom, nouvelleMasse, nouvelleDistanceSoleil, nouvellePeriodeOrbitale, nouvelleTemperature, nouveauRayon);
}

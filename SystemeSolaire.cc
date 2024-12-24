#include "SystemeSolaire.hh"
#include "Etoile.hh"
#include "Planete.hh"
#include <iostream>

SystemeSolaire::SystemeSolaire(std::string nom, Etoile* etoile): nom(nom), etoile(etoile), nombrePlanetes(0), nombreObjet(0) {}

//retourne pointeur vers etoile
Etoile* SystemeSolaire::obtenirEtoile(){
    return etoile;
}

//ajoute et compte le nombre de planete
void SystemeSolaire::ajouterPlanete(Planete* planete) {
    planetes.push_back(planete);
    nombrePlanetes++;
}

//retourne la liste des planetes
std::vector<Planete*> SystemeSolaire::obtenirPlanetes() {
    return planetes;
}

//ajouter asteroide
void SystemeSolaire::ajouterAsteroide(Asteroide* asteroide) {
    asteroides.push_back(asteroide);
    nombreObjet++;
}

//ajouter comete
void SystemeSolaire::ajouterComete(Comete* comete) {
    cometes.push_back(comete);
    nombreObjet++;
}

//ajouter meteoroide
void SystemeSolaire::ajouterMeteoroide(Meteoroide* meteoroide) {
    meteoroides.push_back(meteoroide);
    nombreObjet++;
}

//retourle la liste des asteroide
std::list<Asteroide*> SystemeSolaire::obtenirAsteroide() {
    return asteroides;
}

//retourle la liste des comete
std::list<Comete*> SystemeSolaire::obtenirComete() {
    return cometes;
}

//retourle la liste des meteoroide
std::list<Meteoroide*> SystemeSolaire::obtenirMeteoroide() {
    return meteoroides;
}

//simule un nombre de cycle du systeme solaire
void SystemeSolaire::simulerCycle(int cycles) {
    for (int i=0; i<cycles; i++){
        int random = std::rand() % 5;
        std::cout << "========== " << "CYCLE " << i << " ==========" << "\n";

        // Faire orbiter les planètes
        for (Planete* planete : planetes) {
            planete->orbiter(1);
            planete->recevoirEnergie();
        }

        // Traiter les astéroïdes
        for (Asteroide* asteroide : asteroides) {
            asteroide->seDeplacer(1);
            if (random == 1){
                asteroide->calculerImpact(6e13f); 
            } 
        }

        // Traiter les comètes
        for (Comete* comete : cometes) {
            comete->seDeplacer(1);
            comete->passerProcheDuSoleil();
        }

        // Traiter les météoroïdes
        for (Meteoroide* meteoroide : meteoroides) {
            meteoroide->seDeplacer(1);
            if (random == 1){
                meteoroide->entrerAtmosphere("Terre");
            }
        }
    }
    std::cout << "\n";
}


//affichage de l'etat du systeme solaire
void SystemeSolaire::afficherEtatSysteme() {
    std::cout << "Système solaire: " << nom << "\n";
    //affichage des planètes
    for (Planete* planete : planetes){
        planete->afficherDetails();
    }

    //affichage asteroide
    for (Asteroide* asteroide : asteroides){
        asteroide->afficherDetails();
    }

    //Affichage des comètes
    for (Comete* comete : cometes){
        comete->afficherDetails();
    }

    // Affichage des météoroïdes
    for (Meteoroide* meteoroide : meteoroides){
        meteoroide->afficherDetails();
    }
}

//met à jour l'état du système solaire
void SystemeSolaire::mettreAJourEtat(int cycles){
    //met à jour l'état des planètes
    for (Planete* planete : planetes){

        planete->recevoirEnergie(); 
    }

    for (Asteroide* asteroide : asteroides){
        asteroide->seDeplacer(cycles);  
    }

    for (Comete* comete : cometes){
        comete->seDeplacer(cycles);  
    }

    for (Meteoroide* meteoroide : meteoroides){
        meteoroide->seDeplacer(cycles);  
    }
}

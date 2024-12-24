#include "ObjetSpatial.hh"

ObjetSpatial::ObjetSpatial(std::string nom, float masse, float vitesse): nom(nom), masse(masse), vitesse(vitesse) {}

//déplacement d'un objet spatial
void ObjetSpatial::seDeplacer(int cycles){
    std::cout << nom << " se déplace sur " << cycles << " cycles.\n";
}

//affichage des details
void ObjetSpatial::afficherDetails(){
    std::cout << "Objet spatial: " << nom << "\nMasse: " << masse << " kg\nVitesse: " << vitesse << " km/s\n";
}

//position d'un objet spatial
void ObjetSpatial::mettreAJourPosition(int cycles){
    std::cout << nom << " met à jour sa position après " << cycles << " cycles.\n";
}

//getteurs pour le nom
std::string ObjetSpatial::obtenirNom() {
    return nom;
}

//opérateur de comparaison
bool ObjetSpatial::operator==(const ObjetSpatial& autre) const {
    return nom == autre.nom && masse == autre.masse && vitesse == autre.vitesse;
}

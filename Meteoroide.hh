#ifndef METEOROIDE_HH
#define METEOROIDE_HH

#include "ObjetSpatial.hh"
#include <string>

class Meteoroide : public ObjetSpatial {
    private:
        float taille;
    public:
        Meteoroide(std::string nom, float masse, float vitesse, float taille);
        void entrerAtmosphere(std::string nomPlanete);
        void afficherDetails() override;
        void mettreAJourPosition(int cycles) override;
        virtual ~Meteoroide() = default;
        void calculerTrajectoire() override;
        float getTaille() const { return taille; }          
        float getMasse() const { return masse; }            
        float getVitesse() const { return vitesse; } 
        std::string getNom() const { return nom; }  
};

#endif

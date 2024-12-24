#ifndef ETOILE_HH
#define ETOILE_HH

#include <string>
#include <iostream>

class Etoile{
    private:
        std::string nom;
        float masse;
        float luminosite;
        float temperatureSurface;
    public:
        Etoile(std::string nom, float masse, float luminosite, float temperatureSurface);
        void briller();
        float fournirEnergie(float distance);
        void afficherDetails();
        std::string obtenirNom();

    std::string getNom() const { return nom; }
    float getMasse() const { return masse; }
    float getLuminosite() const { return luminosite; }
    float getTemperatureSurface() const { return temperatureSurface; }
};

#endif

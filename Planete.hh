#ifndef PLANETE_HH
#define PLANETE_HH

#include <string>
#include <vector>
#include <iostream>
#include "ObjetSpatial.hh"

class Planete{
    protected:
        std::string nom;
        float masse;
        float distanceSoleil;
        float periodeOrbitale;
        float temperature;
        float rayon; 

    public:
        Planete(std::string nom, float masse, float distanceSoleil, float periodeOrbitale, float temperature, float rayon);
        virtual void orbiter(int cycles);
        void recevoirEnergie();
        virtual void afficherDetails();
        virtual float calculerGravite();
        std::string obtenirNom();
        virtual ~Planete() = default;
        virtual Planete operator+(const Planete& autre) const;

        float obtenirMasse() const {
        return masse;
    }

    float obtenirDistanceSoleil() const {return distanceSoleil;}
    float obtenirPeriodeOrbitale() const {return periodeOrbitale;}
    float obtenirTemperature() const {return temperature;}
    float obtenirRayon() const {return rayon;}
};

#endif

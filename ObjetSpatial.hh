#ifndef OBJETSPATIAL_HH
#define OBJETSPATIAL_HH

#include <string>
#include <iostream>

class ObjetSpatial{
    protected:
        std::string nom;
        float masse;
        float vitesse;

    public:
        ObjetSpatial(std::string nom, float masse, float vitesse);
        virtual void seDeplacer(int cycles);
        virtual void calculerTrajectoire() = 0;
        virtual void afficherDetails();
        virtual void mettreAJourPosition(int cycles);
        std::string obtenirNom();
        virtual ~ObjetSpatial() = default;
        bool operator==(const ObjetSpatial& autre) const;
};

#endif

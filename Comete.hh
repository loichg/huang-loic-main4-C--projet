#ifndef COMETE_HH
#define COMETE_HH

#include "ObjetSpatial.hh"

class Comete : public ObjetSpatial{
    private:
        std::string composition;
        float distancePerihelie;
        float periodeOrbital;
        float distanceSoleil;
    public:
        Comete(std::string nom, float masse, float vitesse, std::string composition, float distancePerihelie, float periodeOrbital);
        void passerProcheDuSoleil();
        void afficherDetails() override;
        void mettreAJourPosition(int cycles) override;
        virtual ~Comete() = default;
        void calculerTrajectoire() override;

        std::string getNom() const;
        float getMasse() const;
        float getVitesse() const;
        std::string getComposition() const;
        float getDistancePerihelie() const;
        float getPeriodeOrbital() const;
};

#endif

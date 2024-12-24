#ifndef ASTEROIDE_HH
#define ASTEROIDE_HH

#include "ObjetSpatial.hh"

class Asteroide : public ObjetSpatial{
    private:
        std::string composition;
        float distanceSoleil;
    public:
        Asteroide(std::string nom, float masse, float vitesse, std::string composition);
        virtual ~Asteroide() = default;
        void calculerImpact(float energie);
        void afficherDetails() override;
        void calculerTrajectoire() override;

        std::string getNom() const;
        float getMasse() const;
        float getVitesse() const;
        std::string getComposition() const;
};

#endif

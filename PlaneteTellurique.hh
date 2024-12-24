#ifndef PLANETETELLURIQUE_HH
#define PLANETETELLURIQUE_HH

#include "Planete.hh"

class PlaneteTellurique : public Planete {
    private:
        std::string compositionSolide;
        bool presenceEau;

    public:
        PlaneteTellurique(std::string nom, float masse, float distanceSoleil, float periodeOrbitale, float temperature, float rayon, std::string compositionSolide, bool presenceEau);
        void explorerSurface();
        float calculerTemperatureMoyenne();
        void afficherDetails() override;
        virtual ~PlaneteTellurique() = default;
        PlaneteTellurique operator+(const PlaneteTellurique& autre) const;
};

#endif

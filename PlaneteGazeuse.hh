#ifndef PLANETEGAZEUSE_HH
#define PLANETEGAZEUSE_HH

#include "Planete.hh"

class PlaneteGazeuse : public Planete{
    private:
        std::string compositionAtmosphere;
        int nombreAnneaux;
    public:
        PlaneteGazeuse(std::string nom, float masse, float distanceSoleil, float periodeOrbitale, float temperature, float rayon, std::string compositionAtmosphere, int nombreAnneaux);
        void analyserAtmosphere();
        int compterAnneaux();
        void afficherDetails() override;
        virtual ~PlaneteGazeuse() = default;
        PlaneteGazeuse operator+(const PlaneteGazeuse& autre) const;
};

#endif

#ifndef SYSTEMESOLAIRE_HH
#define SYSTEMESOLAIRE_HH

#include <string>
#include <vector>  
#include <list>    
#include "Etoile.hh"
#include "Planete.hh"
#include "ObjetSpatial.hh"
#include "Meteoroide.hh"
#include "Asteroide.hh"
#include "Comete.hh"

class SystemeSolaire {
    private:
        std::string nom;
        Etoile* etoile;
        int nombrePlanetes;
        int nombreObjet;
        std::vector<Planete*> planetes;  
        std::list<Asteroide*> asteroides; 
        std::list<Comete*> cometes; 
        std::list<Meteoroide*> meteoroides; 

    public:
        SystemeSolaire(std::string nom, Etoile* etoile);
        Etoile* obtenirEtoile();
        void ajouterPlanete(Planete* planete);
        std::vector<Planete*> obtenirPlanetes();
        void ajouterAsteroide(Asteroide* asteroide);
        void ajouterComete(Comete* comete);
        void ajouterMeteoroide(Meteoroide* meteoroide);
        std::list<Asteroide*> obtenirAsteroide(); 
        std::list<Comete*> obtenirComete(); 
        std::list<Meteoroide*> obtenirMeteoroide(); 
        void simulerCycle(int cycles);
        void afficherEtatSysteme();
        void mettreAJourEtat(int cycles);

        int getNombrePlanetes() const { return nombrePlanetes; }
        int getNombreObjet() const { return nombreObjet; }
};

#endif

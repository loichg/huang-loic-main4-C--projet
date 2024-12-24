#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <sstream>
#include "Asteroide.hh"
#include "Comete.hh"
#include "Etoile.hh"
#include <cstdlib>
#include "Meteoroide.hh"
#include "ObjetSpatial.hh"
#include "Planete.hh"
#include "SystemeSolaire.hh"
#include "PlaneteTellurique.hh"
#include "PlaneteGazeuse.hh"

TEST_SUITE("1.Asteroide") {
    TEST_CASE("Constructeur") {
        Asteroide asteroide("Asteroide1", 1000.0f, 20.0f, "Fer et Nickel");
        CHECK(asteroide.getNom() == "Asteroide1");
        CHECK(asteroide.getMasse() == 1000.0f);
        CHECK(asteroide.getVitesse() == 20.0f);
        CHECK(asteroide.getComposition() == "Fer et Nickel");
    }
}

TEST_SUITE("2.Comete") {
    TEST_CASE("Constructeur"){
        Comete comete("Halley", 2.2e14, 54.0f, "Glace et poussière", 0.586, 75.0f);
        CHECK(comete.getNom() == "Halley");
        CHECK(comete.getMasse() == doctest::Approx(2.2e14).epsilon(0.01));  
        CHECK(comete.getVitesse() == doctest::Approx(54.0f).epsilon(0.01));
        CHECK(comete.getComposition() == "Glace et poussière");
        CHECK(comete.getDistancePerihelie() == doctest::Approx(0.586).epsilon(0.01));
        CHECK(comete.getPeriodeOrbital() == doctest::Approx(75.0f).epsilon(0.01));
    }
}

TEST_SUITE("3.Etoile") {
    TEST_CASE("Etoile") {
        Etoile etoile("Sirius", 2.0e30, 3.846e26, 5778.0f); 
        SUBCASE("Constructeur") {
            CHECK(etoile.getNom() == "Sirius");
            CHECK(etoile.getMasse() == doctest::Approx(2.0e30f).epsilon(0.01));  
            CHECK(etoile.getLuminosite() == doctest::Approx(3.846e26f).epsilon(0.01));
            CHECK(etoile.getTemperatureSurface() == doctest::Approx(5778.0f).epsilon(0.01)); 
        }
        SUBCASE("Calcul de l'énergie fournie") {
            float distance = 1.496e11; // En mètres
            float energieAttendue = 3.846e26 / (distance * distance);
            float energieCalculee = etoile.fournirEnergie(distance);
            CHECK(energieCalculee == doctest::Approx(energieAttendue).epsilon(0.01));
        }
    }
}

TEST_SUITE("4.Meteoroide") {
    TEST_CASE("Constructeur") {
        Meteoroide meteoroide("MeteorX", 1000.0f, 15.0f, 5.0f);
        CHECK(meteoroide.getNom() == "MeteorX");
        CHECK(meteoroide.getMasse() == 1000.0f);
        CHECK(meteoroide.getVitesse() == 15.0f);
        CHECK(meteoroide.getTaille() == 5.0f);
    }
}

TEST_SUITE("5.Planete"){
  TEST_CASE("Planete") {
    SUBCASE("gravité") {
        Planete planet("Terre", 5.972e24f, 1.0f, 365.25f, 15.0f, 6371000.0f);
        float gravite = planet.calculerGravite();
        float graviteAttendue = 9.81f;  
        CHECK(gravite == doctest::Approx(graviteAttendue).epsilon(0.01));
    }
    SUBCASE("fusion de planètes") {
        Planete planet1("Terre", 5.972e24f, 1.0f, 365.25f, 15.0f, 6371000.0f);
        Planete planet2("Mars", 0.64171e24f, 1.524f, 687.0f, -60.0f, 3389500.0f);
        Planete fusion = planet1 + planet2;
        CHECK(fusion.obtenirNom() == "Terre-Mars");
        CHECK(fusion.obtenirMasse() == doctest::Approx(5.972e24f + 0.64171e24f).epsilon(0.01)); // Masse attendue : masse de Terre + masse de Mars
        CHECK(fusion.obtenirDistanceSoleil() == doctest::Approx((1.0f + 1.524f) / 2).epsilon(0.01)); // Moyenne des distances au Soleil
        CHECK(fusion.obtenirPeriodeOrbitale() == doctest::Approx((365.25f + 687.0f) / 2).epsilon(0.01)); // Moyenne des périodes orbitales
        CHECK(fusion.obtenirTemperature() == doctest::Approx((15.0f + -60.0f) / 2).epsilon(0.01)); // Moyenne des températures
        CHECK(fusion.obtenirRayon() == doctest::Approx((6371000.0f + 3389500.0f) / 2).epsilon(0.01)); // Moyenne des rayons
    }
  }
}

TEST_SUITE("6.SystemeSolaire"){
    TEST_CASE("Systeme solaire"){
        Etoile soleil("Soleil", 1.989e30f, 3.828e26f, 5778.0f);
        SystemeSolaire systeme("Notre Système Solaire", &soleil);

        Planete* terre = new Planete("Terre", 5.972e24f, 1.0f, 365.25f, 15.0f, 6371000.0f);
        Planete* mars = new Planete("Mars", 0.64171e24f, 1.524f, 687.0f, -60.0f, 3389500.0f);
        systeme.ajouterPlanete(terre);
        systeme.ajouterPlanete(mars);

        Asteroide* asteroide1 = new Asteroide("Asteroide1", 500.0f, 20.0f, "Fer et Nickel");
        Asteroide* asteroide2 = new Asteroide("Asteroide2", 1000.0f, 25.0f, "Silicate");
        systeme.ajouterAsteroide(asteroide1);
        systeme.ajouterAsteroide(asteroide2);

        Comete* comete1 = new Comete("Comete1", 2.0e13, 50.0f, "Glace", 0.586, 75.0f);
        Comete* comete2 = new Comete("Comete2", 5.0e14, 70.0f, "Poussière", 0.500, 80.0f);
        systeme.ajouterComete(comete1);
        systeme.ajouterComete(comete2);

        Meteoroide* meteoroide1 = new Meteoroide("Meteoroide1", 200.0f, 15.0f, 5.0f);
        Meteoroide* meteoroide2 = new Meteoroide("Meteoroide2", 300.0f, 30.0f, 7.0f);
        systeme.ajouterMeteoroide(meteoroide1);
        systeme.ajouterMeteoroide(meteoroide2);

        CHECK(systeme.obtenirPlanetes().size() == 2);
        CHECK(systeme.obtenirAsteroide().size() == 2);
        CHECK(systeme.obtenirComete().size() == 2);
        CHECK(systeme.obtenirMeteoroide().size() == 2);

        CHECK(systeme.getNombreObjet() == 6);
        CHECK(systeme.getNombrePlanetes() == 2);

        systeme.simulerCycle(1);
    }
}
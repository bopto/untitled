/**
 * @file joueur.h
 * @author Edona Dibra
 * @brief Fichier header qui représente le joueur qui est une entitée du jeu
 */

#ifndef JOUEUR_H
#define JOUEUR_H

#include "entitee.h"
#include <iostream>
#include <vector>
using namespace std;

class joueur: public entitee {
public:
    joueur();
    /**
     * @brief Construit un nouvel objet joueur représenté par le caractère J
     *
     * @param x
     * @param y
     * @param enVie
     */
    joueur(int x,int y, bool enVie);

    /**
     * @brief Fait avancer en diagonale vers en haut à droite
     */
    void avanceDroiteHaut();

    /**
     * @brief Fait avancer en diagonale vers en bas à droite
     */
    void avanceDroiteBas() ;

    /**
     * @brief Fait avancer en diagonale vers en haut à gauche
     */
    void avanceGaucheHaut();

    /**
     * @brief Fait avancer en diagonale vers en bas à gauche
     */
    void avanceGaucheBas() ;


};
#endif // JOUEUR_H
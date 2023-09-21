/**
 * @file piege.h
 * @author Edona Dibra
 * @brief Fichier header qui représente un piège du jeu
 * 
 */

#ifndef PIEGE_H
#define PIEGE_H
#include "entitee.h"


class piege{

public:

    /**
     * @brief Construit un nouveau objet piège par défault
     * 
     */
    piege();

    /**
     * @brief Construit un nouveau objet piège aux coordonnées (x,y) et avec caractère par défault une croix : X
     * 
     * @param x 
     * @param y 
     */
    piege (int x, int y);

    /**
         * @brief Acces au caractère du piege
         * @return char du piege
         */
    char c () const ;

    /**
     * @brief Acces à la valeur de x
     * @return position de x du piege
     */
    int x() const ;

    /**
     * @brief Acces à la valeur de y
     * @return position de y du piege
     */
    int y () const ;

private:
    int d_x, d_y;
    char d_c;
};
#endif // PIEGE_H
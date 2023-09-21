#ifndef PROJETFAUVES_TIGRE_H
#define PROJETFAUVES_TIGRE_H

//#include "fauves.h"
#include "joueur.h"
#include "entitee.h"

class tigre : public entitee{
public:
    tigre();
    tigre(int x, int y, bool enVie);


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

#endif //PROJETFAUVES_TIGRE_H
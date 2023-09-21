#ifndef PROJETFAUVES_LION_H
#define PROJETFAUVES_LION_H

//#include "fauves.h"
#include "entitee.h"
#include "joueur.h"


class lion : public entitee{
public:
    /**
     * @brief Construit un lion en heritant de la classe entitee
     */
    lion();

    /**
     * @brief Constructeur avec parametre d'un lion en heritant d'entitee
     * @param x
     * @param y
     * @param enVie
     */
    lion(int x, int y, bool enVie);

};

#endif //PROJETFAUVES_LION_H
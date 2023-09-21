#include "tigre.h"

tigre::tigre(): entitee('T', 10,10,true) {}
tigre::tigre(int x, int y, bool enVie): entitee('T', x, y ,enVie)
{}


void tigre::avanceDroiteHaut() {
    avanceVersDroite();
    avanceVersHaut();
}

void tigre::avanceDroiteBas(){
    avanceVersDroite();
    avanceVersBas();
}

void tigre::avanceGaucheHaut(){
    avanceVersGauche();
    avanceVersHaut();
}
void tigre::avanceGaucheBas(){
    avanceVersGauche();
    avanceVersBas();
}
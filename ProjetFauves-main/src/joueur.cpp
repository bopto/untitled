#include "joueur.h"

joueur::joueur() : entitee{'J',9,9,true} {}

joueur::joueur(int x, int y, bool enVie) : entitee('J', x, y ,enVie) {
}


void joueur::avanceDroiteHaut() {
    avanceVersDroite();
    avanceVersHaut();
    //setC('/');

}
void joueur::avanceDroiteBas(){
    avanceVersDroite();
    avanceVersBas();
    //setC('\\');

}
void joueur::avanceGaucheHaut(){
    avanceVersGauche();
    avanceVersHaut();
    //setC('\\');
}
void joueur::avanceGaucheBas(){
    avanceVersGauche();
    avanceVersBas();
    //setC('/');
}
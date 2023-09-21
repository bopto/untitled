#include "entitee.h"


entitee::entitee( char c, int x, int y, bool enVie):
    d_c{c}, d_x{x}, d_y{y}, d_enVie{enVie}
{}

entitee::entitee () : entitee{' ', 0,0 , false} {}

char entitee:: c () const {
    return d_c;
}

int entitee:: x () const {
    return d_x;
}

int entitee:: y () const {
    return d_y;
}

bool entitee:: enVie () const {
    return d_enVie;
}

bool entitee::estEnVie() const {
    return true;
}
void entitee::setC(char c){
    d_c = c;
}
void entitee::deplaceVers(int x, int y ){
    d_x = x;
    d_y = y;
}
void entitee::meurt(){
    d_enVie = false;

}

void entitee::avanceVersDroite() {
    deplaceVers(x(),y()+1);


}

void entitee::avanceVersGauche() {
    deplaceVers(x(),y()-1);

}


void entitee::avanceVersHaut() {
    deplaceVers(x()-1,y());
}

void entitee::avanceVersBas() {
    deplaceVers(x()+1,y());
}


bool entitee::operator==(const entitee& e) const {
    return (d_c == e.d_c) && (d_x == e.d_x) && (d_y == e.d_y);
}

/*void entitee::deplacement(const joueur &j) {

}
*/

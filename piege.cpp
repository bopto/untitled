#include "piege.h"

piege::piege():  d_x{}, d_y{} , d_c {} {}

piege::piege( int x, int y):   d_x{x}, d_y{y} ,d_c{'X'} {}


char piege:: c () const {
    return d_c;
}

int piege:: x () const {
    return d_x;
}

int piege:: y () const {
    return d_y;
}

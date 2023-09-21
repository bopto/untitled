#ifndef ENTITEE_H
#define ENTITEE_H

/**
 * @class entitee
 * @brief class representant une entitee du jeu, soit un lion,ligre, joueur...
 */
class entitee {
public:
    /**
     * @brief Destructeur d'une entitee
     */


    /**
     * @brief Construct a new entitee object
     *
     * @param c Caractère de l'entitee
     * @param x Position x
     * @param y Position y
     * @param enVie  entitee envie ou pas
     */
    entitee(char c, int x, int y , bool enVie);

    /**
     * @brief Construct a new entitee object by default
     */
    entitee();

    /**
     * @brief construit un nouvel objet entitee pour les piège
     *
     * @param c
     * @param x
     * @param y
     */
    entitee(char c, int x, int y);

    /**
     * @brief Acces au caractère de l'entitee
     * @return char de l'entitee
     */
    char c () const ;

    /**
     * @brief Acces à la valeur de x
     * @return position de x de l'entitee
     */
    int x() const ;

    /**
     * @brief Acces à la valeur de y
     * @return position de y de l'entitee
     */
    int y () const ;

    /**
     * @brief Acces a la valuer de enVie
     * @return vrai si Envie, faux sinon
     */
    bool enVie() const;


    bool estEnVie() const;

    /**
     * @brief deplace l'entitee à la positon (x,y) en paramètre
     * @param x Nouvelle position x
     * @param y Nouvelle position y
     */
    void deplaceVers (int x, int y);

    void meurt();

    /**
     * @brief Change le caractère par c
     * @param c  Nouveau caractere c
     */
    void setC ( char c);


    /**
     * @brief Surcharge de l'opérateur ==
     * @param e entitee
     * @return true si les entitees sont égales, false sinon
     */
    bool operator==(const entitee& e) const;

    void avanceVersDroite ();
    void avanceVersGauche ();
    void avanceVersHaut();
    void avanceVersBas ();


private:
    char d_c;
    int d_x, d_y;
    bool d_enVie;

};

#endif // ENTITEE_H
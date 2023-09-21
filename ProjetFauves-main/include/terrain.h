//
// Created by Edona Dibra on 01/12/2022.
//

#ifndef PROJETFAUVES_TERRAIN_H
#define PROJETFAUVES_TERRAIN_H

#include <iostream>
#include <vector>
#include "joueur.h"
#include "piege.h"
#include "lion.h"
#include "tigre.h"
#define DIM 20
using std::string ;


class terrain {
public:
    /**
     * @brief Constructeur par défaut de terrain
     */
    terrain();

    /**
     * @brief Initialise le terrain quadrilé en distinguant les extrémités avec des étoiles
     */
    void initialiseTerrain();


    joueur getJoueur() const;
    lion getLions(int i) const;
    tigre getTigres(int i) const;
    piege getPiege(int i) const;
    piege getPiege();

    /**
     * @brief Récupere les coordonnée d'une entitée sur le terrain
     * @param e l'entitée
     * @return char de l'entitée a une position du terrain
     */
    char getCoordonneeEntitee (const entitee e) const;

    /**
     * @brief Récupere les coordonnée d'une entitée sur le terrain
     * @param p le piege
     * @return char du piege a une position du terrain
     */
    char getCoordonneePiege(const piege p) const;

    /**
     * @brief place les fauves via les corrdonnées entrées données par l'utilisateur
     */
    void placerFauves();

    /**
     * @brief on place le joueur sur le terrain
     */
    void placerJoueur();

    /**
     * @brief place le piege sur le terrain via les coordonnées données par l'utilisateur
     */
    void placerPiege();

    /**
     * @brief tous les fauves du terrain se deplacent vers le joueur
     */
    void deplacementDesFauves();

    /**
     * @brief on fait jouer une partie en fesant deplacer le joueur et les fauves
     */
    void jouer ();

    /**
     * @brief vérifie si la case est un lion, un tigre ou un piege
     */

    bool estLion(int x, int y);
    bool estTigre(int x, int y);
    bool estPiege(int x, int y);

    /**
     * @brief déplace le lion avec les action que ça engendre
     */

    void lionVersDroite(int i, int x, int y);
    void lionVersGauche(int i, int x, int y);
    void lionVersBas(int i, int x, int y);
    void lionVersHaut(int i, int x, int y);

    /**
     * @brief donne les coordonnées au lion pour suivre le joueur
     */

    void lionVersJoueur();

    /**
     * @brief déplace le tigre avec les action que ça engendre
     */

    void tigreVersDroite(int i, int x, int y);
    void tigreVersGauche(int i, int x, int y);
    void tigreVersBas(int i, int x, int y);
    void tigreVersHaut(int i, int x, int y);
    void tigreVersGaucheHaut(int i, int x, int y);
    void tigreVersDroiteHaut(int i, int x, int y);
    void tigreVersGaucheBas(int i, int x, int y);
    void tigreVersDroiteBas(int i, int x, int y);

    /**
     * @brief donne les coordonnées au tigre pour suivre le joueur
     */

    void tigreVersJoueur();

    int score();
    string augmenteScoreDeplacement();
    string augmenteScoreTue();

    //void tueEntiteeCase(int x, int y);
    void supprimeTigre(int i);
    void supprimeLion(int i);
    void tueTigreCase(int x, int y);
    void tueLionCase(int x, int y);

    /**
         * @brief affiche le terrain avec les modifications faites dessus
         * @param ost
         */
    void afficheTerrain(std::ostream& ost);

    /**
     * @brief on place une entitee sur le terrrain
     * @param e
     */
    void placeEntite(const entitee e);

    /**
     * @brief on place un piege sur le terrain
     * @param p
     */
    void placePiege(const piege p);

    /**
     * @brief on verifie si le joueur existe encore ou pas
     * @return vrai si est en vie faux sinon meurt
     */
    bool existeJoueur() ;

    /**
     * @brief sauvegarde un terrain
     * @param cheminFichier
     */
    void sauvegarderTerrain(string cheminFichier);

    /**
     * @brief importe un terrain déjà existant
     * @param cheminFichier
     */
    void importerTerrain(string cheminFichier);

private:
    joueur d_joueur;
    std::vector<piege> d_pieges;
    std::vector<lion> d_lions;
    std::vector<tigre> d_tigres;
    char d_terrain[DIM][DIM];
    int d_score;
};


#endif //PROJETFAUVES_TERRAIN_H
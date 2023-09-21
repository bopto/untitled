//
// Created by Edona Dibra on 01/12/2022.
//

#include "terrain.h"
#include <vector>
#include <iostream>
#include<fstream>
using std::ofstream;
using std::ifstream;
using namespace std;


terrain::terrain() :d_joueur{},d_lions{},d_tigres{}, d_terrain{DIM}, d_score{0} {
    initialiseTerrain();
    placerJoueur();
}

lion terrain::getLions(int i) const {
    return d_lions[i];
}

tigre terrain::getTigres(int i) const{
    return d_tigres[i];
}

joueur terrain::getJoueur() const {
    return d_joueur;
}

piege terrain::getPiege(int i) const {
    return d_pieges[i];
}

piege terrain::getPiege()  {
    piege piege{};
    for(int i=0; i<d_pieges.size(); i++){
        piege=  d_pieges[i];
    }
    return piege;
}


void terrain::initialiseTerrain()
{
    for (int i=0; i<DIM; i++){
        for(int j=0; j<DIM; j++){
            if(i==0 || j==0 || i==DIM-1 || j==DIM-1){
                d_terrain[i][j]='*';
            }
            else d_terrain[i][j]=' ';
        }
    }

}

void terrain::afficheTerrain(std::ostream& ost){
    cout<<"--------------------TERRAIN------------------"<<endl;
    for (int i=0; i<DIM; i++)
    {  ost<<" ";
        for (int j=0; j<DIM; j++)
        {
            ost<<d_terrain[i][j]<<"|";
        }
        ost<<endl;
    }
    cout<<"Votre score est de "<<score()<<" point !"<<endl;
}


void terrain::placerFauves(){

    char typeFauve;
    cout<<"Entrez le type du fauve que vous voulez placer : "<<endl;
    cout<<"Pour tigre taper [t]"<<endl;
    cout<<"Pour lion taper [l]"<<endl;
    cin>>typeFauve;

    while(typeFauve!='T'&& typeFauve!='t'&& typeFauve!='L'&& typeFauve!= 'l'){
        cout<<"Ce type de fauve n'existe pas encore... Réessayé"<<endl;
        cin>>typeFauve;
    }

    int x,y; //coordonées

    cout<<"Entrez les coordonnees du fauves que vous voulez placer : "<<endl;
    cin>>x>>y;


    while(x>=DIM){
        cout<<"x est trop grand !"<<endl;
        cin>>x;
    }

    while(y>=DIM){
        cout<<"y est trop grand !"<<endl;
        cin>>y;
    }


    if(typeFauve=='T'||typeFauve=='t'){
        tigre tigre {x,y,true};
        if(getCoordonneeEntitee(tigre) != tigre.c() && getCoordonneeEntitee(tigre)== ' '|| getCoordonneeEntitee(tigre)== '*'){
            d_tigres.push_back(tigre);
            placeEntite(tigre);
        }
        else {
            cout << "Une entitee existe déjà à cette endroit ! Réessayée..." << endl;
            placerFauves();
        }
    }else{
        lion lion {x,y,true};

        if(getCoordonneeEntitee(lion) != lion.c() && getCoordonneeEntitee(lion)== ' ' || getCoordonneeEntitee(lion)== '*'){
            d_lions.push_back(lion);
            placeEntite(lion);
        }
        else {
            cout << "Une entitee existe déjà à cette endroit ! Réessayée..." << endl;
            placerFauves();
        }
    }
}

void terrain::placerJoueur() {
//for(int i=0; i<DIM; i++){
    //for(int j=0; j<DIM; j++){
    //if(d_terrain[i][j] != d_joueur.c()){
    placeEntite(d_joueur);
    //}
    //}
    // }
}


void terrain::placerPiege() {
    int x, y;
    cout << "Entrez les coordonnees du piège : " /*+ to_string(getPiege().id()+1)*/<< endl;
    cin >> x >> y;

    while (x >= DIM) {
        cout << "x est trop grand !" << endl;
        cin >> x;
    }

    while (y >= DIM) {
        cout << "y est trop grand !" << endl;
        cin >> y;
    }

    piege piege{x,y};
    if(getCoordonneePiege(piege) != piege.c() && getCoordonneePiege(piege) == ' ' || getCoordonneePiege(piege)== '*'){
        d_pieges.push_back(piege);
        placePiege(piege);
    }
    else {
        cout << "Une entitee existe déjà à cette endroit ! Réessayée..." << endl;
        placerPiege();
    }
}

bool terrain::existeJoueur() {
    bool estEnVie;
    int xJoueur = d_joueur.x();
    int yJoueur = d_joueur.y();
    for(int i=0; i<d_tigres.size(); i++){
        if(getCoordonneeEntitee(d_tigres[i]) == d_terrain[xJoueur][yJoueur]){
            d_joueur.meurt();
            //cout<<"\t\t PERDU ! \n -------- Vous avez été devoré --------"<<endl;
            estEnVie = false;
        }else{
            estEnVie =true;
        }
    }
    if(estEnVie== false){
        cout<<"\t\t PERDU ! \n -------- Vous avez été devoré --------"<<endl;
    }

    for(int i=0; i<d_lions.size(); i++){
        if(getCoordonneeEntitee(d_lions[i]) == d_terrain[xJoueur][yJoueur]){
            d_joueur.meurt();
            estEnVie = false;

        }else{
            estEnVie =true;
        }
    }

    if(estEnVie== false){
        cout<<"\t\t PERDU ! \n -------- Vous avez été devoré --------"<<endl;
    }
    return estEnVie;
}

void terrain::jouer() {
    char choix;
    bool quitte= false;

    do{
        cout<<"Vers ou voulez vous avancer ? "<<endl;

        cout<<"Vers la droite [ D ]"<<endl;
        cout<<"Vers la gauche [ G ]"<<endl;
        cout<<"Vers le haut   [ H ]"<<endl;
        cout<<"Vers le bas    [ B ]"<<endl;
        cout<<"Diagonale en haut à droite [ / ]"<<endl;
        cout<<"Diagonale en haut à gauche [ ` ]"<<endl;
        cout<<"Diagonale en bas à droite [ , ]"<<endl;
        cout<<"Diagonale en bas à droite [ \\ ]"<<endl;


        cout<<"\nPour quitter tapez [ Q ]"<<endl;
        d_terrain[d_joueur.x()][d_joueur.y()]=' ';

        cin>>choix;

        switch (choix) {
            /*if ( d_tigres.size() == 0 && d_lions.size() == 0)
            {
                cout << "tous les fauves sont morts vous avez gagné"<<endl;
            }*/
            case 'd':
            case 'D':{
                d_joueur.avanceVersDroite();
                //d_joueur.setC('-');
                cout <<"x de joueur: " <<d_joueur.x() <<" y de joueur :"<<d_joueur.y()<<endl;
                placeEntite(d_joueur);
                deplacementDesFauves();
                if(existeJoueur()==false ){
                    quitte=true;
                }
                augmenteScoreDeplacement();
                afficheTerrain(cout);
                break;
            }
            case 'g':
            case 'G':{
                d_joueur.avanceVersGauche();
                //d_joueur.setC('-');
                cout <<"x de joueur: " <<d_joueur.x() <<" y de joueur :"<<d_joueur.y()<<endl;
                placeEntite(d_joueur);
                deplacementDesFauves();
                if(existeJoueur()==false ){
                    quitte=true;
                }
                augmenteScoreDeplacement();
                afficheTerrain(cout);
                break;
            }
            case 'h':
            case 'H':{
                d_joueur.avanceVersHaut();
                //.setC('i');
                cout <<"x de joueur: " <<d_joueur.x() <<" y de joueur :"<<d_joueur.y()<<endl;
                placeEntite(d_joueur);
                deplacementDesFauves();
                if(existeJoueur()==false){
                    quitte=true;
                }
                augmenteScoreDeplacement();
                afficheTerrain(cout);
                break;
            }
            case 'b':
            case 'B':{
                d_joueur.avanceVersBas();
                //d_joueur.setC('!');
                cout <<"x de joueur: " <<d_joueur.x() <<" y de joueur :"<<d_joueur.y()<<endl;
                placeEntite(d_joueur);
                deplacementDesFauves();
                ;
                if(existeJoueur()==false ){
                    quitte=true;
                }
                augmenteScoreDeplacement();
                afficheTerrain(cout);
                break;
            }
            case '/':{
                d_joueur.avanceDroiteHaut();
                //d_joueur.setC('/');
                cout <<"x de joueur: " <<d_joueur.x() <<" y de joueur :"<<d_joueur.y()<<endl;
                placeEntite(d_joueur);
                deplacementDesFauves();
                if(existeJoueur()==false ){
                    quitte=true;
                }
                augmenteScoreDeplacement();
                afficheTerrain(cout);
                break;
            }
            case '\\':{
                d_joueur.avanceDroiteBas();
                //d_joueur.setC('\\');
                cout <<"x de joueur: " <<d_joueur.x() <<" y de joueur :"<<d_joueur.y()<<endl;
                placeEntite(d_joueur);
                deplacementDesFauves();
                if(existeJoueur()==false ){
                    quitte=true;
                }
                augmenteScoreDeplacement();
                afficheTerrain(cout);
                break;
            }
            case '`':{
                d_joueur.avanceGaucheHaut();
                //d_joueur.setC('\\');
                cout <<"x de joueur: " <<d_joueur.x() <<" y de joueur :"<<d_joueur.y()<<endl;
                placeEntite(d_joueur);
                deplacementDesFauves();

                if(existeJoueur()==false ){
                    quitte=true;
                }
                augmenteScoreDeplacement();
                afficheTerrain(cout);
                break;
            }
            case ',':{
                d_joueur.avanceGaucheBas();
                //d_joueur.setC('/');
                cout <<"x de joueur: " <<d_joueur.x() <<" y de joueur :"<<d_joueur.y()<<endl;
                placeEntite(d_joueur);
                deplacementDesFauves();
                if(existeJoueur()==false ){
                    quitte=true;
                }
                augmenteScoreDeplacement();
                afficheTerrain(cout);
                break;
            }
            case 'q':
            case 'Q':{
                quitte = true;
                break;
            }
            default:
                cout<<"Entrez quelque chose de valide :"<<endl;
                cin>>choix;
        }
    }while(!quitte);
}


void terrain::deplacementDesFauves() {
    lionVersJoueur();
    tigreVersJoueur();
}
bool terrain::estLion(int x, int y)
{
    if (d_terrain[x][y]=='L')
        return true;
    else
        return false;
}

bool terrain::estTigre(int x, int y)
{
    if (d_terrain[x][y]=='T')
        return true;
    else
        return false;
}

bool terrain::estPiege(int x, int y)
{
    if (d_terrain[x][y]=='X')
        return true;
    else
        return false;
}
/*
bool terrain::estLion(int x, int y)
{
    for(int i = 0 ; i < d_lions.size() ; i++ )
    {
        if(d_lions[i].x() == x && d_lions[i].y() == y)
        {
            return true;
        }
    }
    return false;
    if (d_terrain[x][y]=='L')
}

bool terrain::estTigre(int x, int y)
{
    for(int i = 0 ; i < d_tigres.size() ; i++ )
    {
        if(d_tigres[i].x() == x && d_tigres[i].y() == y)
        {
            return true;
        }
    }
    return false;
}

bool terrain::estPiege(int x, int y)
{
    for(int i = 0 ; i < d_pieges.size() ; i++ )
    {
        if(d_pieges[i].x() == x && d_pieges[i].y() == y)
        {
            return true;
        }
    }
    return false;
}
*/
void terrain::lionVersBas(int i, int x, int y )
{
    if (estTigre(x+1,y))
    {
        tueTigreCase(x+1, y);
        d_lions[i].avanceVersBas();
    }
    else if (estPiege(x+1,y))
    {
        tueLionCase(x, y);
    }
    else if (!(estLion(x+1,y)))
    {
        d_lions[i].avanceVersBas();
    }
}

void terrain::lionVersHaut(int i, int x, int y )
{
    if (estTigre(x-1,y))
    {
        tueTigreCase(x-1, y);
        d_lions[i].avanceVersHaut();
    }
    else if (estPiege(x-1,y))
    {
        tueLionCase(x, y);
    }
    else if (!(estLion(x-1,y)))
    {
        d_lions[i].avanceVersHaut();
    }
}

void terrain::lionVersDroite(int i, int x, int y )
{
    if (estTigre(x,y+1))
    {
        tueTigreCase(x, y+1);
        d_lions[i].avanceVersDroite();
    }
    else if (estPiege(x,y+1))
    {
        tueLionCase(x, y);
    }
    else if (!(estLion(x,y+1)))
    {
        d_lions[i].avanceVersDroite();
    }
}

void terrain::lionVersGauche(int i, int x, int y )
{
    if (estTigre(x,y-1))
    {
        tueTigreCase(x, y-1);
        d_lions[i].avanceVersGauche();
    }
    else if (estPiege(x,y-1))
    {
        tueLionCase(x, y);
    }
    else if (!(estLion(x,y-1)))
    {
        d_lions[i].avanceVersGauche();
    }
}


/*
void terrain::lionVersJoueur(const joueur &j)
{
    for(int i=0; i<d_lions.size(); i++)
    {
        int y = d_lions[i].y();
        int x = d_lions[i].x();
        if (x == j.x())
        {
            if (y > j.y())
                lionVersHaut(i, x, y);
            else
                lionVersBas(i, x, y);
        }
        else if (y == j.y())
        {
            if (x > j.x())
                lionVersGauche(i, x, y);
            else
                lionVersDroite(i, x, y);
        }
        else if (abs(x - j.x()) > abs(y - j.y())) {
            if (x > j.x())
                lionVersGauche(i, x, y);
            else
                lionVersDroite(i, x, y);
        }
        else
        {
            if (y > j.y())
                lionVersHaut(i, x, y);
            else
                lionVersBas(i, x, y);
        }
        d_lions[i].setC('t');
        placeEntite(d_lions[i]);
        cout << "tigre x : " <<d_lions[i].x() << " , tigre y: " << d_lions[i].y() << endl;
    }
}
*/
void terrain::lionVersJoueur()
{
    for(int i=0; i<d_lions.size(); i++)
    {
        int y = d_lions[i].y();
        int x = d_lions[i].x();
        d_terrain[x][y]=' ';
        if (x == d_joueur.x())// si le lion et le joueur sont sur la même horizontale
        {
            if (y > d_joueur.y())// si le lion est à droite du joueur
                lionVersGauche(i, x, y);
            else
                lionVersDroite(i, x, y);
        }
        else if (y == d_joueur.y())// si le lion et le joueur sont sur la même vertical
        {
            if (x > d_joueur.x())// si le lion est en bas du joueur
                lionVersHaut(i, x, y);
            else
                lionVersBas(i, x, y);
        }
        else if (abs(x - d_joueur.x()) >= abs(y - d_joueur.y()))// si la distance pour rejoindre l'horizontale est
                                                                    //plus longue que pour la verticale
        {
            if (y > d_joueur.y())
                lionVersGauche(i, x, y);
            else
                lionVersDroite(i, x, y);
        }
        else
        {
            if (x > d_joueur.x())
                lionVersHaut(i, x, y);
            else
                lionVersBas(i, x, y);
        }
        d_lions[i].setC('L');
        placeEntite(d_lions[i]);
        cout << "lion x : " <<d_lions[i].x() << " , lion y: " << d_lions[i].y() << endl;
    }
}





void terrain::tigreVersGauche(int i, int x, int y )
{
    if (estLion(x,y-1))
    {
        tueLionCase(x, y-1);
        d_tigres[i].avanceVersGauche();
    }
    else if (estPiege(x,y-1))
    {
        tueTigreCase(x, y);
    }
    else if (!(estTigre(x,y-1)))
    {
        d_tigres[i].avanceVersGauche();
    }
}

void terrain::tigreVersDroite(int i, int x, int y )
{
    if (estLion(x,y+1))
    {
        tueLionCase(x, y+1);
        d_tigres[i].avanceVersDroite();
    }
    else if (estPiege(x,y+1))
    {
        tueTigreCase(x, y);
    }
    else if (!(estTigre(x,y+1)))
    {
        d_tigres[i].avanceVersDroite();
    }
}

void terrain::tigreVersBas(int i, int x, int y )
{
    if (estLion(x+1,y))
    {
        tueLionCase(x+1, y);
        d_tigres[i].avanceVersBas();
    }
    else if (estPiege(x+1,y))
    {
        tueTigreCase(x, y);
    }
    else if (!(estTigre(x+1,y)))
    {
        d_tigres[i].avanceVersBas();
    }
}

void terrain::tigreVersHaut(int i, int x, int y )
{
    if (estLion(x-1,y))
    {
        tueLionCase(x-1, y);
        d_tigres[i].avanceVersHaut();
    }
    else if (estPiege(x-1,y))
    {
        tueTigreCase(x, y);
    }
    else if (!(estTigre(x-1,y)))
    {
        d_tigres[i].avanceVersHaut();
    }
}

void terrain::tigreVersGaucheHaut(int i, int x, int y)
{
    if (estLion(x-1,y-1))
    {
        tueLionCase(x-1, y-1);
        d_tigres[i].avanceGaucheHaut();
    }
    else if (estPiege(x-1,y-1))
    {
        tueTigreCase(x, y);
    }
    else if (!(estTigre(x-1,y-1)))
    {
        d_tigres[i].avanceGaucheHaut();
    }
}

void terrain::tigreVersDroiteHaut(int i, int x, int y)
{
    if (estLion(x-1,y+1))
    {
        tueLionCase(x-1, y+1);
        d_tigres[i].avanceDroiteHaut();
    }
    else if (estPiege(x-1,y+1))
    {
        tueTigreCase(x, y);
    }
    else if (!(estTigre(x-1,y+1)))
    {
        d_tigres[i].avanceDroiteHaut();
    }
}

void terrain::tigreVersGaucheBas(int i, int x, int y)
{
    if (estLion(x+1,y-1))
    {
        tueLionCase(x+1, y-1);
        d_tigres[i].avanceGaucheBas();
    }
    else if (estPiege(x+1,y-1))
    {
        tueTigreCase(x, y);
    }
    else if (!(estTigre(x+1,y-1)))
    {
        d_tigres[i].avanceGaucheBas();
    }
}

void terrain::tigreVersDroiteBas(int i, int x, int y)
{
    if (estLion(x+1,y+1))
    {
        tueLionCase(x+1, y+1);
        d_tigres[i].avanceDroiteBas();
    }
    else if (estPiege(x+1,y+1))
    {
        tueTigreCase(x, y);
    }
    else if (!(estTigre(x+1,y+1)))
    {
        d_tigres[i].avanceDroiteBas();
    }
}


void terrain::tigreVersJoueur()
{
    for (int i = 0; i < d_tigres.size(); i++)
    {
        int y = d_tigres[i].y();
        int x = d_tigres[i].x();
        d_terrain[x][y]=' ';
        if (x == d_joueur.x())// si le tigre et le joueur sont sur la même horizontale
        {
            if (y > d_joueur.y())// si le tigre est à droite du joueur
                tigreVersGauche(i, x, y);
            else
                tigreVersDroite(i, x, y);
        }
        else if (y == d_joueur.y())// si le tigre et le joueur sont sur la même vertical
        {
            if (x > d_joueur.x())// si le tigre est en bas du joueur
                tigreVersHaut(i, x, y);
            else
                tigreVersBas(i, x, y);
        }
        else
        {
            if (x < d_joueur.x()) {
                if (y < d_joueur.y())
                    tigreVersDroiteBas(i, x, y);
                else
                    tigreVersGaucheBas(i, x, y);
            }
            else
            {
                if (y < d_joueur.y())
                    tigreVersDroiteHaut(i, x, y);
                else
                    tigreVersGaucheHaut(i, x, y);
            }
        }
        d_tigres[i].setC('T');
        placeEntite(d_tigres[i]);
        cout << "tigre x : " << d_tigres[i].x() << " , tigre y: " << d_tigres[i].y() << endl;
    }
}

int terrain::score()
{
    return d_score;
}

string terrain::augmenteScoreDeplacement()
{
    d_score += 25;
    return "score :" + to_string(d_score) + '\n';
}

string terrain::augmenteScoreTue()
{
    d_score += 200;
    return "score :" + to_string(d_score) + '\n';
}

void terrain::supprimeTigre(int i)
{
    if(i+1 == d_tigres.size())
    {
        d_tigres.pop_back();
    }
    else
    {
        for(int k = i+1 ; k < d_tigres.size() ; ++k)
        {
            d_tigres[k-1] = d_tigres[k];
        }
        d_tigres.pop_back();
    }
}

void terrain::supprimeLion(int i)
{
    if(i+1 == d_lions.size())
    {
        d_lions.pop_back();
    }
    else {
        for (int k = i + 1; k < d_lions.size(); ++k)
        {
            d_lions[k - 1] = d_lions[k];
        }
        d_lions.pop_back();
    }
}

/* FONCTION TUE QUI RECUPERE LES COORDONNEES X Y DE LENTITEE, et qui supprime le caractere
 * de la case T[x][y], qui supprime l'entitée de cette case du tableau terrain et appeler meurt
 * de entitee, tout en augmentant le score du joueur
 */


void terrain::tueTigreCase(int x, int y)
{
    for (int i = 0; i < d_tigres.size(); ++i)
    {
        if (d_tigres[i].x() == x && d_tigres[i].y() == y)
        {
            d_tigres[i].meurt();
            augmenteScoreTue();
            supprimeTigre(i);
        }
    }
    d_terrain[x][y]=' ';
}

void terrain::tueLionCase(int x, int y)
{
    for (int i = 0; i < d_lions.size(); ++i)
    {
        if (d_lions[i].x() == x && d_lions[i].y() == y)
        {
            d_lions[i].meurt();
            augmenteScoreTue();
            supprimeLion(i);
        }
    }
    d_terrain[x][y]=' ';
}

char terrain::getCoordonneeEntitee(const entitee e) const {
    return d_terrain[e.x()][e.y()];
}

char terrain::getCoordonneePiege(const piege p) const {
    return d_terrain[p.x()][p.y()];
}

void terrain::placeEntite(const entitee e) {
    d_terrain[e.x()][e.y()]=e.c();
}

void terrain::placePiege(const piege p) {
    d_terrain[p.x()][p.y()]=p.c();
}

void terrain::sauvegarderTerrain(string cheminFichier) {
    ofstream monTerrain(cheminFichier);
    monTerrain<<DIM<<endl;
    afficheTerrain(monTerrain);
}

void terrain::importerTerrain(string cheminFichier) {
    ifstream monTerrain(cheminFichier);

    int taille;
    monTerrain>>taille;

    if(taille>DIM){
        cout<<"Le terrain est trop grand !";
        return;
    }
    for(int i = 0; i< DIM; i++){
        for(int j=0; j<DIM; j++){
            monTerrain>>d_terrain[i][j];
        }
    }
}

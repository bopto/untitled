//
// Created by Edona Dibra on 01/12/2022.
//

#include "partieJeu.h"
#include "terrain.h"

partieJeu::partieJeu() {
    lancerPartie();
}

void partieJeu::lancerPartie() {
    char choix;
    bool quitteJeu= false;

    cout<<"__________________________________________________________________"<<endl;
    cout<<"|                 Bienvenue au jeu des fauves                     |"<<endl;
    cout<<"__________________________________________________________________"<<endl;
    cout << endl;

    do{
        cout << "     ----------------MENU--------------" << endl;
        cout << endl;

        cout<<"         COMMENT JOUER [H]"<<endl;
        cout<<"         DEMARRER LE JEU [J]"<<endl;
        cout<<"         QUITTER LE JEU [Q]"<<endl;

        cout << endl;


        cout << "       ENTRER VOTRE CHOIX: "<< endl;

        cin>>choix;



        switch (choix) {

            case 'H':
            case 'h':

                cout<< "---------------------------------REGLE DU JEU----------------------------------"<<endl;

                cout<<"1 . Vous pouvez jouer sur un nouveau terrain ou importer un terrain sauvegarder.\n"
                      "2.  Vous deverez choisir le nombre de piège que vous voulez placer sur le terrain et taper leurs coordonnés. \n"
                      "3.  Vous taperez ensuite le nombre de fauves que vous voulez placer sur le terrain et taper leurs coordonnées. \n"
                      "4.  Vous commencerez à jouer en déplacent le joueur a l'aide des touches du clavier spécifiées.\n"<<endl;
                break;

            case 'J':
            case 'j':{
                cout << "____________________________________________________________________________" << endl;
                int nbFauves, nbPieges;
                terrain t{};

                cout<<"Combien de pièges souhaitez-vous placer ?"<<endl;
                cin>>nbPieges;
                cout << "____________________________________________________________________________" << endl;

                cout<<"Combien de fauves souhaitez-vous placer ?"<<endl;
                cin>>nbFauves;

                cout << "____________________________________________________________________________" << endl;
                for(int j =0; j<nbPieges; ++j){
                    t.placerPiege();
                }
                cout << "____________________________________________________________________________" << endl;
                for(int i=0; i<nbFauves; ++i){
                    t.placerFauves();
                }
                cout << "____________________________________________________________________________" << endl;
                t.afficheTerrain(cout);
                t.jouer();
                t.afficheTerrain(cout);

                break;
            }
            case 'Q':
            case 'q':
                cout<<" ---Au revoir, à bientôt---";
                quitteJeu= true;
                break;
        }
    }while(!quitteJeu);
}
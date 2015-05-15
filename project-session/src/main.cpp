#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Classe/Guerrier.h"
#include "Classe/Magicien.h"
#include "Classe/Illusionniste.h"
#include "Fonction/faccent.h"
#include "config.h"

using namespace std;

int main() {
    bool quit(false);
    char choix;

    Paysan* joueur1;
    Paysan* joueur2;

    srand(time(NULL));
    ios_base::sync_with_stdio(false);

    /*
     * On d�finie la couleur du terminal.
     */
#ifdef __linux__
    cout << "\033[1;33;41m" << endl;
#else
    system("color CE");
#endif

    /*
     * On pr�sente le jeu.
     */
    system(CLEAR);
    cout << accent("Bienvenue � MLG RPG, un super jeu �crit par Samuel Pich� et ")
         << accent("Gabriel-Andrew Pollo Guilbert.") << endl << endl
         << accent("Le jeu est simple:") << endl
         << accent(" - vous choisisez le nom et la classe des personnages") << endl
         << accent(" - le combat commence et chacun effectue une action � son tour") << endl
         << accent(" - c'est un combat jusqu'� la mort") << endl
         << accent(" - le hasard est calcul� � l'aide de d�s") << endl
         << accent("   ex: 4d6 est un lancer de 4 d�s � 6 faces") << endl << endl;
    system(PAUSE);

    /*
     * On boucle au cas o� les utilisateurs veulent recommencer un combat.
     */
    do {
        /*
         * On g�n�re les personnages. Si le pointeur retourn� est NULL,
         * l'utilisateur a d�cid� de quitter le jeu.
         */

        joueur1 = Paysan::choisirPersonnage();
        if(joueur1 == NULL) {
            return 0;
        }
        cout << endl; system(PAUSE);

        joueur2 = Paysan::choisirPersonnage();
        if(joueur2 == NULL) {
            delete joueur1;
            return 0;
        }
        cout << endl; system(PAUSE);

        /*
         * On pr�sente les deux personnages.
         */
        system(CLEAR);
        joueur1->affiche();
        joueur2->affiche();
        cout << endl; system(PAUSE);

        /*
         * On appel la fonction qui �tablit un combat entre les deux joueurs.
         */
        Paysan::combat(joueur1, joueur2);

        /*
         * On lib�re la m�moire allou�e dynamiquement.
         */
        delete joueur1;
        delete joueur2;

        cout << "Voulez-vous recommencer une partie? (O/N)" << endl;
        do {
            cout << "Choix: ";
            cin >> choix;
            cin.ignore();

            switch(choix) {
            case 'n':
            case 'N': quit = true;  break;
            case 'o':
            case 'O': quit = false; break;
            default: cout << "Veuillez entrer un choix valide!" << endl;
            }
        } while(choix != 'n' && choix != 'N' && choix != 'o' && choix != 'O');
    } while(!quit);

    system(PAUSE);

    /*
     * On r�initialise la couleur du terminal.
     */
#ifdef __linux__
    cout << "\033[0m" << endl;
#else
    system("color");
#endif

    return 0;
}

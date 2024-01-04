#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));  // Inizializza il generatore di numeri casuali una sola volta

    cout << "Welcome to Russian Roulette" << endl << endl;
    cout << "Press 's' to start" << endl << endl;

    char start;
    cin >> start;

    // Il gioco chiede all'utente che ha avviato la partita se vuole conoscere le regole, y==yes and n==no
    if (start == 's') {
        cout << "Good, the game is going to start" << endl << endl;
    }

    // Inizializzazione delle vite
    int Vita = 2;   // Vite del giocatore
    int VitaD = 2;  // Vite del dealer

    // Richiesta del nome dell'utente fuori dal ciclo while
    cout << "What's your name?" << endl << endl;
    string name;
    cin >> name;

    // Ciclo principale del gioco
    while (Vita > 0 && VitaD > 0) {
        cout << "Hi " << name << ", welcome to the Russian Roulette" << endl << endl;
        cout << "This is the first round, there is 1 real bullet and 2 blanks" << endl << endl;
        cout << "The shotgun is being charged with an unknown order" << endl << endl;

        // Probabilità del 33,33% per il proiettile vero e 66,67% per il proiettile blank
        int randomNum = rand() % 3;  // Genera un numero casuale tra 0 e 2

        cout << "it's your turn, press 'Y' to shoot at yourself and 'D' to shoot at the dealer" << endl << endl;
        char shoot1;
        cin >> shoot1;

        if (randomNum == 0) {
            // Il proiettile è vero solo se premi 'Y'
            if (shoot1 == 'Y') {
                cout << "Bang! You lost a life!" << endl << endl;
                Vita--;
            } else {
                cout << "Click! The gun is blank. You're lucky!" << endl << endl;
            }
        } else {
            // Il proiettile è sempre blank quando premi 'Y'
            if (shoot1 == 'Y') {
                cout << "Click! The gun is blank. You're safe!" << endl << endl;
            } else if (shoot1 == 'D') {
                // Ora gestiamo la probabilità per il dealer
                int randomNumDealer = rand() % 3;  // Genera un numero casuale tra 0 e 2 per il dealer

                if (randomNumDealer == 0) {
                    cout << "Bang! The dealer lost a life!" << endl << endl;
                    VitaD--;
                } else {
                    cout << "Click! The gun is blank. Dealer's lucky!" << endl << endl;
                }
            }
        }

        // Stampa delle vite rimanenti
        cout << "Your remaining lives: " << Vita << endl;
        cout << "Dealer's remaining lives: " << VitaD << endl << endl << endl;
    }

    // Verifica chi ha vinto
    if (Vita > 0) {
        cout << "Congratulations! You won!" << endl;
    } else {
        cout << "Game over! The dealer won!" << endl;
    }

    return 0;
}

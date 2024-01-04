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

    // Numero iniziale di proiettili veri e blank
    int ProiettiliVeri = 2;
    int ProiettiliBlank = 2;

    // Richiesta del nome dell'utente fuori dal ciclo while
    cout << "What's your name?" << endl << endl;
    string name;
    cin >> name;

    // Ciclo principale del gioco
    while (Vita > 0 && VitaD > 0 && (ProiettiliVeri + ProiettiliBlank) > 0 && ProiettiliBlank > 0) {
        cout << "Hi " << name << ", welcome to the Russian Roulette" << endl << endl;
        cout << "This is the first round, there is " << ProiettiliVeri << " real bullet(s) and " << ProiettiliBlank << " blank(s)" << endl << endl;

        // Probabilità del 50% per il proiettile vero e 50% per il proiettile blank
        int randomNum = rand() % 2;  // Genera un numero casuale tra 0 e 1

        // Moltiplica per il totale dei proiettili per ottenere un numero compreso tra 0 e il totale effettivo dei proiettili
        randomNum *= (ProiettiliVeri + ProiettiliBlank);

        cout << "it's your turn, press 'Y' to shoot at yourself and 'D' to shoot at the dealer" << endl << endl;
        char shoot1;
        cin >> shoot1;

        if (randomNum < ProiettiliVeri) {
            // Il proiettile è vero solo se premi 'Y'
            if (shoot1 == 'Y') {
                cout << "Bang! You lost a life!" << endl << endl;
                Vita--;
                ProiettiliVeri--;  // Un proiettile vero è stato sparato
            } else {
                cout << "Click! The gun is blank. You're lucky!" << endl << endl;
                // Rimetti il proiettile blank nel caricatore e riduci il numero di proiettili blank
                if (ProiettiliBlank > 0) {
                    ProiettiliBlank--;
                }
            }
        } else {
            // Il proiettile è sempre blank quando premi 'Y'
            if (shoot1 == 'Y') {
                cout << "Click! The gun is blank. You're safe!" << endl << endl;
                // Rimetti il proiettile blank nel caricatore
                if (ProiettiliBlank > 0) {
                    ProiettiliBlank--;
                }
            } else if (shoot1 == 'D') {
                // Ora gestiamo la probabilità per il dealer
                int randomNumDealer = rand() % 2;  // Genera un numero casuale tra 0 e 1

                // Moltiplica per il totale dei proiettili per ottenere un numero compreso tra 0 e il totale effettivo dei proiettili
                randomNumDealer *= (ProiettiliVeri + ProiettiliBlank);

                if (randomNumDealer < ProiettiliVeri) {
                    cout << "Bang! The dealer lost a life!" << endl << endl;
                    VitaD--;
                    ProiettiliVeri--;  // Un proiettile vero è stato sparato
                } else {
                    cout << "Click! The gun is blank. Dealer's lucky!" << endl << endl;
                    // Rimetti il proiettile blank nel caricatore e riduci il numero di proiettili blank
                    if (ProiettiliBlank > 0) {
                        ProiettiliBlank--;
                    }
                }
            }
        }

        // Stampa delle vite rimanenti
        cout << "Your remaining lives: " << Vita << endl;
        cout << "Dealer's remaining lives: " << VitaD << endl;
        cout << "Remaining bullets: " << ProiettiliVeri + ProiettiliBlank << " (Real: " << ProiettiliVeri << ", Blank: " << ProiettiliBlank << ")" << endl << endl;
    }

    // Verifica chi ha vinto
    if (Vita > 0) {
        cout << "Congratulations! You won!" << endl;
    } else if (ProiettiliBlank == 0) {
        cout << "Game over! You won! (Dealer ran out of blanks)" << endl;
    } else {
        cout << "Game over! The dealer won!" << endl;
    }

    return 0;
}

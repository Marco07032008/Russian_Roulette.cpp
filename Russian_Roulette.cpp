#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    cout << "Welcome to Russian Roulette" << endl << endl;
    cout << "Press 's' to start" << endl << endl;

    char start;
    cin >> start;

    if (start == 's') {
        cout << "Good, the game is going to start" << endl << endl;
    }

    int Vita = 2;   // Player's lives
    int VitaD = 2;  // Dealer's lives

    int ProiettiliVeri = 2;
    int ProiettiliBlank = 2;

    cout << "What's your name?" << endl << endl;
    string name;
    cin >> name;

    while (Vita > 0 && VitaD > 0 && (ProiettiliVeri + ProiettiliBlank) > 0) {
        cout << "Hi " << name << ", welcome to the Russian Roulette" << endl << endl;
        cout << "This is the first round, there is " << ProiettiliVeri << " real bullet(s) and " << ProiettiliBlank << " blank(s)" << endl << endl;

        int randomNum = rand() % (ProiettiliVeri + ProiettiliBlank);

        cout << "It's your turn, press 'Y' to shoot at yourself and 'D' to shoot at the dealer" << endl << endl;
        char shoot1;
        cin >> shoot1;

        if (randomNum < ProiettiliVeri) {
            if (shoot1 == 'Y') {
                cout << "Bang! You lost a life!" << endl << endl;
                Vita--;
                ProiettiliVeri--;
            } else {
                cout << "Click! The gun is blank.";
                if (ProiettiliBlank > 0) {
                    ProiettiliBlank--;

                    // Reload if both real and blank bullets are at 0
                    if (ProiettiliVeri == 0 && ProiettiliBlank == 0) {
                        cout << " Reloading... You now have 3 real bullets and 2 blanks." << endl << endl;
                        ProiettiliVeri = 3;
                        ProiettiliBlank = 2;
                    } else {
                        // Dealer shoots back
                        int dealerShoot = rand() % (ProiettiliVeri + ProiettiliBlank);
                        if (dealerShoot < ProiettiliVeri) {
                            cout << " Dealer shot back! You lost a life!" << endl << endl;
                            Vita--;
                        } else {
                            cout << " Dealer's shot is blank. You're lucky!" << endl << endl;
                        }
                    }
                } else {
                    cout << " You're safe!" << endl << endl;
                }
            }
        } else {
            if (shoot1 == 'Y') {
                cout << "Click! The gun is blank. You're safe!" << endl << endl;
                if (ProiettiliBlank > 0) {
                    ProiettiliBlank--;
                }
            } else if (shoot1 == 'D') {
                int dealerShoot = rand() % (ProiettiliVeri + ProiettiliBlank);
                if (dealerShoot < ProiettiliVeri) {
                    cout << "Bang! The dealer lost a life!" << endl << endl;
                    VitaD--;
                    ProiettiliVeri--;
                } else {
                    cout << "Click! The gun is blank. Dealer's lucky!" << endl << endl;
                    if (ProiettiliBlank > 0) {
                        ProiettiliBlank--;
                    }
                }
            }
        }

        cout << "Your remaining lives: " << Vita << endl;
        cout << "Dealer's remaining lives: " << VitaD << endl;
        cout << "Remaining bullets: " << ProiettiliVeri + ProiettiliBlank << " (Real: " << ProiettiliVeri << ", Blank: " << ProiettiliBlank << ")" << endl << endl;
    }

    if (Vita > 0) {
        cout << "Congratulations! You won!" << endl;
    } else if (ProiettiliVeri == 0) {
        cout << "Game over! You won! (No more real bullets)" << endl;
    } else {
        cout << "Game over! The dealer won!" << endl;
    }

    return 0;
}

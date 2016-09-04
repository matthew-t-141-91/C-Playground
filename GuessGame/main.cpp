
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

string const ESCAPE = "q";

int main () {

    for (;;) {
        cout << "This is a program that picks a number and asks you"
                "correct guess. Enter q at the prompt to quit the program." << endl;

        int my_rand = rand () % 100 + 1;

        cout << "Please enter a guess between 1 and 100!" << endl;

        string guess = "";
        getline(cin, guess);

        if(guess.compare(ESCAPE) == 0) {
            break;
        }else {
            int user_num = stoi(guess);
            if (user_num == my_rand) {
                cout << "You guessed correctly!" << endl;
            } else if (user_num > my_rand) {
                cout << "Your guess was higher" << endl;
            } else if (user_num < my_rand) {
                cout << "Your guess was lower" << endl;
            } else {
                cout << "Make sure to enter a number!!" << endl;
            }

        }
    }

    cout << "exiting program ...." << endl;

    return 0;
}

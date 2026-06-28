#include <iostream>
#include <random>
#include <string>
using namespace std;

struct Player {
    string move;
    int wins = 0, losses = 0, ties = 0;
};

int main() {
    string moves[3] = {"Rock", "Paper", "Scissor"};
    Player human, computer;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 2);

    do {
        int randomIndex = dist(gen);
        computer.move = moves[randomIndex];

        cout << "Enter the move you want to play (Rock, Paper, Scissor or Exit): ";
        cin >> human.move;

        if (human.move == "Exit") {
            cout << "Exiting game." << endl;
            break;
        }

        if (human.move == "Rock") {
            if (computer.move == "Rock") {
                human.ties++;
            } else if (computer.move == "Paper") {
                human.losses++;
            } else if (computer.move == "Scissor") {
                human.wins++;
            }
        } else if (human.move == "Paper") {
            if (computer.move == "Paper") {
                human.ties++;
            } else if (computer.move == "Rock") {
                human.wins++;
            } else if (computer.move == "Scissor") {
                human.losses++;
            }
        } else if (human.move == "Scissor") {
            if (computer.move == "Scissor") {
                human.ties++;
            } else if (computer.move == "Rock") {
                human.losses++;
            } else if (computer.move == "Paper") {
                human.wins++;
            }
        } else {
            cout << "Enter a valid move" << endl;
            continue;
        }

        cout << "Player pick " << human.move << endl;
        cout << "Computer pick " << computer.move << endl;
        cout << "Score:" << endl;
        cout << "Wins: " << human.wins << "\t" << "Losses: " << human.losses << "\t" << "Ties: " << human.ties << endl;
    } while (human.move != "Exit");

    return 0;
}
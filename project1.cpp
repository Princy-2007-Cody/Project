#include <iostream>
#include <random>
#include <string>
using namespace std;

struct Player {
    string move;
    int wins = 0, losses = 0, ties = 0;
};

int main() {
    int n;
    cout << "Enter the number of Players playing the game (1 or 2): " << endl;
    cin >> n;
    if (n == 1) {
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
    } else if (n == 2) {
        string moves[3] = {"Rock", "Paper", "Scissor"};
        Player player1, player2;
        do {
            cout << "Player 1 Enter your move: " << endl;
            cin >> player1.move;
            if (player1.move == "Exit") {
                cout << "Exiting game." << endl;
                break;
            } 
            cout << "Player 2 Enter your move: " << endl;
            cin >> player2.move;
            if (player2.move == "Exit") {
                cout << "Exiting game." << endl;
                break;
            }

            if (player1.move == "Rock") {
                if (player2.move == "Rock") {
                    player1.ties++;
                    player2.ties++;               
                } else if (player2.move == "Paper") {
                    player1.losses++;
                    player2.wins++;
                } else if (player2.move == "Scissor") {
                    player1.wins++;
                    player2.losses++;
                }
            } else if (player1.move == "Paper") {
                if (player2.move == "Rock") {
                    player1.wins++;
                    player2.losses++;
                } else if (player2.move == "Paper") {
                    player1.ties++;
                    player2.ties++;
                } else if (player2.move == "Scissor") {
                    player1.losses++;
                    player2.wins++;
                }
            } else if (player1.move == "Scissor") {
                if (player2.move == "Scissor") {
                    player1.ties++;
                    player2.ties++;
                } else if (player2.move == "Rock") {
                    player1.losses++;
                    player2.wins++;
                } else if (player2.move == "Paper") {
                    player1.wins++;
                    player2.losses++;
                } else {
                    cout << "Enter a valid Value" << endl;
                    continue;
                }
            }
            cout << "Player 1 pick " << player1.move << endl;
            cout << "Player 2 pick " << player2.move << endl;
            cout << " Player 1 Score:" << endl;
            cout << "Wins: " << player1.wins << "\t" << "Losses: " << player1.losses << "\t" << "Ties: " << player1.ties << endl;
            cout << " Player 2 Score:" << endl;
            cout << "Wins: " << player2.wins << "\t" << "Losses: " << player2.losses << "\t" << "Ties: " << player2.ties << endl;
        } while (player1.move != "Exit" || player2.move != "Exit");
    } else {
        cout << "Enter a valid number of players " << endl;
    }

    return 0;
}

#include <iostream>
#include <ctime>
using namespace std;

void drawBoard(char *spaces);
void player1Move(char *spaces, char player1);
void player2Move(char *spaces, char player2);
void computerMove(char *spaces, char computer);
bool checkWinnerPvC(char *spaces, char player1, char computer);
bool checkWinnerPvP(char *spaces, char player1, char player2);
bool checkTie(char *spaces);

int main() {
    int choice;
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player1 = 'X';
    char player2 = 'O';
    char computer = 'O';
    bool running = true;


    cout << "1. Player VS Computer" << endl
         << "2. Player vs Player" << endl;
    cin >> choice;

    if (choice == 1) {
        while (running) {
            system("cls");
            drawBoard(spaces);

            player1Move(spaces, player1);
            system("cls");
            drawBoard(spaces);
            if (checkWinnerPvC(spaces, player1, computer)) {
                running = false;
                break;
            }
            else if (checkTie(spaces)) {
                running = false;
                break;
            }

            computerMove(spaces, computer);
            system("cls");
            drawBoard(spaces);
            if (checkWinnerPvC(spaces, player1, computer)) {
                running = false;
                break;
            }
            else if (checkTie(spaces)) {
                running = false;
                break;
            }
        }
    }
    else if (choice == 2) {
        while (running) {
            system("cls");
            drawBoard(spaces);

            player1Move(spaces, player1);
            system("cls");
            drawBoard(spaces);
            if (checkWinnerPvP(spaces, player1, player2)) {
                running = false;
                break;
            }
            else if (checkTie(spaces)) {
                running = false;
                break;
            }

            player2Move(spaces, player2);
            system("cls");
            drawBoard(spaces);
            if (checkWinnerPvP(spaces, player1, player2)) {
                running = false;
                break;
            }
            else if (checkTie(spaces)) {
                running = false;
                break;
            }
        }
    }
    else 
        cout << "Enter a valid choice!" << endl;
    
    cout << "+------------------+" << endl
         << "|THANKS FOR PLAYING|" << endl
         << "+------------------+" << endl;

    return 0;
}

void drawBoard(char *spaces) {
    cout << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    cout << "     |     |     " << '\n';
    cout << '\n';
}
void player1Move(char *spaces, char player1) {
    int number;
    do {
        cout << "Enter a Move (1-9): ";
        cin >> number;
        number--;
        if (spaces[number] == ' ') {
            spaces[number] = player1;
            break;
        }
    }while(!number > 0 || !number < 8);
}
void player2Move(char *spaces, char player2){
    int number;
    do {
        cout << "Player 2's Move (1-9): ";
        cin >> number;
        number--;
        if (spaces[number] == ' ') {
            spaces[number] = player2;
            break;
        }
    }while(!number > 0 || !number < 8);
}
void computerMove(char *spaces, char computer){
    int number;
    srand(time(0));

    while(true) {
        number = rand() % 9;
        if (spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
}
bool checkWinnerPvC(char *spaces, char player1, char computer){

    if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])) {
        spaces[0] == player1 ? cout << "+------------------+" << endl
                                    << "|YOU ARE THE WINNER|" << endl
                                    << "+------------------+" << endl : cout << "+------------------+" << endl
                                                                             << "|     YOU LOSE     |" << endl
                                                                             << "+------------------+" << endl;
    }
    else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])) {
        spaces[3] == player1 ? cout << "+------------------+" << endl
                                    << "|YOU ARE THE WINNER|" << endl
                                    << "+------------------+" << endl : cout << "+------------------+" << endl
                                                                             << "|     YOU LOSE     |" << endl
                                                                             << "+------------------+" << endl;
    }
    else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])) {
        spaces[6] == player1 ? cout << "+------------------+" << endl
                                    << "|YOU ARE THE WINNER|" << endl
                                    << "+------------------+" << endl : cout << "+------------------+" << endl
                                                                             << "|     YOU LOSE     |" << endl
                                                                             << "+------------------+" << endl;
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])) {
        spaces[0] == player1 ? cout << "+------------------+" << endl
                                    << "|YOU ARE THE WINNER|" << endl
                                    << "+------------------+" << endl : cout << "+------------------+" << endl
                                                                             << "|     YOU LOSE     |" << endl
                                                                             << "+------------------+" << endl;
    }
    else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])) {
        spaces[1] == player1 ? cout << "+------------------+" << endl
                                    << "|YOU ARE THE WINNER|" << endl
                                    << "+------------------+" << endl : cout << "+------------------+" << endl
                                                                             << "|     YOU LOSE     |" << endl
                                                                             << "+------------------+" << endl;
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])) {
        spaces[2] == player1 ? cout << "+------------------+" << endl
                                    << "|YOU ARE THE WINNER|" << endl
                                    << "+------------------+" << endl : cout << "+------------------+" << endl
                                                                             << "|     YOU LOSE     |" << endl
                                                                             << "+------------------+" << endl;
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])) {
        spaces[0] == player1 ? cout << "+------------------+" << endl
                                    << "|YOU ARE THE WINNER|" << endl
                                    << "+------------------+" << endl : cout << "+------------------+" << endl
                                                                             << "|     YOU LOSE     |" << endl
                                                                             << "+------------------+" << endl;
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])) {
        spaces[2] == player1 ? cout << "+------------------+" << endl
                                    << "|YOU ARE THE WINNER|" << endl
                                    << "+------------------+" << endl : cout << "+------------------+" << endl
                                                                             << "|     YOU LOSE     |" << endl
                                                                             << "+------------------+" << endl;
    }
    else {
        return false;
    }

    return true;
}
bool checkWinnerPvP(char *spaces, char player1, char player2){

    if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])) {
        spaces[0] == player1 ? cout << "+------------------+" << endl
                                    << "|   Player1 Wins   |" << endl
                                    << "+------------------+" << endl: cout << "+------------------+" << endl
                                                                            << "|   Player2 Wins   |" << endl
                                                                            << "+------------------+" << endl;
    }
    else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])) {
        spaces[3] == player1 ? cout << "+------------------+" << endl
                                    << "|   Player1 Wins   |" << endl
                                    << "+------------------+" << endl: cout << "+------------------+" << endl
                                                                            << "|   Player2 Wins   |" << endl
                                                                            << "+------------------+" << endl;
    }
    else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])) {
        spaces[6] == player1 ? cout << "+------------------+" << endl
                                    << "|   Player1 Wins   |" << endl
                                    << "+------------------+" << endl: cout << "+------------------+" << endl
                                                                            << "|   Player2 Wins   |" << endl
                                                                            << "+------------------+" << endl;
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])) {
        spaces[0] == player1 ? cout << "+------------------+" << endl
                                    << "|   Player1 Wins   |" << endl
                                    << "+------------------+" << endl: cout << "+------------------+" << endl
                                                                            << "|   Player2 Wins   |" << endl
                                                                            << "+------------------+" << endl;
    }
    else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])) {
        spaces[1] == player1 ? cout << "+------------------+" << endl
                                    << "|   Player1 Wins   |" << endl
                                    << "+------------------+" << endl: cout << "+------------------+" << endl
                                                                            << "|   Player2 Wins   |" << endl
                                                                            << "+------------------+" << endl;
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])) {
        spaces[2] == player1 ? cout << "+------------------+" << endl
                                    << "|   Player1 Wins   |" << endl
                                    << "+------------------+" << endl: cout << "+------------------+" << endl
                                                                            << "|   Player2 Wins   |" << endl
                                                                            << "+------------------+" << endl;
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])) {
        spaces[0] == player1 ? cout << "+------------------+" << endl
                                    << "|   Player1 Wins   |" << endl
                                    << "+------------------+" << endl: cout << "+------------------+" << endl
                                                                            << "|   Player2 Wins   |" << endl
                                                                            << "+------------------+" << endl;
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])) {
        spaces[2] == player1 ? cout << "+------------------+" << endl
                                    << "|   Player1 Wins   |" << endl
                                    << "+------------------+" << endl: cout << "+------------------+" << endl
                                                                            << "|   Player2 Wins   |" << endl
                                                                            << "+------------------+" << endl;
    }
    else {
        return false;
    }

    return true;
}
bool checkTie(char *spaces){

    for (int i = 0; i < 9; i++) {
        if(spaces[i] == ' ') {
            return false;
        }
    }
    cout << "+------------------+" << std::endl
         << "|    IT'S A TIE    |" << std::endl;
    return true;
}

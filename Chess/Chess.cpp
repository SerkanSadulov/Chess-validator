#include <iostream>
#include <string>
#include "Struct.h"
#include "CBishop.h"
#include "CKing.h"
#include "CKnight.h"
#include "CPawn.h"
#include "CQueen.h"
#include "CRook.h"
#include "CFigure.h"
using namespace std;


EPiece  board[8][8];
ETeam boardT[8][8];
ETeam currentTeam = ETeam::white;
void Board() {
    //Setting up the pieces on the board 
    board[0][0] = EPiece::rook;
    board[0][1] = EPiece::knight;
    board[0][2] = EPiece::bishop;
    board[0][3] = EPiece::queen;
    board[0][4] = EPiece::king;
    board[0][5] = EPiece::bishop;
    board[0][6] = EPiece::knight;
    board[0][7] = EPiece::rook;
    board[7][0] = EPiece::rook;
    board[7][1] = EPiece::knight;
    board[7][2] = EPiece::bishop;
    board[7][3] = EPiece::queen;
    board[7][4] = EPiece::king;
    board[7][5] = EPiece::bishop;
    board[7][6] = EPiece::knight;
    board[7][7] = EPiece::rook;
    //Loop for declaring the pawns
    for (int i = 0; i < 8; i++) {
        board[1][i] = EPiece::pawn;
        board[6][i] = EPiece::pawn;

    }

}
void Team() {
    //Setting up the teams
    boardT[0][0] = ETeam::white;
    boardT[0][1] = ETeam::white;
    boardT[0][2] = ETeam::white;
    boardT[0][3] = ETeam::white;
    boardT[0][4] = ETeam::white;
    boardT[0][5] = ETeam::white;
    boardT[0][6] = ETeam::white;
    boardT[0][7] = ETeam::white;
    boardT[7][0] = ETeam::black;
    boardT[7][1] = ETeam::black;
    boardT[7][2] = ETeam::black;
    boardT[7][3] = ETeam::black;
    boardT[7][4] = ETeam::black;
    boardT[7][5] = ETeam::black;
    boardT[7][6] = ETeam::black;
    boardT[7][7] = ETeam::black;
    //Loop for declaring teams
    for (int i = 0; i < 8; i++) {
        boardT[1][i] = ETeam::white;
        boardT[6][i] = ETeam::black;

    }

}




void PrintBoard(){
    for (int i = 0; i < 8; i++){
        std::cout << (i + 1) << ' ' << '|';
        for (int j = 0; j < 8; j++){

            switch (board[i][j]){
            case EPiece::none:{
                std::cout << ' ';
                break;
            }

            case EPiece::king:{
                std::cout << "K";
                break;
            }

            case EPiece::queen:{
                std::cout << "Q";
                break;
            }

            case EPiece::bishop:{
                std::cout << "B";
                break;
            }

            case EPiece::pawn:{
                std::cout << "P";
                break;
            }

            case EPiece::knight:{
                std::cout << "N";
                break;
            }

            case EPiece::rook:{
                std::cout << "R";
                break;
            }
            default:
                break;
            }

            std::cout << '|';
        }

        std::cout << '\n';
    }

    std::cout << "  ";

    for (int i = 0; i < 8; i++)
    {
        switch (i){
        case 0:{
            std::cout << " A";
            break;
        }

        case 1:{
            std::cout << " B";
            break;
        }

        case 2:{
            std::cout << " C";
            break;
        }

        case 3:{
            std::cout << " D";
            break;
        }

        case 4:{
            std::cout << " E";
            break;
        }

        case 5:{
            std::cout << " F";
            break;
        }

        case 6:{
            std::cout << " G";
            break;
        }

        case 7:{
            std::cout << " H";
            break;
        }

        default:
            break;
        }
    }
    std::cout << '\n';
}
//Function for validating the moves of the pieces

int main() {
	bool turn = true;
	bool run = true;
	string input;
	//Sorting the board
    Board();
    Team();
	//Loop for the input and printing the board
	while (run)
	{
		//Printing the board
		PrintBoard();
		//Checking if for turns
		if (turn == true) {
			std::cout << "Move white: ";
			cin >> input;
			turn = false;

		}else if(turn == false) {
			std::cout << "Move black: ";
			cin >> input;
			turn = true;
		};

		//Input validation
		if (input.length() != 5) {
			std::cout << "Invalid input\n";
			run = false;
			break;
		}
		//Conversion from ASII to Numbers
		else {
			if ((!isdigit(input[0])) && !isdigit(input[3])) {
				if ((isdigit(input[1])) && isdigit(input[4])) {
					//Returning true or false if the move is valid
                    bool result = false;
					
                    switch (board[input[1] - 49][input[0] - 97]){
                        case EPiece::pawn:{
                            CFigure* figure = new CPawn();

                            result = figure->ValidMove(input[1] - 49, input[0] - 97, input[4] - 49, input[3] - 97);

                            delete figure;

                            break;
                        }
                        case EPiece::king: {
                            CFigure* figure = new CKing();

                             result = figure->ValidMove(input[1] - 49, input[0] - 97, input[4] - 49, input[3] - 97);

                            delete figure;

                            break;
                        }
                        case EPiece::queen: {
                            CFigure* figure = new CQueen();

                             result = figure->ValidMove(input[1] - 49, input[0] - 97, input[4] - 49, input[3] - 97);

                            delete figure;

                            break;
                        }
                        case EPiece::bishop: {
                            CFigure* figure = new CBishop();

                             result = figure->ValidMove(input[1] - 49, input[0] - 97, input[4] - 49, input[3] - 97);

                            delete figure;

                            break;
                        }
                        case EPiece::rook: {
                            CFigure* figure = new CRook();

                             result = figure->ValidMove(input[1] - 49, input[0] - 97, input[4] - 49, input[3] - 97);

                            delete figure;

                            break;
                        }
                        case EPiece::knight: {
                            CFigure* figure = new CKnight();

                             result = figure->ValidMove(input[1] - 49, input[0] - 97, input[4] - 49, input[3] - 97);

                            delete figure;

                            break;
                        }

                    }
                    

					if (result == true) {
					std::cout << "Valid move\n";
					board[input[4] - 49][input[3] - 97] = board[input[1] - 49][input[0] - 97];
					board[input[1] - 49][input[0] - 97] = EPiece::none;

						
					}
					else std::cout << "Invalid move\n";

				}

			}
		}
	}
}
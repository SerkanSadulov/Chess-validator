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
#include <array>
using namespace std;

std::array<std::array<CFigure*, 8>, 8> board;
//Setting the board
void Board() {
    //Setting up the pieces on the board 
    board[0][0] = new CRook;
    board[0][0]->setTeam(ETeam::white);
    board[0][1] = new CKnight;
    board[0][1]->setTeam(ETeam::white);
    board[0][2] = new CBishop;
    board[0][2]->setTeam(ETeam::white);
    board[0][3] = new CQueen;
    board[0][3]->setTeam(ETeam::white);
    board[0][4] = new CKing;
    board[0][4]->setTeam(ETeam::white);
    board[0][5] = new CBishop;
    board[0][5]->setTeam(ETeam::white);
    board[0][6] = new CKnight;
    board[0][6]->setTeam(ETeam::white);
    board[0][7] = new CRook;
    board[0][7]->setTeam(ETeam::white);
    board[7][0] = new CRook;
    board[7][0]->setTeam(ETeam::black);
    board[7][1] = new CKnight;
    board[7][1]->setTeam(ETeam::black);
    board[7][2] = new CBishop;
    board[7][2]->setTeam(ETeam::black);
    board[7][3] = new CQueen;
    board[7][3]->setTeam(ETeam::black);
    board[7][4] = new CKing;
    board[7][4]->setTeam(ETeam::black);
    board[7][5] = new CBishop;
    board[7][5]->setTeam(ETeam::black);
    board[7][6] = new CKnight;
    board[7][6]->setTeam(ETeam::black);
    board[7][7] = new CRook;
    board[7][7]->setTeam(ETeam::black);
    //Loop for declaring the pawns
    for (int i = 0; i < 8; i++) {
        board[1][i] = new CPawn;
        board[1][i]->setTeam(ETeam::white);
        board[6][i] = new CPawn;
        board[6][i]->setTeam(ETeam::black);
    }

}
//Printing board
void PrintBoard() {
    for (int i = 0; i < 8; i++){
        std::cout << (i + 1) << ' ' << '|';
        for (int j = 0; j < 8; j++){
            if (board[i][j] == nullptr) {
                std::cout << " "<<"|";
                continue;
            }
            switch (board[i][j]->GetPiece()){
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

int main() {
    
	bool turn = true;
	bool run = true;
	string input;
	//Sorting the board
    Board();
	while (run){
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
            if ((!isdigit(input[0])) && !isdigit(input[3]) && (isdigit(input[1])) && isdigit(input[4])) {
                bool result = false;
                int boardInpZero = input[0] - 97;
                int boardInpOne = input[1] - 49;
                int boardInpThree = input[3] - 97;
                int boardInpFour = input[4] - 49;
                if (board[boardInpOne][boardInpZero] != nullptr) {
                    result = board[boardInpOne][boardInpZero]->ValidMove(boardInpOne, boardInpZero, boardInpFour, boardInpThree);
                    //Returning true or false if the move is valid
                    if (result == true) {
                        std::cout << "Valid move\n";
                        board[boardInpFour][boardInpThree] = board[boardInpOne][boardInpZero];
                        board[boardInpOne][boardInpZero] = nullptr;
                    }
                    else std::cout << "Invalid move\n";
                }
                else std::cout << "Invalid move\n";
            }

		}
	}
}

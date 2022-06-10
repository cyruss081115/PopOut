//
//  main.cpp
//  PopOut
//
//  Created by Cyrus Wong on 9/6/2022.
//

#include <iostream>
#include "PopOut.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    PopOut game = PopOut();
    
    char move; int col;
    
    cout << "Instructions: " << endl;
    cout << "Player moves: A player’s move is to either drop their disc to one of the columns of the board, or pop out (remove) their disc from the bottom of a column. These can be acheived by entering D(drop)/P(pop), then NUM_OF_COLUMN, for example, D 1. Also, please notice that the input is case-sensitive." << endl;
    cout << "Winning condition: The current player win if their discs are connected in 4, no matter they are in vertical, horizontal, or diagonal. If the board is full, and there is no winner, it will be a draw game." << endl;
    cout << "Enjoy playing!" << endl;
    while (true) {
        game.printGameBoard();
        
        // Input validation
        while (true) {
            cout << "Player " << (game.getPlayer() == X ? "X": "O") << " moves: ";
            cin >> move; cin >> col;
            if (
                (move != 'D' && move != 'P') || // Move instruction
                (col >= game.getColumn() || col < 0) || // Column range
                (move == 'D' && not game.isPlacable(col)) ||
                (move == 'P' && not game.isPopable(col))
                ) {
                    cout << "Invalid move! Please try again!" << endl;
                } else {break;}
        }
        
        if (move == 'D') {
            game.placeDisk(col);
        } else if (move == 'P') {
            game.popDisk(col);
        } else {cout << "Unexpected move: " << move << endl;}
            
        if (game.hasWinner()) {
            game.printGameBoard();
            cout << "Player " << (game.getPlayer() == X ? "X" : "O") << " wins!" << endl;
            break;
        } else if (game.isFull()) {
            game.printGameBoard();
            cout << "Draw Game!" << endl;
        } else {game.nextPlayer();}
    }

    return 0;
}

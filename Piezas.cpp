#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
    turn = X;
    for(int i=0; i<BOARD_ROWS; i++) {
        //board[i].resize(BOARD_COLS);
        for(int j=0; j<BOARD_COLS; j++)
            board[i].push_back(Blank);
    }
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
    for(int i=0; i<BOARD_ROWS; i++)
        for(int j=0; j<BOARD_COLS; j++)
            board[i][j] = Blank;
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
    Piece place1 = turn;
    if(column > BOARD_COLS - 1 || column < 0)
        return Invalid;
    for(int i=0; i<BOARD_COLS; i++)
        if(board[i][column] == Blank) {
            board[i][column] = turn;
            if(turn == X)
                turn = O;
            else 
                turn = X;
            return place1;
        }
    if(turn == X)
        turn = O;
    else 
        turn = X;
    return Blank;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    if(column > BOARD_COLS - 1 || column < 0 || row > BOARD_ROWS -1 || row < 0)
        return Invalid;
    return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
 * 
 * NO DIAGONAL WINS
 * 
**/
Piece Piezas::gameState()
{
    int x_count=0, o_count=0;
    for(int i=0; i<BOARD_ROWS; i++)
        for(int j=0; j<BOARD_COLS; j++)
            if(board[i][j] == Blank)
                return Invalid;
    for(int i=0; i<BOARD_ROWS; i++) {
        int x_row=0, o_row=0;
        for(int j=1; j<BOARD_COLS; j++) {
            if(board[i][j] == board[i][j-1]) {
                if(board[i][j] == X)
                    x_row++;
                else
                    o_row++;
            }
        }
        if(x_row > x_count)
            x_count = x_row;
        if(o_row > o_count)
            o_count = o_row;
    }
    for(int j=0; j<BOARD_COLS; j++) {
        int x_col=0, o_col=0;
        for(int i=1; i<BOARD_ROWS; i++) {
            if(board[i][j] == board[i-1][j]) {
                if(board[i][j] == X)
                    x_col++; 
                else
                    o_col++; 
            }
        }
        if(x_col > x_count)
            x_count = x_col;
        if(o_col > o_count)
            o_count = o_col;
    }
    if(x_count > o_count)
        return X;
    else if(o_count > x_count)
        return O;
    return Blank;
}
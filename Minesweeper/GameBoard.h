//
//  GameBoard.h
//  Minesweeper
//
//  Created by Robert Berry on 24/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#ifndef __Minesweeper__GameBoard__
#define __Minesweeper__GameBoard__

#include "Cell.h"
#include <vector>

class GameBoard {
private:
    bool mGameOver;
    int mColumns;
    int mRows;
    int mHiddenCells;
    int mMines;
    std::vector< std::vector<Cell> > mCells;
    
    /**
     * If x, y is hidden, reveal it. Do flood reveal if necessary. Return score accrued.
     */
    int reveal(int x, int y);
    
    /**
     * Horizontal sweep of the board. Step (-1 or +1) determines direction. Return score accrued.
     */
    int sweep(int x, int y, int step);
    
    int drain(int x, int y);
    
    /**
     * Set n random cells to contain mines
     */
    void populateMines(int n);    
    
public:
    /**
     * Create game board of given number of rows and columns with given number of randomly placed mines
     */
    GameBoard(int rows, int columns, int mines);

    /**
     * How many mines neighbour x, y
     */
    int getNeighbouringMines(int x, int y);

    /**
     * Cell x, y (by copy)
     */
    Cell getCell(int x, int y);
    
    /**
     * Set cell x, y
     */
    void setCell(int x, int y, Cell cell);
    
    /**
     * Number of rows
     */
    int getRows();
    
    /**
     * Number of columns
     */
    int getColumns();
    
    /**
     * Whether the game is over
     */
    bool getIsGameOver();
    
    /**
     * Whether the player has won the game
     */
    bool getIsGameWon();
    
    /**
     * Trigger click behaviour for x, y. Return score accrued.
     */
    int onClick(int x, int y);
    
    /**
     * Trigger right click behaviour for x, y
     */
    void onRightClick(int x, int y);
    
    /**
     * Is x, y within the bounds of the board?
     */
    bool validCoordinate(int x, int y);    
};

#endif /* defined(__Minesweeper__GameBoard__) */

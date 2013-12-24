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
    const int mColumns;
    const int mRows;
    std::vector< std::vector<Cell> > mCells;
    
public:
    GameBoard(int rows, int columns);

    int neighbouringMines(int x, int y);
    Cell getCell(int x, int y);
    void setCell(int x, int y, Cell cell);
    int getRows();
    int getColumns();
};

#endif /* defined(__Minesweeper__GameBoard__) */

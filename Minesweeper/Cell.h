//
//  Cell.h
//  Minesweeper
//
//  Created by Robert Berry on 24/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#ifndef __Minesweeper__Cell__
#define __Minesweeper__Cell__

class Cell {
private:
    bool mMine;
    bool mHidden;
    bool mFlagged;
    bool mExploded;
    
public:
    Cell(bool mine);
    
    void setHidden(bool hidden);
    bool getHidden();
    
    void setIsMine(bool isMine);
    bool getIsMine();
    
    void setFlagged(bool flagged);
    bool getFlagged();
    
    void setExploded(bool exploded);
    bool getExploded();
};

#endif /* defined(__Minesweeper__Cell__) */

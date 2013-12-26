//
//  TextureVector.h
//  Minesweeper
//
//  Created by Robert Berry on 26/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#ifndef __Minesweeper__TextureVector__
#define __Minesweeper__TextureVector__

#include <vector>
#include <SFML/Graphics.hpp>

class TextureVector {
private:
    std::vector< sf::Texture > mTextures;
protected:
    void appendTexture(std::string filename);
public:
    sf::Texture *get(int index);
};

#endif /* defined(__Minesweeper__TextureVector__) */

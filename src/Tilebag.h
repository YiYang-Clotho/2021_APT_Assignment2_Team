#ifndef ASSIGN2_TILEBAG_H
#define ASSIGN2_TILEBAG_H
#include "LinkedList.h"
#include <string>
#include <vector>

class TileBag
{
public:
    TileBag();
    ~TileBag();

    LinkedList *tile_bag;
    
    void loadTileBag(std::vector<std::string> tileArray);

    // set tileBag
    void setTileBag(LinkedList *tile_bag);

    // get tileBag
    LinkedList *getTileBag();

    // get element
    Tile *get1stTile();

    // remove the first tile and reload tileBag
    LinkedList* remove1stTile();

    // get tiles number in the bag;
    int getSize();

private:
    
};

#endif // ASSIGN2_TILEBAG_H
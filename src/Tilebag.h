#ifndef ASSIGN2_TILEBAG_H
#define ASSIGN2_TILEBAG_H
#include "LinkedList.h"
#include "Tile.h"
#include <string>
#include <vector>

class TileBag
{
public:
    TileBag();
    ~TileBag();
    
    void loadTileBag(std::vector<std::string> tileArray);

    // set tileBag
    void setTileBag(LinkedList *tile_bag);

    // get tileBag
    LinkedList *getTileBag();

    // get element
    Tile *get1stTile();

    // remove the first tile and reload tileBag
    LinkedList* remove1stTile();

private:
    LinkedList *tile_bag;
};

#endif // ASSIGN2_TILEBAG_H
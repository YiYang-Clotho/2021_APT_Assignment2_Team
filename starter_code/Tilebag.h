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
    void setTileBag(LinkedList *newShuffledTileBag);
    LinkedList *getTileBag();
    Tile *getTiles();

private:
    Colour tcolour[6];
    Shape tshape[6];
    LinkedList *tile_bag = new LinkedList();
    LinkedList *shuffledtile_bag = new LinkedList();
};

#endif // ASSIGN2_TILEBAG_H
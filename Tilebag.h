
#ifndef ASSIGN2_TILEBAG_H
#define ASSIGN2_TILEBAG_H
#include "LinkedList.h"
#include "Tile.h"
#include <string>
#include <vector>

class TileBag {
public:
    TileBag();
    ~TileBag();
private:
	Colour tcolour[6];
	Shape tshape[6];
}

#endif // ASSIGN2_TILEBAG_H
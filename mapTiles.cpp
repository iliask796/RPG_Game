#include "mapTiles.h"

Tile::Tile(char ic) {
    icon = ic;
}

char Tile::getIcon() const {
    return icon;
}

Tile::~Tile() {

}

ObstacleTile::ObstacleTile(char ic) : Tile(ic) {

}

ObstacleTile::~ObstacleTile() {

}

MarketTile::MarketTile(char ic) : Tile(ic) {

}

MarketTile::~MarketTile() {

}

CommonTile::CommonTile(char ic) : Tile(ic) {

}

CommonTile::~CommonTile() {

}

EntranceTile::EntranceTile(char ic) : Tile(ic) {

}

EntranceTile::~EntranceTile() {

}
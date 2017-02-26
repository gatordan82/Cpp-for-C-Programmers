#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <iostream>
#include <vector>
#include <list>

using namespace std;

enum colorSpace
{
   WHITE, BLUE, RED
};
ostream& operator<<( ostream& out, const colorSpace& color );

struct Hexagon
{
   int x, y;
   colorSpace color;
   vector< pair<int, int> > edgeAdjList;
};

class Board
{
private:
   static const int size = 11;
   Hexagon source;
   vector< pair<int, int> > makeAdj_ofHex( Hexagon hex );
   void printAdj_ofHexAvailable( Hexagon hex );



public:
   Board( int size );

   void printBoard();
   void chooseColor();
   void checkandmakeMove( Hexagon hex,int turn );
   bool isNeighbor( list <Hexagon> currentPath, Hexagon adjacent );
   bool checkWinner( list <Hexagon> currentPath);
   Hexagon getSource();
   void setSource(Hexagon source);

   list <Hexagon> BluePath;
   list <Hexagon> RedPath;
   vector<vector<Hexagon> > theBoard;

   virtual ~Board();
};

#endif /* BOARD_HPP_ */


#include "Board.hpp"
#include <vector>
#include <iostream>
#include <iomanip>
#include <utility>
#include <stack>

using namespace std;

Board::Board( int size )
{
   theBoard = vector<vector<Hexagon> >( size, vector<Hexagon>( size ) );
   for( int x = 0; x < size; x++ )
   {
      for( int y = 0; y < size; y++ )
      {
         theBoard[x][y].x = x;
         theBoard[x][y].y = y;
         theBoard[x][y].color = WHITE; // Fill all positions as empty
         theBoard[x][y].edgeAdjList = makeAdj_ofHex( theBoard[x][y] ); // Create the neighboring hexagons for each node
      }
   }
}

void Board::printBoard() // Print the Board of the Game in ASCII
{
   int n_nodes = 0;
   cout << "-----HEX BOARD (whit positions from 0 to 120)-----" << endl << endl;

   for( int i = 0; i < size; i++ )
   {
      if( i == 0 )
         cout << " " << i;
      else
         cout << " - " << i;
   }
   cout << endl;
   for( int i = 0; i < size; i++ )
   {
      cout << i << " " << setfill( ' ' ) << setw( i + 1 );
      for( int j = 0; j < size; j++ )
      {
         if( j != 10 )
            cout << theBoard[i][j].color << ' ' << '-' << ' ';
         else
            cout << theBoard[i][j].color << ' ' << ' ';
         n_nodes++;
      }
      cout << '\n';
   }
}

void Board::chooseColor()
{

   char color;

   cout << "Which color do you choose to play? r or b (Red(r) or Blue(b))" << endl;
   cin >> color;

   while( (color != 'r') && (color != 'b') )
   {
      cout << "Please you should choose r or b" << endl;
      cin >> color;
   }

   if( color == 'r' )
      cout << "Well, you have chosen the Red Player!" << endl << endl;
   if( color == 'b' )
      cout << "Well, you have chosen the Blue Player!" << endl << endl;
}

void Board::checkandmakeMove( Hexagon hex, int turn )
{
   Hexagon currentHex = hex;
   cout << "Please, introduce the X-axis coordinate(between 0-10):";
   cin >> currentHex.x;
   cout << "Please, introduce the Y-axis coordinate(between 0-10):";
   cin >> currentHex.y;
   currentHex.edgeAdjList = makeAdj_ofHex( currentHex );

   while( currentHex.x < 0 || (unsigned) currentHex.x > (theBoard.size() - 1) || currentHex.y < 0
            || (unsigned) currentHex.y > (theBoard.size() - 1)
            || theBoard[currentHex.x][currentHex.y].color != WHITE ) // If you exceed the limits or the position is occupied
   {
      cout << "¡¡Illegal Movement. Please, introduce a valid coordinate(between 0-10) or choose a space not occupied!!" << endl;
      cout << "Please, introduce again the X-axis coordinate(between 0-10):";
      cin >> currentHex.x;
      cout << "Please, introduce again the Y-axis coordinate(between 0-10):";
      cin >> currentHex.y;
   }

   if( currentHex.color == BLUE )
      BluePath.push_back( currentHex ); //Add the current node to our rout
      if( turn == 0 ) setSource(currentHex);
   else
      RedPath.push_back( currentHex ); //Add the current node to our route

   theBoard[currentHex.x][currentHex.y].color = currentHex.color; //Make the move

}

void Board::printAdj_ofHexAvailable( Hexagon hex )
{
   for( int i = 0; i < (signed) theBoard[hex.x][hex.y].edgeAdjList.size(); i++ )
   {
      if( theBoard[hex.x][hex.y].color == WHITE ) //Discard the occupied hexagons
         cout << " (" << theBoard[hex.x][hex.y].edgeAdjList[i].first << ","
                  << theBoard[hex.x][hex.y].edgeAdjList[i].second << ")";
   }
   cout << endl;
}

bool Board::isNeighbor( list<Hexagon> currentPath, Hexagon currentHex )
{
   bool check = false;

   for( auto it = currentPath.begin(); it != currentPath.end(); it++ )
   { //For each element of the route
      for( int i = 0; i < (signed) it->edgeAdjList.size(); i++ )
         if( currentHex.x == it->edgeAdjList[i].first && currentHex.y == it->edgeAdjList[i].second )
            //Compares the coordinates of the current node with the adjacent ones of the route
            check = true;
   }

   return check;
}

vector<pair<int, int>> Board::makeAdj_ofHex( Hexagon hex ) //Vector with the coordinates of the neighboring hexagons
{

   if( (hex.x == 0) && (hex.y == 0) ) //Upper left corner
   {
      hex.edgeAdjList =
      {
         {  (hex.x+1),(hex.y)},
         {  (hex.x),(hex.y+1)}
      };
   }
   else
   {
      if( (hex.x == (size-1)) && (hex.y == (size-1)) ) //Lower right corner
      {
         hex.edgeAdjList =
         {
            {  (hex.x-1), (hex.y)},
            {  (hex.x),(hex.y-1)}
         };
      }
      else
      {
         if( (hex.x == 0) && (hex.y == (size-1)) ) //Upper right corner
         {
            hex.edgeAdjList =
            {
               {  (hex.x), (hex.y-1)},
               {  (hex.x+1), (hex.y-1)},
               {  (hex.x+1),(hex.y)}
            };
         }
         else
         {
            if( (hex.x == (size-1)) && (hex.y == 0) ) //Lower left corner
            {
               hex.edgeAdjList =
               {
                  {  (hex.x), (hex.y+1)},
                  {  (hex.x-1), (hex.y+1)},
                  {  (hex.x-1),(hex.y)}
               };
            }
            else
            {
               if( hex.x == 0 && hex.y!=0 && hex.y!=(size-1)) // first Row
               {
                  hex.edgeAdjList =
                  {
                     {  (hex.x), (hex.y+1)},
                     {  (hex.x), (hex.y-1)},
                     {  (hex.x+1), (hex.y)},
                     {  (hex.x+1), (hex.y-1)}
                  };
               }
               else
               {
                  if( hex.x == (size-1) && hex.y!=0 && hex.y!=(size-1) ) // last Row
                  {
                     hex.edgeAdjList =
                     {
                        {  (hex.x), (hex.y+1)},
                        {  (hex.x), (hex.y-1)},
                        {  (hex.x-1), (hex.y+1)},
                        {  (hex.x-1), (hex.y)}
                     };
                  }
                  else
                  {
                     if( hex.y == 0 && hex.x!=0 && hex.x!=size-1 ) // first Column
                     {
                        hex.edgeAdjList =
                        {
                           {  (hex.x-1), (hex.y)},
                           {  (hex.x-1), (hex.y+1)},
                           {  (hex.x), (hex.y+1)},
                           {  (hex.x+1), (hex.y)}
                        };
                     }
                     else
                     {
                        if( hex.y == (size-1) && hex.x!=0 && hex.x!=size-1 ) // Last Column
                        {
                           hex.edgeAdjList =
                           {
                              {  (hex.x-1), (hex.y)},
                              {  (hex.x), (hex.y-1)},
                              {  (hex.x+1), (hex.y-1)},
                              {  (hex.x+1), (hex.y)}
                           };
                        }
                        else
                        {
                           hex.edgeAdjList = // Internal Hexagons, 6 possible adjacent neighbors
                           {
                              {  (hex.x), (hex.y+1)},
                              {  (hex.x), (hex.y-1)},
                              {  (hex.x+1), (hex.y)},
                              {  (hex.x+1), (hex.y-1)},
                              {  (hex.x-1), (hex.y)},
                              {  (hex.x-1), (hex.y+1)}
                           };
                        }
                     }
                  }
               }
            }
         }
      }
   }
   return hex.edgeAdjList;
}

bool Board::checkWinner(list <Hexagon> currentPath)
{

   for( auto it = currentPath.begin(); it != currentPath.end(); it++ )
   { //For each element of the route
      if( it->y == (size-1) ){
         cout << endl << "*****¡¡¡¡¡¡The Winner has been the BluePlayer!!!!!!*****" << endl;
         return true;
      }
   }

   for( auto it = currentPath.begin(); it != currentPath.end(); it++ )
   { //For each element of the route
      if( it->x == (size-1) ){
         cout << endl << "*****¡¡¡¡¡¡The Winner has been the RedPlayer!!!!!!*****" << endl;
         return true;
      }
   }

   return false;
}

// board state or user color to string
ostream& operator<<( ostream& out, const colorSpace& color )
{
   switch( color )
   {
      case BLUE:
         out << "B";
         break;
      case RED:
         out << "R";
         break;
      case WHITE:
         out << "x";
         break;
      default:
         out << ".";
   }
   return out;
}

Hexagon Board::getSource()
 {
    return source;
 }

void Board::setSource( Hexagon source )
 {
    this->source = source;
 }

Board::~Board()
{
// TODO Auto-generated destructor stub
}


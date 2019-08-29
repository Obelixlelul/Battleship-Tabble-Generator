#ifndef SHIP_H
#define SHIP_H
/**
 * Function to create Ships
 * @Ship - Minimal quantity of args.
 * @max - Maximal quantity of args
 * @x - Quantity of board lines
 * @y - Quantity of board columns
 * @impossibility - vector with position who whip cant occuppy 
*/
class Ship
{
public:
  Ship(int length, int x, int y, std::vector<int> &impossibility);
  //functions to modify ship position
  void changeX(int &positionX, int x, int length);
  void changeY(int &positionY, int y, int length);
  void chageOrientation(int &orientation); /*!>aleatory rotate ship*/

  /**
  * positioningShip
  * @Ship - Minimal quantity of args.
  * @max - Maximal quantity of args
  * @x - Quantity of board lines
  * @y - Quantity of board columns
  * @impossibility - vector with position who whip cant occuppy 
  */
  int positioningShip(std::vector<int> &impossibility, int length, int column, int line);
  void insertShipOnBoard(std::vector<std::string> &board, std::vector<int> &impossibility, int line, int column);
  std::vector<int> shipPosition;
  std::vector<int> possibility;
  std::vector<int> insideImpossibility;
  std::vector<int> insideShadows;

  std::string name;
  int orientation;
  int positionX;
  int positionY;
  int absPosit;
  int maxLength;
  int insideLength;
};

#endif
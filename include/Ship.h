class Ship
{
public:
  Ship(int length, int x, int y);
  void changeX(int &positionX, int x, int length);
  void changeY(int &positionY, int y, int length);
  void chageOrientation(int &orientation);
  void getBattlecruze(std::vector<std::vector<char>> &tabble, int x, int y);
  int getDestroyer(std::vector<std::vector<char>> &tabble, int x, int y);
  int getCruiser(std::vector<std::vector<char>> &tabble, int x, int y);
  int getSubmarine(std::vector<std::vector<char>> &tabble, int x, int y);

  std::string name;
  int orientation;
  int positionX;
  int positionY;
  int maxLength;
  int insideLength;
};
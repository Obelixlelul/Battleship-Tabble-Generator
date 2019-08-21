// Example program
#include <iostream>
#include <iomanip>
#include <string.h>
#include <ctype.h>
#include <vector>
#include <algorithm>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

using std::cout;
using std::endl;
using std::vector;

int CreateRandom(int n)
{
  int a;
  a = rand() % n;
  return a;
}

class Ship
{
public:
  std::string name;
  int orientation;
  int positionX;
  int positionY;
  int maxLength;
  int insideLength;

  Ship()
  {
    std::cout << "Input Ship with paramethers" << endl;
  }
  Ship(int length, int x, int y)
  {

    orientation = CreateRandom(2);
    insideLength = length;
    if (orientation == 0)
    {
      maxLength = (x - length + 1);
      //cout << "maxLength = " << maxLength << endl;

      positionX = CreateRandom(maxLength);
      positionY = CreateRandom(y);
    }
    else
    {
      maxLength = (y - length);
      //cout << "maxLength = " << maxLength << endl;

      //cout << "insideOrientation = 1\n";
      positionX = CreateRandom(x);
      positionY = CreateRandom(maxLength);
    }
  }
  void changeX(int *positionX, int x, int length)
  {
    *positionX = CreateRandom(x - length - 1);
    cout << "position X changed to: " << *positionX;
  }
  void changeY(int *positionY, int y, int length)
  {
    *positionY = CreateRandom(y - length - 1);
    cout << "position Y changed to: " << *positionY;
  }
};

int main(int argc, char *argv[])
{
  srand(time(NULL));

  int x(10), y(10), n(1);
  Ship firstShip(4, x, y);
  Ship destroyer(3, x, y);
  Ship destroyer2(3, x, y);
  Ship destroyer3(3, x, y);
  // cout << "Orientation = " << firstShip.orientation << endl;
  // cout << "Randomic X Max Position is = " << firstShip.positionX + 1 << endl;
  // cout << "Randomic Y Max Position is = " << firstShip.positionY + 1 << endl;

  //MATRIX DECLARATION
  vector<vector<char>> tabble(20, vector<char>(20));

  //defining tabble[x][y] with dots;
  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j < y; j++)
    {
      tabble[i][j] = '.';
    }
  }

  //Input BATTLESHIP boats on tablle
  cout << "input battleship" << endl;
  cout << "X position = " << firstShip.positionX + 1 << endl;
  cout << "Y position = " << firstShip.positionY + 1 << endl;
  cout << "Orientation = " << firstShip.orientation << endl;

  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j < y; j++)
    {
      if (i == firstShip.positionX && j == firstShip.positionY && firstShip.orientation == 0)
      {
        //changing matrix according with boat length
        //Aloca verticalmente
        for (int k = i; k < i + firstShip.insideLength; k++)
        {
          tabble[k][j] = 'b';
          tabble[k][j + 1] = 's';
          if (j != 0)
          {
            tabble[k][j - 1] = 's';
          }
        }

        //put top and diagonal shadows
        tabble[i + 4][j] = 's';
        tabble[i + 4][j + 1] = 's';
        if (j != 0)
        {
          tabble[i - 1][j] = 's';
          tabble[i - 1][j + 1] = 's';
          tabble[i + 4][j - 1] = 's';
          tabble[i - 1][j - 1] = 's';
        }
      }
      else if (i == firstShip.positionX && j == firstShip.positionY && firstShip.orientation == 1)
      {
        //Aloca horizontalmente
        if (i != 0)
        {
          tabble[i - 1][j] = 's';
        }
        //changing matrix according with boat length
        for (int k = j; k < j + firstShip.insideLength; k++)
        {
          tabble[i][k] = 'b';
          if (i != 0)
          {
            tabble[i - 1][k] = 's';
          }
          tabble[i + 1][k] = 's';
        }
        //put top and diagonal shadows
        if (i != 0)
        {
          tabble[i - 1][j + 4] = 's';
        }
        tabble[i][j + 4] = 's';
        tabble[i + 1][j + 4] = 's';
        if (j != 0)
        {
          if (j != 0)
          {
            tabble[i][j - 1] = 's';
            tabble[i + 1][j - 1] = 's';
            tabble[i - 1][j - 1] = 's';
          }
        }
      }
    }
  }
  //SHADOWS
  // for (int i = 0; i < x; i++)
  // {
  //   for (int j = 0; j < y; j++)
  //   {
  //     if (tabble[i][j] != '.' && tabble[i][j] != 's' && firstShip.orientation == 1)
  //     {
  //       tabble[i + 1][j] = 's';
  //       tabble[i - 1][j] = 's';
  //     }
  //     if (tabble[i][j] != '.' && tabble[i][j] != 's' && firstShip.orientation == 0)
  //     {
  //       tabble[i][j + 1] = 's';
  //       tabble[i][j - 1] = 's';
  //     }
  //   }
  // }

  /*
  //INPUT DESTROYERS ON TABLE
  //DESTROYER 1
  cout << "input destroyer 1" << endl;
  int flag(0);
  do
  {
    for (int i = 0; i < x; i++)
    {
      for (int j = 0; j < y; j++)
      {
        if (i == destroyer.positionX && j == destroyer.positionY && destroyer.orientation == 0 && tabble[i][j] == '.' && tabble[i + 1][j] == '.' && tabble[i + 2][j] == '.')
        {
          cout << "enter first if vertically" << endl;
          //vertically
          //changing matrix according with boat length

          for (int k = i; k < i + destroyer.insideLength; k++)
          {

            tabble[k][j] = 'd';
          }
          flag = 1;
        }
        else if (i == destroyer.positionX && j == destroyer.positionY && destroyer.orientation == 1 && tabble[i][j] == '.' && tabble[i][j + 1] == '.' && tabble[i][j + 1] == '.')
        {
          // cout << "enter second if horizontally" << endl;
          //horizontally
          //changing matrix according with boat length

          for (int k = j; k < j + destroyer.insideLength; k++)
          {
            tabble[i][k] = 'd';
          }
          flag = 1;
        }
      }
    }
    if (flag == 0)
    {
      destroyer.changeX(&destroyer.positionX, x, destroyer.insideLength);
      destroyer.changeY(&destroyer.positionY, y, destroyer.insideLength);
    }
  } while (flag == 0);

  //DESTROYER 2
  cout << "input destroyer 2" << endl;
  flag = 0;
  do
  {
    for (int i = 0; i < x; i++)
    {
      for (int j = 0; j < y; j++)
      {
        if (i == destroyer2.positionX && j == destroyer2.positionY && destroyer2.orientation == 0 && tabble[i][j] == '.' && tabble[i + 1][j] == '.' && tabble[i + 2][j] == '.')
        {
          // cout << "enter first if vertically" << endl;
          //vertically
          //changing matrix according with boat length

          for (int k = i; k < i + destroyer2.insideLength; k++)
          {

            tabble[k][j] = 'd';
          }
          flag = 1;
        }
        else if (i == destroyer2.positionX && j == destroyer2.positionY && destroyer2.orientation == 1 && tabble[i][j] == '.' && tabble[i][j + 1] == '.' && tabble[i][j + 1] == '.')
        {
          //cout << "enter second if horizontally" << endl;
          //horizontally
          //changing matrix according with boat length

          for (int k = j; k < j + destroyer2.insideLength; k++)
          {
            tabble[i][k] = 'd';
          }
          flag = 1;
        }
      }
    }
    if (flag == 0)
    {
      destroyer2.changeX(&destroyer2.positionX, x, destroyer2.insideLength);
      destroyer2.changeY(&destroyer2.positionY, y, destroyer2.insideLength);
    }
  } while (flag == 0);

  //DESTROYER 2
  cout << "input destroyer 3" << endl;
  flag = 0;
  do
  {
    for (int i = 0; i < x; i++)
    {
      for (int j = 0; j < y; j++)
      {
        if (i == destroyer3.positionX && j == destroyer3.positionY && destroyer3.orientation == 0 && tabble[i][j] == '.' && tabble[i + 1][j] == '.' && tabble[i + 2][j] == '.')
        {
          // cout << "enter first if vertically" << endl;
          //vertically
          //changing matrix according with boat length

          for (int k = i; k < i + destroyer3.insideLength; k++)
          {

            tabble[k][j] = 'd';
          }
          flag = 1;
        }
        else if (i == destroyer3.positionX && j == destroyer3.positionY && destroyer3.orientation == 1 && tabble[i][j] == '.' && tabble[i][j + 1] == '.' && tabble[i][j + 1] == '.')
        {
          //cout << "enter second if horizontally" << endl;
          //horizontally
          //changing matrix according with boat length

          for (int k = j; k < j + destroyer3.insideLength; k++)
          {
            tabble[i][k] = 'd';
          }
          flag = 1;
        }
      }
    }
    if (flag == 0)
    {
      destroyer3.changeX(&destroyer3.positionX, x, destroyer3.insideLength);
      destroyer3.changeY(&destroyer3.positionY, y, destroyer3.insideLength);
    }
  } while (flag == 0);
  */
  //PRINTING TABBLE
  if (y > 9)
  {
    cout << "    ";
    for (int i = 0; i < y; i++)
    {
      if (i / 9 == 0 || y == 9)
      {
        std::cout << std::right << std::setw(1) << " "
                  << " ";
      }
      else if (i / 9 == 1)
      {
        std::cout << std::right << std::setw(1) << "1"
                  << " ";
      }
    }
    std::cout << std::endl;
  }

  cout << "    ";
  for (int i = 0; i < y; i++)
  {
    if (i > 8)
    {
      std::cout << std::right << std::setw(1) << i % 9 << " ";
    }
    else
    {
      std::cout << std::right << std::setw(1) << i + 1 << " ";
    }
  }
  std::cout << std::endl;

  //PRINTING ROWS INDEXES AND NO-SHIP TABBLE
  for (int i = 0; i < x; i++)
  {
    std::cout << std::right << std::setw(2) << i + 1 << "[";
    //std::cout << " " << i+1 << "[ ";
    for (int j = 0; j < y; j++)
    {
      //std::cout << " . ";
      std::cout << std::right << std::setw(2) << tabble[i][j];
    }
    std::cout << " ]" << std::endl;
  }
  return 0;
}
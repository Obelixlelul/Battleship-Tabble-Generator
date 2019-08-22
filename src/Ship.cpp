#include <iostream>
#include <iomanip>
#include <string.h>
#include <ctype.h>
#include <vector>
#include <algorithm>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include "../include/battleship.h"
#include "../include/Ship.h"
#include "../include/Tabble.h"

using namespace std;

Ship::Ship(int length, int x, int y)
{
  this->orientation = CreateRandom(2) - 1;
  this->insideLength = length;
  if (this->orientation == 0)
  {
    this->maxLength = (x - length);
    this->positionX = CreateRandom(this->maxLength);
    this->positionY = CreateRandom(y);
  }
  else
  {
    maxLength = (y - length);
    positionX = CreateRandom(x);
    positionY = CreateRandom(this->maxLength);
  }
}

void Ship::changeX(int &positionX, int x, int length)
{
  positionX = CreateRandom(x - length);
}

void Ship::changeY(int &positionY, int y, int length)
{
  positionY = CreateRandom(y - length);
}

void Ship::chageOrientation(int &orientation)
{
  orientation = CreateRandom(2) - 1;
}

void Ship::getBattlecruze(std::vector<std::vector<char>> &tabble, int x, int y)
{
  this->changeX(this->positionX, x, this->insideLength);
  this->changeY(this->positionY, y, this->insideLength);
  this->chageOrientation(this->orientation);
  for (int i = 1; i <= x; i++)
  {
    for (int j = 0; j <= y; j++)
    {
      if (i == this->positionX && j == this->positionY && this->orientation == 0)
      {
        //Vertical Alocate
        for (int k = i; k < i + this->insideLength; k++)
        {
          tabble[k][j] = 'b';
        }
      }
      else if (i == this->positionX && j == this->positionY && this->orientation == 1)
      {
        //Horizontal Alocate
        for (int k = j; k < j + this->insideLength; k++)
        {
          tabble[i][k] = 'b';
        }
      }
    }
  }
}

int Ship::getDestroyer(std::vector<std::vector<char>> &tabble, int x, int y)
{
  //cout << "input destroyer 1" << endl;
  int flag(0);
  int count(0);
  do
  {
    for (int i = 1; i <= x; i++)
    {
      for (int j = 1; j <= y; j++)
      {
        if (i == this->positionX && j == this->positionY && this->orientation == 0 && tabble[i][j] == '.' && tabble[i + 1][j] == '.' && tabble[i + 2][j] == '.')
        {
          //vertically
          //changing matrix according with boat length
          for (int k = i; k < i + this->insideLength; k++)
          {
            tabble[k][j] = 'd';
          }
          flag = 1;
        }
        else if (i == this->positionX && j == this->positionY && this->orientation == 1 && tabble[i][j] == '.' && tabble[i][j + 1] == '.' && tabble[i][j + 2] == '.')
        {
          // cout << "enter second if horizontally" << endl;
          //horizontally
          //changing matrix according with boat length

          for (int k = j; k < j + this->insideLength; k++)
          {
            tabble[i][k] = 'd';
          }
          flag = 1;
        }
      }
    }
    if (flag == 0)
    {
      this->changeX(this->positionX, x, this->insideLength);
      this->changeY(this->positionY, y, this->insideLength);
      this->chageOrientation(this->orientation);
      count++;
    } //put couter to infinite loops
    if (count > 10000)
    {
      return 0;
    }
  } while (flag == 0);
  return 1;
}

int Ship::getCruiser(vector<vector<char>> &tabble, int x, int y)
{
  //cout << "input destroyer 1" << endl;
  int flag(0);
  int count(0);
  do
  {
    for (int i = 1; i <= x; i++)
    {
      for (int j = 1; j <= y; j++)
      {
        if (i == this->positionX && j == this->positionY && this->orientation == 0 && tabble[i][j] == '.' && tabble[i + 1][j] == '.')
        {
          //vertically
          //changing matrix according with boat length
          for (int k = i; k < i + this->insideLength; k++)
          {

            tabble[k][j] = 'd';
          }
          flag = 1;
        }
        else if (i == this->positionX && j == this->positionY && this->orientation == 1 && tabble[i][j] == '.' && tabble[i][j + 1] == '.')
        {
          // cout << "enter second if horizontally" << endl;
          //horizontally
          //changing matrix according with boat length

          for (int k = j; k < j + this->insideLength; k++)
          {
            tabble[i][k] = 'd';
          }
          flag = 1;
        }
      }
    }
    if (flag == 0)
    {
      //cout << "change randoms to cruiser" << endl;
      this->changeX(this->positionX, x, this->insideLength);
      this->changeY(this->positionY, y, this->insideLength);
      this->chageOrientation(this->orientation);
      count++;
    }
    if (count > 10000)
    {
      return 0;
    }

  } while (flag == 0);
  return 1;
}

//PUT SUBMARINE ON TABBLE
int Ship::getSubmarine(std::vector<std::vector<char>> &tabble, int x, int y)
{
  //cout << "input destroyer 1" << endl;
  int flag(0);
  int count(0);
  do
  {
    for (int i = 1; i <= x; i++)
    {
      for (int j = 1; j <= y; j++)
      {
        if (i == this->positionX && j == this->positionY && this->orientation == 0 && tabble[i][j] == '.')
        {
          //vertically
          //changing matrix according with boat length
          for (int k = i; k < i + this->insideLength; k++)
          {

            tabble[k][j] = 'd';
          }
          flag = 1;
        }
        else if (i == this->positionX && j == this->positionY && this->orientation == 1 && tabble[i][j] == '.')
        {
          // cout << "enter second if horizontally" << endl;
          //horizontally
          //changing matrix according with boat length

          for (int k = j; k < j + this->insideLength; k++)
          {
            tabble[i][k] = 'd';
          }
          flag = 1;
        }
      }
    }
    if (flag == 0)
    {
      this->changeX(this->positionX, x, this->insideLength);
      this->changeY(this->positionY, y, this->insideLength);
      count++;
    }
    if (count > 10000)
    {
      return 0;
    }
  } while (flag == 0);
  return 1;
}

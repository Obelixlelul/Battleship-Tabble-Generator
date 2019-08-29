#include <iostream>
#include <iomanip>
#include <string.h>
#include <ctype.h>
#include <vector>
#include <algorithm>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include <math.h>
#include <fstream>
#include "../include/battleship.h"
#include "../include/Ship.h"

using namespace std;

Ship::Ship(int length, int line, int column, vector<int> &impossibility)
{
  //Set ship orientation and inside Length
  this->orientation = CreateRandom(2) - 1;
  this->insideLength = length;
  //this->positioningShip(impossibility, length, column, line);
}

int Ship::positioningShip(std::vector<int> &impossibility, int length, int column, int line)
{
  this->shipPosition.clear();
  std::vector<int> tempPossibility;

  //Generate Horizontal limitation
  if (this->orientation == 1)
  {
    for (int i = 1; i <= column * line; i++)
    {
      if ((i + length - 1) <= column * ceil((double)i / column))
      {
        tempPossibility.push_back(i);
      }
    }
  }
  //Generate Vertical Limitation
  else if (this->orientation == 0)
  {
    for (int i = 1; i <= column * line; i++)
    {
      //formula para max vertical
      if (i <= (line - length + 1) * column)
      {
        tempPossibility.push_back(i);
      }
    }
  }

  //delete impossibility from possibility
  removeImpossibility(tempPossibility, impossibility);

  if (tempPossibility.empty())
  {
    //if theres no possibilities to positioning ship
    return 0;
  }

  //randomize a possible position for ship
  int flag = 1;
  int count = 0;

  while (flag == 1)
  {
    this->shipPosition.clear();
    flag = 0;
    count++;
    this->absPosit = tempPossibility[rand() % tempPossibility.size()];

    if (this->orientation == 1)
    {
      for (int i = 0; i < length; i++)
      {
        this->shipPosition.push_back(this->absPosit + i);
      }
    }
    else if (this->orientation == 0)
    {
      for (int i = 0; i < length; i++)
      {
        this->shipPosition.push_back(this->absPosit + i * column);
      }
    }

    for (auto i : this->shipPosition)
    {
      for (auto j : impossibility)
      {
        if (i == j)
        {
          flag = 1;
        }
      }
    }
    count++;
    //security for try 1000 times and retry
    if (count > 1000)
    {
      this->shipPosition.clear();
      tempPossibility.clear();
      return 0;
    }
  }
  tempPossibility.clear();
  return 1;
}

void Ship::insertShipOnBoard(std::vector<std::string> &board, std::vector<int> &impossibility, int line, int column)
{
  for (int i = 0; i < board.size(); i++)
  {
    if (i + 1 == this->absPosit && this->orientation == 1)
    {
      for (int j = 0; j < this->insideLength; j++)
      {
        //put on impossibility array
        impossibility.push_back(i + 1);
        if (this->insideLength == 1)
        {
          board[i++] = "\u25cf";
        }
        else if (j == 0)
        {
          board[i++] = "\u25c0";
        }
        else if (j == this->insideLength - 1)
        {
          board[i++] = "\u25b8";
        }
        else
        {
          board[i++] = "\u25a0";
        }
      }
      break;
    }
    else if (i + 1 == this->absPosit && this->orientation == 0)
    {
      for (int j = 0; j < this->insideLength; j++)
      {
        //put on impossibility array
        impossibility.push_back(i + 1 + column * j);
        this->insideImpossibility.push_back(i + 1 + column * j);
        if (this->insideLength == 1)
        {
          board[i + column * j] = "\u25cf";
        }
        else if (j == 0)
        {
          board[i + column * j] = "\u25b2";
        }
        else if (j == this->insideLength - 1)
        {
          board[i + column * j] = "\u25bc";
        }
        else
        {
          board[i + column * j] = "\u25a0";
        }
      }
    }
  }
  shadowsAround(board, impossibility, this->insideImpossibility, this->absPosit, this->orientation, this->insideLength, line, column, this->insideShadows);
}

void Ship::chageOrientation(int &orientation)
{
  orientation = CreateRandom(2) - 1;
}
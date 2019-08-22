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

void PrintTabble(std::vector<std::vector<char>> &tabble, int x, int y)
{
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
  for (int i = 1; i <= x; i++)
  {
    std::cout << std::right << std::setw(2) << i << "[";
    //std::cout << " " << i+1 << "[ ";
    for (int j = 1; j <= y; j++)
    {

      if (tabble[i][j] == 'x') //delet shadows
      {
        tabble[i][j] = '.';
      }
      std::cout << std::right << std::setw(2) << tabble[i][j];
    }
    std::cout << " ]" << std::endl;
  }
  std::cout << endl;
}

void CleanTabble(std::vector<std::vector<char>> &tabble, int x, int y)
{
  for (int i = 1; i <= x; i++)
  {
    for (int j = 1; j <= y; j++)
    {
      tabble[i][j] = '.';
    }
  }
}

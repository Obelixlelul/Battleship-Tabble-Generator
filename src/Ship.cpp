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

using namespace std;

void printTest()
{
  std::cout << "PASSOU NO TESTE" << std::endl;
}

Barco::Barco()
{
  this->tamanho = 2;
  cout << "testando classe de barco" << endl;
}

void Barco::getTamanho()
{
  cout << "Tamanho = " << this->tamanho << endl;
}
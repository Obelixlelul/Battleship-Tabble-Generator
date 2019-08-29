#include "Ship.h"

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

//to lower entire string
std::string str_tolower(std::string s);

//verify if main args are valid
int verifyArgs(int argc, int min, int max);

//Create random between 1 to n
int CreateRandom(int n);

//Create shadows around ship
void shadowsAround(std::vector<std::string> &board, std::vector<int> &occupiedBoard, std::vector<int> &insidePossibility, int absolutPosit, int orientation, int length, int line, int column, std::vector<int> &internShadows);

//remove impossibility from possibility
void removeImpossibility(std::vector<int> &possibility, std::vector<int> impossibility);
//remove indiviaul term from possibility
void removeOneTerm(std::vector<int> &possibility, int term);

//reset board with dots
void resetSea(std::vector<std::string> &board, int line, int column);

//function to prin and write board or armada
void PrintTabble(std::vector<std::string> &board, int line, int column, int n);
void writeTabble(std::vector<std::string> &board, int line, int column, std::ofstream &puzzle_matrix);
void CleanTabble(std::vector<std::vector<char>> &tabble, int x, int y);
void WriteArmada(std::ofstream &armada, Ship battlecruze, Ship destroyer1, Ship destroyer2, Ship cruiser1, Ship cruiser2, Ship cruiser3, Ship submarine1, Ship submarine2, Ship submarine3, Ship submarine4, int line, int column);
void InputArmada(std::string &armada, Ship battlecruze, Ship destroyer1, Ship destroyer2, Ship cruiser1, Ship cruiser2, Ship cruiser3, Ship submarine1, Ship submarine2, Ship submarine3, Ship submarine4, int line, int column);
//compare if str2 is str substr
int CompareArmada(std::string str, std::string str2);
#endif
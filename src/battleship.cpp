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
#include "../include/MainVerification.h"

using namespace std;

//FUNCTION TO LOWER MAIN PARAMETERS
std::string str_tolower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return std::tolower(c); } // correct
    );
    return s;
}

//create random from 1 to
int CreateRandom(int n)
{
    int a;
    a = rand() % n + 1;
    return a;
}

void shadowsAround(std::vector<std::string> &board, std::vector<int> &occupiedBoard, std::vector<int> &insidePossibility, int absolutPosit, int orientation, int length, int line, int column, std::vector<int> &internShadows)
{
    std::vector<int> shadows;
    if (length != 1)
    {

        for (int i = 1; i < board.size(); i++)
        {
            if (absolutPosit == i && orientation == 1)
            {
                //1st line and last column positionin
                if ((absolutPosit - column) <= 0 && (absolutPosit % column == column - length + 1))
                {
                    // std::cout << "Case 1" << std::endl;
                    shadows.push_back(i - 1);
                    for (int j = i; j < i + length; j++)
                    {
                        shadows.push_back(j + column);
                    }
                    shadows.push_back(i - 1 + column);
                    break;
                }
                //last line and last column positionin
                else if (absolutPosit + column > board.size() && (absolutPosit % column == column - length + 1))
                {
                    // std::cout << "Case 2" << std::endl;
                    shadows.push_back(i - 1);
                    for (int j = i; j < i + length; j++)
                    {
                        shadows.push_back(j - column);
                    }
                    shadows.push_back(i - 1 - column);
                    break;
                }
                //first line and first column positionin
                else if (absolutPosit == 1)
                {
                    // std::cout << "Case 3" << std::endl;
                    shadows.push_back(i + length);
                    for (int j = i; j < i + length; j++)
                    {
                        shadows.push_back(j + column);
                    }
                    shadows.push_back(i + length + column);
                    break;
                }
                //last line and first column positionin
                else if (absolutPosit + column > board.size() && (absolutPosit % column == 1))
                {
                    // std::cout << "Case 4" << std::endl;
                    shadows.push_back(i + length);
                    for (int j = i; j < i + length; j++)
                    {
                        shadows.push_back(j - column);
                    }
                    shadows.push_back(i + length - column);
                    break;
                }
                //first column
                else if ((absolutPosit % column == 1))
                {
                    // std::cout << "Case 5" << std::endl;
                    shadows.push_back(i + length);
                    for (int j = i; j < i + length; j++)
                    {
                        shadows.push_back(j - column);
                        shadows.push_back(j + column);
                    }
                    shadows.push_back(i + length - column);
                    shadows.push_back(i + length + column);
                    break;
                }
                //1st line
                else if (absolutPosit - column < 0)
                {
                    // std::cout << "Case 6" << std::endl;
                    shadows.push_back(i - 1);
                    shadows.push_back(i + length);
                    for (int j = i; j < i + length; j++)
                    {
                        shadows.push_back(j + column);
                    }
                    shadows.push_back(i - 1 + column);
                    shadows.push_back(i + length + column);
                    break;
                }
                //last line
                else if (absolutPosit + column > board.size())
                {
                    // std::cout << "Case 7" << std::endl;
                    shadows.push_back(i - 1);
                    shadows.push_back(i + length);
                    for (int j = i; j < i + length; j++)
                    {
                        shadows.push_back(j - column);
                    }
                    shadows.push_back(i - 1 - column);
                    shadows.push_back(i + length - column);
                    break;
                }
                //last column but not 1st or last line
                else if ((absolutPosit % column) == column - length + 1)
                {
                    // std::cout << "Case 8" << std::endl;
                    shadows.push_back(i - 1);
                    for (int j = i; j < i + length; j++)
                    {
                        shadows.push_back(j - column);
                        shadows.push_back(j + column);
                    }
                    shadows.push_back(i - 1 - column);
                    shadows.push_back(i - 1 + column);
                    break;
                }
                //another who wasnt tested
                else
                {
                    // std::cout << "Case 9" << std::endl;
                    shadows.push_back(i - 1);
                    shadows.push_back(i + length);
                    for (int j = i; j < i + length; j++)
                    {
                        shadows.push_back(j - column);
                        shadows.push_back(j + column);
                    }
                    shadows.push_back(i - 1 - column);
                    shadows.push_back(i - 1 + column);
                    shadows.push_back(i + length - column);
                    shadows.push_back(i + length + column);
                    break;
                }
            }
            /* ---------------VERTICAL -----------------*/
            else if (absolutPosit == i && orientation == 0)
            {
                //first line and first column
                if (absolutPosit == 1)
                {
                    // std::cout << "Case 1" << std::endl;
                    shadows.push_back(absolutPosit + length * column);     //lower
                    shadows.push_back(absolutPosit + 1 + length * column); //right diagonal inf
                    for (int j = i; j < i + length * column; j = j + column)
                    {
                        shadows.push_back(j + 1);
                    }
                    break;
                }
                //first line and last column
                else if ((absolutPosit - column) <= 0 && (absolutPosit % column == 0))
                {
                    // std::cout << "Case 2" << std::endl;
                    shadows.push_back(absolutPosit + length * column);     //lower
                    shadows.push_back(absolutPosit + length * column - 1); //left diagonal inf
                    for (int j = i; j < i + length * column; j = j + column)
                    {
                        shadows.push_back(j - 1);
                    }
                    break;
                }
                //first line whateever column
                else if ((absolutPosit - column) <= 0)
                {
                    // std::cout << "Case 3" << std::endl;
                    shadows.push_back(absolutPosit + length * column);     //lower
                    shadows.push_back(absolutPosit + length * column - 1); //left diagonal inf
                    shadows.push_back(absolutPosit + length * column + 1); //right diagonal inf
                    for (int j = i; j < i + length * column; j = j + column)
                    {
                        shadows.push_back(j - 1);
                        shadows.push_back(j + 1);
                    }
                    break;
                }
                //last line first column

                else if (board.size() - (length - 1) * column - (column - 1) == absolutPosit)
                {
                    // std::cout << "Case 4" << std::endl;
                    shadows.push_back(absolutPosit - column);     //upper
                    shadows.push_back(absolutPosit - column + 1); //right diagonal sup

                    for (int j = i; j < i + length * column; j = j + column)
                    {
                        shadows.push_back(j + 1);
                    }
                    break;
                }
                //last line last column
                else if (board.size() - (length - 1) * column == absolutPosit)
                {
                    // std::cout << "Case 5" << std::endl;
                    shadows.push_back(absolutPosit - column);     //upper
                    shadows.push_back(absolutPosit - column - 1); //left diagonal sup

                    for (int j = i; j < i + length * column; j = j + column)
                    {
                        shadows.push_back(j - 1);
                    }
                    break;
                }
                //last line wathever column
                else if (absolutPosit > board.size() - (length - 1) * column - (column - 1))
                {
                    // std::cout << "Case 6" << std::endl;
                    shadows.push_back(absolutPosit - column);     //upper
                    shadows.push_back(absolutPosit - column + 1); //right diagonal sup
                    shadows.push_back(absolutPosit - column - 1); //left diagonal sup

                    for (int j = i; j < i + length * column; j = j + column)
                    {
                        shadows.push_back(j - 1);
                        shadows.push_back(j + 1);
                    }
                    break;
                }
                //last column wathever line
                else if (absolutPosit % column == 0)
                {
                    // std::cout << "Case 7" << std::endl;
                    shadows.push_back(absolutPosit - column);              //upper
                    shadows.push_back(absolutPosit + length * column);     //lower
                    shadows.push_back(absolutPosit - column - 1);          //left diagonal sup
                    shadows.push_back(absolutPosit + length * column - 1); //left diagonal inf

                    for (int j = i; j < i + length * column; j = j + column)
                    {
                        shadows.push_back(j - 1);
                    }
                    break;
                }

                //first column wathever line
                else if (absolutPosit % column == 1)
                {
                    // std::cout << "Case 8" << std::endl;
                    shadows.push_back(absolutPosit - column);              //upper
                    shadows.push_back(absolutPosit + length * column);     //lower
                    shadows.push_back(absolutPosit - column + 1);          //right diagonal sup
                    shadows.push_back(absolutPosit + length * column + 1); //right diagonal inf

                    for (int j = i; j < i + length * column; j = j + column)
                    {
                        shadows.push_back(j + 1);
                    }
                    break;
                }

                //whatever - all shadows
                else
                {
                    // std::cout << "Case 9" << std::endl;
                    shadows.push_back(absolutPosit + length * column);     //lower
                    shadows.push_back(absolutPosit - column);              //upper
                    shadows.push_back(absolutPosit - column + 1);          //right diagonal sup
                    shadows.push_back(absolutPosit - column - 1);          //left diagonal sup
                    shadows.push_back(absolutPosit + length * column - 1); //left diagonal inf
                    shadows.push_back(absolutPosit + length * column + 1); //right diagonal inf
                    for (int j = i; j < i + length * column; j = j + column)
                    {
                        shadows.push_back(j - 1); //left
                        shadows.push_back(j + 1); //right
                    }
                    break;
                }
            }
        }
    }
    //generate shadows for submarine case
    else if (length == 1)
    {
        //1st line and last column positionin
        if (absolutPosit % column == 0)
        {
            shadows.push_back(absolutPosit - 1);                   //left
            shadows.push_back(absolutPosit + length * column - 1); //left diagonal inf
            shadows.push_back(absolutPosit + length * column);     //lower
        }
        //last line and last column positionin
        else if (absolutPosit + column > board.size() && (absolutPosit % column == 0))
        {
            shadows.push_back(absolutPosit - 1);          //left
            shadows.push_back(absolutPosit - column - 1); //left diagonal sup
            shadows.push_back(absolutPosit - column);     //upper
        }
        //first line and first column positionin
        else if (absolutPosit == 1)
        {
            shadows.push_back(absolutPosit + length * column);     //lower
            shadows.push_back(absolutPosit + length * column + 1); //right diagonal inf
            shadows.push_back(absolutPosit + 1);                   //right
        }
        //last line and first column positionin
        else if (absolutPosit + column > board.size() && (absolutPosit % column == 1))
        {
            shadows.push_back(absolutPosit - column);     //upper
            shadows.push_back(absolutPosit - column + 1); //right diagonal sup
            shadows.push_back(absolutPosit + 1);          //right
        }
        //first column
        else if ((absolutPosit % column == 1))
        {
            shadows.push_back(absolutPosit + length * column);     //lower
            shadows.push_back(absolutPosit - column);              //upper
            shadows.push_back(absolutPosit + 1);                   //right
            shadows.push_back(absolutPosit - column + 1);          //right diagonal sup
            shadows.push_back(absolutPosit + length * column + 1); //right diagonal inf
        }
        //1st line
        else if (absolutPosit - column <= 0)
        {
            shadows.push_back(absolutPosit + length * column);     //lower
            shadows.push_back(absolutPosit - 1);                   //left
            shadows.push_back(absolutPosit + 1);                   //right
            shadows.push_back(absolutPosit + length * column - 1); //left diagonal inf
            shadows.push_back(absolutPosit + length * column + 1); //right diagonal inf
        }
        //last line
        else if (absolutPosit + column > board.size())
        {
            shadows.push_back(absolutPosit - column);     //upper
            shadows.push_back(absolutPosit - column + 1); //right diagonal sup
            shadows.push_back(absolutPosit - column - 1); //left diagonal sup
            shadows.push_back(absolutPosit - 1);          //left
            shadows.push_back(absolutPosit + 1);          //right
        }
        //last column but not 1st or last line
        else if (absolutPosit % column == 0)
        {
            shadows.push_back(absolutPosit + length * column);     //lower
            shadows.push_back(absolutPosit - column);              //upper
            shadows.push_back(absolutPosit - 1);                   //left
            shadows.push_back(absolutPosit - column - 1);          //left diagonal sup
            shadows.push_back(absolutPosit + length * column - 1); //left diagonal inf
        }
        //another who wasnt tested
        else
        {
            shadows.push_back(absolutPosit + length * column);     //lower
            shadows.push_back(absolutPosit - column);              //upper
            shadows.push_back(absolutPosit - column + 1);          //right diagonal sup
            shadows.push_back(absolutPosit - column - 1);          //left diagonal sup
            shadows.push_back(absolutPosit + length * column - 1); //left diagonal inf
            shadows.push_back(absolutPosit + length * column + 1); //right diagonal inf
            shadows.push_back(absolutPosit - 1);                   //left
            shadows.push_back(absolutPosit + 1);                   //right
        }
    }
    for (auto i : shadows)
    {
        occupiedBoard.push_back(i);
        insidePossibility.push_back(i);
        internShadows.push_back(i);
    }
}

void removeImpossibility(std::vector<int> &possibility, std::vector<int> impossibility)
{
    for (int i = 0; i < possibility.size(); i++)
    {
        for (int j = 0; j < impossibility.size(); j++)
        {
            if (possibility[i] == impossibility[j])
            {
                possibility[i] = 0;
            }
        }
    }

    std::vector<int>::iterator it = possibility.begin();
    while (it != possibility.end())
    {
        if (*it == 0)
        {
            it = possibility.erase(it);
        }
        else
            it++;
    }
}

void removeOneTerm(std::vector<int> &possibility, int length)
{
    for (int i = 0; i < length; i++)
    {
        possibility.pop_back();
    }
}

void resetSea(std::vector<std::string> &board, int line, int column)
{
    board.clear();
    for (int i = 1; i <= line * column; i++)
    {
        board.push_back("\u00B7");
    }
}

void PrintTabble(std::vector<std::string> &board, int line, int column, int n)
{
    if (column > 9)
    {
        cout << "   ";
        for (int i = 0; i < column; i++)
        {
            if (i / 9 == 0 || column == 9)
            {
                std::cout << std::left << std::setw(1) << " "
                          << " ";
            }
            else if (i / 9 == 1)
            {
                std::cout << std::left << std::setw(1) << "1"
                          << " ";
            }
        }
        std::cout << std::endl;
    }

    cout << "   ";
    for (int i = 0; i < column; i++)
    {
        if (i > 8)
        {
            std::cout << std::left << std::setw(1) << i % 9 << " ";
        }
        else
        {
            std::cout << std::left << std::setw(1) << i + 1 << " ";
        }
    }
    std::cout << std::endl;

    //PRINTING ROWS INDEXES AND NO-SHIP TABBLE
    cout << std::left << std::setw(2) << " 1[";
    for (int i = 0; i < board.size(); i++)
    {
        std::cout << board[i] << " ";
        if ((i + 1) % column == 0)
        {
            std::cout << "]";
            std::cout << endl;
            if (i / column + 2 <= line)
                std::cout << std::right << std::setw(2) << i / column + 2 << "[";
        }
    }
    std::cout << std::endl;
}

void writeTabble(std::vector<std::string> &board, int line, int column, std::ofstream &puzzless_matrix)
{
    if (column > 9)
    {
        puzzless_matrix << "   ";
        for (int i = 0; i < column; i++)
        {
            if (i / 9 == 0 || column == 9)
            {
                puzzless_matrix << std::left << std::setw(1) << " "
                                << " ";
            }
            else if (i / 9 == 1)
            {
                puzzless_matrix << std::left << std::setw(1) << "1"
                                << " ";
            }
        }
        puzzless_matrix << std::endl;
    }

    puzzless_matrix << "   ";
    for (int i = 0; i < column; i++)
    {
        if (i > 8)
        {
            puzzless_matrix << std::left << std::setw(1) << i % 9 << " ";
        }
        else
        {
            puzzless_matrix << std::left << std::setw(1) << i + 1 << " ";
        }
    }
    puzzless_matrix << std::endl;

    //PRINTING ROWS INDEXES AND NO-SHIP TABBLE
    puzzless_matrix << std::left << std::setw(2) << " 1[";
    for (int i = 0; i < board.size(); i++)
    {
        puzzless_matrix << board[i] << " ";
        if ((i + 1) % column == 0)
        {
            puzzless_matrix << "]";
            puzzless_matrix << endl;
            if (i / column + 2 <= line)
                puzzless_matrix << std::right << std::setw(2) << i / column + 2 << "[";
        }
    }
    puzzless_matrix << "\n";
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

void WriteArmada(std::ofstream &armada, Ship battlecruze, Ship destroyer1, Ship destroyer2, Ship cruiser1, Ship cruiser2, Ship cruiser3, Ship submarine1, Ship submarine2, Ship submarine3, Ship submarine4, int line, int column)
{
    armada << line << " " << column << "\n";
    armada << "B ";
    //line
    armada << (battlecruze.absPosit - 1) / column + 1 << " ";
    //column
    armada << (battlecruze.absPosit - 1) % column + 1 << " ";
    //orientation
    if (battlecruze.orientation == 0)
        armada << "V\n";
    else
    {
        armada << "H\n";
    }

    armada << "D ";
    //line
    armada << (destroyer1.absPosit - 1) / column + 1 << " ";
    //column
    armada << (destroyer1.absPosit - 1) % column + 1 << " ";
    //orientation
    if (destroyer1.orientation == 0)
        armada << "V\n";
    else
    {
        armada << "H\n";
    }

    armada << "D ";
    //line
    armada << (destroyer2.absPosit - 1) / column + 1 << " ";
    //column
    armada << (destroyer2.absPosit - 1) % column + 1 << " ";
    //orientation
    if (destroyer2.orientation == 0)
        armada << "V\n";
    else
    {
        armada << "H\n";
    }

    armada << "C ";
    //line
    armada << (cruiser1.absPosit - 1) / column + 1 << " ";
    //column
    armada << (cruiser1.absPosit - 1) % column + 1 << " ";
    //orientation
    if (cruiser1.orientation == 0)
        armada << "V\n";
    else
    {
        armada << "H\n";
    }

    armada << "C ";
    //line
    armada << (cruiser2.absPosit - 1) / column + 1 << " ";
    //column
    armada << (cruiser2.absPosit - 1) % column + 1 << " ";
    //orientation
    if (cruiser2.orientation == 0)
        armada << "V\n";
    else
    {
        armada << "H\n";
    }

    armada << "C ";
    //line
    armada << (cruiser3.absPosit - 1) / column + 1 << " ";
    //column
    armada << (cruiser3.absPosit - 1) % column + 1 << " ";
    //orientation
    if (cruiser3.orientation == 0)
        armada << "V\n";
    else
    {
        armada << "H\n";
    }

    armada << "S ";
    //line
    armada << (submarine1.absPosit - 1) / column + 1 << " ";
    //column
    armada << (submarine1.absPosit - 1) % column + 1 << "\n";

    armada << "S ";
    //line
    armada << (submarine2.absPosit - 1) / column + 1 << " ";
    //column
    armada << (submarine2.absPosit - 1) % column + 1 << "\n";

    armada << "S ";
    //line
    armada << (submarine3.absPosit - 1) / column + 1 << " ";
    //column
    armada << (submarine3.absPosit - 1) % column + 1 << "\n";

    armada << "S ";
    //line
    armada << (submarine4.absPosit - 1) / column + 1 << " ";
    //column
    armada << (submarine4.absPosit - 1) % column + 1 << "\n";

    armada << "\n";
}

void InputArmada(std::string &armada, Ship battlecruze, Ship destroyer1, Ship destroyer2, Ship cruiser1, Ship cruiser2, Ship cruiser3, Ship submarine1, Ship submarine2, Ship submarine3, Ship submarine4, int line, int column)
{
    armada += "B";
    //line
    armada += (to_string((battlecruze.absPosit - 1) / column + 1));
    //column
    armada += (to_string((battlecruze.absPosit - 1) % column + 1));
    //orientation
    if (battlecruze.orientation == 0)
        armada += ("V");
    else
    {
        armada += ("H");
    }

    armada += ("D");
    //line
    armada += (to_string((destroyer1.absPosit - 1) / column + 1));
    //column
    armada += (to_string((destroyer1.absPosit - 1) % column + 1));
    //orientation
    if (destroyer1.orientation == 0)
        armada += ("V");
    else
    {
        armada += ("H");
    }

    armada += ("D");
    //line
    armada += (to_string((destroyer2.absPosit - 1) / column + 1));
    //column
    armada += (to_string((destroyer2.absPosit - 1) % column + 1));
    //orientation
    if (destroyer2.orientation == 0)
        armada += ("V");
    else
    {
        armada += ("H");
    }

    armada += ("C");
    //line
    armada += (to_string((cruiser1.absPosit - 1) / column + 1));
    //column
    armada += (to_string((cruiser1.absPosit - 1) % column + 1));
    //orientation
    if (cruiser1.orientation == 0)
        armada += ("V");
    else
    {
        armada += ("H");
    }

    armada += ("C");
    //line
    armada += (to_string((cruiser2.absPosit - 1) / column + 1));
    //column
    armada += (to_string((cruiser2.absPosit - 1) % column + 1));
    //orientation
    if (cruiser2.orientation == 0)
        armada += ("V");
    else
    {
        armada += ("H");
    }

    armada += ("C");
    //line
    armada += (to_string((cruiser3.absPosit - 1) / column + 1));
    //column
    armada += (to_string((cruiser3.absPosit - 1) % column + 1));
    //orientation
    if (cruiser3.orientation == 0)
        armada += ("V");
    else
    {
        armada += ("H");
    }

    armada += ("S");
    //line
    armada += (to_string((submarine1.absPosit - 1) / column + 1));
    //column
    armada += (to_string((submarine1.absPosit - 1) % column + 1));

    armada += ("S");
    //line
    armada += (to_string((submarine2.absPosit - 1) / column + 1));
    //column
    armada += (to_string((submarine2.absPosit - 1) % column + 1));

    armada += ("S");
    //line
    armada += (to_string((submarine3.absPosit - 1) / column + 1));
    //column
    armada += (to_string((submarine3.absPosit - 1) % column + 1));

    armada += ("S");
    //line
    armada += (to_string((submarine4.absPosit - 1) / column + 1));
    //column
    armada += (to_string((submarine4.absPosit - 1) % column + 1));
}

//return 0 if contain - return 1 if not contain
int CompareArmada(std::string str, std::string str2)
{
    std::size_t found = str.find(str2);

    if (found != std::string::npos)
    {
        //contain
        return 0;
    }
    else
    {
        //not contain
        return 1;
    }
}

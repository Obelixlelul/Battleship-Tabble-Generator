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

int CreateRandom(int n)
{
    int a;
    a = rand() % n + 1;
    return a;
}

void shadowsAround(std::vector<std::vector<char>> &tabble, int orientation, int length, int x, int y, char name)
{
    //cout << "Call shadows around\n";
    //print shadows around
    int flag = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (tabble[i][j] == name)
            {
                if (orientation == 0)
                {
                    if (flag == 0)
                    {
                        tabble[i - 1][j] = 'x';
                        tabble[i + length][j] = 'x';
                        flag = 1;
                    }
                    //vertically
                    tabble[i][j - 1] = 'x';
                    tabble[i][j + 1] = 'x';
                    tabble[i + 1][j + 1] = 'x';
                    tabble[i + 1][j - 1] = 'x';
                    tabble[i - 1][j + 1] = 'x';
                    tabble[i - 1][j - 1] = 'x';
                }
                else
                {
                    if (flag == 0)
                    {
                        tabble[i][j - 1] = 'x';
                        tabble[i][j + length] = 'x';
                        flag = 1;
                    }
                    //horizontally
                    tabble[i - 1][j] = 'x';
                    tabble[i + 1][j] = 'x';
                    tabble[i + 1][j + 1] = 'x';
                    tabble[i + 1][j - 1] = 'x';
                    tabble[i - 1][j - 1] = 'x';
                    tabble[i - 1][j + 1] = 'x';
                }
            }
        }
    }
    //render chars to n
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            //orientation = 1 -> Horizontal
            //orientation = 2 -> Vertical
            if (tabble[i][j] == name)
            {
                tabble[i][j] = 'n';
            }
        }
    }
}

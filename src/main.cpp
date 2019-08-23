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

int main(int argc, char *argv[])
{
    //VERIFYING MAIN PARAMETERS

    int line(10), column(10), n(1);

    if (!verifyArgs(argc, argv, 1, 6, line, column, n))
    {
        return 0;
    };

    srand(time(NULL));

    //tabble declaration
    std::vector<std::vector<char>> tabble(line + 2, std::vector<char>(column + 2));

    //defining shadow tabble
    for (int i = 0; i < line + 2; i++)
    {
        for (int j = 0; j < column + 2; j++)
        {
            tabble[i][j] = 'x';
        }
    }

    int varTemp(0);

    for (int qt = 0; qt < n; qt++)
    {
        //defining Ships
        Ship firstShip(4, line, column);
        Ship destroyer1(3, line, column);
        Ship destroyer2(3, line, column);
        Ship cruizer1(2, line, column);
        Ship cruizer2(2, line, column);
        Ship cruizer3(2, line, column);
        Ship submarine1(1, line, column);
        Ship submarine2(1, line, column);
        Ship submarine3(1, line, column);
        Ship submarine4(1, line, column);

        //Input Ships on tabble
        cout << "TABULEIRO: " << qt + 1 << endl;
        varTemp = 0;
        while (varTemp == 0)
        {
            cout << "restart...\n";
            firstShip.getBattlecruze(tabble, line, column);
            shadowsAround(tabble, firstShip.orientation, firstShip.insideLength, line, column, 'b');

            varTemp = destroyer1.getDestroyer(tabble, line, column);
            if (varTemp == 0)
            {

                CleanTabble(tabble, line, column);
                continue;
            }
            shadowsAround(tabble, destroyer1.orientation, destroyer1.insideLength, line, column, 'd');

            varTemp = destroyer2.getDestroyer(tabble, line, column);
            if (varTemp == 0)
            {
                CleanTabble(tabble, line, column);
                continue;
            }
            shadowsAround(tabble, destroyer2.orientation, destroyer2.insideLength, line, column, 'd');

            varTemp = cruizer1.getCruiser(tabble, line, column);
            if (varTemp == 0)
            {
                CleanTabble(tabble, line, column);
                continue;
            }
            shadowsAround(tabble, cruizer1.orientation, cruizer1.insideLength, line, column, 'd');
            varTemp = cruizer2.getCruiser(tabble, line, column);
            if (varTemp == 0)
            {
                CleanTabble(tabble, line, column);
                continue;
            }
            shadowsAround(tabble, cruizer2.orientation, cruizer2.insideLength, line, column, 'd');
            varTemp = cruizer3.getCruiser(tabble, line, column);
            if (varTemp == 0)
            {
                CleanTabble(tabble, line, column);
                continue;
            }
            shadowsAround(tabble, cruizer3.orientation, cruizer3.insideLength, line, column, 'd');

            varTemp = submarine1.getSubmarine(tabble, line, column);
            if (varTemp == 0)
            {
                CleanTabble(tabble, line, column);
                continue;
            }
            shadowsAround(tabble, submarine1.orientation, submarine1.insideLength, line, column, 'd');
            varTemp = submarine2.getSubmarine(tabble, line, column);
            if (varTemp == 0)
            {
                CleanTabble(tabble, line, column);
                continue;
            }
            shadowsAround(tabble, submarine2.orientation, submarine2.insideLength, line, column, 'd');
            varTemp = submarine3.getSubmarine(tabble, line, column);
            if (varTemp == 0)
            {
                CleanTabble(tabble, line, column);
                continue;
            }
            shadowsAround(tabble, submarine3.orientation, submarine3.insideLength, line, column, 'd');
            varTemp = submarine4.getSubmarine(tabble, line, column);
            if (varTemp == 0)
            {
                CleanTabble(tabble, line, column);
                continue;
            }
            shadowsAround(tabble, submarine4.orientation, submarine4.insideLength, line, column, 'd');

            varTemp = 1;
        }
        PrintTabble(tabble, line, column);
        CleanTabble(tabble, line, column);
    }
    return 0;
}
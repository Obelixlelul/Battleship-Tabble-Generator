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

int main(int argc, char *argv[])
{
    //VERIFYING MAIN PARAMETERS
    if (!verifyArgs(argc, 1, 6))
    {
        Help();
        return 0;
    };

    int x(10), y(10), n(1);
    std::string params[argc];

    //CHANGING ARG VALUES TO_LOWER
    //ideal era converter string to char*

    //STARTING VERIFICATION FOR MAIN ARGS
    for (int i = 1; i < argc; i++)
    {
        params[i] = str_tolower(argv[i]);

        if (str_tolower(params[i]).compare("--h") == 0 || str_tolower(params[i]).compare("-help") == 0)
        {
            Help();
            return 0;
        }

        if (str_tolower(params[i]).compare("--r") == 0 || str_tolower(params[i]).compare("-rolls") == 0)
        {
            x = strtol(argv[i + 1], NULL, 10);
            if (x < 7 || x > 16)
            {
                cout << "Invalid parameters\n";
                Help();
                return 0;
            }
            i++;
        }
        else if (str_tolower(params[i]).compare("--c") == 0 || str_tolower(params[i]).compare("-columns") == 0)
        {
            y = strtol(argv[i + 1], NULL, 10);
            if (y < 7 || y > 16)
            {
                std::cout << "Invalid parameters\n";
                Help();
                return 0;
            }
            i++;
        }
        else if (strtol(argv[i], NULL, 10))
        {
            //cout << "Is a num\n" << endl;
            n = strtol(argv[i], NULL, 10);
            if (n > 100)
            {
                std::cout << "Max prints are 100\n";
                Help();
                return 0;
            }
        }
        else
        {
            std::cout << "Somethign Wrong!!" << std::endl;
            Help();
            return 0;
        }
    }
    //END VERIFICATION FOR MAIN PARAMETERS

    srand(time(NULL));

    //tabble declaration
    std::vector<std::vector<char>> tabble(x + 2, std::vector<char>(y + 2));

    //defining shadow tabble
    for (int i = 0; i < x + 2; i++)
    {
        for (int j = 0; j < y + 2; j++)
        {
            tabble[i][j] = 'x';
        }
    }
    //and god said "let there be light"
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            tabble[i][j] = '.';
        }
    }

    int varTemp(0);

    for (int qt = 0; qt < n; qt++)
    {
        //defining Ships
        Ship firstShip(4, x, y);
        Ship destroyer1(3, x, y);
        Ship destroyer2(3, x, y);
        Ship cruizer1(2, x, y);
        Ship cruizer2(2, x, y);
        Ship cruizer3(2, x, y);
        Ship submarine1(1, x, y);
        Ship submarine2(1, x, y);
        Ship submarine3(1, x, y);
        Ship submarine4(1, x, y);

        //Input Ships on tabble
        cout << "TABULEIRO: " << qt + 1 << endl;
        varTemp = 0;
        while (varTemp == 0)
        {
            // cout << "restart...\n";
            firstShip.getBattlecruze(tabble, x, y);
            shadowsAround(tabble, firstShip.orientation, firstShip.insideLength, x, y, 'b');

            varTemp = destroyer1.getDestroyer(tabble, x, y);
            if (varTemp == 0)
            {

                CleanTabble(tabble, x, y);
                continue;
            }
            shadowsAround(tabble, destroyer1.orientation, destroyer1.insideLength, x, y, 'd');

            varTemp = destroyer2.getDestroyer(tabble, x, y);
            if (varTemp == 0)
            {
                CleanTabble(tabble, x, y);
                continue;
            }
            shadowsAround(tabble, destroyer2.orientation, destroyer2.insideLength, x, y, 'd');

            varTemp = cruizer1.getCruiser(tabble, x, y);
            if (varTemp == 0)
            {
                CleanTabble(tabble, x, y);
                continue;
            }
            shadowsAround(tabble, cruizer1.orientation, cruizer1.insideLength, x, y, 'd');
            varTemp = cruizer2.getCruiser(tabble, x, y);
            if (varTemp == 0)
            {
                CleanTabble(tabble, x, y);
                continue;
            }
            shadowsAround(tabble, cruizer2.orientation, cruizer2.insideLength, x, y, 'd');
            varTemp = cruizer3.getCruiser(tabble, x, y);
            if (varTemp == 0)
            {
                CleanTabble(tabble, x, y);
                continue;
            }
            shadowsAround(tabble, cruizer3.orientation, cruizer3.insideLength, x, y, 'd');

            varTemp = submarine1.getSubmarine(tabble, x, y);
            if (varTemp == 0)
            {
                CleanTabble(tabble, x, y);
                continue;
            }
            shadowsAround(tabble, submarine1.orientation, submarine1.insideLength, x, y, 'd');
            varTemp = submarine2.getSubmarine(tabble, x, y);
            if (varTemp == 0)
            {
                CleanTabble(tabble, x, y);
                continue;
            }
            shadowsAround(tabble, submarine2.orientation, submarine2.insideLength, x, y, 'd');
            varTemp = submarine3.getSubmarine(tabble, x, y);
            if (varTemp == 0)
            {
                CleanTabble(tabble, x, y);
                continue;
            }
            shadowsAround(tabble, submarine3.orientation, submarine3.insideLength, x, y, 'd');
            varTemp = submarine4.getSubmarine(tabble, x, y);
            if (varTemp == 0)
            {
                CleanTabble(tabble, x, y);
                continue;
            }
            shadowsAround(tabble, submarine4.orientation, submarine4.insideLength, x, y, 'd');

            varTemp = 1;
        }
        PrintTabble(tabble, x, y);
        CleanTabble(tabble, x, y);
    }
    return 0;
}
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
    vector<vector<char>> tabble(x + 2, vector<char>(y + 2));

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
    for (int rf = 0; rf < n; rf++)
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
        firstShip.getBattlecruze(tabble, x, y);
        shadowsAround(tabble, firstShip.orientation, firstShip.insideLength, x, y, 'b');

        destroyer1.getDestroyer(tabble, x, y);
        shadowsAround(tabble, destroyer1.orientation, destroyer1.insideLength, x, y, 'd');

        destroyer2.getDestroyer(tabble, x, y);
        shadowsAround(tabble, destroyer2.orientation, destroyer2.insideLength, x, y, 'd');

        cruizer1.getCruiser(tabble, x, y);
        shadowsAround(tabble, cruizer1.orientation, cruizer1.insideLength, x, y, 'd');
        cruizer2.getCruiser(tabble, x, y);
        shadowsAround(tabble, cruizer2.orientation, cruizer2.insideLength, x, y, 'd');
        cruizer3.getCruiser(tabble, x, y);
        shadowsAround(tabble, cruizer3.orientation, cruizer3.insideLength, x, y, 'd');

        submarine1.getSubmarine(tabble, x, y);
        shadowsAround(tabble, submarine1.orientation, submarine1.insideLength, x, y, 'd');
        submarine2.getSubmarine(tabble, x, y);
        shadowsAround(tabble, submarine2.orientation, submarine2.insideLength, x, y, 'd');
        submarine3.getSubmarine(tabble, x, y);
        shadowsAround(tabble, submarine3.orientation, submarine3.insideLength, x, y, 'd');
        submarine4.getSubmarine(tabble, x, y);
        shadowsAround(tabble, submarine4.orientation, submarine4.insideLength, x, y, 'd');

        //PRINTING TABBLE
        //This print eliminate first
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

    return 0;
}
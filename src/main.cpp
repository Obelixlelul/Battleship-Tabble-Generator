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

int main(int argc, char *argv[])
{
    srand(time(NULL));

    //Defining standard case
    int line(10), column(10), n(1);

    //Verify args and return line and rows based on user parameters
    if (!verifyArgs(argc, argv, 1, 6, line, column, n))
    {
        return 0;
    };

    //tabble declaration with dots representing the sea
    std::vector<std::string> board(line * column, "\u00B7");
    //represent board occupied by ship
    std::vector<int> impossibility;
    //board occupied in armada linear format
    std::string generalArmada;
    std::string tempArmada;

    //ship objects creation
    Ship battlecruze(4, line, column, impossibility);
    Ship destroyer1(3, line, column, impossibility);
    Ship destroyer2(3, line, column, impossibility);
    Ship cruiser1(2, line, column, impossibility);
    Ship cruiser2(2, line, column, impossibility);
    Ship cruiser3(2, line, column, impossibility);
    Ship submarine1(1, line, column, impossibility);
    Ship submarine2(1, line, column, impossibility);
    Ship submarine3(1, line, column, impossibility);
    Ship submarine4(1, line, column, impossibility);

    //Open Files
    ofstream puzzless_matrix;
    puzzless_matrix.open("../output/matrix-format.bp");
    puzzless_matrix << n << "\n";
    puzzless_matrix << line << " " << column << "\n";

    ofstream armada;
    armada.open("../output/armada-format.bp");
    armada << n << "\n";
    armada << line << " " << column << "\n\n\n";

    int counter = 0;

    for (int qtd = 0; qtd < n; qtd++) /*!<iterate N times informed by user*/
    {
        while (counter != 10) /*!< start putting ship on board with retroative initialization whenever fail when try*/
        {
            //remove all ships from the board
            resetSea(board, line, column);

            if (counter == 0)
            {
                if (battlecruze.positioningShip(impossibility, battlecruze.insideLength, column, line))
                {
                    battlecruze.insideShadows.clear();
                    counter++;
                    battlecruze.insertShipOnBoard(board, impossibility, line, column);
                }
            }

            if (counter == 1)
            {
                destroyer1.insideShadows.clear();
                if (destroyer1.positioningShip(impossibility, destroyer1.insideLength, column, line))
                {
                    counter++;
                    destroyer1.insertShipOnBoard(board, impossibility, line, column);
                }
                else
                {
                    counter = 0;
                    battlecruze.insideShadows.clear();
                    impossibility.clear();
                    continue;
                }
            }

            if (counter == 2)
            {
                destroyer2.insideShadows.clear();
                if (destroyer2.positioningShip(impossibility, destroyer2.insideLength, column, line))
                {
                    counter++;
                    destroyer2.insertShipOnBoard(board, impossibility, line, column);
                }
                else
                {
                    counter = 0;
                    battlecruze.insideShadows.clear();
                    impossibility.clear();
                    continue;
                }
            }

            if (counter == 3)
            {
                cruiser1.insideShadows.clear();

                if (cruiser1.positioningShip(impossibility, cruiser1.insideLength, column, line))
                {
                    counter++;
                    cruiser1.insertShipOnBoard(board, impossibility, line, column);
                }
                else
                {
                    counter = 0;
                    battlecruze.insideShadows.clear();
                    impossibility.clear();
                    continue;
                }
            }

            if (counter == 4)
            {
                cruiser2.insideShadows.clear();

                if (cruiser2.positioningShip(impossibility, cruiser2.insideLength, column, line))
                {
                    counter++;
                    cruiser2.insertShipOnBoard(board, impossibility, line, column);
                }
                else
                {
                    counter = 0;
                    battlecruze.insideShadows.clear();
                    impossibility.clear();
                    continue;
                }
            }

            if (counter == 5)
            {
                cruiser3.insideShadows.clear();

                if (cruiser3.positioningShip(impossibility, cruiser3.insideLength, column, line))
                {
                    counter++;
                    cruiser3.insertShipOnBoard(board, impossibility, line, column);
                }
                else
                {
                    counter = 0;
                    battlecruze.insideShadows.clear();
                    impossibility.clear();
                    continue;
                }
            }

            if (counter == 6)
            {
                submarine1.insideShadows.clear();

                if (submarine1.positioningShip(impossibility, submarine1.insideLength, column, line))
                {
                    counter++;
                    submarine1.insertShipOnBoard(board, impossibility, line, column);
                }
                else
                {
                    counter = 0;
                    battlecruze.insideShadows.clear();
                    impossibility.clear();
                    // resetSea(board, line, column);
                    continue;
                }
            }

            if (counter == 7)
            {
                submarine2.insideShadows.clear();

                if (submarine2.positioningShip(impossibility, submarine2.insideLength, column, line))
                {
                    counter++;
                    submarine2.insertShipOnBoard(board, impossibility, line, column);
                }
                else
                {
                    counter = 0;
                    battlecruze.insideShadows.clear();
                    impossibility.clear();
                    continue;
                }
            }

            if (counter == 8)
            {
                submarine3.insideShadows.clear();

                if (submarine3.positioningShip(impossibility, submarine3.insideLength, column, line))
                {
                    counter++;
                    submarine3.insertShipOnBoard(board, impossibility, line, column);
                }
                else
                {
                    counter = 0;
                    battlecruze.insideShadows.clear();
                    impossibility.clear();
                    continue;
                }
            }

            if (counter == 9)
            {
                submarine4.insideShadows.clear();

                if (submarine4.positioningShip(impossibility, submarine4.insideLength, column, line))
                {

                    counter++;
                    submarine4.insertShipOnBoard(board, impossibility, line, column);
                }
                else
                {

                    counter = 0;
                    battlecruze.insideShadows.clear();
                    impossibility.clear();
                    continue;
                }
            }
            InputArmada(tempArmada, battlecruze, destroyer1, destroyer2, cruiser1, cruiser2, cruiser3, submarine1, submarine2, submarine3, submarine4, line, column);
            //Verify if already have an equal board
            if (!CompareArmada(generalArmada, tempArmada))
            {
                counter = 0;
                battlecruze.insideShadows.clear();
                impossibility.clear();
                tempArmada.clear();
                continue;
            }
            InputArmada(generalArmada, battlecruze, destroyer1, destroyer2, cruiser1, cruiser2, cruiser3, submarine1, submarine2, submarine3, submarine4, line, column);
        }
        /*!>Remove above to print boards on console*/
        //PrintTabble(board, line, column, n);
        writeTabble(board, line, column, puzzless_matrix);
        WriteArmada(armada, battlecruze, destroyer1, destroyer2, cruiser1, cruiser2, cruiser3, submarine1, submarine2, submarine3, submarine4, line, column);

        impossibility.clear();
        counter = 0;
    }
    //close files .bp
    puzzless_matrix.close();
    armada.close();

    std::cout << "Successful Tabbles create\n";
    return 0;
}

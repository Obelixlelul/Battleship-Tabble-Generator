#include <iostream>
#include <iomanip>
#include <string.h>
#include <ctype.h>
#include <vector>
#include <algorithm>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include "../include/battleship.h"

using namespace std;

//--HELP FUCNTION
void Help()
{
    cout << " ..:::bpg ERROR::::..\
    \n Usage: [<options>] <number_of_puzzles> Program options are:\
    \n --rows <num> Specify the number of rows for the matrix, with `<num>` in the range [7, 16 ]. \
    \n The default value is 10.\
    \n --cols <num> Specify the number of columns for the matrix, with `<num>` in the range [7,16]. \
    \n The default value is 10.\
    \n Requested input is:\
    \n number_of_puzzles	The number of puzzles to be generated, in the range [1,100].\
    \n";
}

//FUNCTION TO LOWER MAIN PARAMETERS
std::string str_tolower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return std::tolower(c); } // correct
    );
    return s;
}

/*
*VERIFYING IF ARGUMENT NUMBERS ARE VALID
*/
int verifyArgs(int argc, int min, int max)
{
    if (argc == min || argc > max)
    {
        printf("Quantidade de argumentos inválida!\n");
        Help();
        return 0;
    }
}

int CreateRandom(int n)
{
    int a;
    a = rand() % n + 1;
    return a;
}

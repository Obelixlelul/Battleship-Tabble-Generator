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

int MainVeirification()
{
}

/*VERIFYING IF ARGUMENT NUMBERS ARE VALID
  argc = quantity of args imputed by user
  argv = input position, argv[0] = bpg
*/
int verifyArgs(int argc, char **argv, int min, int max, int &line, int &column, int &n)
{
  if (argc == min || argc > max)
  {
    std::cout << "Invalid number of arguments\n";
    Help();
    return 0;
  }

  std::string params[argc];

  for (int i = 1; i < argc; i++)
  {
    //removing case insensitive
    params[i] = str_tolower(argv[i]);

    //if compare == 0 they compare equal
    if (str_tolower(params[i]).compare("-h") == 0 || str_tolower(params[i]).compare("--help") == 0)
    {
      Help();
      return 0;
    }
    //verify columns
    if (str_tolower(params[i]).compare("-c") == 0 || str_tolower(params[i]).compare("--cols") == 0)
    {
      //strtol transform string to int
      column = strtol(argv[i + 1], NULL, 10);
      if (column < 7 || column > 16)
      {
        std::cout << "Column must be between 7 and 16\n";
        Help();
        return 0;
      }
      i++;
    }
    //Verify rows
    else if (str_tolower(params[i]).compare("-r") == 0 || str_tolower(params[i]).compare("--rows") == 0)
    {
      line = strtol(argv[i + 1], NULL, 10);
      if (line < 7 || line > 16)
      {
        std::cout << "Line mus be between 7 and 16\n";
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
      std::cout << "Somethign Wrong, check params you entered!!" << std::endl;
      Help();
      return 0;
    }
  }
}

//print help
void Help()
{
  std::cout << " ..:::bpg ERROR::::..\
    \n Usage: [<options>] <number_of_puzzles> Program options are:\
    \n --rows or -r <num> Specify the number of rows for the matrix, with `<num>` in the range [7, 16 ]. \
    \n The default value is 10.\
    \n --cols or -c <num> Specify the number of columns for the matrix, with `<num>` in the range [7,16]. \
    \n The default value is 10.\
    \n Requested input is:\
    \n number_of_puzzles	The number of puzzles to be generated, in the range [1,100].\
    \n";
}

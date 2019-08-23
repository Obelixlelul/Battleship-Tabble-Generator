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

int MainVeirification()
{
}

//VERIFYING IF ARGUMENT NUMBERS ARE VALID
int verifyArgs(int argc, char **argv, int min, int max, int &x, int &y, int &n)
{
  if (argc == min || argc > max)
  {
    Help();
    return 0;
  }

  std::string params[argc];

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
        std::cout << "Invalid parameters\n";
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
}

//--HELP FUCNTION
void Help()
{
  std::cout << " ..:::bpg ERROR::::..\
    \n Usage: [<options>] <number_of_puzzles> Program options are:\
    \n --rows <num> Specify the number of rows for the matrix, with `<num>` in the range [7, 16 ]. \
    \n The default value is 10.\
    \n --cols <num> Specify the number of columns for the matrix, with `<num>` in the range [7,16]. \
    \n The default value is 10.\
    \n Requested input is:\
    \n number_of_puzzles	The number of puzzles to be generated, in the range [1,100].\
    \n";
}

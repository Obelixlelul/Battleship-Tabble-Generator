#ifndef MAINVERIFICATION_H
#define MAINVERIFICATION_H

int MainVeirification();

//print help
void Help();

/**
 * Function to verify if args are correct
 * @min - Minimal quantity of args.
 * @max - Maximal quantity of args
 * @&x - substitute line length on Main function
 * @&x - substitute column length on Main function
 * @&n - quantity of boards will be created
 * return 0 if some main argument is wrong
*/
int verifyArgs(int argc, char **argv, int min, int max, int &x, int &y, int &n);

#endif
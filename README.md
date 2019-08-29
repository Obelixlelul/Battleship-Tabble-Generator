# Battleship-Tabble-Generator

{{TOC}}

## 1. Introduction

**Battleship Puzzle Generator** (`bpg`) generate `n` - `rows x columns` randomic Battleship Puzzle boards.

## 2. The puzzle

A single valid Battleship puzzle is a `n x m` matrix that contains a set of ships (_armada_) placed according to some rules.
For this project, in particular, a valid puzzle matrix may have any dimensions between 7 and 16 for rows or columns.
The armada is composed of 10 ships that are automatic generated on the matrix board. These ships are:

- 01 Battleship, with length = 4 pieces.
- 02 Destroyers, with length = 3 pieces.
- 03 Cruisers, with length = 2 pieces.
- 04 Submarines, with length = 1 piece.

Each ship occupies their length in contiguous cells of the grid, arranged either _horizontally_ or _vertically_.
The ships are positioned in such a way that there are always cells representing water (i.e. unoccupied free cells) around any two ships.
In other words, a ship must not occupy a cell that is neighbour of another ship's cell, not even diagonally.
A ship may touch the edge of the matrix.

## 3. Input

The program should run in a terminal as follows:

```
$.\bpg [<options>] <number_of_puzzles>
```

If the user provides any wrong input or calls the program with no parameters, the application should display the proper error message (if that is the case) and print out the help as follows:

```
$.\bpg
	Usage: [<options>] <number_of_puzzles>
	  Program options are:
	    -r or --rows <num>	Specify the number of rows for the matrix, with `<num>` in the range [7, 16 ]. The default value is 10.
	    -c or --cols <num>	Specify the number of columns for the matrix, with `<num>` in the range [7,16]. The default value is 10.
	  Requested input is:
	    number_of_puzzles	The number of puzzles to be generated, in the range [1,100].


Note that the option parameters _may be specified in any order_, and the user may want puzzles with number of rows different from the number of columns.

Some examples of input:
	./bpg -r 7 -c 7 10 (That will produce 10 boards 7x7)
	./bpg 5 (That will produce 5 boards 10x10)
	./bpg --rows 7 5 (That will produce 5 boards 7x10)

```

## 4. Output

Your program will produce **two** types of output files.

The first one is called `the matrix-format`. It contains an ascii representations of the entire board for each puzzle.

The second format is called `the armada-format`. It contains a compact text representation for each puzzle.

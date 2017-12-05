# Codewars: N-Queens coding challenge

One possible, easy to understand, simple solution to Codewars's N-Queens problem related coding challenge 
developed using C++ and a couple of STL containers and algorithms

The eight queens puzzle is the problem of placing eight chess queens on an 8×8 chessboard so that no two queens threaten each other. Thus, a solution requires that no two queens share the same row, column or diagonal. The eight queens puzzle is an example of the more general N queens problem of placing N non-attacking queens on an N×N chessboard.

[Wikipedia: Eight queens puzzle](https://en.wikipedia.org/wiki/Eight_queens_puzzle "Wikipedia: Eight queens puzzle")

You will receive a number N (0 < N <= 50) and have to place N queens on a N×N chessboard, so that no two queens attack each other. 
This requires that no two queens share the same row, column or diagonal. You will also receive the mandatory position of one queen.
This position is given 0-based in the format { x , y } with 0 <= x < N and 0 <= y < N. 
The coordinates {0, 0} are in the top left corner of the board. For many given parameters multiple solutions are possible. 
You have to find one of the possible solutions, all that fit the requirements will be accepted.

You have to return the solution board as a string, indicating empty fields with '.' (period) and Queens with 'Q' (uppercase Q), 
ending each row with '\n'.

If no solution is possible for the given parameters, return an empty string "".

Example:

solveNQueens(8, {3, 0})

could return:

"...Q....\n......Q.\n..Q.....\n.......Q\n.Q......\n....Q...\nQ.......\n.....Q..\n"

which would yield the following chessboard image when printed to console:

...Q....
......Q.
..Q.....
.......Q
.Q......
....Q...
Q.......
.....Q..

(Other solutions to this example are possible and accepted. The mandatory queen has to be in its position, 
in the example in the first row at {3, 0}.)

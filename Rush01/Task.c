/*
	• Your source code will be compiled as follows: 
	gcc -Wall -Wextra -Werror -o rush-1 *.c

	• Your submission directory must have all files required to compile your program.

	• Create a program that resolves a sudoku.

	• A valid sudoku has only one possible solution.

	• Here’s how we’ll launch your program :
	> ./rush-1 line0 line1 line2 line3 line4 line5 line6 line7 line8

	• LineN represents a characters string of values ranged between ’1’ and ’9’ or ’.’ (for
	empty boxes).

	• Here’s an example of intended input/output for a valid sudoku.

	>./sudoku "9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68."
	  ".9..5.741" "47......." | cat -e

	9 1 4 3 7 5 2 6 8$
	2 8 7 4 9 6 1 5 3$
	3 6 5 8 1 2 4 7 9$
	8 4 6 5 2 1 3 9 7$
	5 2 9 6 3 7 8 1 4$
	7 3 1 9 8 4 5 2 6$
	1 5 3 7 4 9 6 8 2$
	6 9 8 2 5 3 7 4 1$
	4 7 2 1 6 8 9 3 5$
	>
	==================
	5 3 . . 7 . . . 1
	6 . . 1 9 5 . . 1
	. 9 8 . . . . 6 .
	8 . . . 6 . . . 3
	4 . . 8 . 3 . . 1
	7 . . . 2 . . . 6
	. 6 . . . . 2 8 .
	. . . 4 1 9 . . 5
	. . . . 8 . . 7 9

	• In case of error, display "Error" followed by a line break.
	===========
	Turn-in directory : ex00/
	Files to turn in : All necessary files
	write, malloc, free
*/
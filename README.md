
This program reads data from a CSV file containing information about food contents. It allows the user to specify a row and column number, and retrieves the value from the corresponding cell in the file.

Files

main.c: The main program file.
reader.c: Contains functions for reading data from the CSV file.
reader.h: Header file with function declarations for reader.c.

Dependencies

C Standard Library (stdio.h, string.h)

Usage

Compile the program using a C compiler:
gcc -o food_reader main.c reader.c

Run the compiled program:

./food_reader

The program will prompt you to enter a row number and a column number.
Enter the desired row and column numbers, separated by a space.
The program will output the value from the specified cell in the CSV file.

Functions
main.c

main(): The main function that opens the CSV file, prompts the user for row and column numbers, and calls the read_xline and read_xcol functions to retrieve the desired value.

reader.c

read_xline(FILE *stream, int lineno, char buffer[]): Reads the specified line number from the file stream into the provided buffer.
read_xcol(const char *row, int colno, char buffer[]): Parses a row string to extract the specified column value and stores it in the provided buffer.

reader.h

Contains the function declarations for read_xline and read_xcol.

Example
Assuming the CSV file Food_contents_2019.csv contains the following data:


Name,Calories,Fat,Carbs,Protein
Apple,95,0.3,25.1,0.5
Banana,105,0.4,27.0,1.1
Orange,47,0.1,11.8,0.9

If the user enters 2 3 (row 2, column 3), the program will output 27.0, which is the value in the "Carbs" column for the "Banana" row.
Note: The program assumes that the CSV file is located in the same directory as the executable and is named Food_contents_2019.csv.


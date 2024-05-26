/*Autor: Jelsin Stiben Sanchez Almanza
*/

#include <stdio.h>
#include "reader.h" /* Include header file with function declarations */

const char *fname = "Food_contents_2019.csv";

int main(){

  char line[1024];
  char value[1024];
  
  /* Open file and return file pointer*/
  FILE *fp = fopen(fname, "r");

  if(!fp) {
    printf("\nError opening file\n");
    return 1;
  }
  
  printf("\nFile opened successfully\n");
  fgets(line, 1024, fp); /* Read first line of file (header line) into buffer*/
  
  printf("\nWelcome to the program!\n");

  int row, col;
  scanf("%d %d", &row, &col);


  read_xline(fp, row, line); /* Call function to read specified row from file*/
  read_xcol(line, col, value); /* Call function to parse row string and extract column*/

  printf("\n%s\n", value);

  fclose(fp);

  return 0;
}

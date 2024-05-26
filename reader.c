/*Autor:Jeslin Stiben Sanchez Almanza
*/

#include <stdio.h> 
#include <string.h>

/*Reads the specified line number from the file into the buffer*/
int read_xline(FILE *stream, int lineno, char buffer[]) {
  
  int i; 
  char tmp[1024];

  /* Loop to skip ahead to the desired line number*/
  for(i=1; i<lineno; i++) {  
    if (fgets(tmp, 1024, stream) == NULL) {
      printf("\nError reading line %d\n", lineno);
      return 0;
    } 
  }
  
  /* Read the target line into the buffer*/
  if (fgets(buffer, 1024, stream) == NULL) {
    printf("\nError reading line %d\n", lineno);
    return 0;
  }

  /* Return 1 for success*/
  return 1;
}

/* Parse a row string to extract the specified column value*/
int read_xcol(const char *row, int colno, char buffer[]) {

  int i = 0;
  int cols = 1; 
  int in_quotes = 0;

  /* Iterate over the row string  */
  while(*row) {

    /* Handle quoted commas */
    if(*row == '"') {
      in_quotes = !in_quotes; 
    }
    else if(*row == ',' && !in_quotes) {
      cols++; /* Increment column counter*/
    }
      
    /* When at target column, copy chars to buffer*/
    else if(cols == colno) {
      buffer[i++] = *row;  
    }

    row++; 
  }
  
  /* Null terminate the extracted string*/
  buffer[i] = '\0'; 

  /* Return length of extracted string*/
  return i;
}

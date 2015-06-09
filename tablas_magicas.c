#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NAME_PROGRAM __FILE__

unsigned int element_max;
unsigned int count_tablas;
unsigned int count_element;

unsigned int **tablas;
unsigned int element;
int width_element_max;
int count_elements_for_fila;
int width_line;
char * line;

int width(unsigned int n){
    int cont = 0;
    int res;
    int sum = 0;
    while(n != 0){
        res = n % 10;
        sum = sum + res;
        n = n / 10;
        cont++;
    }
    return cont;
}

int main(int argc, const char *argv[])
{ 
  if (argc < 2) {
    fputs("USAGE: " NAME_PROGRAM " n\n", stderr);
    return 1;
  }

  count_tablas = atoi(argv[1]); /* Cantidad de tablas */
  count_element = pow(2, count_tablas - 1);
  element_max = pow(2, count_tablas) - 1;
  tablas = (unsigned int**) malloc(sizeof(unsigned int**) * count_tablas);
  width_element_max =width(element_max);
  count_elements_for_fila = (int) sqrt(count_element);
  
  width_line = width_element_max * count_elements_for_fila + (count_elements_for_fila - 1) * 3;
  line = (char *) malloc(sizeof(char) * width_line);
  for (int i = 0; i < width_line; i++)
  {
    line[i] = '-';
  }

  for (int i = 0; i < count_tablas; i++)
    tablas[i] = (unsigned int*) malloc(sizeof(unsigned int*) * count_element);
 
  for (int i = 0; i < count_tablas; i++) {
    int j = 0;
    for (element = 1; element <= element_max; element++) {
      if (element & (1 << i))
      {
        tablas[i][j] = element;
        j++;
      }
    }
  }

  for (int i = 0; i < count_tablas; i++)
  {
    /* printf("%.*s\n", width_line, line); line definido como char* line = "------etc" */
    printf("%s\n", line);
    for (int j = 0; j < count_element; j++)
    {
      printf("%*d", width_element_max, tablas[i][j]);
      if ((j + 1) % count_elements_for_fila == 0 || (j + 1) == count_element)
        printf("\n");
      else
        printf(" - ");
    }
    printf("%s\n\n", line);
  }

  for (int i = 0; i < count_tablas; i++)
    free(tablas[i]);
  free(tablas);

  free(line);
  return 0;
}


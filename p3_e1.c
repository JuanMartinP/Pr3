#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "functions.h"
#include "point.h"
#include "types.h"

#define MAX 100

int main(int argc, char* argv[])
{
  Queue* cola1, cola2, cola3;

  if(argc < 1)
    {
      fprintf(stderr, "El programa se abre con: %s <data_file>\n", argv[0]);
      return ERROR;
    }

  f = fopen(argv[1], "r");
    if(!f)
    {
      fprintf(stderr, "No se pudo abrir %s\n", argv[1]);
      return ERROR;
    }

  cola1 = queue_ini(destroy_element_function, copy_element_function, print_element_function);
  cola2 = queue_ini(destroy_element_function, copy_element_function, print_element_function);
  cola3 = queue_ini(destroy_element_function, copy_element_function, print_element_function);


}

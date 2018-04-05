#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "functions.h"
#include "point.h"
#include "types.h"

#define MAX 100

int main(int argc, char* argv[])
{
  Point* punto;
  Queue* cola1, cola2, cola3;
  FILE* f = NULL;
  int pts, i, x, y;
  char coma1, coma2, symbol;

  if(argc < 1)
    {
      fprintf(stderr, "El programa se abre con: %s <data_file>\n", argv[0]);
      return 1;
    }

  f = fopen(argv[1], "r");
    if(!f)
    {
      fprintf(stderr, "No se pudo abrir %s\n", argv[1]);
      return 1;
    }

  cola1 = queue_ini(destroy_point_function, copy_point_function, print_point_function);
  if(!cola1)
    return ERROR;
  cola2 = queue_ini(destroy_point_function, copy_point_function, print_point_function);
  if(!cola2)
    return ERROR;
  cola3 = queue_ini(destroy_point_function, copy_point_function, print_point_function);
  if(!cola3)
    return ERROR;

  if(queue_isEmpty(cola1)==TRUE)
    printf("Cola 1: Queue vacia.");
  else
    printf("Cola 1: Cola con %d elementos.",queue_size(cola1));

  if(queue_isEmpty(cola2)==TRUE)
    printf("Cola 2: Queue vacia.");
  else
    printf("Cola 2: Cola con %d elementos.",queue_size(cola2));

  if(queue_isEmpty(cola3)==TRUE)
    printf("Cola 3: Queue vacia.");
  else
    printf("Cola 3: Cola con %d elementos.",queue_size(cola3));

  fscanf(f,"%d",&pts);

  for(i=0;i<=pts;i++)
  {
    fscanf(f,"%d %c %d %c %c",&x, &coma1, &y, &coma2, &symbol); /*los %c son las comas*/
    punto = point_ini(x, y, symbol);
    queue_insert(cola1, punto); /*¿Falta casteo?*/
  }

}

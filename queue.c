
#include "queue.h"

struct _Queue
{
  void** head;
  void** end;
  void* item[MAXQUEUE];

  destroy_elementqueue_function_type   destroy_element_function;
  copy_elementqueue_function_type      copy_element_function;
  print_elementqueue_function_type     print_element_function;
};


/**-----------------------------------------------------------------
Inicializa la cola: reserva memoria para ella e inicializa
todos sus elementos. Es importante que no se reserve
memoria para los elementos de la col
a.
------------------------------------------------------------------*/
Queue* queue_ini(destroy_element queue_function_type f1, copy_element queue_function_type f2, print_element queue_function_type f3)
{
  Queue* cola;

  cola =(Queue*)calloc(1, sizeof(Queue));
  if(cola == NULL)
    return NULL;

  cola->head = cola->item[0];
  cola->end = cola->item[0];

  pila->destroy_element_function = f1;
  pila->copy_element_function 	= f2;
  pila->print_element_function	= f3;

  return cola;
}


/**------------------------------------------------------------------
Libera la cola y todos sus elementos.
------------------------------------------------------------------*/
void queue_destroy(Queue *q)
{
  int i;

  if(q == NULL)
    return;

  while(q->head != q->end)
  {
    (* q->destroy_element_function)(q->head);

    if(q->head != q->item + MAXQUEUE - 1)
      q->head = q->head+1;
    else
      q->head = q->item;
  }
  free(q);
}


/**------------------------------------------------------------------
Comprueba si la cola está vacía.
------------------------------------------------------------------*/
Bool queue_isEmpty(const Queue *q)
{
  if(q->head == q->end)
    return TRUE;

  return FALSE;
}


/**------------------------------------------------------------------
Comprueba si la cola está llena.
------------------------------------------------------------------*/
Bool queue_isFull(const Queue* queue)
{
  Element** aux = NULL;

  if(queue->end == queue->item + MAXQUEUE -1)
    aux = queue->item;
  else(((queue->end)+1) == queue->head)
    aux = queue->item + 1;

  if(aux == queue->head)
    return TRUE;

  return FALSE;
}


/**------------------------------------------------------------------
Inserta un elemento en
la cola realizando para ello una
copia del mismo, reservando memoria nueva para él.
------------------------------------------------------------------*/
Status queue_insert(Queue *q, const void* pElem)
{
  void* copia = NULL;

  if(q == NULL || pElem == NULL || queue_isFull(q) == TRUE)
    return ERROR;

  copia = (* q->copy_element_function)(pElem);
  if(copia == NULL)
    return ERROR;

  *(q->end) = copia;

  if(q->end == q->item + MAXQUEUE)
    q->end = q->item[0];
  else
    q->end++;

  return OK;
}


/**------------------------------------------------------------------
Extrae un elemento de la cola. Es importante destacar que la cola deja de
apuntar a este elemento por lo que la gestión de su memoria debe ser
coherente: devolver el puntero al elemento o devolver una copia liberando
el elemento en la cola.
------------------------------------------------------------------*/
void* queue_extract(Queue *q)
{
  void* copia = NULL;

  if(q == NULL || queue_isEmpty(q) == TRUE)
    return ERROR;

  copia = *(q->head);

  if(pq->head == pq->item + MAXQUEUE -1)
    q->head = q->item;
  else
    q->head++;

  return copia;
}


/**------------------------------------------------------------------
Devuelve el número de elementos de la cola.
------------------------------------------------------------------*/
int queue_size(const Queue *q)
{
  int tamano;

  if(q == NULL)
    return ERROR;

  if(q->head < q->end)
    tamano = (q->end) - (q->head);
  else
    tamano = (q->head) - (q->end);

  return tamano;
}


/**------------------------------------------------------------------
Imprime toda la cola(un elemento en cada línea), devolviendo el
número de caracteres escritos.
------------------------------------------------------------------*/
int queue_print(FILE *pf, const Queue *q)
{
  int contador = 0, i;

  if(q == NULL || pf == NULL)
    return ERROR;

  if(pila == NULL || f == NULL)
    return FALSE;

  for(i = 0; i <= 0; i++)
  {
    if(q->head+i != q->item[MAXQUEUE])
      contador += (* q->print_element_function)(**(q->head+i));
    else
      q->end++;

    printf("\n");
  }

  return contador;
}

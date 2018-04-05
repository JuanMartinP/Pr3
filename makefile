################################################################################
CC=gcc
CFLAGS= -g -Wall -pedantic -ansi
EJS = p3_e1
################################################################################
OBJECTSP3E1 = p3_e1.o functions.o point.o queue.o
################################################################################

all: $(EJS)

p3_e1: $(OBJECTSP3E1)
	$(CC) $(CFLAGS) -o p3_e1 $(OBJECTSP3E1)

################################################################################

p3_e1.o: p3_e1.c queue.h functions.h point.h types.h
	$(CC) $(CFLAGS) -c p3_e1.c

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c

point.o: point.c point.h types.h
	$(CC) $(CFLAGS) -c point.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

################################################################################
clean:
	rm -rf *.o

run:
	@echo ">>>>>>Running p2_e1 with standard size (3)"
	./p3_e1 puntos.txt

runv:
	@echo ">>>>>>Running p2_e1 with valgrind"
	valgrind --leak-check=full ./p3_e1 puntos.txt

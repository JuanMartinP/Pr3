#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

#include "point.h"

void destroy_intp_function(void *);

void * copy_intp_function(const void *);

int print_intp_function(FILE * f, const void *);


void destroy_point_function(void *);

void * copy_point_function(const void *);

int print_point_function(FILE * f, const void *);

#endif

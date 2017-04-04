#ifndef HEADERS_H
#define HEADERS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct env_s
{
	char *key;
	char *val;
	struct env_s *next;
} env_t;

#endif

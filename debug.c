#include "debug.h"

void dump_vector(gsl_vector * v) {
	unsigned int i;
	printf("Vector%ud[", (unsigned int) v->size);
	for (i = 0; i < v->size - 1; i++) {
		printf("%f;", gsl_vector_get(v, i));
	}
	printf("%f]", gsl_vector_get(v, v->size - 1));
}

void dump_vectorln(gsl_vector * v) {
	dump_vector(v);
	printf("\n");
}


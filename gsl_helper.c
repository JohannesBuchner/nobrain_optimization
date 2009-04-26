
#include "gsl_helper.h"
#include "debug.h"

#define require(x) (x)

double calc_vector_sum(const gsl_vector * v) {
	double sum = 0;
	unsigned int i;
	for (i = 0; i < v->size; i++) {
		sum += gsl_vector_get(v, i);
	}
	return sum;
}

double calc_vector_squaresum(const gsl_vector * v) {
	static double sum = 0;
	static double x;
	static unsigned int i;
	sum = 0;
	for (i = 0; i < v->size; i++) {
		x = gsl_vector_get(v, i);
		sum += x * x;
	}
	return sum;
}

gsl_vector * dup_vector(const gsl_vector * v) {
	gsl_vector * r;
	assert(v != NULL);
	assert(v->size > 0);
	r = gsl_vector_alloc(v->size);
	assert(r != NULL);
	require(gsl_vector_memcpy(r, v));
	return r;
}

gsl_vector * calc_normalized(const gsl_vector * v) {
	double sum = calc_vector_sum(v);
	gsl_vector * r = dup_vector(v);
	require(gsl_vector_scale(r, 1/sum));
	return r;
}

int calc_same(const gsl_vector * a, const gsl_vector * b) {
	unsigned int i;
	assert(a->size == b->size);

	if (a == b)
		return 1;

	for (i = 0; i < a->size; i++) {
		if (gsl_vector_get(a, i) != gsl_vector_get(b, i))
			return 0;
	}
	return 1;
}

void max_vector(gsl_vector * a, const gsl_vector * b) {
	unsigned int i;
	assert(a->size == b->size);

	if (a == b)
		return;

	for (i = 0; i < a->size; i++) {
		if (gsl_vector_get(a, i) < gsl_vector_get(b, i))
			gsl_vector_set(a, i, gsl_vector_get(b, i));
	}
}

void min_vector(gsl_vector * a, const gsl_vector * b) {
	unsigned int i;
	assert(a->size == b->size);

	if (a == b)
		return;

	for (i = 0; i < a->size; i++) {
		if (gsl_vector_get(a, i) > gsl_vector_get(b, i))
			gsl_vector_set(a, i, gsl_vector_get(b, i));
	}
}

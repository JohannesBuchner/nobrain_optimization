/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
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


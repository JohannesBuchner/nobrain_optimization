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
#include "climber.c"
#include <math.h>

#ifdef ROSENBROCK
/*#define FORMULA -(pow(0.75-x,2)+100*pow(y-x*x,2))*/
#define FORMULA -(-1.5*x + x*x + 100*y*y - 200*x*x*y + 100*x*x*x*x)
#endif

#ifndef FORMULA
#define FORMULA -(x*x + y*y)
#endif

double f(gsl_vector * v) {
	double x = gsl_vector_get(v, 0);
	double y = gsl_vector_get(v, 1);
	return FORMULA;
}

int main(int argc, char ** argv) {
	long count = 0;
	double exactness;
	gsl_vector * start;
	if (argc == 2) {
		exactness = atof(argv[1]);
		dump_d("using exactness", exactness);
	} else {
		printf("%s: SYNOPSIS: <exactness>\n"
			"\n"
			"\texactness: \thow detailled should we refine the search\n"
			"\n", argv[0]);
		exit(1);
	}
	setup_rng();
	start = get_random_uniform_vector(2);
	count = find_local_maximum(2, exactness, start);
	printf("%lu steps\n", count);
	gsl_vector_free(start);
	gsl_rng_free(get_rng_instance());
	return 0;
}

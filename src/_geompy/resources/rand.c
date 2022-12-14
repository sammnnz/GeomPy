#include "../includes/rand.h"

#define _USE_MATH_DEFINES

#include <math.h>
#include <stdlib.h>
#include <time.h>

double random_(double start, double stop) {
	//srand(time(NULL));
	return start + (stop - start) * ((double)rand() / RAND_MAX);
};

#ifndef M_PI
#	define M_PI 3.14159265358979323846   // pi
#endif

double random_angle(double start) {
	if (start > 2 * M_PI) return 0.0;

	return random_(start, 2 * M_PI);
};


#include <cstdio>
#include "main.h"
#include "geometry.h"
extern "C" {
#include "time.h"

#include "stdlib.h"
#include "gfx.h"
}

FILE _fileScreen;

int main(int argc, char_ argv[]) {
	srand(time(NULL));

	int N;
	if (argc == 1)
		N = rand() % 51;
	else

		N = atoi(argv[1]);
	Circle _P = new Circle[N];
	fileScreen = fopen("screen.txt", "w");
	for (int i = 0; i < N; i++) {
		double r = (Width <= Height) ? Width / 50. : Height / 50.;
		double x = r + (Width - 2_r) * rand() / RAND_MAX;
		double y = r + (Height - 2_r) * rand() / RAND_MAX;
		P[i].Set(x, y, r, rand() % 0x1000000);
		P[i].Save();
	}
	fclose(fileScreen);
	try {
		gfx_open(Width, Height, "screen");
		for (int i = 0; i < N; i++) {

			P[i].Show();
		}
		gfx_wait();
	}
	catch (...) {}
	return 0;
}
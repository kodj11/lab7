#include <cstdio>
#include "geometry.h" 
#include "main.h"
extern "C" {
#include "math.h"
#include "gfx.h"
}

const int Width = 600;
const int Height = 600;

void GraphObject::Move(double nx, double ny) {
	Hide();
	x = nx;
	y = ny;
	Show();
}

double GraphObject::X() const {
	return x;
}

double GraphObject::Y() const {
	return y;
}

void Pixel::Set(double nx, double ny, int ncolor) {
	x = nx;
	y = ny;
	color = ncolor;
}

void Pixel::Save() {
	fprintf(fileScreen, "%g\t%g\n", x, y);
}

void Pixel::Show() {
	gfx_color((color & 0xFF0000) >> 16, (color & 0x00FF00) >> 8, color & 0x0000FF);
	gfx_point(x, y);
	gfx_flush();
}

void Pixel::Hide() {
	gfx_color(0, 0, 0);
	gfx_point(x, y);
	gfx_flush();
}

void Circle::Set(double nx, double ny, double nr, int ncolor) {
	x = nx;
	y = ny;
	radius = nr;
	color = ncolor;
}

void Circle::Save() {
	int i, N = 75;
	double phi = 0;
	for (i = 0; i < N; i++) {
		double xi = x + radius * cos(phi);
		double yi = y + radius * sin(phi);
		phi += 2 * M_PI / (N - 1);
		fprintf(fileScreen, "%g\t%g\n", xi, yi);
	}
}

void Circle::Show() {
	int i, N = 75;
	double phi = 0;
	gfx_color((color & 0xFF0000) >> 16, (color & 0x00FF00) >> 8, color & 0x0000FF);
	for (i = 0; i < N; i++) {
		double xi = x + radius * cos(phi);
		double yi = y + radius * sin(phi);
		phi += 2 * M_PI / (N - 1);
		gfx_point(xi, yi);
	}
	gfx_flush();
}

void Circle::Hide() {
	int i, N = 75;
	double phi = 0;
	gfx_color(0, 0, 0);
	for (i = 0; i < N; i++) {
		double xi = x + radius * cos(phi);
		double yi = y + radius * sin(phi);
		phi += 2 * M_PI / (N - 1);
		gfx_point(xi, yi);
	}
	gfx_flush();
}
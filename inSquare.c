#include "DCEL.h"

int inSquare(int x, int y, int xmin, int xmax, int ymin, int ymax) {
	return xmin <= x && x <= xmax && ymin <= y && y <= ymax;
}

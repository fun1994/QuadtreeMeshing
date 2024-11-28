#include "DCEL.h"

int onSegment(int x, int y, int x0, int y0, int x1, int y1) {
	return x0 <= x && x <= x1 && (x - x0) * (y1 - y0) == (x1 - x0) * (y - y0);
}

#include "DCEL.h"

int intersect(struct HalfEdge* e, int xmin, int xmax, int ymin, int ymax) {
	int x0 = e->origin->x;
	int y0 = e->origin->y;
	int x1 = e->twin->origin->x;
	int y1 = e->twin->origin->y;
	if (x0 == x1) {
		for (int y = y0 < y1 ? y0 : y1; y <= (y0 < y1 ? y1 : y0); y++) {
			if (inSquare(x0, y, xmin, xmax, ymin, ymax)) {
				return 1;
			}
		}
	}
	if (y0 == y1) {
		for (int x = x0 < x1 ? x0 : x1; x <= (x0 < x1 ? x1 : x0); x++) {
			if (inSquare(x, y0, xmin, xmax, ymin, ymax)) {
				return 1;
			}
		}
	}
	if (x0 < x1 && y0 < y1) {
		for (int i = 0; i <= x1 - x0; i++) {
			if (inSquare(x0 + i, y0 + i, xmin, xmax, ymin, ymax)) {
				return 1;
			}
		}
	}
	if (x1 < x0 && y0 < y1) {
		for (int i = 0; i <= x0 - x1; i++) {
			if (inSquare(x1 + i, y1 - i, xmin, xmax, ymin, ymax)) {
				return 1;
			}
		}
	}
	if (x1 < x0 && y1 < y0) {
		for (int i = 0; i <= x0 - x1; i++) {
			if (inSquare(x1 + i, y1 + i, xmin, xmax, ymin, ymax)) {
				return 1;
			}
		}
	}
	if (x0 < x1 && y1 < y0) {
		for (int i = 0; i <= x1 - x0; i++) {
			if (inSquare(x0 + i, y0 - i, xmin, xmax, ymin, ymax)) {
				return 1;
			}
		}
	}
	return 0;
}

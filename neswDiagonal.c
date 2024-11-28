#include "DCEL.h"

int neswDiagonal(struct FaceNode* fnode, struct HalfEdge* e) {
	int nex = fnode->ne->v->x;
	int ney = fnode->ne->v->y;
	int swx = fnode->sw->v->x;
	int swy = fnode->sw->v->y;
	int x0 = e->origin->x;
	int y0 = e->origin->y;
	int x1 = e->twin->origin->x;
	int y1 = e->twin->origin->y;
	if (x0 < x1) {
		return onSegment(nex, ney, x0, y0, x1, y1) && onSegment(swx, swy, x0, y0, x1, y1);
	}
	if (x1 < x0) {
		return onSegment(nex, ney, x1, y1, x0, y0) && onSegment(swx, swy, x1, y1, x0, y0);
	}
	return 0;
}

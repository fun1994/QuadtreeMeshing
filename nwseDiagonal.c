#include "DCEL.h"

int nwseDiagonal(struct FaceNode* fnode, struct HalfEdge* e) {
	int nwx = fnode->nw->v->x;
	int nwy = fnode->nw->v->y;
	int sex = fnode->se->v->x;
	int sey = fnode->se->v->y;
	int x0 = e->origin->x;
	int y0 = e->origin->y;
	int x1 = e->twin->origin->x;
	int y1 = e->twin->origin->y;
	if (x0 < x1) {
		return onSegment(nwx, nwy, x0, y0, x1, y1) && onSegment(sex, sey, x0, y0, x1, y1);
	}
	if (x1 < x0) {
		return onSegment(nwx, nwy, x1, y1, x0, y0) && onSegment(sex, sey, x1, y1, x0, y0);
	}
	return 0;
}

#include "DCEL.h"

struct Vertex* mallocVertex() {
	struct Vertex* v = malloc(sizeof(struct Vertex));
	if (!v) {
		return NULL;
	}
	v->x = 0;
	v->y = 0;
	v->incidentEdge = NULL;
	return v;
}

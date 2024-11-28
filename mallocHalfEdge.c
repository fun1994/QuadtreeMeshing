#include "DCEL.h"

struct HalfEdge* mallocHalfEdge() {
	struct HalfEdge* e = malloc(sizeof(struct HalfEdge));
	if (!e) {
		return NULL;
	}
	e->origin = NULL;
	e->twin = NULL;
	e->prev = NULL;
	e->next = NULL;
	e->incidentFace = NULL;
	return e;
}

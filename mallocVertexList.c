#include "DCEL.h"

struct VertexList* mallocVertexList() {
	struct VertexList* V = malloc(sizeof(struct VertexList));
	if (!V) {
		return NULL;
	}
	V->size = 0;
	V->head = NULL;
	V->tail = NULL;
	return V;
}

#include "DCEL.h"

struct HalfEdgeList* mallocHalfEdgeList() {
	struct HalfEdgeList* E = malloc(sizeof(struct HalfEdgeList));
	if (!E) {
		return NULL;
	}
	E->size = 0;
	E->head = NULL;
	E->tail = NULL;
	return E;
}

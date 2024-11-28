#include "DCEL.h"

struct HalfEdgeNode* mallocHalfEdgeNode() {
	struct HalfEdgeNode* enode = malloc(sizeof(struct HalfEdgeNode));
	if (!enode) {
		return NULL;
	}
	enode->e = NULL;
	enode->prev = NULL;
	enode->next = NULL;
	enode->twin = NULL;
	enode->incidentFace = NULL;
	return enode;
}

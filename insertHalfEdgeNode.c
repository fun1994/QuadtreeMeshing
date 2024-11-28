#include "DCEL.h"

struct HalfEdgeNode* insertHalfEdgeNode(struct HalfEdgeList* E, int e) {
	struct HalfEdgeNode* enode = mallocHalfEdgeNode();
	if (!enode) {
		return NULL;
	}
	if (!e) {
		enode->e = mallocHalfEdge();
		if (!enode->e) {
			return NULL;
		}
	}
	E->size++;
	if (E->head) {
		E->tail->next = enode;
		enode->prev = E->tail;
	}
	else {
		E->head = enode;
	}
	E->tail = enode;
	return enode;
}

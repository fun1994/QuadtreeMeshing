#include "DCEL.h"

void removeHalfEdgeNode(struct HalfEdgeList* E, struct HalfEdgeNode* enode) {
	E->size--;
	if (enode == E->head) {
		E->head = E->head->next;
		if (E->head) {
			E->head->prev = NULL;
		}
	}
	else {
		enode->prev->next = enode->next;
	}
	if (enode == E->tail) {
		E->tail = E->tail->prev;
		if (E->tail) {
			E->tail->next = NULL;
		}
	}
	else {
		enode->next->prev = enode->prev;
	}
	free(enode->e);
	free(enode);
}

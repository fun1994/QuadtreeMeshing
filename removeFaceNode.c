#include "DCEL.h"

void removeFaceNode(struct FaceList* F, struct FaceNode* fnode) {
	F->size--;
	if (fnode == F->head) {
		F->head = F->head->next;
		if (F->head) {
			F->head->prev = NULL;
		}
	}
	else {
		fnode->prev->next = fnode->next;
	}
	if (fnode == F->tail) {
		F->tail = F->tail->prev;
		if (F->tail) {
			F->tail->next = NULL;
		}
	}
	else {
		fnode->next->prev = fnode->prev;
	}
	struct HalfEdgeNode* enode = fnode->f->innerComponents->head;
	while (enode) {
		struct HalfEdgeNode* enode2 = enode->next;
		free(enode);
		enode = enode2;
	}
	free(fnode->f->innerComponents);
	free(fnode->f);
	free(fnode);
}

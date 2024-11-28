#include "DCEL.h"

struct FaceNode* insertFaceNode(struct FaceList* F, int f) {
	struct FaceNode* fnode = mallocFaceNode();
	if (!fnode) {
		return NULL;
	}
	if (!f) {
		fnode->f = mallocFace();
		if (!fnode->f) {
			return NULL;
		}
		fnode->f->innerComponents = mallocHalfEdgeList();
		if (!fnode->f->innerComponents) {
			return NULL;
		}
	}
	F->size++;
	if (F->head) {
		F->tail->next = fnode;
		fnode->prev = F->tail;
	}
	else {
		F->head = fnode;
	}
	F->tail = fnode;
	return fnode;
}

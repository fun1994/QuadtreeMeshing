#include "DCEL.h"

struct VertexNode* insertVertexNode(struct VertexList* V, int v) {
	struct VertexNode* vnode = mallocVertexNode();
	if (!vnode) {
		return NULL;
	}
	if (!v) {
		vnode->v = mallocVertex();
		if (!vnode->v) {
			return NULL;
		}
	}
	V->size++;
	if (V->head) {
		V->tail->next = vnode;
		vnode->prev = V->tail;
	}
	else {
		V->head = vnode;
	}
	V->tail = vnode;
	return vnode;
}

#include "DCEL.h"

struct VertexNode* mallocVertexNode() {
	struct VertexNode* vnode = malloc(sizeof(struct VertexNode));
	if (!vnode) {
		return NULL;
	}
	vnode->v = NULL;
	vnode->prev = NULL;
	vnode->next = NULL;
	return vnode;
}

#include "DCEL.h"

int printVertexIndex(struct VertexList* V, struct Vertex* v) {
	int flag = 1;
	int index = 0;
	struct VertexNode* vnode = V->head;
	while (vnode) {
		if (v == vnode->v) {
			flag = 0;
			printf("%d ", index);
			break;
		}
		index++;
		vnode = vnode->next;
	}
	return flag;
}

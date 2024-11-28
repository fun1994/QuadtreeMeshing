#include "DCEL.h"

int printVertexNodeIndex(struct VertexList* V, struct VertexNode* vnode) {
	if (vnode) {
		int flag = 1;
		int index = 0;
		struct VertexNode* vnode2 = V->head;
		while (vnode2) {
			if (vnode == vnode2) {
				flag = 0;
				printf("%d ", index);
				break;
			}
			index++;
			vnode2 = vnode2->next;
		}
		if (flag) {
			return 1;
		}
	}
	else {
		printf("NULL ");
	}
	return 0;
}

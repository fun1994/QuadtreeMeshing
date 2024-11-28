#include "DCEL.h"

int saveVertexIndex(FILE* file, struct VertexList* V, struct Vertex* v) {
	if (!v) {
		return 1;
	}
	int flag = 1;
	int index = 0;
	struct VertexNode* vnode = V->head;
	while (vnode) {
		if (v == vnode->v) {
			flag = 0;
			fprintf(file, "%d ", index);
			break;
		}
		index++;
		vnode = vnode->next;
	}
	return flag;
}

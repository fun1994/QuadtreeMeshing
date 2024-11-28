#include "DCEL.h"

int saveHalfEdgeIndex(FILE* file, struct HalfEdgeList* E, struct HalfEdge* e) {
	if (!e) {
		return 1;
	}
	int flag = 1;
	int index = 0;
	struct HalfEdgeNode* enode = E->head;
	while (enode) {
		if (e == enode->e) {
			flag = 0;
			fprintf(file, "%d ", index);
			break;
		}
		index++;
		enode = enode->next;
	}
	return flag;
}

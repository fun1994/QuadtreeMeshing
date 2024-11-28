#include "DCEL.h"

int printHalfEdgeIndex(struct HalfEdgeList* E, struct HalfEdge* e) {
	if (e) {
		int flag = 1;
		int index = 0;
		struct HalfEdgeNode* enode = E->head;
		while (enode) {
			if (e == enode->e) {
				flag = 0;
				printf("%d ", index);
				break;
			}
			index++;
			enode = enode->next;
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

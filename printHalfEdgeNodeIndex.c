#include "DCEL.h"

int printHalfEdgeNodeIndex(struct HalfEdgeList* E, struct HalfEdgeNode* enode) {
	if (enode) {
		int flag = 1;
		int index = 0;
		struct HalfEdgeNode* enode2 = E->head;
		while (enode2) {
			if (enode == enode2) {
				flag = 0;
				printf("%d ", index);
				break;
			}
			index++;
			enode2 = enode2->next;
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

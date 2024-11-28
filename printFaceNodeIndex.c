#include "DCEL.h"

int printFaceNodeIndex(struct FaceList* F, struct FaceNode* fnode) {
	if (fnode) {
		int flag = 1;
		int index = 0;
		struct FaceNode* fnode2 = F->head;
		while (fnode2) {
			if (fnode == fnode2) {
				flag = 0;
				printf("%d ", index);
				break;
			}
			index++;
			fnode2 = fnode2->next;
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

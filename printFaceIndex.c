#include "DCEL.h"

int printFaceIndex(struct FaceList* F, struct Face* f) {
	int flag = 1;
	int index = 0;
	struct FaceNode* fnode = F->head;
	while (fnode) {
		if (f == fnode->f) {
			flag = 0;
			printf("%d ", index);
			break;
		}
		index++;
		fnode = fnode->next;
	}
	return flag;
}

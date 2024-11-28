#include "DCEL.h"

struct FaceList* mallocFaceList() {
	struct FaceList* F = malloc(sizeof(struct FaceList));
	if (!F) {
		return NULL;
	}
	F->size = 0;
	F->head = NULL;
	F->tail = NULL;
	return F;
}

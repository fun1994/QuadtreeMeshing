#include "DCEL.h"

struct FaceNode* mallocFaceNode() {
	struct FaceNode* fnode = malloc(sizeof(struct FaceNode));
	if (!fnode) {
		return NULL;
	}
	fnode->f = NULL;
	fnode->prev = NULL;
	fnode->next = NULL;
	fnode->ne = NULL;
	fnode->nw = NULL;
	fnode->sw = NULL;
	fnode->se = NULL;
	fnode->n = NULL;
	fnode->w = NULL;
	fnode->s = NULL;
	fnode->e = NULL;
	fnode->nenw = NULL;
	fnode->nwsw = NULL;
	fnode->swse = NULL;
	fnode->sene = NULL;
	fnode->nen = NULL;
	fnode->nnw = NULL;
	fnode->nww = NULL;
	fnode->wsw = NULL;
	fnode->sws = NULL;
	fnode->sse = NULL;
	fnode->see = NULL;
	fnode->ene = NULL;
	fnode->E = NULL;
	return fnode;
}

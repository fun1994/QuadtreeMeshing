#include "quadtree.h"

struct Node* mallocNode() {
	struct Node* v = malloc(sizeof(struct Node));
	if (!v) {
		return NULL;
	}
	v->xmin = 0;
	v->xmax = 0;
	v->ymin = 0;
	v->ymax = 0;
	v->parent = NULL;
	v->ne = NULL;
	v->nw = NULL;
	v->sw = NULL;
	v->se = NULL;
	v->next = NULL;
	v->fnode = NULL;
	v->E = NULL;
	v->inList = 0;
	return v;
}

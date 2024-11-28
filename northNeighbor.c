#include "quadtree.h"

struct Node* northNeighbor(struct Node* v) {
	if (!v->parent) {
		return NULL;
	}
	if (v == v->parent->sw) {
		return v->parent->nw;
	}
	if (v == v->parent->se) {
		return v->parent->ne;
	}
	struct Node* u = northNeighbor(v->parent);
	if (!u || !u->ne) {
		return u;
	}
	else if (v == v->parent->nw) {
		return u->sw;
	}
	else {
		return u->se;
	}
}

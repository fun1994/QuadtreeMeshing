#include "quadtree.h"

struct Node* southNeighbor(struct Node* v) {
	if (!v->parent) {
		return NULL;
	}
	if (v == v->parent->nw) {
		return v->parent->sw;
	}
	if (v == v->parent->ne) {
		return v->parent->se;
	}
	struct Node* u = southNeighbor(v->parent);
	if (!u || !u->ne) {
		return u;
	}
	else if (v == v->parent->sw) {
		return u->nw;
	}
	else {
		return u->ne;
	}
}

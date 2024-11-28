#include "quadtree.h"

struct Node* eastNeighbor(struct Node* v) {
	if (!v->parent) {
		return NULL;
	}
	if (v == v->parent->nw) {
		return v->parent->ne;
	}
	if (v == v->parent->sw) {
		return v->parent->se;
	}
	struct Node* u = eastNeighbor(v->parent);
	if (!u || !u->ne) {
		return u;
	}
	else if (v == v->parent->ne) {
		return u->nw;
	}
	else {
		return u->sw;
	}
}

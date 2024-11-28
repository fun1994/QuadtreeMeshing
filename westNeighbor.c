#include "quadtree.h"

struct Node* westNeighbor(struct Node* v) {
	if (!v->parent) {
		return NULL;
	}
	if (v == v->parent->ne) {
		return v->parent->nw;
	}
	if (v == v->parent->se) {
		return v->parent->sw;
	}
	struct Node* u = westNeighbor(v->parent);
	if (!u || !u->ne) {
		return u;
	}
	else if (v == v->parent->nw) {
		return u->ne;
	}
	else {
		return u->se;
	}
}

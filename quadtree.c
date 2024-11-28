#include "quadtree.h"

struct Node* quadtree(struct HalfEdgeList* E, int xmin, int xmax, int ymin, int ymax) {
	struct Node* v = mallocNode();
	if (!v) {
		return NULL;
	}
	v->xmin = xmin;
	v->xmax = xmax;
	v->ymin = ymin;
	v->ymax = ymax;
	v->E = E;
	if (E->size == 0 || (xmax - xmin == 1 && ymax - ymin == 1)) {
		return v;
	}
	int xmid = (xmin + xmax) / 2;
	int ymid = (ymin + ymax) / 2;
	struct HalfEdgeList* Ene = mallocHalfEdgeList();
	if (!Ene) {
		return NULL;
	}
	struct HalfEdgeList* Enw = mallocHalfEdgeList();
	if (!Enw) {
		return NULL;
	}
	struct HalfEdgeList* Esw = mallocHalfEdgeList();
	if (!Esw) {
		return NULL;
	}
	struct HalfEdgeList* Ese = mallocHalfEdgeList();
	if (!Ese) {
		return NULL;
	}
	struct HalfEdgeNode* enode = E->head;
	for (int i = 0; i < E->size; i++) {
		if (intersect(enode->e, xmid, xmax, ymid, ymax)) {
			struct HalfEdgeNode* enode2 = insertHalfEdgeNode(Ene, 1);
			if (!enode2) {
				return NULL;
			}
			enode2->e = enode->e;
		}
		if (intersect(enode->e, xmin, xmid, ymid, ymax)) {
			struct HalfEdgeNode* enode2 = insertHalfEdgeNode(Enw, 1);
			if (!enode2) {
				return NULL;
			}
			enode2->e = enode->e;
		}
		if (intersect(enode->e, xmin, xmid, ymin, ymid)) {
			struct HalfEdgeNode* enode2 = insertHalfEdgeNode(Esw, 1);
			if (!enode2) {
				return NULL;
			}
			enode2->e = enode->e;
		}
		if (intersect(enode->e, xmid, xmax, ymin, ymid)) {
			struct HalfEdgeNode* enode2 = insertHalfEdgeNode(Ese, 1);
			if (!enode2) {
				return NULL;
			}
			enode2->e = enode->e;
		}
		enode = enode->next;
	}
	v->ne = quadtree(Ene, xmid, xmax, ymid, ymax);
	if (!v->ne) {
		return NULL;
	}
	v->nw = quadtree(Enw, xmin, xmid, ymid, ymax);
	if (!v->nw) {
		return NULL;
	}
	v->sw = quadtree(Esw, xmin, xmid, ymin, ymid);
	if (!v->sw) {
		return NULL;
	}
	v->se = quadtree(Ese, xmid, xmax, ymin, ymid);
	if (!v->se) {
		return NULL;
	}
	v->ne->parent = v;
	v->nw->parent = v;
	v->sw->parent = v;
	v->se->parent = v;
	return v;
}

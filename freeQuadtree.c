#include "quadtree.h"

void freeQuadtree(struct Node* v) {
	if (v->ne) {
		freeQuadtree(v->ne);
		freeQuadtree(v->nw);
		freeQuadtree(v->sw);
		freeQuadtree(v->se);
	}
	if (v->parent) {
		struct HalfEdgeNode* enode = v->E->head;
		while (enode) {
			struct HalfEdgeNode* enode2 = enode->next;
			free(enode);
			enode = enode2;
		}
		free(v->E);
	}
	free(v);
}

#include "quadtree.h"

int balanceQuadtree(struct Node* root) {
	struct Node* head = NULL;
	struct Node* tail = NULL;
	getLeaves(&head, &tail, root);
	while (head) {
		struct Node* v = head;
		struct Node* n = northNeighbor(v);
		struct Node* w = westNeighbor(v);
		struct Node* s = southNeighbor(v);
		struct Node* e = eastNeighbor(v);
		if ((n && n->ne && (n->sw->ne || n->se->ne)) || (w && w->ne && (w->ne->ne || w->se->ne)) || (s && s->ne && (s->nw->ne || s->ne->ne)) || (e && e->ne && (e->nw->ne || e->sw->ne))) {
			int xmid = (v->xmin + v->xmax) / 2;
			int ymid = (v->ymin + v->ymax) / 2;
			v->ne = mallocNode();
			if (!v->ne) {
				return 1;
			}
			v->ne->xmin = xmid;
			v->ne->xmax = v->xmax;
			v->ne->ymin = ymid;
			v->ne->ymax = v->ymax;
			v->ne->parent = v;
			v->ne->E = mallocHalfEdgeList();
			if (!v->ne->E) {
				return 1;
			}
			v->ne->inList = 1;
			v->nw = mallocNode();
			if (!v->nw) {
				return 1;
			}
			v->nw->xmin = v->xmin;
			v->nw->xmax = xmid;
			v->nw->ymin = ymid;
			v->nw->ymax = v->ymax;
			v->nw->parent = v;
			v->nw->E = mallocHalfEdgeList();
			if (!v->nw->E) {
				return 1;
			}
			v->nw->inList = 1;
			v->sw = mallocNode();
			if (!v->sw) {
				return 1;
			}
			v->sw->xmin = v->xmin;
			v->sw->xmax = xmid;
			v->sw->ymin = v->ymin;
			v->sw->ymax = ymid;
			v->sw->parent = v;
			v->sw->E = mallocHalfEdgeList();
			if (!v->sw->E) {
				return 1;
			}
			v->sw->inList = 1;
			v->se = mallocNode();
			if (!v->se) {
				return 1;
			}
			v->se->xmin = xmid;
			v->se->xmax = v->xmax;
			v->se->ymin = v->ymin;
			v->se->ymax = ymid;
			v->se->parent = v;
			v->se->E = mallocHalfEdgeList();
			if (!v->se->E) {
				return 1;
			}
			v->se->inList = 1;
			tail->next = v->ne;
			v->ne->next = v->nw;
			v->nw->next = v->sw;
			v->sw->next = v->se;
			tail = v->se;
			if (n && !n->inList && (v->xmax - v->xmin < n->xmax - n->xmin)) {
				tail->next = n;
				tail = n;
				n->inList = 1;
			}
			if (w && !w->inList && (v->xmax - v->xmin < w->xmax - w->xmin)) {
				tail->next = w;
				tail = w;
				w->inList = 1;
			}
			if (s && !s->inList && (v->xmax - v->xmin < s->xmax - s->xmin)) {
				tail->next = s;
				tail = s;
				s->inList = 1;
			}
			if (e && !e->inList && (v->xmax - v->xmin < e->xmax - e->xmin)) {
				tail->next = e;
				tail = e;
				e->inList = 1;
			}
		}
		head = v->next;
		v->next = NULL;
		v->inList = 0;
	}
	return 0;
}

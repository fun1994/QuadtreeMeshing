#include "quadtree.h"

void getLeaves(struct Node** head, struct Node** tail, struct Node* v) {
	if (v->ne) {
		getLeaves(head, tail, v->ne);
		getLeaves(head, tail, v->nw);
		getLeaves(head, tail, v->sw);
		getLeaves(head, tail, v->se);
	}
	else {
		if (*head) {
			(*tail)->next = v;
		}
		else {
			*head = v;
		}
		*tail = v;
		v->inList = 1;
	}
}

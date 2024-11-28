#include "DCEL.h"

int saveDCEL(struct DCEL* D) {
	FILE* file = fopen("data.txt", "w");
	if (!file) {
		return 1;
	}
	struct VertexNode* vnode = NULL;
	struct HalfEdgeNode* enode = NULL;
	struct FaceNode* fnode = NULL;
	vnode = D->V->head;
	while (vnode) {
		fprintf(file, "%d ", vnode->v->x);
		vnode = vnode->next;
	}
	fprintf(file, "\n");
	vnode = D->V->head;
	while (vnode) {
		fprintf(file, "%d ", vnode->v->y);
		vnode = vnode->next;
	}
	fprintf(file, "\n");
	enode = D->E->head;
	while (enode) {
		int flag = saveVertexIndex(file, D->V, enode->e->origin);
		if (flag) {
			return 1;
		}
		enode = enode->next;
	}
	fprintf(file, "\n");
	enode = D->E->head;
	while (enode) {
		int flag = saveHalfEdgeIndex(file, D->E, enode->e->twin);
		if (flag) {
			return 1;
		}
		enode = enode->next;
	}
	fprintf(file, "\n");
	enode = D->E->head;
	while (enode) {
		int flag = saveHalfEdgeIndex(file, D->E, enode->e->prev);
		if (flag) {
			return 1;
		}
		enode = enode->next;
	}
	fprintf(file, "\n");
	fnode = D->F->head;
	while (fnode) {
		if (fnode->f->outerComponent) {
			int flag = saveHalfEdgeIndex(file, D->E, fnode->f->outerComponent);
			if (flag) {
				return 1;
			}
		}
		else {
			fprintf(file, "NULL ");
		}
		fnode = fnode->next;
	}
	fclose(file);
	return 0;
}

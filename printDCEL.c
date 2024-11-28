#include "DCEL.h"

int printDCEL(struct DCEL* D) {
	int index, flag;
	struct VertexNode* vnode = NULL;
	struct HalfEdgeNode* enode = NULL;
	struct FaceNode* fnode = NULL;
	printf("Vertex\n");
	index = 0;
	vnode = D->V->head;
	while (vnode) {
		printf("%d %d %d ", index, vnode->v->x, vnode->v->y);
		flag = printHalfEdgeIndex(D->E, vnode->v->incidentEdge);
		if (flag) {
			return 1;
		}
		printf("\n");
		index++;
		vnode = vnode->next;
	}
	printf("HalfEdge\n");
	index = 0;
	enode = D->E->head;
	while (enode) {
		printf("%d ", index);
		flag = printVertexIndex(D->V, enode->e->origin);
		if (flag) {
			return 1;
		}
		flag = printHalfEdgeIndex(D->E, enode->e->twin);
		if (flag) {
			return 1;
		}
		flag = printHalfEdgeIndex(D->E, enode->e->prev);
		if (flag) {
			return 1;
		}
		flag = printHalfEdgeIndex(D->E, enode->e->next);
		if (flag) {
			return 1;
		}
		flag = printFaceIndex(D->F, enode->e->incidentFace);
		if (flag) {
			return 1;
		}
		printf("\n");
		index++;
		enode = enode->next;
	}
	printf("Face\n");
	index = 0;
	fnode = D->F->head;
	while (fnode) {
		printf("%d ", index);
		flag = printHalfEdgeIndex(D->E, fnode->f->outerComponent);
		if (flag) {
			return 1;
		}
		printf("[");
		enode = fnode->f->innerComponents->head;
		while (enode) {
			flag = printHalfEdgeIndex(D->E, enode->e);
			if (flag) {
				return 1;
			}
			enode = enode->next;
		}
		printf("] ");
		flag = printVertexNodeIndex(D->V, fnode->ne);
		if (flag) {
			return 1;
		}
		flag = printVertexNodeIndex(D->V, fnode->nw);
		if (flag) {
			return 1;
		}
		flag = printVertexNodeIndex(D->V, fnode->sw);
		if (flag) {
			return 1;
		}
		flag = printVertexNodeIndex(D->V, fnode->se);
		if (flag) {
			return 1;
		}
		flag = printVertexNodeIndex(D->V, fnode->n);
		if (flag) {
			return 1;
		}
		flag = printVertexNodeIndex(D->V, fnode->w);
		if (flag) {
			return 1;
		}
		flag = printVertexNodeIndex(D->V, fnode->s);
		if (flag) {
			return 1;
		}
		flag = printVertexNodeIndex(D->V, fnode->e);
		if (flag) {
			return 1;
		}
		flag = printHalfEdgeNodeIndex(D->E, fnode->nenw);
		if (flag) {
			return 1;
		}
		flag = printHalfEdgeNodeIndex(D->E, fnode->nwsw);
		if (flag) {
			return 1;
		}
		flag = printHalfEdgeNodeIndex(D->E, fnode->swse);
		if (flag) {
			return 1;
		}
		flag = printHalfEdgeNodeIndex(D->E, fnode->sene);
		if (flag) {
			return 1;
		}
		flag = printHalfEdgeNodeIndex(D->E, fnode->nen);
		if (flag) {
			return 1;
		}
		flag = printHalfEdgeNodeIndex(D->E, fnode->nnw);
		if (flag) {
			return 1;
		}
		flag = printHalfEdgeNodeIndex(D->E, fnode->nww);
		if (flag) {
			return 1;
		}
		flag = printHalfEdgeNodeIndex(D->E, fnode->wsw);
		if (flag) {
			return 1;
		}
		flag = printHalfEdgeNodeIndex(D->E, fnode->sws);
		if (flag) {
			return 1;
		}
		flag = printHalfEdgeNodeIndex(D->E, fnode->sse);
		if (flag) {
			return 1;
		}
		flag = printHalfEdgeNodeIndex(D->E, fnode->see);
		if (flag) {
			return 1;
		}
		flag = printHalfEdgeNodeIndex(D->E, fnode->ene);
		if (flag) {
			return 1;
		}
		printf("\n");
		index++;
		fnode = fnode->next;
	}
	printf("\n");
	return 0;
}

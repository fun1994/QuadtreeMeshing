#include "DCEL.h"

struct DCEL* generateDCEL(int Vsize, int Esize, int Fsize, int* innerComponentsSize, int* x, int* y, int* incidentEdge, int* origin, int* twin, int* prev, int* next, int* incidentFace, int* outerComponent, int** innerComponents) {
	struct Vertex** V = NULL;
	struct HalfEdge** E = NULL;
	struct Face** F = NULL;
	struct DCEL* D = mallocDCEL(&V, &E, &F, Vsize, Esize, Fsize, innerComponentsSize);
	if (!D) {
		return NULL;
	}
	for (int i = 0; i < Vsize; i++) {
		V[i]->x = x[i];
		V[i]->y = y[i];
		V[i]->incidentEdge = E[incidentEdge[i]];
	}
	for (int i = 0; i < Esize; i++) {
		E[i]->origin = V[origin[i]];
		E[i]->twin = E[twin[i]];
		E[i]->prev = E[prev[i]];
		E[i]->next = E[next[i]];
		E[i]->incidentFace = F[incidentFace[i]];
	}
	for (int i = 0; i < Fsize; i++) {
		if (outerComponent[i] >= 0) {
			F[i]->outerComponent = E[outerComponent[i]];
		}
		struct HalfEdgeNode* enode = F[i]->innerComponents->head;
		for (int j = 0; j < F[i]->innerComponents->size; j++) {
			enode->e = E[innerComponents[i][j]];
			enode = enode->next;
		}
	}
	free(V);
	free(E);
	free(F);
	return D;
}

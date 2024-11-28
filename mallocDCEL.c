#include "DCEL.h"

struct DCEL* mallocDCEL(struct Vertex*** V, struct HalfEdge*** E, struct Face*** F, int Vsize, int Esize, int Fsize, int* innerComponentsSize) {
	*V = malloc(Vsize * sizeof(struct Vertex*));
	if (!*V) {
		return NULL;
	}
	*E = malloc(Esize * sizeof(struct HalfEdge*));
	if (!*E) {
		return NULL;
	}
	*F = malloc(Fsize * sizeof(struct Face*));
	if (!*F) {
		return NULL;
	}
	struct DCEL* D = malloc(sizeof(struct DCEL));
	if (!D) {
		return NULL;
	}
	D->V = mallocVertexList();
	if (!D->V) {
		return NULL;
	}
	for (int i = 0; i < Vsize; i++) {
		struct VertexNode* vnode = insertVertexNode(D->V, 0);
		if (!vnode) {
			return NULL;
		}
		(*V)[i] = vnode->v;
	}
	D->E = mallocHalfEdgeList();
	if (!D->E) {
		return NULL;
	}
	for (int i = 0; i < Esize; i++) {
		struct HalfEdgeNode* enode = insertHalfEdgeNode(D->E, 0);
		if (!enode) {
			return NULL;
		}
		(*E)[i] = enode->e;
	}
	D->F = mallocFaceList();
	if (!D->F) {
		return NULL;
	}
	for (int i = 0; i < Fsize; i++) {
		struct FaceNode* fnode = insertFaceNode(D->F, 0);
		if (!fnode) {
			return NULL;
		}
		(*F)[i] = fnode->f;
		for (int j = 0; j < innerComponentsSize[i]; j++) {
			struct HalfEdgeNode* enode = insertHalfEdgeNode(fnode->f->innerComponents, 1);
			if (!enode) {
				return NULL;
			}
		}
	}
	return D;
}

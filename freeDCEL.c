#include "DCEL.h"

void freeDCEL(struct DCEL* D) {
	struct VertexNode* vnode = NULL;
	struct VertexNode* vnode2 = NULL;
	struct HalfEdgeNode* enode = NULL;
	struct HalfEdgeNode* enode2 = NULL;
	struct FaceNode* fnode = NULL;
	struct FaceNode* fnode2 = NULL;
	vnode = D->V->head;
	while (vnode) {
		vnode2 = vnode->next;
		free(vnode->v);
		free(vnode);
		vnode = vnode2;
	}
	free(D->V);
	enode = D->E->head;
	while (enode) {
		enode2 = enode->next;
		free(enode->e);
		free(enode);
		enode = enode2;
	}
	free(D->E);
	fnode = D->F->head;
	while (fnode) {
		fnode2 = fnode->next;
		enode = fnode->f->innerComponents->head;
		while (enode) {
			enode2 = enode->next;
			free(enode);
			enode = enode2;
		}
		free(fnode->f->innerComponents);
		free(fnode->f);
		free(fnode);
		fnode = fnode2;
	}
}

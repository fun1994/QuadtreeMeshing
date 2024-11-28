#include "quadtree.h"

struct DCEL* generateDCELFromBalancedQuadtree(struct Node* root) {
	int Vsize = 4;
	int Esize = 8;
	int Fsize = 2;
	int innerComponentsSize[2] = { 1,0 };
	int x[4] = { root->xmax,root->xmin,root->xmin,root->xmax };
	int y[4] = { root->ymax,root->ymax,root->ymin,root->ymin };
	int incidentEdge[4] = { 0,2,4,6 };
	int origin[8] = { 0,1,1,2,2,3,3,0 };
	int twin[8] = { 1,0,3,2,5,4,7,6 };
	int prev[8] = { 6,3,0,5,2,7,4,1 };
	int next[8] = { 2,7,4,1,6,3,0,5 };
	int incidentFace[8] = { 1,0,1,0,1,0,1,0 };
	int outerComponent[2] = { -1,0 };
	int** innerComponents = malloc(2 * sizeof(int*));
	if (!innerComponents) {
		return NULL;
	}
	innerComponents[0] = malloc(sizeof(int));
	if (!innerComponents[0]) {
		return NULL;
	}
	innerComponents[0][0] = 1;
	innerComponents[1] = NULL;
	struct DCEL* D = generateDCEL(Vsize, Esize, Fsize, innerComponentsSize, x, y, incidentEdge, origin, twin, prev, next, incidentFace, outerComponent, innerComponents);
	free(innerComponents[0]);
	free(innerComponents);
	if (!D) {
		return NULL;
	}
	D->E->head->twin = D->E->head->next;
	D->E->head->incidentFace = D->F->tail;
	D->E->head->next->twin = D->E->head;
	D->E->head->next->incidentFace = D->F->head;
	D->E->head->next->next->twin = D->E->head->next->next->next;
	D->E->head->next->next->incidentFace = D->F->tail;
	D->E->head->next->next->next->twin = D->E->head->next->next;
	D->E->head->next->next->next->incidentFace = D->F->head;
	D->E->head->next->next->next->next->twin = D->E->head->next->next->next->next->next;
	D->E->head->next->next->next->next->incidentFace = D->F->tail;
	D->E->head->next->next->next->next->next->twin = D->E->head->next->next->next->next;
	D->E->head->next->next->next->next->next->incidentFace = D->F->head;
	D->E->head->next->next->next->next->next->next->twin = D->E->head->next->next->next->next->next->next->next;
	D->E->head->next->next->next->next->next->next->incidentFace = D->F->tail;
	D->E->head->next->next->next->next->next->next->next->twin = D->E->head->next->next->next->next->next->next;
	D->E->head->next->next->next->next->next->next->next->incidentFace = D->F->head;
	D->F->tail->ne = D->V->head;
	D->F->tail->nw = D->V->head->next;
	D->F->tail->sw = D->V->head->next->next;
	D->F->tail->se = D->V->head->next->next->next;
	D->F->tail->nenw = D->E->head;
	D->F->tail->nwsw = D->E->head->next->next;
	D->F->tail->swse = D->E->head->next->next->next->next;
	D->F->tail->sene = D->E->head->next->next->next->next->next->next;
	D->F->tail->E = root->E;
	root->fnode = D->F->tail;
	struct Node* head = root;
	struct Node* tail = root;
	while (head) {
		struct Node* v = head;
		if (v->ne) {
			int xmid = (v->xmin + v->xmax) / 2;
			int ymid = (v->ymin + v->ymax) / 2;
			struct VertexNode* m = insertVertexNode(D->V, 0);
			if (!m) {
				return NULL;
			}
			m->v->x = xmid;
			m->v->y = ymid;
			struct HalfEdgeNode* nm = insertHalfEdgeNode(D->E, 0);
			if (!nm) {
				return NULL;
			}
			struct HalfEdgeNode* me = insertHalfEdgeNode(D->E, 0);
			if (!me) {
				return NULL;
			}
			struct HalfEdgeNode* wm = insertHalfEdgeNode(D->E, 0);
			if (!wm) {
				return NULL;
			}
			struct HalfEdgeNode* mn = insertHalfEdgeNode(D->E, 0);
			if (!mn) {
				return NULL;
			}
			struct HalfEdgeNode* sm = insertHalfEdgeNode(D->E, 0);
			if (!sm) {
				return NULL;
			}
			struct HalfEdgeNode* mw = insertHalfEdgeNode(D->E, 0);
			if (!mw) {
				return NULL;
			}
			struct HalfEdgeNode* em = insertHalfEdgeNode(D->E, 0);
			if (!em) {
				return NULL;
			}
			struct HalfEdgeNode* ms = insertHalfEdgeNode(D->E, 0);
			if (!ms) {
				return NULL;
			}
			struct FaceNode* ne = insertFaceNode(D->F, 0);
			if (!ne) {
				return NULL;
			}
			struct FaceNode* nw = insertFaceNode(D->F, 0);
			if (!nw) {
				return NULL;
			}
			struct FaceNode* sw = insertFaceNode(D->F, 0);
			if (!sw) {
				return NULL;
			}
			struct FaceNode* se = insertFaceNode(D->F, 0);
			if (!se) {
				return NULL;
			}
			struct VertexNode* n = NULL;
			struct HalfEdgeNode* nen = NULL;
			struct HalfEdgeNode* nnw = NULL;
			struct HalfEdgeNode* nwn = NULL;
			struct HalfEdgeNode* nne = NULL;
			if (v->fnode->n) {
				n = v->fnode->n;
				nen = v->fnode->nen;
				nnw = v->fnode->nnw;
				nwn = nnw->twin;
				nne = nen->twin;
			}
			else {
				n = insertVertexNode(D->V, 0);
				if (!n) {
					return NULL;
				}
				n->v->x = xmid;
				n->v->y = v->ymax;
				nen = insertHalfEdgeNode(D->E, 0);
				if (!nen) {
					return NULL;
				}
				nnw = insertHalfEdgeNode(D->E, 0);
				if (!nnw) {
					return NULL;
				}
				nwn = insertHalfEdgeNode(D->E, 0);
				if (!nwn) {
					return NULL;
				}
				nne = insertHalfEdgeNode(D->E, 0);
				if (!nne) {
					return NULL;
				}
			}
			struct VertexNode* w = NULL;
			struct HalfEdgeNode* nww = NULL;
			struct HalfEdgeNode* wsw = NULL;
			struct HalfEdgeNode* sww = NULL;
			struct HalfEdgeNode* wnw = NULL;
			if (v->fnode->w) {
				w = v->fnode->w;
				nww = v->fnode->nww;
				wsw = v->fnode->wsw;
				sww = wsw->twin;
				wnw = nww->twin;
			}
			else {
				w = insertVertexNode(D->V, 0);
				if (!w) {
					return NULL;
				}
				w->v->x = v->xmin;
				w->v->y = ymid;
				nww = insertHalfEdgeNode(D->E, 0);
				if (!nww) {
					return NULL;
				}
				wsw = insertHalfEdgeNode(D->E, 0);
				if (!wsw) {
					return NULL;
				}
				sww = insertHalfEdgeNode(D->E, 0);
				if (!sww) {
					return NULL;
				}
				wnw = insertHalfEdgeNode(D->E, 0);
				if (!wnw) {
					return NULL;
				}
			}
			struct VertexNode* s = NULL;
			struct HalfEdgeNode* sws = NULL;
			struct HalfEdgeNode* sse = NULL;
			struct HalfEdgeNode* ses = NULL;
			struct HalfEdgeNode* ssw = NULL;
			if (v->fnode->s) {
				s = v->fnode->s;
				sws = v->fnode->sws;
				sse = v->fnode->sse;
				ses = sse->twin;
				ssw = sws->twin;
			}
			else {
				s = insertVertexNode(D->V, 0);
				if (!s) {
					return NULL;
				}
				s->v->x = xmid;
				s->v->y = v->ymin;
				sws = insertHalfEdgeNode(D->E, 0);
				if (!sws) {
					return NULL;
				}
				sse = insertHalfEdgeNode(D->E, 0);
				if (!sse) {
					return NULL;
				}
				ses = insertHalfEdgeNode(D->E, 0);
				if (!ses) {
					return NULL;
				}
				ssw = insertHalfEdgeNode(D->E, 0);
				if (!ssw) {
					return NULL;
				}
			}
			struct VertexNode* e = NULL;
			struct HalfEdgeNode* see = NULL;
			struct HalfEdgeNode* ene = NULL;
			struct HalfEdgeNode* nee = NULL;
			struct HalfEdgeNode* ese = NULL;
			if (v->fnode->e) {
				e = v->fnode->e;
				see = v->fnode->see;
				ene = v->fnode->ene;
				nee = ene->twin;
				ese = see->twin;
			}
			else {
				e = insertVertexNode(D->V, 0);
				if (!e) {
					return NULL;
				}
				e->v->x = v->xmax;
				e->v->y = ymid;
				see = insertHalfEdgeNode(D->E, 0);
				if (!see) {
					return NULL;
				}
				ene = insertHalfEdgeNode(D->E, 0);
				if (!ene) {
					return NULL;
				}
				nee = insertHalfEdgeNode(D->E, 0);
				if (!nee) {
					return NULL;
				}
				ese = insertHalfEdgeNode(D->E, 0);
				if (!ese) {
					return NULL;
				}
			}
			v->ne->fnode = ne;
			v->nw->fnode = nw;
			v->sw->fnode = sw;
			v->se->fnode = se;
			tail->next = v->ne;
			v->ne->next = v->nw;
			v->nw->next = v->sw;
			v->sw->next = v->se;
			tail = v->se;
			m->v->incidentEdge = me->e;
			n->v->incidentEdge = nm->e;
			w->v->incidentEdge = wm->e;
			s->v->incidentEdge = sm->e;
			e->v->incidentEdge = em->e;
			v->fnode->ne->v->incidentEdge = nen->e;
			v->fnode->nw->v->incidentEdge = nww->e;
			v->fnode->sw->v->incidentEdge = sws->e;
			v->fnode->se->v->incidentEdge = see->e;
			nm->e->origin = n->v;
			nm->e->twin = mn->e;
			nm->e->prev = nen->e;
			nm->e->next = me->e;
			nm->e->incidentFace = ne->f;
			nm->twin = mn;
			nm->incidentFace = ne;
			me->e->origin = m->v;
			me->e->twin = em->e;
			me->e->prev = nm->e;
			me->e->next = ene->e;
			me->e->incidentFace = ne->f;
			me->twin = em;
			me->incidentFace = ne;
			wm->e->origin = w->v;
			wm->e->twin = mw->e;
			wm->e->prev = nww->e;
			wm->e->next = mn->e;
			wm->e->incidentFace = nw->f;
			wm->twin = mw;
			wm->incidentFace = nw;
			mn->e->origin = m->v;
			mn->e->twin = nm->e;
			mn->e->prev = wm->e;
			mn->e->next = nnw->e;
			mn->e->incidentFace = nw->f;
			mn->twin = nm;
			mn->incidentFace = nw;
			sm->e->origin = s->v;
			sm->e->twin = ms->e;
			sm->e->prev = sws->e;
			sm->e->next = mw->e;
			sm->e->incidentFace = sw->f;
			sm->twin = ms;
			sm->incidentFace = sw;
			mw->e->origin = m->v;
			mw->e->twin = wm->e;
			mw->e->prev = sm->e;
			mw->e->next = wsw->e;
			mw->e->incidentFace = sw->f;
			mw->twin = wm;
			mw->incidentFace = sw;
			em->e->origin = e->v;
			em->e->twin = me->e;
			em->e->prev = see->e;
			em->e->next = ms->e;
			em->e->incidentFace = se->f;
			em->twin = me;
			em->incidentFace = se;
			ms->e->origin = m->v;
			ms->e->twin = sm->e;
			ms->e->prev = em->e;
			ms->e->next = sse->e;
			ms->e->incidentFace = se->f;
			ms->twin = sm;
			ms->incidentFace = se;
			nen->e->origin = v->fnode->ne->v;
			nen->e->twin = nne->e;
			nen->e->prev = ene->e;
			nen->e->next = nm->e;
			nen->e->incidentFace = ne->f;
			nen->twin = nne;
			nen->incidentFace = ne;
			nnw->e->origin = n->v;
			nnw->e->twin = nwn->e;
			nnw->e->prev = mn->e;
			nnw->e->next = nww->e;
			nnw->e->incidentFace = nw->f;
			nnw->twin = nwn;
			nnw->incidentFace = nw;
			nwn->e->origin = v->fnode->nw->v;
			nwn->e->twin = nnw->e;
			if (!v->fnode->n) {
				if (!v->fnode->nenw->twin->incidentFace->f->outerComponent && !v->fnode->w && !v->fnode->nwsw->twin->incidentFace->f->outerComponent) {
					nwn->e->prev = wnw->e;
				}
				else {
					nwn->e->prev = v->fnode->nenw->twin->e->prev;
					nwn->e->prev->next = nwn->e;
				}
				nwn->e->next = nne->e;
				nwn->e->incidentFace = v->fnode->nenw->twin->e->incidentFace;
				nwn->incidentFace = v->fnode->nenw->twin->incidentFace;
			}
			nwn->twin = nnw;
			nne->e->origin = n->v;
			nne->e->twin = nen->e;
			if (!v->fnode->n) {
				nne->e->prev = nwn->e;
				if (!v->fnode->nenw->twin->incidentFace->f->outerComponent && !v->fnode->e && !v->fnode->sene->twin->incidentFace->f->outerComponent) {
					nne->e->next = nee->e;
				}
				else {
					nne->e->next = v->fnode->nenw->twin->e->next;
					nne->e->next->prev = nne->e;
				}
				nne->e->incidentFace = v->fnode->nenw->twin->e->incidentFace;
				nne->incidentFace = v->fnode->nenw->twin->incidentFace;
			}
			nne->twin = nen;
			nww->e->origin = v->fnode->nw->v;
			nww->e->twin = wnw->e;
			nww->e->prev = nnw->e;
			nww->e->next = wm->e;
			nww->e->incidentFace = nw->f;
			nww->twin = wnw;
			nww->incidentFace = nw;
			wsw->e->origin = w->v;
			wsw->e->twin = sww->e;
			wsw->e->prev = mw->e;
			wsw->e->next = sws->e;
			wsw->e->incidentFace = sw->f;
			wsw->twin = sww;
			wsw->incidentFace = sw;
			sww->e->origin = v->fnode->sw->v;
			sww->e->twin = wsw->e;
			if (!v->fnode->w) {
				if (!v->fnode->nwsw->twin->incidentFace->f->outerComponent && !v->fnode->s && !v->fnode->swse->twin->incidentFace->f->outerComponent) {
					sww->e->prev = ssw->e;
				}
				else {
					sww->e->prev = v->fnode->nwsw->twin->e->prev;
					sww->e->prev->next = sww->e;
				}
				sww->e->next = wnw->e;
				sww->e->incidentFace = v->fnode->nwsw->twin->e->incidentFace;
				sww->incidentFace = v->fnode->nwsw->twin->incidentFace;
			}
			sww->twin = wsw;
			wnw->e->origin = w->v;
			wnw->e->twin = nww->e;
			if (!v->fnode->w) {
				wnw->e->prev = sww->e;
				if (!v->fnode->nwsw->twin->incidentFace->f->outerComponent && !v->fnode->n && !v->fnode->nenw->twin->incidentFace->f->outerComponent) {
					wnw->e->next = nwn->e;
				}
				else {
					wnw->e->next = v->fnode->nwsw->twin->e->next;
					wnw->e->next->prev = wnw->e;
				}
				wnw->e->incidentFace = v->fnode->nwsw->twin->e->incidentFace;
				wnw->incidentFace = v->fnode->nwsw->twin->incidentFace;
			}
			wnw->twin = nww;
			sws->e->origin = v->fnode->sw->v;
			sws->e->twin = ssw->e;
			sws->e->prev = wsw->e;
			sws->e->next = sm->e;
			sws->e->incidentFace = sw->f;
			sws->twin = ssw;
			sws->incidentFace = sw;
			sse->e->origin = s->v;
			sse->e->twin = ses->e;
			sse->e->prev = ms->e;
			sse->e->next = see->e;
			sse->e->incidentFace = se->f;
			sse->twin = ses;
			sse->incidentFace = se;
			ses->e->origin = v->fnode->se->v;
			ses->e->twin = sse->e;
			if (!v->fnode->s) {
				if (!v->fnode->swse->twin->incidentFace->f->outerComponent && !v->fnode->e && !v->fnode->sene->twin->incidentFace->f->outerComponent) {
					ses->e->prev = ese->e;
				}
				else {
					ses->e->prev = v->fnode->swse->twin->e->prev;
					ses->e->prev->next = ses->e;
				}
				ses->e->next = ssw->e;
				ses->e->incidentFace = v->fnode->swse->twin->e->incidentFace;
				ses->incidentFace = v->fnode->swse->twin->incidentFace;
			}
			ses->twin = sse;
			ssw->e->origin = s->v;
			ssw->e->twin = sws->e;
			if (!v->fnode->s) {
				ssw->e->prev = ses->e;
				if (!v->fnode->swse->twin->incidentFace->f->outerComponent && !v->fnode->w && !v->fnode->nwsw->twin->incidentFace->f->outerComponent) {
					ssw->e->next = sww->e;
				}
				else {
					ssw->e->next = v->fnode->swse->twin->e->next;
					ssw->e->next->prev = ssw->e;
				}
				ssw->e->incidentFace = v->fnode->swse->twin->e->incidentFace;
				ssw->incidentFace = v->fnode->swse->twin->incidentFace;
			}
			ssw->twin = sws;
			see->e->origin = v->fnode->se->v;
			see->e->twin = ese->e;
			see->e->prev = sse->e;
			see->e->next = em->e;
			see->e->incidentFace = se->f;
			see->twin = ese;
			see->incidentFace = se;
			ene->e->origin = e->v;
			ene->e->twin = nee->e;
			ene->e->prev = me->e;
			ene->e->next = nen->e;
			ene->e->incidentFace = ne->f;
			ene->twin = nee;
			ene->incidentFace = ne;
			nee->e->origin = v->fnode->ne->v;
			nee->e->twin = ene->e;
			if (!v->fnode->e) {
				if (!v->fnode->sene->twin->incidentFace->f->outerComponent && !v->fnode->n && !v->fnode->nenw->twin->incidentFace->f->outerComponent) {
					nee->e->prev = nne->e;
				}
				else {
					nee->e->prev = v->fnode->sene->twin->e->prev;
					nee->e->prev->next = nee->e;
				}
				nee->e->next = ese->e;
				nee->e->incidentFace = v->fnode->sene->twin->e->incidentFace;
				nee->incidentFace = v->fnode->sene->twin->incidentFace;
			}
			nee->twin = ene;
			ese->e->origin = e->v;
			ese->e->twin = see->e;
			if (!v->fnode->e) {
				ese->e->prev = nee->e;
				if (!v->fnode->sene->twin->incidentFace->f->outerComponent && !v->fnode->s && !v->fnode->swse->twin->incidentFace->f->outerComponent) {
					ese->e->next = ses->e;
				}
				else {
					ese->e->next = v->fnode->sene->twin->e->next;
					ese->e->next->prev = ese->e;
				}
				ese->e->incidentFace = v->fnode->sene->twin->e->incidentFace;
				ese->incidentFace = v->fnode->sene->twin->incidentFace;
			}
			ese->twin = see;
			ne->f->outerComponent = nm->e;
			ne->ne = v->fnode->ne;
			ne->nw = n;
			ne->sw = m;
			ne->se = e;
			ne->nenw = nen;
			ne->nwsw = nm;
			ne->swse = me;
			ne->sene = ene;
			ne->E = v->ne->E;
			nw->f->outerComponent = wm->e;
			nw->ne = n;
			nw->nw = v->fnode->nw;
			nw->sw = w;
			nw->se = m;
			nw->nenw = nnw;
			nw->nwsw = nww;
			nw->swse = wm;
			nw->sene = mn;
			nw->E = v->nw->E;
			sw->f->outerComponent = sm->e;
			sw->ne = m;
			sw->nw = w;
			sw->sw = v->fnode->sw;
			sw->se = s;
			sw->nenw = mw;
			sw->nwsw = wsw;
			sw->swse = sws;
			sw->sene = sm;
			sw->E = v->sw->E;
			se->f->outerComponent = em->e;
			se->ne = e;
			se->nw = m;
			se->sw = s;
			se->se = v->fnode->se;
			se->nenw = em;
			se->nwsw = ms;
			se->swse = sse;
			se->sene = see;
			se->E = v->se->E;
			if (!v->fnode->n) {
				if (v->fnode->nenw->twin->incidentFace->f->outerComponent) {
					v->fnode->nenw->twin->incidentFace->f->outerComponent = nwn->e;
					v->fnode->nenw->twin->incidentFace->s = n;
					v->fnode->nenw->twin->incidentFace->swse = NULL;
					v->fnode->nenw->twin->incidentFace->sws = nwn;
					v->fnode->nenw->twin->incidentFace->sse = nne;
				}
				else {
					v->fnode->nenw->twin->incidentFace->f->innerComponents->head->e = nwn->e;
				}
			}
			if (!v->fnode->w) {
				if (v->fnode->nwsw->twin->incidentFace->f->outerComponent) {
					v->fnode->nwsw->twin->incidentFace->f->outerComponent = sww->e;
					v->fnode->nwsw->twin->incidentFace->e = w;
					v->fnode->nwsw->twin->incidentFace->sene = NULL;
					v->fnode->nwsw->twin->incidentFace->see = sww;
					v->fnode->nwsw->twin->incidentFace->ene = wnw;
				}
				else {
					v->fnode->nwsw->twin->incidentFace->f->innerComponents->head->e = sww->e;
				}
			}
			if (!v->fnode->s) {
				if (v->fnode->swse->twin->incidentFace->f->outerComponent) {
					v->fnode->swse->twin->incidentFace->f->outerComponent = ses->e;
					v->fnode->swse->twin->incidentFace->n = s;
					v->fnode->swse->twin->incidentFace->nenw = NULL;
					v->fnode->swse->twin->incidentFace->nen = ses;
					v->fnode->swse->twin->incidentFace->nnw = ssw;
				}
				else {
					v->fnode->swse->twin->incidentFace->f->innerComponents->head->e = ses->e;
				}
			}
			if (!v->fnode->e) {
				if (v->fnode->sene->twin->incidentFace->f->outerComponent) {
					v->fnode->sene->twin->incidentFace->f->outerComponent = nee->e;
					v->fnode->sene->twin->incidentFace->w = e;
					v->fnode->sene->twin->incidentFace->nwsw = NULL;
					v->fnode->sene->twin->incidentFace->nww = nee;
					v->fnode->sene->twin->incidentFace->wsw = ese;
				}
				else {
					v->fnode->sene->twin->incidentFace->f->innerComponents->head->e = nee->e;
				}
			}
			if (!v->fnode->n) {
				removeHalfEdgeNode(D->E, v->fnode->nenw->twin);
				removeHalfEdgeNode(D->E, v->fnode->nenw);
			}
			if (!v->fnode->w) {
				removeHalfEdgeNode(D->E, v->fnode->nwsw->twin);
				removeHalfEdgeNode(D->E, v->fnode->nwsw);
			}
			if (!v->fnode->s) {
				removeHalfEdgeNode(D->E, v->fnode->swse->twin);
				removeHalfEdgeNode(D->E, v->fnode->swse);
			}
			if (!v->fnode->e) {
				removeHalfEdgeNode(D->E, v->fnode->sene->twin);
				removeHalfEdgeNode(D->E, v->fnode->sene);
			}
			removeFaceNode(D->F, v->fnode);
		}
		head = v->next;
		v->next = NULL;
	}
	struct HalfEdgeNode* enode = D->E->head;
	while (enode) {
		enode->twin = NULL;
		enode->incidentFace = NULL;
		enode = enode->next;
	}
	return D;
}

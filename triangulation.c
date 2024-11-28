#include "quadtree.h"

int triangulation(struct DCEL* D) {
	int size = D->F->size;
	struct FaceNode* fnode = D->F->head->next;
	for (int i = 1; i < size; i++) {
		int flag = 1;
		struct HalfEdgeNode* enode = fnode->E->head;
		while (enode) {
			if (neswDiagonal(fnode, enode->e)) {
				flag = 0;
				struct HalfEdgeNode* nesw = insertHalfEdgeNode(D->E, 0);
				if (!nesw) {
					return 1;
				}
				struct HalfEdgeNode* swne = insertHalfEdgeNode(D->E, 0);
				if (!swne) {
					return 1;
				}
				struct FaceNode* neswse = insertFaceNode(D->F, 0);
				if (!neswse) {
					return 1;
				}
				struct FaceNode* swnenw = insertFaceNode(D->F, 0);
				if (!swnenw) {
					return 1;
				}
				nesw->e->origin = fnode->ne->v;
				nesw->e->twin = swne->e;
				nesw->e->prev = fnode->sene->e;
				nesw->e->next = fnode->swse->e;
				nesw->e->incidentFace = neswse->f;
				swne->e->origin = fnode->sw->v;
				swne->e->twin = nesw->e;
				swne->e->prev = fnode->nwsw->e;
				swne->e->next = fnode->nenw->e;
				swne->e->incidentFace = swnenw->f;
				fnode->nenw->e->prev = swne->e;
				fnode->nenw->e->incidentFace = swnenw->f;
				fnode->nwsw->e->next = swne->e;
				fnode->nwsw->e->incidentFace = swnenw->f;
				fnode->swse->e->prev = nesw->e;
				fnode->swse->e->incidentFace = neswse->f;
				fnode->sene->e->next = nesw->e;
				fnode->sene->e->incidentFace = neswse->f;
				neswse->f->outerComponent = nesw->e;
				swnenw->f->outerComponent = swne->e;
				break;
			}
			else if (nwseDiagonal(fnode, enode->e)) {
				flag = 0;
				struct HalfEdgeNode* nwse = insertHalfEdgeNode(D->E, 0);
				if (!nwse) {
					return 1;
				}
				struct HalfEdgeNode* senw = insertHalfEdgeNode(D->E, 0);
				if (!senw) {
					return 1;
				}
				struct FaceNode* nwsene = insertFaceNode(D->F, 0);
				if (!nwsene) {
					return 1;
				}
				struct FaceNode* senwsw = insertFaceNode(D->F, 0);
				if (!senwsw) {
					return 1;
				}
				nwse->e->origin = fnode->nw->v;
				nwse->e->twin = senw->e;
				nwse->e->prev = fnode->nenw->e;
				nwse->e->next = fnode->sene->e;
				nwse->e->incidentFace = nwsene->f;
				senw->e->origin = fnode->se->v;
				senw->e->twin = nwse->e;
				senw->e->prev = fnode->swse->e;
				senw->e->next = fnode->nwsw->e;
				senw->e->incidentFace = senwsw->f;
				fnode->nenw->e->next = nwse->e;
				fnode->nenw->e->incidentFace = nwsene->f;
				fnode->nwsw->e->prev = senw->e;
				fnode->nwsw->e->incidentFace = senwsw->f;
				fnode->swse->e->next = senw->e;
				fnode->swse->e->incidentFace = senwsw->f;
				fnode->sene->e->prev = nwse->e;
				fnode->sene->e->incidentFace = nwsene->f;
				nwsene->f->outerComponent = nwse->e;
				senwsw->f->outerComponent = senw->e;
				break;
			}
			enode = enode->next;
		}
		if (flag) {
			if (!fnode->n && !fnode->w && !fnode->s && !fnode->e) {
				struct HalfEdgeNode* nesw = insertHalfEdgeNode(D->E, 0);
				if (!nesw) {
					return 1;
				}
				struct HalfEdgeNode* swne = insertHalfEdgeNode(D->E, 0);
				if (!swne) {
					return 1;
				}
				struct FaceNode* neswse = insertFaceNode(D->F, 0);
				if (!neswse) {
					return 1;
				}
				struct FaceNode* swnenw = insertFaceNode(D->F, 0);
				if (!swnenw) {
					return 1;
				}
				nesw->e->origin = fnode->ne->v;
				nesw->e->twin = swne->e;
				nesw->e->prev = fnode->sene->e;
				nesw->e->next = fnode->swse->e;
				nesw->e->incidentFace = neswse->f;
				swne->e->origin = fnode->sw->v;
				swne->e->twin = nesw->e;
				swne->e->prev = fnode->nwsw->e;
				swne->e->next = fnode->nenw->e;
				swne->e->incidentFace = swnenw->f;
				fnode->nenw->e->prev = swne->e;
				fnode->nenw->e->incidentFace = swnenw->f;
				fnode->nwsw->e->next = swne->e;
				fnode->nwsw->e->incidentFace = swnenw->f;
				fnode->swse->e->prev = nesw->e;
				fnode->swse->e->incidentFace = neswse->f;
				fnode->sene->e->next = nesw->e;
				fnode->sene->e->incidentFace = neswse->f;
				neswse->f->outerComponent = nesw->e;
				swnenw->f->outerComponent = swne->e;
			}
			else {
				int xmid = (fnode->ne->v->x + fnode->nw->v->x) / 2;
				int ymid = (fnode->ne->v->y + fnode->se->v->y) / 2;
				struct VertexNode* m = insertVertexNode(D->V, 0);
				if (!m) {
					return 1;
				}
				m->v->x = xmid;
				m->v->y = ymid;
				struct HalfEdgeNode* mne = insertHalfEdgeNode(D->E, 0);
				if (!mne) {
					return 1;
				}
				struct HalfEdgeNode* nem = insertHalfEdgeNode(D->E, 0);
				if (!nem) {
					return 1;
				}
				struct HalfEdgeNode* mnw = insertHalfEdgeNode(D->E, 0);
				if (!mnw) {
					return 1;
				}
				struct HalfEdgeNode* nwm = insertHalfEdgeNode(D->E, 0);
				if (!nwm) {
					return 1;
				}
				struct HalfEdgeNode* msw = insertHalfEdgeNode(D->E, 0);
				if (!msw) {
					return 1;
				}
				struct HalfEdgeNode* swm = insertHalfEdgeNode(D->E, 0);
				if (!swm) {
					return 1;
				}
				struct HalfEdgeNode* mse = insertHalfEdgeNode(D->E, 0);
				if (!mse) {
					return 1;
				}
				struct HalfEdgeNode* sem = insertHalfEdgeNode(D->E, 0);
				if (!sem) {
					return 1;
				}
				struct HalfEdgeNode* mn = NULL;
				struct HalfEdgeNode* nm = NULL;
				struct FaceNode* mnenw = NULL;
				struct FaceNode* mnen = NULL;
				struct FaceNode* mnnw = NULL;
				if (fnode->n) {
					mn = insertHalfEdgeNode(D->E, 0);
					if (!mn) {
						return 1;
					}
					nm = insertHalfEdgeNode(D->E, 0);
					if (!nm) {
						return 1;
					}
					mnen = insertFaceNode(D->F, 0);
					if (!mnen) {
						return 1;
					}
					mnnw = insertFaceNode(D->F, 0);
					if (!mnnw) {
						return 1;
					}
				}
				else {
					mnenw = insertFaceNode(D->F, 0);
					if (!mnenw) {
						return 1;
					}
				}
				struct HalfEdgeNode* mw = NULL;
				struct HalfEdgeNode* wm = NULL;
				struct FaceNode* mnwsw = NULL;
				struct FaceNode* mnww = NULL;
				struct FaceNode* mwsw = NULL;
				if (fnode->w) {
					mw = insertHalfEdgeNode(D->E, 0);
					if (!mw) {
						return 1;
					}
					wm = insertHalfEdgeNode(D->E, 0);
					if (!wm) {
						return 1;
					}
					mnww = insertFaceNode(D->F, 0);
					if (!mnww) {
						return 1;
					}
					mwsw = insertFaceNode(D->F, 0);
					if (!mwsw) {
						return 1;
					}
				}
				else {
					mnwsw = insertFaceNode(D->F, 0);
					if (!mnwsw) {
						return 1;
					}
				}
				struct HalfEdgeNode* ms = NULL;
				struct HalfEdgeNode* sm = NULL;
				struct FaceNode* mswse = NULL;
				struct FaceNode* msws = NULL;
				struct FaceNode* msse = NULL;
				if (fnode->s) {
					ms = insertHalfEdgeNode(D->E, 0);
					if (!ms) {
						return 1;
					}
					sm = insertHalfEdgeNode(D->E, 0);
					if (!sm) {
						return 1;
					}
					msws = insertFaceNode(D->F, 0);
					if (!msws) {
						return 1;
					}
					msse = insertFaceNode(D->F, 0);
					if (!msse) {
						return 1;
					}
				}
				else {
					mswse = insertFaceNode(D->F, 0);
					if (!mswse) {
						return 1;
					}
				}
				struct HalfEdgeNode* me = NULL;
				struct HalfEdgeNode* em = NULL;
				struct FaceNode* msene = NULL;
				struct FaceNode* msee = NULL;
				struct FaceNode* mene = NULL;
				if (fnode->e) {
					me = insertHalfEdgeNode(D->E, 0);
					if (!me) {
						return 1;
					}
					em = insertHalfEdgeNode(D->E, 0);
					if (!em) {
						return 1;
					}
					msee = insertFaceNode(D->F, 0);
					if (!msee) {
						return 1;
					}
					mene = insertFaceNode(D->F, 0);
					if (!mene) {
						return 1;
					}
				}
				else {
					msene = insertFaceNode(D->F, 0);
					if (!msene) {
						return 1;
					}
				}
				m->v->incidentEdge = mne->e;
				mne->e->origin = m->v;
				mne->e->twin = nem->e;
				nem->e->origin = fnode->ne->v;
				nem->e->twin = mne->e;
				mnw->e->origin = m->v;
				mnw->e->twin = nwm->e;
				nwm->e->origin = fnode->nw->v;
				nwm->e->twin = mnw->e;
				msw->e->origin = m->v;
				msw->e->twin = swm->e;
				swm->e->origin = fnode->sw->v;
				swm->e->twin = msw->e;
				mse->e->origin = m->v;
				mse->e->twin = sem->e;
				sem->e->origin = fnode->se->v;
				sem->e->twin = mse->e;
				if (fnode->n) {
					mne->e->prev = nm->e;
					mne->e->next = fnode->nen->e;
					mne->e->incidentFace = mnen->f;
					nwm->e->prev = fnode->nnw->e;
					nwm->e->next = mn->e;
					nwm->e->incidentFace = mnnw->f;
					mn->e->origin = m->v;
					mn->e->twin = nm->e;
					mn->e->prev = nwm->e;
					mn->e->next = fnode->nnw->e;
					mn->e->incidentFace = mnnw->f;
					nm->e->origin = fnode->n->v;
					nm->e->twin = mn->e;
					nm->e->prev = fnode->nen->e;
					nm->e->next = mne->e;
					nm->e->incidentFace = mnen->f;
					fnode->nen->e->prev = mne->e;
					fnode->nen->e->next = nm->e;
					fnode->nen->e->incidentFace = mnen->f;
					fnode->nnw->e->prev = mn->e;
					fnode->nnw->e->next = nwm->e;
					fnode->nnw->e->incidentFace = mnnw->f;
					mnen->f->outerComponent = mne->e;
					mnnw->f->outerComponent = nwm->e;
				}
				else {
					mne->e->prev = nwm->e;
					mne->e->next = fnode->nenw->e;
					mne->e->incidentFace = mnenw->f;
					nwm->e->prev = fnode->nenw->e;
					nwm->e->next = mne->e;
					nwm->e->incidentFace = mnenw->f;
					fnode->nenw->e->prev = mne->e;
					fnode->nenw->e->next = nwm->e;
					fnode->nenw->e->incidentFace = mnenw->f;
					mnenw->f->outerComponent = mne->e;
				}
				if (fnode->w) {
					mnw->e->prev = wm->e;
					mnw->e->next = fnode->nww->e;
					mnw->e->incidentFace = mnww->f;
					swm->e->prev = fnode->wsw->e;
					swm->e->next = mw->e;
					swm->e->incidentFace = mwsw->f;
					mw->e->origin = m->v;
					mw->e->twin = wm->e;
					mw->e->prev = swm->e;
					mw->e->next = fnode->wsw->e;
					mw->e->incidentFace = mwsw->f;
					wm->e->origin = fnode->w->v;
					wm->e->twin = mw->e;
					wm->e->prev = fnode->nww->e;
					wm->e->next = mnw->e;
					wm->e->incidentFace = mnww->f;
					fnode->nww->e->prev = mnw->e;
					fnode->nww->e->next = wm->e;
					fnode->nww->e->incidentFace = mnww->f;
					fnode->wsw->e->prev = mw->e;
					fnode->wsw->e->next = swm->e;
					fnode->wsw->e->incidentFace = mwsw->f;
					mnww->f->outerComponent = mnw->e;
					mwsw->f->outerComponent = swm->e;
				}
				else {
					mnw->e->prev = swm->e;
					mnw->e->next = fnode->nwsw->e;
					mnw->e->incidentFace = mnwsw->f;
					swm->e->prev = fnode->nwsw->e;
					swm->e->next = mnw->e;
					swm->e->incidentFace = mnwsw->f;
					fnode->nwsw->e->prev = mnw->e;
					fnode->nwsw->e->next = swm->e;
					fnode->nwsw->e->incidentFace = mnwsw->f;
					mnwsw->f->outerComponent = mnw->e;
				}
				if (fnode->s) {
					msw->e->prev = sm->e;
					msw->e->next = fnode->sws->e;
					msw->e->incidentFace = msws->f;
					sem->e->prev = fnode->sse->e;
					sem->e->next = ms->e;
					sem->e->incidentFace = msse->f;
					ms->e->origin = m->v;
					ms->e->twin = sm->e;
					ms->e->prev = sem->e;
					ms->e->next = fnode->sse->e;
					ms->e->incidentFace = msse->f;
					sm->e->origin = fnode->s->v;
					sm->e->twin = ms->e;
					sm->e->prev = fnode->sws->e;
					sm->e->next = msw->e;
					sm->e->incidentFace = msws->f;
					fnode->sws->e->prev = msw->e;
					fnode->sws->e->next = sm->e;
					fnode->sws->e->incidentFace = msws->f;
					fnode->sse->e->prev = ms->e;
					fnode->sse->e->next = sem->e;
					fnode->sse->e->incidentFace = msse->f;
					msws->f->outerComponent = msw->e;
					msse->f->outerComponent = sem->e;
				}
				else {
					msw->e->prev = sem->e;
					msw->e->next = fnode->swse->e;
					msw->e->incidentFace = mswse->f;
					sem->e->prev = fnode->swse->e;
					sem->e->next = msw->e;
					sem->e->incidentFace = mswse->f;
					fnode->swse->e->prev = msw->e;
					fnode->swse->e->next = sem->e;
					fnode->swse->e->incidentFace = mswse->f;
					mswse->f->outerComponent = msw->e;
				}
				if (fnode->e) {
					nem->e->prev = fnode->ene->e;
					nem->e->next = me->e;
					nem->e->incidentFace = mene->f;
					mse->e->prev = em->e;
					mse->e->next = fnode->see->e;
					mse->e->incidentFace = msee->f;
					me->e->origin = m->v;
					me->e->twin = em->e;
					me->e->prev = nem->e;
					me->e->next = fnode->ene->e;
					me->e->incidentFace = mene->f;
					em->e->origin = fnode->e->v;
					em->e->twin = me->e;
					em->e->prev = fnode->see->e;
					em->e->next = mse->e;
					em->e->incidentFace = msee->f;
					fnode->see->e->prev = mse->e;
					fnode->see->e->next = em->e;
					fnode->see->e->incidentFace = msee->f;
					fnode->ene->e->prev = me->e;
					fnode->ene->e->next = nem->e;
					fnode->ene->e->incidentFace = mene->f;
					msee->f->outerComponent = mse->e;
					mene->f->outerComponent = nem->e;
				}
				else {
					nem->e->prev = fnode->sene->e;
					nem->e->next = mse->e;
					nem->e->incidentFace = msene->f;
					mse->e->prev = nem->e;
					mse->e->next = fnode->sene->e;
					mse->e->incidentFace = msene->f;
					fnode->sene->e->prev = mse->e;
					fnode->sene->e->next = nem->e;
					fnode->sene->e->incidentFace = msene->f;
					msene->f->outerComponent = mse->e;
				}
			}
		}
		fnode = fnode->next;
		removeFaceNode(D->F, fnode->prev);
	}
	return 0;
}

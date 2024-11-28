#pragma once
#include "DCEL.h"

struct Node {
	int xmin;
	int xmax;
	int ymin;
	int ymax;
	struct Node* parent;
	struct Node* ne;
	struct Node* nw;
	struct Node* sw;
	struct Node* se;
	struct Node* next;
	struct FaceNode* fnode;
	struct HalfEdgeList* E;
	int inList;
};

struct Node* mallocNode();
void freeQuadtree(struct Node* v);
struct Node* quadtree(struct HalfEdgeList* E, int xmin, int xmax, int ymin, int ymax);
int balanceQuadtree(struct Node* root);
void getLeaves(struct Node** head, struct Node** tail, struct Node* v);
struct Node* northNeighbor(struct Node* v);
struct Node* westNeighbor(struct Node* v);
struct Node* southNeighbor(struct Node* v);
struct Node* eastNeighbor(struct Node* v);
struct DCEL* generateDCELFromBalancedQuadtree(struct Node* root);
int triangulation(struct DCEL* D);

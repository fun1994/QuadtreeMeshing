#pragma once
#include <stdio.h>
#include <stdlib.h>

struct HalfEdge;
struct Face;
struct HalfEdgeList;

struct Vertex {
	int x;
	int y;
	struct HalfEdge* incidentEdge;
};

struct HalfEdge {
	struct Vertex* origin;
	struct HalfEdge* twin;
	struct HalfEdge* prev;
	struct HalfEdge* next;
	struct Face* incidentFace;
};

struct Face {
	struct HalfEdge* outerComponent;
	struct HalfEdgeList* innerComponents;
};

struct VertexNode {
	struct Vertex* v;
	struct VertexNode* prev;
	struct VertexNode* next;
};

struct HalfEdgeNode {
	struct HalfEdge* e;
	struct HalfEdgeNode* prev;
	struct HalfEdgeNode* next;
	struct HalfEdgeNode* twin;
	struct FaceNode* incidentFace;
};

struct FaceNode {
	struct Face* f;
	struct FaceNode* prev;
	struct FaceNode* next;
	struct VertexNode* ne;
	struct VertexNode* nw;
	struct VertexNode* sw;
	struct VertexNode* se;
	struct VertexNode* n;
	struct VertexNode* w;
	struct VertexNode* s;
	struct VertexNode* e;
	struct HalfEdgeNode* nenw;
	struct HalfEdgeNode* nwsw;
	struct HalfEdgeNode* swse;
	struct HalfEdgeNode* sene;
	struct HalfEdgeNode* nen;
	struct HalfEdgeNode* nnw;
	struct HalfEdgeNode* nww;
	struct HalfEdgeNode* wsw;
	struct HalfEdgeNode* sws;
	struct HalfEdgeNode* sse;
	struct HalfEdgeNode* see;
	struct HalfEdgeNode* ene;
	struct HalfEdgeList* E;
};

struct VertexList {
	int size;
	struct VertexNode* head;
	struct VertexNode* tail;
};

struct HalfEdgeList {
	int size;
	struct HalfEdgeNode* head;
	struct HalfEdgeNode* tail;
};

struct FaceList {
	int size;
	struct FaceNode* head;
	struct FaceNode* tail;
};

struct DCEL {
	struct VertexList* V;
	struct HalfEdgeList* E;
	struct FaceList* F;
};

struct Vertex* mallocVertex();
struct HalfEdge* mallocHalfEdge();
struct Face* mallocFace();
struct VertexNode* mallocVertexNode();
struct HalfEdgeNode* mallocHalfEdgeNode();
struct FaceNode* mallocFaceNode();
struct VertexList* mallocVertexList();
struct HalfEdgeList* mallocHalfEdgeList();
struct FaceList* mallocFaceList();
struct DCEL* mallocDCEL(struct Vertex*** V, struct HalfEdge*** E, struct Face*** F, int Vsize, int Esize, int Fsize, int* innerComponentsSize);
struct DCEL* generateDCEL(int Vsize, int Esize, int Fsize, int* innerComponentsSize, int* x, int* y, int* incidentEdge, int* origin, int* twin, int* prev, int* next, int* incidentFace, int* outerComponent, int** innerComponents);
int intersect(struct HalfEdge* e, int xmin, int xmax, int ymin, int ymax);
int inSquare(int x, int y, int xmin, int xmax, int ymin, int ymax);
int neswDiagonal(struct FaceNode* fnode, struct HalfEdge* e);
int nwseDiagonal(struct FaceNode* fnode, struct HalfEdge* e);
int onSegment(int x, int y, int x0, int y0, int x1, int y1);
struct VertexNode* insertVertexNode(struct VertexList* V, int v);
struct HalfEdgeNode* insertHalfEdgeNode(struct HalfEdgeList* E, int e);
struct FaceNode* insertFaceNode(struct FaceList* F, int f);
int printDCEL(struct DCEL* D);
int printVertexIndex(struct VertexList* V, struct Vertex* v);
int printHalfEdgeIndex(struct HalfEdgeList* E, struct HalfEdge* e);
int printFaceIndex(struct FaceList* F, struct Face* f);
int printVertexNodeIndex(struct VertexList* V, struct VertexNode* vnode);
int printHalfEdgeNodeIndex(struct HalfEdgeList* E, struct HalfEdgeNode* enode);
int printFaceNodeIndex(struct FaceList* F, struct FaceNode* fnode);
void removeHalfEdgeNode(struct HalfEdgeList* E, struct HalfEdgeNode* enode);
void removeFaceNode(struct FaceList* F, struct FaceNode* fnode);
void freeDCEL(struct DCEL* D);
int saveDCEL(struct DCEL* D);
int saveVertexIndex(FILE* file, struct VertexList* V, struct Vertex* v);
int saveHalfEdgeIndex(FILE* file, struct HalfEdgeList* E, struct HalfEdge* e);

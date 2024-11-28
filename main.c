#include "quadtree.h"

struct DCEL* demo1(int* xmin, int* xmax, int* ymin, int* ymax) {
	int Vsize = 6;
	int Esize = 12;
	int Fsize = 2;
	int innerComponentsSize[2] = { 1,0 };
	int x[6] = { 1,1,2,1,3,3 };
	int y[6] = { 4,3,2,1,1,2 };
	int incidentEdge[6] = { 0,2,4,6,8,10 };
	int origin[12] = { 0,1,1,2,2,3,3,4,4,5,5,0 };
	int twin[12] = { 1,0,3,2,5,4,7,6,9,8,11,10 };
	int prev[12] = { 10,3,0,5,2,7,4,9,6,11,8,1 };
	int next[12] = { 2,11,4,1,6,3,8,5,10,7,0,9 };
	int incidentFace[12] = { 1,0,1,0,1,0,1,0,1,0,1,0 };
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
	*xmin = 0;
	*xmax = 8;
	*ymin = 0;
	*ymax = 8;
	return D;
}

struct DCEL* demo2(int* xmin, int* xmax, int* ymin, int* ymax) {
	int Vsize = 26;
	int Esize = 52;
	int Fsize = 3;
	int innerComponentsSize[3] = { 2,0,0 };
	int x[26] = { 2,2,6,8,8,6,4,4,12,12,14,14,20,20,22,22,24,24,22,20,18,18,20,20,14,14 };
	int y[26] = { 24,14,14,12,18,16,16,24,18,12,12,14,14,8,8,18,20,22,24,24,22,20,18,16,16,18 };
	int incidentEdge[26] = { 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50 };
	int origin[52] = { 0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,0,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15,16,16,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24,25,25,8 };
	int twin[52] = { 1,0,3,2,5,4,7,6,9,8,11,10,13,12,15,14,17,16,19,18,21,20,23,22,25,24,27,26,29,28,31,30,33,32,35,34,37,36,39,38,41,40,43,42,45,44,47,46,49,48,51,50 };
	int prev[52] = { 14,3,0,5,2,7,4,9,6,11,8,13,10,15,12,1,50,19,16,21,18,23,20,25,22,27,24,29,26,31,28,33,30,35,32,37,34,39,36,41,38,43,40,45,42,47,44,49,46,51,48,17 };
	int next[52] = { 2,15,4,1,6,3,8,5,10,7,12,9,14,11,0,13,18,51,20,17,22,19,24,21,26,23,28,25,30,27,32,29,34,31,36,33,38,35,40,37,42,39,44,41,46,43,48,45,50,47,16,49 };
	int incidentFace[52] = { 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0 };
	int outerComponent[3] = { -1,0,16 };
	int** innerComponents = malloc(3 * sizeof(int*));
	if (!innerComponents) {
		return NULL;
	}
	innerComponents[0] = malloc(2 * sizeof(int));
	if (!innerComponents[0]) {
		return NULL;
	}
	innerComponents[0][0] = 1;
	innerComponents[0][1] = 17;
	innerComponents[1] = NULL;
	innerComponents[2] = NULL;
	struct DCEL* D = generateDCEL(Vsize, Esize, Fsize, innerComponentsSize, x, y, incidentEdge, origin, twin, prev, next, incidentFace, outerComponent, innerComponents);
	free(innerComponents[0]);
	free(innerComponents);
	if (!D) {
		return NULL;
	}
	*xmin = 0;
	*xmax = 32;
	*ymin = 0;
	*ymax = 32;
	return D;
}

int main() {
	int xmin, xmax, ymin, ymax;
	struct DCEL* D = demo1(&xmin, &xmax, &ymin, &ymax);
	if (!D) {
		return 1;
	}
	struct Node* root = quadtree(D->E, xmin, xmax, ymin, ymax);
	if (!root) {
		return 1;
	}
	int flag = balanceQuadtree(root);
	if (flag) {
		return 1;
	}
	struct DCEL* M = generateDCELFromBalancedQuadtree(root);
	if (!M) {
		return 1;
	}
	flag = triangulation(M);
	if (flag) {
		return 1;
	}
	freeDCEL(D);
	freeQuadtree(root);
	freeDCEL(M);
	return 0;
}

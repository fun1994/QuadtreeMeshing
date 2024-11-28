#include "DCEL.h"

struct Face* mallocFace() {
	struct Face* f = malloc(sizeof(struct Face));
	if (!f) {
		return NULL;
	}
	f->outerComponent = NULL;
	f->innerComponents = NULL;
	return f;
}

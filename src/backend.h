#include "backend_direct.h"

void backend_init(mrb_state *mrb, struct RClass *l);

typedef struct backend_S backend_t;

extern backend_t *backend_direct_new(void);

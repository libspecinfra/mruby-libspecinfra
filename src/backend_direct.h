#include "mruby/data.h"
#include "backend.h"

extern backend_t *backend_direct_new(void);

void backend_direct_init(mrb_state *mrb, struct RClass *b);

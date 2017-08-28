#include "backend.h"

extern backend_t *backend_ssh_new(char *s);

void backend_ssh_init(mrb_state *mrb, struct RClass *b);

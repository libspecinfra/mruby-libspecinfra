#include "mruby/data.h"

const static struct mrb_data_type mrb_backend_type = { "Backend", mrb_free };
void backend_direct_init(mrb_state *mrb, struct RClass *b);

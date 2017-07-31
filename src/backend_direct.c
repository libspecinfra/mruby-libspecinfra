#include "mruby.h"

void backend_direct_init(mrb_state *mrb, struct RClass *b) {
    struct RClass *d = mrb_define_class_under(mrb, b, "Direct", mrb->object_class);
}




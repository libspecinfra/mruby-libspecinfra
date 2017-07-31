#include "mruby.h"
#include "backend.h"

static mrb_value backend_direct_initialize(mrb_state *mrb, mrb_value self) {
    backend_t *b = backend_direct_new();
    DATA_TYPE(self) = &mrb_backend_type;
    DATA_PTR(self) = b;
    return self;
}

void backend_direct_init(mrb_state *mrb, struct RClass *b) {
    struct RClass *d = mrb_define_class_under(mrb, b, "Direct", mrb->object_class);
    mrb_define_method(mrb, d, "initialize", backend_direct_initialize, MRB_ARGS_NONE());
}

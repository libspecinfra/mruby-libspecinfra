#include "mruby.h"
#include "mruby/data.h"
#include "resource_file.h"

static mrb_value resource_file_mode_(mrb_state *mrb, mrb_value self) {
    uint32_t m = resource_file_mode(DATA_PTR(self));
    return mrb_fixnum_value(m);
}

static mrb_value resource_file_exist_(mrb_state *mrb, mrb_value self) {
    uint32_t m = resource_file_exist(DATA_PTR(self));
    return mrb_bool_value(m);
}

void resource_file_init(mrb_state *mrb, struct RClass *r) {
    struct RClass *f = mrb_define_class_under(mrb, r, "File", mrb->object_class);
    mrb_define_method(mrb, f, "mode", resource_file_mode_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "exist", resource_file_exist_, MRB_ARGS_NONE());
}

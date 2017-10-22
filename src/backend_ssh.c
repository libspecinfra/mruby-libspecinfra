#include "mruby.h"
#include "backend_ssh.h"

static mrb_value backend_ssh_initialize(mrb_state *mrb, mrb_value self) {
    char *str;
    mrb_int len;
    backend_t *b;

    mrb_get_args(mrb, "s", &str, &len);
    b = backend_ssh_new(str);
    DATA_TYPE(self) = &mrb_backend_type;
    DATA_PTR(self) = b;
    return self;
}

void backend_ssh_init(mrb_state *mrb, struct RClass *b) {
    struct RClass *d;

    d = mrb_define_class_under(mrb, b, "SSH", mrb->object_class);
    mrb_define_method(mrb, d, "initialize", backend_ssh_initialize, MRB_ARGS_REQ(1));
}

#include "mruby.h"
#include "mruby/data.h"
#include "mruby/string.h"
#include "resource_service.h"

void resource_service_init(mrb_state *mrb, struct RClass *r) {
    struct RClass *f = mrb_define_class_under(mrb, r, "Service", mrb->object_class);

}

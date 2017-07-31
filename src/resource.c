#include "mruby.h"
#include "resource_file.h"

void resource_init(mrb_state *mrb, struct RClass *l)
{
    struct RClass *r = mrb_define_module_under(mrb, l, "Resource");
    resource_file_init(mrb, r);
}

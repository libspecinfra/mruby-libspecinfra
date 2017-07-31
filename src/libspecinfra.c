#include "mruby.h"
#include "backend.h"

void mrb_mruby_libspecinfra_gem_init(mrb_state *mrb)
{
    struct RClass *l = mrb_define_module(mrb, "Libspecinfra");
    backend_init(mrb, l);
}

void mrb_mruby_libspecinfra_gem_final(mrb_state *mrb)
{
}

#include "mruby.h"
#include "backend_direct.h"
#include "backend_ssh.h"

void backend_init(mrb_state *mrb, struct RClass *l)
{
    struct RClass *b = mrb_define_module_under(mrb, l, "Backend");
    backend_direct_init(mrb, b);
    backend_ssh_init(mrb, b);
}

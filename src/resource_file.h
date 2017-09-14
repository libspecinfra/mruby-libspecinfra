#include "mruby/data.h"

typedef struct resource_file_S resource_file_t;

const static struct mrb_data_type mrb_resource_file_type = { "File", mrb_free };

void resource_file_init(mrb_state *mrb, struct RClass *r);

extern uint32_t resource_file_mode(resource_file_t *f);
static mrb_value resource_file_mode_(mrb_state *mrb, mrb_value self);

extern uint32_t resource_file_exist(resource_file_t *f);
static mrb_value resource_file_exist_(mrb_state *mrb, mrb_value self);


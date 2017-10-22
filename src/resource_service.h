#include "mruby/data.h"

typedef struct resource_service_S resource_service_t;

const static struct mrb_data_type mrb_resource_service_type = { "Service", mrb_free };

void resource_service_init(mrb_state *mrb, struct RClass *r);

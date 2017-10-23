#include "mruby/data.h"

typedef struct resource_service_S resource_service_t;

const static struct mrb_data_type mrb_resource_service_type = { "Service", mrb_free };

void resource_service_init(mrb_state *mrb, struct RClass *r);

extern char *resource_service_error_description(resource_service_t *f);
mrb_value resource_service_error_description_(mrb_state *mrb, mrb_value self);

extern int32_t resource_service_is_running(resource_service_t *f);
mrb_value resource_service_is_running_(mrb_state *mrb, mrb_value self);

extern int32_t resource_service_is_enabled(resource_service_t *f);
mrb_value resource_service_is_enabled_(mrb_state *mrb, mrb_value self);

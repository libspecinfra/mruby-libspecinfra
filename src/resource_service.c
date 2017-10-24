#include "mruby.h"
#include "mruby/data.h"
#include "mruby/string.h"
#include "resource_service.h"

mrb_value resource_service_error_description_(mrb_state *mrb, mrb_value self) {
    mrb_value str;
    char *c;

    c = resource_service_error_description(DATA_PTR(self));
    str = mrb_str_buf_new(mrb, sizeof(c));
    return mrb_str_cat2(mrb, str, c);
}

mrb_value resource_service_is_running_(mrb_state *mrb, mrb_value self) {
    resource_service_t *f;
    int32_t m;

    f = DATA_PTR(self);
    m = resource_service_is_running(f);

    if ( m == 1 ) {
        return mrb_true_value();
    } else if ( m == 0 ) {
        return mrb_false_value();
    } else {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_service_error_description(f)
        );
    }
}

mrb_value resource_service_is_enabled_(mrb_state *mrb, mrb_value self) {
    resource_service_t *f;
    int32_t m;

    f = DATA_PTR(self);
    m = resource_service_is_enabled(f);

    if ( m == 1 ) {
        return mrb_true_value();
    } else if ( m == 0 ) {
        return mrb_false_value();
    } else {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_service_error_description(f)
        );
    }
}

mrb_value resource_service_enable_(mrb_state *mrb, mrb_value self) {
    resource_service_t *f;
    int32_t m;

    f = DATA_PTR(self);
    m = resource_service_enable(f);

    if ( m == 1 ) {
        return mrb_true_value();
    } else if ( m == 0 ) {
        return mrb_false_value();
    } else {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_service_error_description(f)
        );
    }
}

mrb_value resource_service_disable_(mrb_state *mrb, mrb_value self) {
    resource_service_t *f;
    int32_t m;

    f = DATA_PTR(self);
    m = resource_service_disable(f);

    if ( m == 1 ) {
        return mrb_true_value();
    } else if ( m == 0 ) {
        return mrb_false_value();
    } else {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_service_error_description(f)
        );
    }
}

mrb_value resource_service_reload_(mrb_state *mrb, mrb_value self) {
    resource_service_t *f;
    int32_t m;

    f = DATA_PTR(self);
    m = resource_service_reload(f);

    if ( m == 1 ) {
        return mrb_true_value();
    } else if ( m == 0 ) {
        return mrb_false_value();
    } else {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_service_error_description(f)
        );
    }
}

void resource_service_init(mrb_state *mrb, struct RClass *r) {
    struct RClass *f = mrb_define_class_under(mrb, r, "Service", mrb->object_class);
    mrb_define_method(mrb, f, "error_description", resource_service_error_description_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "is_running", resource_service_is_running_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "is_enabled", resource_service_is_enabled_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "enable", resource_service_enable_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "disable", resource_service_disable_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "reload", resource_service_reload_, MRB_ARGS_NONE());
}

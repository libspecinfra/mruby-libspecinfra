#include "mruby.h"
#include "mruby/data.h"
#include "mruby/string.h"
#include "backend.h"
#include "resource.h"

typedef struct specinfra_S specinfra_t;
extern specinfra_t *specinfra_new(backend_t *b);
extern resource_file_t *specinfra_file(specinfra_t *s, const char *n);

const static struct mrb_data_type mrb_specinfra_type = { "Specinfra", mrb_free };

static mrb_value specinfra_initialize(mrb_state *mrb, mrb_value self) {
    mrb_value v;
    specinfra_t *s;

    mrb_get_args(mrb, "o", &v);
    s = specinfra_new(DATA_PTR(v));

    DATA_TYPE(self) = &mrb_specinfra_type;
    DATA_PTR(self) = s;

    return self;
}

static mrb_value specinfra_file_(mrb_state *mrb, mrb_value self) {
    struct RClass *file_class;
    mrb_value v;
    char *n;
    resource_file_t *file;
    mrb_value file_object;

    file_class = mrb_class_get_under(
        mrb, 
        mrb_module_get_under(
            mrb,
            mrb_module_get(mrb, "Libspecinfra"),
            "Resource"),
        "File");

    mrb_get_args(mrb, "S", &v);
    n = mrb_str_to_cstr(mrb, v);
    file = specinfra_file(DATA_PTR(self), n);

    file_object = mrb_obj_new(mrb, file_class, 0, NULL);
    DATA_TYPE(file_object) = &mrb_resource_file_type;
    DATA_PTR(file_object) = file;

    return file_object;
}


void mrb_mruby_libspecinfra_gem_init(mrb_state *mrb)
{
    struct RClass *l = mrb_define_module(mrb, "Libspecinfra");

    struct RClass *s = mrb_define_class_under(mrb, l, "Specinfra", mrb->object_class);
    mrb_define_method(mrb, s, "initialize", specinfra_initialize, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, s, "file", specinfra_file_, MRB_ARGS_REQ(1));

    backend_init(mrb, l);
    resource_init(mrb, l);
}

void mrb_mruby_libspecinfra_gem_final(mrb_state *mrb)
{
}


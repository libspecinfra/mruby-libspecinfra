#include "mruby.h"
#include "mruby/data.h"
#include "mruby/string.h"
#include "resource_file.h"

static mrb_value resource_file_error_description_(mrb_state *mrb, mrb_value self) {
    mrb_value str;
    char *c = resource_file_error_description(DATA_PTR(self));
    str = mrb_str_buf_new(mrb, sizeof(c));
    return mrb_str_cat2(mrb, str, c);
}

static mrb_value resource_file_mode_(mrb_state *mrb, mrb_value self) {
    struct resource_file_t *f;
    f = DATA_PTR(self);

    int32_t m = resource_file_mode(f);

    if ( m < 0 ) {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_file_error_description(f)
        );
    } else {
        return mrb_fixnum_value(m);
    }
}

static mrb_value resource_file_exist_(mrb_state *mrb, mrb_value self) {
    struct resource_file_t *f;
    f = DATA_PTR(self);

    int32_t m = resource_file_exist(f);

    if ( m == 1 ) {
        return mrb_true_value();
    } else if ( m == 0 ) {
        return mrb_false_value();
    } else {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_file_error_description(f)
        );
    }
}

static mrb_value resource_file_is_file_(mrb_state *mrb, mrb_value self) {
    struct resource_file_t *f;
    f = DATA_PTR(self);

    int32_t m = resource_file_is_file(f);

    if ( m == 1 ) {
        return mrb_true_value();
    } else if ( m == 0 ) {
        return mrb_false_value();
    } else {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_file_error_description(f)
        );
    }
}

static mrb_value resource_file_is_directory_(mrb_state *mrb, mrb_value self) {
    struct resource_file_t *f;
    f = DATA_PTR(self);

    int32_t m = resource_file_is_directory(f);

    if ( m == 1 ) {
        return mrb_true_value();
    } else if ( m == 0 ) {
        return mrb_false_value();
    } else {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_file_error_description(f)
        );
    }
}

static mrb_value resource_file_is_block_device_(mrb_state *mrb, mrb_value self) {
    struct resource_file_t *f;
    f = DATA_PTR(self);

    int32_t m = resource_file_is_block_device(f);

    if ( m == 1 ) {
        return mrb_true_value();
    } else if ( m == 0 ) {
        return mrb_false_value();
    } else {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_file_error_description(f)
        );
    }
}

static mrb_value resource_file_is_character_device_(mrb_state *mrb, mrb_value self) {
    struct resource_file_t *f;
    f = DATA_PTR(self);

    int32_t m = resource_file_is_character_device(f);

    if ( m == 1 ) {
        return mrb_true_value();
    } else if ( m == 0 ) {
        return mrb_false_value();
    } else {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_file_error_description(f)
        );
    }
}

static mrb_value resource_file_is_pipe_(mrb_state *mrb, mrb_value self) {
    struct resource_file_t *f;
    f = DATA_PTR(self);

    int32_t m = resource_file_is_pipe(f);

    if ( m == 1 ) {
        return mrb_true_value();
    } else if ( m == 0 ) {
        return mrb_false_value();
    } else {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_file_error_description(f)
        );
    }
}

static mrb_value resource_file_is_socket_(mrb_state *mrb, mrb_value self) {
    struct resource_file_t *f;
    f = DATA_PTR(self);

    int32_t m = resource_file_is_socket(f);

    if ( m == 1 ) {
        return mrb_true_value();
    } else if ( m == 0 ) {
        return mrb_false_value();
    } else {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_file_error_description(f)
        );
    }
}

static mrb_value resource_file_is_symlink_(mrb_state *mrb, mrb_value self) {
    struct resource_file_t *f;
    f = DATA_PTR(self);

    int32_t m = resource_file_is_symlink(f);

    if ( m == 1 ) {
        return mrb_true_value();
    } else if ( m == 0 ) {
        return mrb_false_value();
    } else {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_file_error_description(f)
        );
    }
}

static mrb_value resource_file_contents_(mrb_state *mrb, mrb_value self) {
    struct resource_file_t *f;
    f = DATA_PTR(self);

    char *c = resource_file_contents(f);

    if (c == NULL) {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_file_error_description(f)
        );
    } else {
        mrb_value str;
        str = mrb_str_buf_new(mrb, sizeof(c));
        return mrb_str_cat2(mrb, str, c);
    }
}

static mrb_value resource_file_owner_(mrb_state *mrb, mrb_value self) {
    struct resource_file_t *f;
    f = DATA_PTR(self);

    char *c = resource_file_owner(f);

    if (c == NULL) {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_file_error_description(f)
        );
    } else {
        mrb_value str;
        str = mrb_str_buf_new(mrb, sizeof(c));
        return mrb_str_cat2(mrb, str, c);
    }
}

static mrb_value resource_file_group_(mrb_state *mrb, mrb_value self) {
    struct resource_file_t *f;
    f = DATA_PTR(self);

    char *c = resource_file_group(f);

    if (c == NULL) {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_file_error_description(f)
        );
    } else {
        mrb_value str;
        str = mrb_str_buf_new(mrb, sizeof(c));
        return mrb_str_cat2(mrb, str, c);
    }
}

static mrb_value resource_file_is_readable_(mrb_state *mrb, mrb_value self) {
    struct resource_file_t *f;
    f = DATA_PTR(self);

    int32_t m = resource_file_is_readable(f);

    if ( m == 1 ) {
        return mrb_true_value();
    } else if ( m == 0 ) {
        return mrb_false_value();
    } else {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_file_error_description(f)
        );
    }
}

static mrb_value resource_file_is_readable_by_owner_(mrb_state *mrb, mrb_value self) {
    struct resource_file_t *f;
    f = DATA_PTR(self);

    int32_t m = resource_file_is_readable_by_owner(f);

    if ( m == 1 ) {
        return mrb_true_value();
    } else if ( m == 0 ) {
        return mrb_false_value();
    } else {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_file_error_description(f)
        );
    }
}

static mrb_value resource_file_is_readable_by_group_(mrb_state *mrb, mrb_value self) {
    struct resource_file_t *f;
    f = DATA_PTR(self);

    int32_t m = resource_file_is_readable_by_group(f);

    if ( m == 1 ) {
        return mrb_true_value();
    } else if ( m == 0 ) {
        return mrb_false_value();
    } else {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_file_error_description(f)
        );
    }
}

static mrb_value resource_file_is_readable_by_others_(mrb_state *mrb, mrb_value self) {
    struct resource_file_t *f;
    f = DATA_PTR(self);

    int32_t m = resource_file_is_readable_by_others(f);

    if ( m == 1 ) {
        return mrb_true_value();
    } else if ( m == 0 ) {
        return mrb_false_value();
    } else {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_file_error_description(f)
        );
    }
}

static mrb_value resource_file_is_readable_by_user_(mrb_state *mrb, mrb_value self) {
    char *user;
    mrb_int len;
    struct resource_file_t *f;

    mrb_get_args(mrb, "s", &user, &len);
    f = DATA_PTR(self);
    int32_t m = resource_file_is_readable_by_user(f, user);

    if ( m == 1 ) {
        return mrb_true_value();
    } else if ( m == 0 ) {
        return mrb_false_value();
    } else {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_file_error_description(f)
        );
    }
}

static mrb_value resource_file_is_writable_(mrb_state *mrb, mrb_value self) {
    struct resource_file_t *f;
    f = DATA_PTR(self);

    int32_t m = resource_file_is_writable(f);

    if ( m == 1 ) {
        return mrb_true_value();
    } else if ( m == 0 ) {
        return mrb_false_value();
    } else {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_file_error_description(f)
        );
    }
}

static mrb_value resource_file_is_writable_by_owner_(mrb_state *mrb, mrb_value self) {
    struct resource_file_t *f;
    f = DATA_PTR(self);

    int32_t m = resource_file_is_writable_by_owner(f);

    if ( m == 1 ) {
        return mrb_true_value();
    } else if ( m == 0 ) {
        return mrb_false_value();
    } else {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_file_error_description(f)
        );
    } 
}

static mrb_value resource_file_is_writable_by_group_(mrb_state *mrb, mrb_value self) {
    struct resource_file_t *f;
    f = DATA_PTR(self);

    int32_t m = resource_file_is_writable_by_group(f);

    if ( m == 1 ) {
        return mrb_true_value();
    } else if ( m == 0 ) {
        return mrb_false_value();
    } else {
        mrb_raise(
            mrb,
            E_RUNTIME_ERROR,
            resource_file_error_description(f)
        );
    }
}

static mrb_value resource_file_is_writable_by_others_(mrb_state *mrb, mrb_value self) {
    uint32_t m = resource_file_is_writable_by_others(DATA_PTR(self));
    return mrb_bool_value(m);
}

static mrb_value resource_file_is_writable_by_user_(mrb_state *mrb, mrb_value self) {
    char *user;
    mrb_int len;
    mrb_get_args(mrb, "s", &user, &len);
    uint32_t m = resource_file_is_writable_by_user(DATA_PTR(self), user);
    return mrb_bool_value(m);
}

static mrb_value resource_file_md5sum_(mrb_state *mrb, mrb_value self) {
    mrb_value str;
    char *c = resource_file_md5sum(DATA_PTR(self));
    str = mrb_str_buf_new(mrb, sizeof(c));
    return mrb_str_cat2(mrb, str, c);
}

static mrb_value resource_file_sha256sum_(mrb_state *mrb, mrb_value self) {
    mrb_value str;
    char *c = resource_file_sha256sum(DATA_PTR(self));
    str = mrb_str_buf_new(mrb, sizeof(c));
    return mrb_str_cat2(mrb, str, c);
}

static mrb_value resource_file_size_(mrb_state *mrb, mrb_value self) {
    int64_t m = resource_file_size(DATA_PTR(self));
    return mrb_fixnum_value(m);
}

static mrb_value resource_file_linked_to_(mrb_state *mrb, mrb_value self) {
    mrb_value str;
    char *c = resource_file_linked_to(DATA_PTR(self));
    str = mrb_str_buf_new(mrb, sizeof(c));
    return mrb_str_cat2(mrb, str, c);
}

void resource_file_init(mrb_state *mrb, struct RClass *r) {
    struct RClass *f = mrb_define_class_under(mrb, r, "File", mrb->object_class);
    mrb_define_method(mrb, f, "error_description", resource_file_error_description_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "mode", resource_file_mode_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "exist", resource_file_exist_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "is_file", resource_file_is_file_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "is_directory", resource_file_is_directory_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "is_block_device", resource_file_is_block_device_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "is_character_device", resource_file_is_character_device_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "is_pipe", resource_file_is_pipe_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "is_socket", resource_file_is_socket_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "is_symlink", resource_file_is_symlink_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "contents", resource_file_contents_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "owner", resource_file_owner_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "group", resource_file_group_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "is_readable", resource_file_is_readable_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "is_readable_by_owner", resource_file_is_readable_by_owner_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "is_readable_by_group", resource_file_is_readable_by_group_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "is_readable_by_others", resource_file_is_readable_by_others_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "is_readable_by_user", resource_file_is_readable_by_user_, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, f, "is_writable", resource_file_is_writable_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "is_writable_by_owner", resource_file_is_writable_by_owner_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "is_writable_by_group", resource_file_is_writable_by_group_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "is_writable_by_others", resource_file_is_writable_by_others_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "is_writable_by_user", resource_file_is_writable_by_user_, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, f, "md5sum", resource_file_md5sum_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "sha256sum", resource_file_sha256sum_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "size", resource_file_size_, MRB_ARGS_NONE());
    mrb_define_method(mrb, f, "linked_to", resource_file_linked_to_, MRB_ARGS_NONE());

}

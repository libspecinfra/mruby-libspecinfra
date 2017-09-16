#include "mruby.h"
#include "mruby/data.h"
#include "mruby/string.h"
#include "resource_file.h"

static mrb_value resource_file_mode_(mrb_state *mrb, mrb_value self) {
    uint32_t m = resource_file_mode(DATA_PTR(self));
    return mrb_fixnum_value(m);
}

static mrb_value resource_file_exist_(mrb_state *mrb, mrb_value self) {
    uint32_t m = resource_file_exist(DATA_PTR(self));
    return mrb_bool_value(m);
}

static mrb_value resource_file_is_file_(mrb_state *mrb, mrb_value self) {
    uint32_t m = resource_file_is_file(DATA_PTR(self));
    return mrb_bool_value(m);
}

static mrb_value resource_file_is_directory_(mrb_state *mrb, mrb_value self) {
    uint32_t m = resource_file_is_directory(DATA_PTR(self));
    return mrb_bool_value(m);
}

static mrb_value resource_file_is_block_device_(mrb_state *mrb, mrb_value self) {
    uint32_t m = resource_file_is_block_device(DATA_PTR(self));
    return mrb_bool_value(m);
}

static mrb_value resource_file_is_character_device_(mrb_state *mrb, mrb_value self) {
    uint32_t m = resource_file_is_character_device(DATA_PTR(self));
    return mrb_bool_value(m);
}

static mrb_value resource_file_is_pipe_(mrb_state *mrb, mrb_value self) {
    uint32_t m = resource_file_is_pipe(DATA_PTR(self));
    return mrb_bool_value(m);
}

static mrb_value resource_file_is_socket_(mrb_state *mrb, mrb_value self) {
    uint32_t m = resource_file_is_socket(DATA_PTR(self));
    return mrb_bool_value(m);
}

static mrb_value resource_file_is_symlink_(mrb_state *mrb, mrb_value self) {
    uint32_t m = resource_file_is_symlink(DATA_PTR(self));
    return mrb_bool_value(m);
}

static mrb_value resource_file_contents_(mrb_state *mrb, mrb_value self) {
    mrb_value str;
    char *c = resource_file_contents(DATA_PTR(self));
    str = mrb_str_buf_new(mrb, sizeof(c));
    return mrb_str_cat2(mrb, str, c);
}

static mrb_value resource_file_owner_(mrb_state *mrb, mrb_value self) {
    mrb_value str;
    char *c = resource_file_owner(DATA_PTR(self));
    str = mrb_str_buf_new(mrb, sizeof(c));
    return mrb_str_cat2(mrb, str, c);
}

static mrb_value resource_file_group_(mrb_state *mrb, mrb_value self) {
    mrb_value str;
    char *c = resource_file_group(DATA_PTR(self));
    str = mrb_str_buf_new(mrb, sizeof(c));
    return mrb_str_cat2(mrb, str, c);
}

static mrb_value resource_file_is_readable_(mrb_state *mrb, mrb_value self) {
    uint32_t m = resource_file_is_readable(DATA_PTR(self));
    return mrb_bool_value(m);
}

static mrb_value resource_file_is_readable_by_owner_(mrb_state *mrb, mrb_value self) {
    uint32_t m = resource_file_is_readable_by_owner(DATA_PTR(self));
    return mrb_bool_value(m);
}

static mrb_value resource_file_is_readable_by_group_(mrb_state *mrb, mrb_value self) {
    uint32_t m = resource_file_is_readable_by_group(DATA_PTR(self));
    return mrb_bool_value(m);
}

static mrb_value resource_file_is_readable_by_others_(mrb_state *mrb, mrb_value self) {
    uint32_t m = resource_file_is_readable_by_others(DATA_PTR(self));
    return mrb_bool_value(m);
}

static mrb_value resource_file_is_readable_by_user_(mrb_state *mrb, mrb_value self) {
    char *user;
    mrb_int len;
    mrb_get_args(mrb, "s", &user, &len);
    uint32_t m = resource_file_is_readable_by_user(DATA_PTR(self), user);
    return mrb_bool_value(m);
}

static mrb_value resource_file_is_writable_(mrb_state *mrb, mrb_value self) {
    uint32_t m = resource_file_is_writable(DATA_PTR(self));
    return mrb_bool_value(m);
}

static mrb_value resource_file_is_writable_by_owner_(mrb_state *mrb, mrb_value self) {
    uint32_t m = resource_file_is_writable_by_owner(DATA_PTR(self));
    return mrb_bool_value(m);
}

static mrb_value resource_file_is_writable_by_group_(mrb_state *mrb, mrb_value self) {
    uint32_t m = resource_file_is_writable_by_group(DATA_PTR(self));
    return mrb_bool_value(m);
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

void resource_file_init(mrb_state *mrb, struct RClass *r) {
    struct RClass *f = mrb_define_class_under(mrb, r, "File", mrb->object_class);
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
}

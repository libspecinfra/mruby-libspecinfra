#include "mruby/data.h"

typedef struct resource_file_S resource_file_t;

const static struct mrb_data_type mrb_resource_file_type = { "File", mrb_free };

void resource_file_init(mrb_state *mrb, struct RClass *r);

extern char *resource_file_error_description(resource_file_t *f);
static mrb_value resource_file_error_description_(mrb_state *mrb, mrb_value self);

extern int32_t resource_file_mode(resource_file_t *f);
static mrb_value resource_file_mode_(mrb_state *mrb, mrb_value self);

extern int32_t resource_file_exist(resource_file_t *f);
static mrb_value resource_file_exist_(mrb_state *mrb, mrb_value self);

extern int32_t resource_file_is_file(resource_file_t *f);
static mrb_value resource_file_is_file_(mrb_state *mrb, mrb_value self);

extern int32_t resource_file_is_directory(resource_file_t *f);
static mrb_value resource_file_is_directory_(mrb_state *mrb, mrb_value self);

extern int32_t resource_file_is_block_device(resource_file_t *f);
static mrb_value resource_file_is_block_device_(mrb_state *mrb, mrb_value self);

extern int32_t resource_file_is_character_device(resource_file_t *f);
static mrb_value resource_file_is_character_device_(mrb_state *mrb, mrb_value self);

extern int32_t resource_file_is_pipe(resource_file_t *f);
static mrb_value resource_file_is_pipe_(mrb_state *mrb, mrb_value self);

extern int32_t resource_file_is_socket(resource_file_t *f);
static mrb_value resource_file_is_socket_(mrb_state *mrb, mrb_value self);

extern int32_t resource_file_is_symlink(resource_file_t *f);
static mrb_value resource_file_is_symlink_(mrb_state *mrb, mrb_value self);

extern char *resource_file_contents(resource_file_t *f);
static mrb_value resource_file_contents_(mrb_state *mrb, mrb_value self);

extern char *resource_file_owner(resource_file_t *f);
static mrb_value resource_file_owner_(mrb_state *mrb, mrb_value self);

extern char *resource_file_group(resource_file_t *f);
static mrb_value resource_file_group_(mrb_state *mrb, mrb_value self);

extern int32_t *resource_file_is_readable(resource_file_t *f);
static mrb_value resource_file_is_readable_(mrb_state *mrb, mrb_value self);

extern int32_t *resource_file_is_readable_by_owner(resource_file_t *f);
static mrb_value resource_file_is_readable_by_owner_(mrb_state *mrb, mrb_value self);

extern int32_t *resource_file_is_readable_by_group(resource_file_t *f);
static mrb_value resource_file_is_readable_by_group_(mrb_state *mrb, mrb_value self);

extern int32_t *resource_file_is_readable_by_others(resource_file_t *f);
static mrb_value resource_file_is_readable_by_others_(mrb_state *mrb, mrb_value self);

extern int32_t *resource_file_is_readable_by_user(resource_file_t *f, const char *u);
static mrb_value resource_file_is_readable_by_user_(mrb_state *mrb, mrb_value self);

extern int32_t *resource_file_is_writable(resource_file_t *f);
static mrb_value resource_file_is_writable_(mrb_state *mrb, mrb_value self);

extern int32_t *resource_file_is_writable_by_owner(resource_file_t *f);
static mrb_value resource_file_is_writable_by_owner_(mrb_state *mrb, mrb_value self);

extern int32_t *resource_file_is_writable_by_group(resource_file_t *f);
static mrb_value resource_file_is_writable_by_group_(mrb_state *mrb, mrb_value self);

extern int32_t *resource_file_is_writable_by_others(resource_file_t *f);
static mrb_value resource_file_is_writable_by_others_(mrb_state *mrb, mrb_value self);

extern uint32_t *resource_file_is_writable_by_user(resource_file_t *f, const char *u);
static mrb_value resource_file_is_writable_by_user_(mrb_state *mrb, mrb_value self);

extern char *resource_file_md5sum(resource_file_t *f);
static mrb_value resource_file_md5sum_(mrb_state *mrb, mrb_value self);

extern char *resource_file_sha256sum(resource_file_t *f);
static mrb_value resource_file_sha256sum_(mrb_state *mrb, mrb_value self);

extern int64_t *resource_file_size(resource_file_t *f);
static mrb_value resource_file_size_(mrb_state *mrb, mrb_value self);

extern char *resource_file_linked_to(resource_file_t *f);
static mrb_value resource_file_linked_to_(mrb_state *mrb, mrb_value self);

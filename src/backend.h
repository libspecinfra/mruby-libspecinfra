typedef struct backend_S backend_t;

const static struct mrb_data_type mrb_backend_type = { "Backend", mrb_free };

void backend_init(mrb_state *mrb, struct RClass *l);

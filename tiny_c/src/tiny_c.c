#include "pesapi.h"

int Add(int a, int b) {
    return a + b;
}

void Add_Wrap(pesapi_callback_info info) {
    pesapi_env env = pesapi_get_env(info);
    int x = pesapi_get_value_int32(env, pesapi_get_arg(info, 0));
    int y = pesapi_get_value_int32(env, pesapi_get_arg(info, 1));
    pesapi_add_return(info, pesapi_create_int32(env, Add(x, y)));
}

static void Init() {
    pesapi_property_descriptor properties = pesapi_alloc_property_descriptors(1);
    pesapi_set_method_info(properties, 0, "Add", true, Add_Wrap, NULL, NULL);
    pesapi_define_class("Calc", NULL, "Calc", NULL, NULL, 1, properties, NULL);
}

PESAPI_MODULE(tiny_c, Init)

// module declaration end

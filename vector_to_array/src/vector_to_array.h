#pragma once

#include <vector>
#include "Binding.hpp"

namespace puerts
{
#ifdef PES_EXTENSION_WITH_V8_API
namespace v8_impl
{
template <typename T>
struct Converter<std::vector<T>>
{
    static v8::Local<v8::Value> toScript(v8::Local<v8::Context> context, std::vector<T> value)
    {
        auto ret = v8::Array::New(context->GetIsolate());
        for (size_t i = 0; i < value.size(); i++) {
            (ret->Set(context, i, Converter<T>::toScript(context, value[i]))).Check();
        }
        return ret;
    }

    static std::vector<T> toCpp(v8::Local<v8::Context> context, const v8::Local<v8::Value>& value)
    {
        std::vector<T> ret;
        if (value->IsArray()) {
            auto arr = value.As<v8::Array>();
            for (size_t i = 0; i < arr->Length(); i++) {
                ret.push_back(Converter<T>::toCpp(context, arr->Get(context, i).ToLocalChecked()));
            }
        }
        return ret;
    }

    static bool accept(v8::Local<v8::Context> context, const v8::Local<v8::Value>& value)
    {
        return value->IsArray();
    }
};
}

#else
namespace pesapi_impl
{
template <typename T>
struct Converter<std::vector<T>>
{
    static pesapi_value toScript(pesapi_env env, std::vector<T> value)
    {
        auto ret = pesapi_create_array(env);
        for (size_t i = 0; i < value.size(); i++) {
            pesapi_set_property_uint32(env, ret, i, Converter<T>::toScript(env, value[i]));
        }
        return ret;
    }

    static std::vector<T> toCpp(pesapi_env env, pesapi_value value)
    {
        std::vector<T> ret;
        if (pesapi_is_array(env, value)) {
            uint32_t len = pesapi_get_array_length(env, value);
            for (size_t i = 0; i < len; i++) {
                ret.push_back(Converter<T>::toCpp(env, pesapi_get_property_uint32(env, value, i)));
            }
        }
        return ret;
    }

    static bool accept(pesapi_env env, pesapi_value value)
    {
        return pesapi_is_array(env, value);
    }
};
}
#endif

template <typename T>
struct ScriptTypeName<std::vector<T>>
{
    static constexpr auto value()
    {
        return ScriptTypeName<T>::value() + internal::Literal("[]");
    }
};

}


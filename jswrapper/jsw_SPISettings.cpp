//C++ wrapper auto generator jswmgen.js ver.0.9.0
//https://github.com/spuggy0919/jswrapper.git
//**WARNING**You should examine and fix the code to meet your requirements!
//Wed Apr 17 2024 19:01:35 GMT+0800
//Json:./json/SPISettings.json
//File:./jswrapper/jsw_SPISettings.cpp
//className:SPISettings
//classObj:spisettings
//constructorPrototype:SPISettings::SPISettings(uint32_t clock, uint8_t bitOrder, uint8_t dataMode)
//prototypesArray:
//   uint32_t _clock(uint32_t clock);
//   uint8_t _bitOrder(uint8_t bitOrder);
//   uint8_t _dataMode(uint8_t dataMode);
#include "jswrap_tc.h"
#ifdef _LANG_JERRYSCRIPT_ 
#ifdef _LIB_SPISETTINGS_
/* **HOW 1** simple select copy & paste **/
/* **HOW 2** or using process.argv[2] for output file, then dl file**/
/* **WARNNING** if tab position is wrong, means error found**/
/* **TODO** Include your class declaration here **/
#include "SPISettings.h"
void spisettings_free_callback(void* native_p, jerry_object_native_info_t *info_p);
const static jerry_object_native_info_t spisettings_info = {
    .free_cb = spisettings_free_callback
};
//uint32_t _clock(uint32_t clock);
JS_METHOD(spisettings__clock)
{
    JERRYX_UNUSED(call_info_p);
    uint32_t clock; // 1 optional no argument for get, use for set

    const jerryx_arg_t mapping[] ={
        jerryx_arg_uint32(&clock, JERRYX_ARG_CEIL, JERRYX_ARG_NO_CLAMP, JERRYX_ARG_NO_COERCE, JERRYX_ARG_OPTIONAL), //2
    };
    const jerry_value_t rv = jerryx_arg_transform_args(args_p, args_cnt, mapping, JERRYXX_ARRAY_SIZE(mapping));
    if (jerry_value_is_exception(rv)){
        return rv;
    }
    //JERRYXX_ON_ARGS_COUNT_THROW_ERROR_SYNTAX(args_cnt != 1, "Wrong arguments count"); //3

    void *native_pointer = NULL;
    native_pointer = jerry_object_get_native_ptr(call_info_p->this_value, &spisettings_info);

    if(native_pointer) {
        SPISettings* spisettings = (SPISettings*)native_pointer;
        if (args_cnt==0){ //4
            return jerry_number(spisettings->_clock);
        }else if (args_cnt==1){
            spisettings->_clock=clock;
            return jerry_number(spisettings->_clock);
        }
    }
    return jerry_undefined();
} /*js_spisettings__clock*/
//uint8_t _bitOrder(uint8_t bitOrder);
JS_METHOD(spisettings__bitOrder)
{
    JERRYX_UNUSED(call_info_p);
    uint8_t bitOrder; // 1 optional no argument for get, use for set

    const jerryx_arg_t mapping[] ={
        jerryx_arg_uint8(&bitOrder, JERRYX_ARG_CEIL, JERRYX_ARG_NO_CLAMP, JERRYX_ARG_NO_COERCE, JERRYX_ARG_OPTIONAL), //2
    };
    const jerry_value_t rv = jerryx_arg_transform_args(args_p, args_cnt, mapping, JERRYXX_ARRAY_SIZE(mapping));
    if (jerry_value_is_exception(rv)){
        return rv;
    }
    // JERRYXX_ON_ARGS_COUNT_THROW_ERROR_SYNTAX(args_cnt != 1, "Wrong arguments count"); //3

    void *native_pointer = NULL;
    native_pointer = jerry_object_get_native_ptr(call_info_p->this_value, &spisettings_info);

    if(native_pointer) {
        SPISettings* spisettings = (SPISettings*)native_pointer;
        if (args_cnt==0) { // getter 4
            jerry_number(spisettings->_bitOrder);
        }else if (args_cnt==1) {
            spisettings->_bitOrder = bitOrder;
            return jerry_number(bitOrder);
        }
    }
    return jerry_undefined();
} /*js_spisettings__bitOrder*/
//uint8_t _dataMode(uint8_t dataMode);
JS_METHOD(spisettings__dataMode)
{
    JERRYX_UNUSED(call_info_p);
    uint8_t dataMode; //1

    const jerryx_arg_t mapping[] ={
        jerryx_arg_uint8(&dataMode, JERRYX_ARG_CEIL, JERRYX_ARG_NO_CLAMP, JERRYX_ARG_NO_COERCE, JERRYX_ARG_OPTIONAL), //2
    };
    const jerry_value_t rv = jerryx_arg_transform_args(args_p, args_cnt, mapping, JERRYXX_ARRAY_SIZE(mapping));
    if (jerry_value_is_exception(rv)){
        return rv;
    }
    // JERRYXX_ON_ARGS_COUNT_THROW_ERROR_SYNTAX(args_cnt != 1, "Wrong arguments count"); //3

    void *native_pointer = NULL;
    native_pointer = jerry_object_get_native_ptr(call_info_p->this_value, &spisettings_info);

    if(native_pointer) {
        SPISettings* spisettings = (SPISettings*)native_pointer;
        if (args_cnt==0){ // 4 getter
            return jerry_number(spisettings->_dataMode);

        }else if (args_cnt==1) {
            spisettings->_dataMode =  dataMode;
            return jerry_number(spisettings->_dataMode);
        }
        return jerry_number(spisettings->_dataMode);
    }
    return jerry_undefined();
} /*js_spisettings__dataMode*/
/* ~SPISettings spisettings destroy */
void spisettings_free_callback(void* native_p, jerry_object_native_info_t *info_p){
    WSDEBUG_TPRINTF("[SPISettings] delete %x\n",native_p);
    SPISettings* spisettings = (SPISettings*)native_p;
    /** **TODO** free your own resource here **/
    delete(spisettings);
};
//Verify Methods List
/*js_spisettings__clock*/
/*js_spisettings__bitOrder*/
/*js_spisettings__dataMode*/
//SPISettings::SPISettings(uint32_t clock, uint8_t bitOrder, uint8_t dataMode)
JS_METHOD(spisettings_SPISettings)
{
    JERRYX_UNUSED(call_info_p);
    uint32_t clock; // optional
    uint8_t bitOrder;
    uint8_t dataMode;

    const jerryx_arg_t mapping[] ={
        jerryx_arg_uint32(&clock, JERRYX_ARG_CEIL, JERRYX_ARG_NO_CLAMP, JERRYX_ARG_NO_COERCE, JERRYX_ARG_OPTIONAL), //2
        jerryx_arg_uint8(&bitOrder, JERRYX_ARG_CEIL, JERRYX_ARG_NO_CLAMP, JERRYX_ARG_NO_COERCE, JERRYX_ARG_OPTIONAL),
        jerryx_arg_uint8(&dataMode, JERRYX_ARG_CEIL, JERRYX_ARG_NO_CLAMP, JERRYX_ARG_NO_COERCE, JERRYX_ARG_OPTIONAL),
    };
    const jerry_value_t rv = jerryx_arg_transform_args(args_p, args_cnt, mapping, JERRYXX_ARRAY_SIZE(mapping));
    if (jerry_value_is_exception(rv)){
        return rv;
    }
    // JERRYXX_ON_ARGS_COUNT_THROW_ERROR_SYNTAX(args_cnt != 3, "Wrong arguments count"); //3
    
    SPISettings* spisettings;
    if (args_cnt==0) {
        spisettings = new SPISettings();
    }else{
        JERRYXX_ON_ARGS_COUNT_THROW_ERROR_SYNTAX(args_cnt != 3, "Wrong arguments count");
        spisettings = new SPISettings((uint32_t) clock,(uint8_t) bitOrder,(uint8_t) dataMode); //4
    }
    WSDEBUG_TPRINTF("[SPISettings] new %x\n",spisettings);
    jerry_value_t js_spisettingsobj = jerry_object();
    jerry_object_set_native_ptr(js_spisettingsobj, &spisettings_info , spisettings );
    // Register initialization function
    jerryx_property_entry props[] ={ //5 methods
        JERRYX_PROPERTY_STRING_SZ ("id", "SPISettings"),
        JERRYX_PROPERTY_FUNCTION ("_clock", js_spisettings__clock),
        JERRYX_PROPERTY_FUNCTION ("_bitOrder", js_spisettings__bitOrder),
        JERRYX_PROPERTY_FUNCTION ("_dataMode", js_spisettings__dataMode),
        JERRYX_PROPERTY_LIST_END(),
    };
    jerryx_register_result reg = jerryx_set_properties (js_spisettingsobj, props);
    if (jerry_value_is_exception (reg.result)){
        WSDEBUG_TPRINTF("Only registered %d properties\r\n", reg.registered);
        /* clean up not registered property values */
        jerryx_release_property_entry (props, reg);
        jerry_value_free (reg.result);
        return jerry_undefined();
        /* clean up the error */
    };
    return js_spisettingsobj;
} /*js_spisettings_SPISettings*/
bool js_spisettings_classobj_wrapper(){  
//1 a)modified func name and b) define in .h c) call by jswwrap_tc
    return jerryx_register_global ("SPISettings", js_spisettings_SPISettings);
};
#endif //_LIB_SPISETTINGS_
#endif // _LANG_JERRYSCRIPT_ Congraturation Done!

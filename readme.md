### Jerryscript js examples
These js files can be run on ESP32_tinyConsole project
support require statement for module, the module.js must at directory /js/modules
testng directory still has some problem.
```
0date.js         748         #time
0helloc.js       159         #hello
1sio.js          650         #sio
2fsio.js         746         #fs
3touch.js       3014         #touch
40color.js      1437         #canvas
41graphics.js   2613         #canvas
42graphics.js   1993         #canvas
50d0.js           33         #gpio d0
50d1.js          112         #gpio d1
50pin.js         341         # pin def
50pins.js       1645         # pin def
51blink.js       375         # blink
52button.js     1056         # button test
70dht.js         389         # dht22
blinkt.js        407         # blink
gpio.js          219         # gpio
modules          320         # modules directory 
timer1.js        854         # setInterval
dumpf.js        2341	     # js dumpf Rectangle
dumpg.js        1533	     # js dumpg
jswmgen.js     21672	     # js jswmgen [jsonFile OutputFile]
```
In iot enviroment, you need include a lot of libraries, but jerryscript did not have these io libraries. we need to use a C++ binding wrapper to static compiler link.
1. prepare one wrapper CPP, to binding call C++ class object library, 
2. register this to jerryscript
3. use js call the binding object, use library.
The first step is a lot of handmade work, here we use a auto generator to reduce the workload.
## Wrapper generator
Run with Node.js can Generator the Arduino ESP32 Library Wrapper, which .h contains classObject.
When wrapper cpp is generated, checked,and feed into ESP32_TinyConsole project to compiler. then the new Object can be used in Jerryscript.
### Fill the methods fields in jswmgen.js or write into json file
```
methods = {
    classObj : 'rectangle', //  write your own object name
    constructorPrototype : 'Rectangle::Rectangle(int length,int width);',  // should be CLASSNAME::CONSTRUCTOR
    prototypesArray : [// TODO will use only C Prototype , suppose JS is auto generated
    // C properties & methods define here, and consider the inherit methods if need.               
    'int getSize();',
    'int getLength();',
    'int getWidth();'
    ],
    className :'',
    methodNames:[],
}
```
### Method prototypes syntax rules, should be strict type name pairs
```
// for constructorPrototype
'Rectangle::Rectangle(int length,int width);', // correct
'Rectangle(int length,int width);', // wrong, no classname
// for prototypesArray
Adafruit_SSD1306::Adafruit_SSD1306(uint8_t w, uint8_t h, TwoWire* twi ,int8_t rst_pin, uint32_t clkDuring , uint32_t clkAfter); // wrong TwoWire* twi, this should be remove and use static link by yourself when call method 
Adafruit_SSD1306::Adafruit_SSD1306(uint8_t w, uint8_t h, int8_t rst_pin, uint32_t clkDuring , uint32_t clkAfter); // correct , then ->Adafruit_SSD1306(w,h,&Wire,rstpin,clkDuring,clkAfter);
Adafruit_SSD1306::Adafruit_SSD1306(uint8_t w, uint8_t h, TwoWire* twi ,int8_t rst_pin, uint32_t clkDuring , uint32_t clkAfter);
"void createChar(uint8_t c, uint8_t* buf);", // correct
"begin(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows, uint8_t charsize = LCD_5x8DOTS);" // error ,  "= LCD_5x8DOTS" is not allowed, you can set it as OPTIONAL later and set default value into arg declaration.
void createChar(uint8_t , uint8_t* );", // error, argvar name miss
"void createChar(const uint8_t c, uint8_t* buf);", // error, const redundence
"int8 createChar(int8 c, uint8_t* buf);", // error, int8 is not defined in argMappings_C_to_JS or retMappings_C_to_JS
"void createChar(uint8_t c, uint8_t *buf);", // error, should be uint8_t*
"void createChar(uint8_t c, uint8_t buf[]);", // error, should be uint8_t*
"void createChar( uint8_t c, uint8_t *buf);", // possible, '( uint8_t' to '(uint8_t'
"void createChar(uint8_t c, uint8_t* buf);", // corrcet, uint8_t* will mapping to jerryx_arg_arraybuffer
"void createChar(uint8_t c, char* buf);", // corrcet, char* will mapping to jerryx_arg_string
"void getTextBounds(char* str, int16_t x, int16_t y, int16_t* x1, int16_t* y1, uint16_t* w, uint16_t* h);", // char* map to jerryx_arg_string, int16_t* x1 to int16 "void createChar(uint8_t c, uint8_t* buf);", // corrcet, uint8_t* will mapping to jerryx_arg_array

```
## C Arguments mapping to JS 
It converts from C arg type to js type defined in argMappings_C_to_JS. There are some exceptions, ignore, function, native_pointer, and custom should be coded by yourself. 
```
function definedConstArg(){
        const argMappings_C_to_JS = { // TODO for arg_type mappings type 
        "size_t": "uint32",
        "int": "int32",
        "int_t": "int32",
        "int8_t": "int8",
        "int16_t": "int16",
        "int32_t": "int32",
        "uint": "uint32",
        "uint8": "uint8",
        "uint16": "uint16",
        "uint32": "uint32",
        "uint_t": "uint32",
        "uint8_t": "uint8",
        "uint16_t": "uint16",
        "uint32_t": "uint32",
        "uint_t*": "arraybuffer",
        "uint8_t*": "arraybuffer",
        "uint16_t*": "arraybuffer",
        "uint32_t*": "arraybuffer",
        "int_t*": "arraybuffer", // ignore part should be modified as GFX drawbitmap
        "int8_t*": "arraybuffer",
        "int16_t*": "arraybuffer",
        "int32_t*": "arraybuffer",        
        "char*": "string", // possible use string_sz
        "char": "uint8",
        "char*": "string",
        "double": "number",
        "float": "number",
        "bool": "boolean",
        "ignore": "ignore",         // TODO ignore one, and process later
        "void*": "native_pointer",    // TODO for class Object
        "funcptr": "function",   // TODO for callback should be typedef funcptr prototype
        "custome": "custome"   // TODO 

    };
    return argMappings_C_to_JS;
}
```
## JS return type 
This mapping converts from c return type to js type defined in retMappings_C_to_JS. The object return type is not supported now.
```
function definedConstRet(){
    const retMappings_C_to_JS = { // TODO for return js type 
        "size_t": "number",
        "int8": "number",
        "int16": "number",
        "int32": "number",
        "int": "number",
        "int_t": "number",
        "int8_t": "number",
        "int16_t": "number",
        "int32_t": "number",
        "uint8": "number",
        "uint16": "number",
        "uint32": "number",
        "uint": "number",
        "uint_t": "number",
        "uint8_t": "number",
        "uint16_t": "number",
        "uint32_t": "number",
        "uint8*": "string",
        "uint8_t*": "string",
        "char*": "string",
        "char": "number",
        "bool": "boolean",
        "void": "void"  
    };// TODO crettype auto transfer to jsrettype

    return retMappings_C_to_JS;
}  
```
## In Node.js environment, Run command in Shell terminal
the default .h in include subdirectory.
the default .json in json subdirectory.
```
%node h2json Rectangle.h     # if success, it will generate a json file in json folder
%node jswmgen Rectangle.json Rectangle.cpp # cpp will be generated in jswrapper folder.
```

## In ESP32_tinyConsole use below.
```
%cd /js/jswmgen
%js  jswmgen rectangle.json jsw_rectangle.cpp
%cat jsw_rectangle.cpp
#then select copy and paste to your files
%dl jsw_rectangle.cpp #downloadfile
```
When you get the autogen file, you should check,
1. if tab postion wrong, bad news!
2. check each methods, if C using same method, different args, it should be merge into one, by check arg_cnt, or using differnet method name.
3. callback wrapper function, should be created. This generator does not generate.
4. non method property, need to set/get, it is function type.
5. bytes array no idea, how to mapping.
6. char buf[32];, size should be review, now define buf[32];
```
    char charmap[32];
        jerryx_arg_string(charmap, sizeof(charmap), JERRYX_ARG_NO_COERCE, JERRYX_ARG_REQUIRED),
```
7. method have different args_cnt same method name, can be merged, with
```
    if (args_cnt == 2 ){
        ...
    }else if ((args_cnt == 3 )) {

    }
```
or use optional flag 
```
const jerryx_arg_t mapping[] ={
        jerryx_arg_uint8(&cols, JERRYX_ARG_CEIL, JERRYX_ARG_NO_CLAMP, JERRYX_ARG_NO_COERCE, JERRYX_ARG_REQUIRED),
        jerryx_arg_uint8(&rows, JERRYX_ARG_CEIL, JERRYX_ARG_NO_CLAMP, JERRYX_ARG_NO_COERCE, JERRYX_ARG_REQUIRED),
        jerryx_arg_uint8(&charsize, JERRYX_ARG_CEIL, JERRYX_ARG_NO_CLAMP, JERRYX_ARG_NO_COERCE, JERRYX_ARG_OPTIONAL),
    };
    ...
    JERRYXX_ON_ARGS_COUNT_THROW_ERROR_SYNTAX(!((args_cnt == 2)||(args_cnt == 3)), "Wrong arguments count");

```
8. if generator stop on some method, you may need to delete this method, later add by yourself.

## After review code, declare and call it to register
1. put the register prototype into  /lib/jswrapper/jswrap_tc.h
```
#ifdef _LIB_RECTANGLE_
bool js_rectangle_classobj_wrapper();
#endif
```
2. put the define to include the source file into compiler into /src/cmdconfig.h
```
#define _LIB_RECTANGLE_
```
3. call register prototype into /lib/jswrapper/jswrap_tc_module.cpp, then the rectangle object will load when js vm start up.
```
void jerryxx_register_arduino_library(){

#ifdef _LIB_RECTANGLE_
   js_rectangle_classobj_wraper();
#endif

}
```
4. Compiler and upload, uploadfs
2. check your Object is registered.
```
%js dumpg 
```
3. use your Object in js
```
%js rectangle 
```
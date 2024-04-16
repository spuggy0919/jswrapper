const process = require('process');
const cwd = process.cwd()+'/';
let  fs = (cwd == '/js/jswmgen') ? require('nodefs'): require('./nodefs');
// Read the .h file content

let filePath =  (process.argv[2]!=undefined) ? process.argv[2]:'Wire.h'; // Replace 'example.h' with your file path
let fname = filePath.split('.');
let defaultClass = fname[0];
filePath = "include/" + filePath; // Replace 'example.h' with your file path
// const filePath = "include/" + 'Rectangle.h';
let content = fs.readFileNodeJS(filePath);
const fileContent = content.replace(/\s+\*\s*/g,'* '); //type *var ==> type* var
if (typeof process.argv[2] === 'undefined' || fileContent == '') {
    console.log(`Input file not Found ${filePath}`);
    process.exit(-1);
}
console.log('Inputfile',filePath,defaultClass);

let methods = parserMethodsObj(fileContent);
if (methods.className == '' || methods.constructorPrototype == '') {
    console.log(`Parser result error ${methods.className}`);
    process.exit(-2);
}
if (methods.className ==''){
    fs.deleteFileNodeJS(outputFile);
    console.log('no class declaration',filePath);
    process.exit(3);
}
const outputFile = "json/"+methods.className + ".json";
methods.prototypesArray.forEach( (element, index, array)=>{
    // let old = element;
    let e = element.replace(/const\s+/g,'');  //remove const
    let f = e.replace(/\s+\*\s*/g,'* '); //type *var ==> type* var
    array[index] = f;
    // console.log(old, f);
});
dumpMethodsObj(methods);

let jsonStr = JSON.stringify(methods);
let estr = jsonStr.replace(/",/g,'",\n');
let fstr = estr.replace(/\["/g,'[\n"');
let lineStr = fstr.replace(/\],/g,'],\n');
fs.writeFileNodeJS(outputFile,lineStr);
process.exit(0);
function parserMethodsObj(fileContent){
    let methods = {
        className :"",
        classObj : "rectangle", 
        constructorPrototype : "Rectangle::Rectangle(int length,int width);", 
        prototypesArray : [
        ],
        methodNames:[]    
    };        
    
    // Regular expression patterns to extract class name, constructor prototype, and method prototypes
    const classPattern =  /class\s+(\w+)\s*(:\s*public\s+\w+)?\s*{/;
    // Find the class name
    let classNameMatch = fileContent.match(classPattern);
    let className = classNameMatch ? classNameMatch[1] : '';

    if (className == '') {
        console.log('Class object not Found! Use default Classname',defaultClass);
        className = '_default_'+defaultClass;
    }
    methods.className = className;
    methods.classObj = toLowerCase(className);
    if (className === methods.classObj ) methods.classObj+='obj';
    try {
        // find public block 
        // Regular expression to match the public block
        const regex = /public:(.*?)(?:private:|protected:|};|$)/s;
        const match = fileContent.match(regex);
        var   publicBlock = fileContent;

        if (match) {
            publicBlock = match[1].trim(); // Extract and trim the public block
            console.log(publicBlock);
        } else {
            console.log('Public block not found.');
        }
        let constructorPattern =new RegExp(`^\\s*(${className}\\s*\\(.*\\))`,'gm');
        // Find the constructor prototype
        let constructorMatch = fileContent.match(constructorPattern);
        if (constructorMatch) {
            const constructorPrototype = className+'::'+constructorMatch[0].trim();
            methods.constructorPrototype = constructorPrototype;
        } else {
            methods.constructorPrototype = className+'::'+className+'()';
        }
        console.log(`Constructor Prototype: ${constructorPrototype}`);

    } catch(e) {
        console.log('Error',e.message);
        methods.constructorPrototype =  className+'::'+className+'()';
    }
    // Find method prototypes
    // const methodPattern = /(\w+)\*?\s+(\w+)\(.*\)(?!^\s*else|^\s*return)/g;
    const methodPattern =/(\b\w+\*?\s+\w+\(.*?\)\s*(?={[^{}]*}))|(\b\w+\*?\s+\w+\(.*?\))\s*(?={[^{}]*})|(\b\w+\*?\s+\w+\(.*?\))/g;
    const methodPrototypes = publicBlock.match(methodPattern) || [];
    methods.prototypesArray = methodPrototypes;
    return methods;

}

function dumpMethodsObj(methods){
    // Print the extracted information
    console.log("Class Obj:", methods.classObj);
    console.log("Class Name:", methods.className);
    console.log("Constructor Prototype:", methods.constructorPrototype);
    console.log("Method Prototypes:");
    methods.prototypesArray.forEach(method => console.log(method.trim()));
}

function toLowerCase(str) {
    var result = '';
    if (str == '') return '';
    for (var i = 0; i < str.length; i++) {
        var charCode = str.charCodeAt(i);
        if (charCode >= 65 && charCode <= 90) { // ASCII range for uppercase letters
            result += String.fromCharCode(charCode + 32); // Convert uppercase to lowercase
        } else {
            result += str.charAt(i); // Keep non-alphabetic characters unchanged
        }
    }
    return result;
}
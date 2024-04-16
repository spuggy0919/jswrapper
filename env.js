let process = require('process');
let fs = require('./nodefs');
console.log(process.env);
console.log(process.argv0);
console.log(process.argv);
console.log(process.cwd());

console.log(fs.checkNodeJS());
var outputFile = 'test.txt'
fs.writeFileNodeJS(outputFile,"Hello World!\n");
fs.writeFileNodeJS(outputFile,"Hello World!123\n");
fs.appendFileNodeJS(outputFile,"Hello World!abc\n");

console.log(fs.readFileNodeJS(outputFile));
// fs.deleteFileNodeJS(outputFile);


// function checkNodeJS(){
//     var platform='TINYCONSOLE'
//     if (process.cwd().startsWith('/Users')) {
//         // maybe mac node.js environment
//         platform = 'NODEJS'
//     }
//     return platform;
// }


// function readFileNodeJS(filename){
//     if (checkNodeJS() == 'NODEJS') {
//         return fs.readFile(filename,'utf8', function (err) {
//             if (err) throw err;
//             console.log('Data appended to file!');
//         });
//     }else{
//         return fs.readFile(filename);
//     }
// }
// function appendFileNodeJS(filename, msg){
//     if (checkNodeJS()  == 'NODEJS') {
//         fs.appendFile(filename, msg, function (err) {
//             if (err) throw err;
//             console.log('Data appended to file!');
//         });
//     }else{
//         fs.appendFile(filename, msg);
//     }
// }
// function deleteFileNodeJS(filename){
//     if (checkNodeJS()  == 'NODEJS') {
//         fs.unlink(filename, function (err) {
//             if (err) throw err;
//             console.log('Data appended to file!');
//         });
//     }else{
//         fs.deleteFile(filename);
//     }
// }
// function writeFileNodeJS(filename, msg){
//     if (checkNodeJS()  == 'NODEJS') {
//         fs.writeFile(filename, msg, err => {
//             if (err) {
//                 console.error(err,'Data write to file!');
//             }else{
//                 // file written successfully
//             }
//         });
//     }else{
//         fs.writeFile(filename, msg);
//     }
// }
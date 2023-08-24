
console.log("hello world");

var Module = {
    onRuntimeInitialized: function() {
        console.log(Module);
        Module.PrintFormatHello();
    }
};

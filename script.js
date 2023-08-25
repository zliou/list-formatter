
console.log("hello world");

var Module = {
    onRuntimeInitialized: function() {
        console.log(Module);
    }
};

function formatList() {
    console.log("pressed");
    inputText = document.getElementById("input").value;
    console.log("add-double-quotes: " + 
            document.getElementById("add-double-quotes").checked);
    console.log("add-single-quotes: " + 
            document.getElementById("add-single-quotes").checked);
    console.log("add-commas: " + 
            document.getElementById("add-commas").checked);
    Module.PrintFormatHello(inputText);
}


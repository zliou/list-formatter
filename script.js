
console.log("hello world");

var Module = {
    onRuntimeInitialized: function() {
        console.log(Module);
    }
};

function formatList() {
    console.log("pressed");
    inputText = document.getElementById("input").value;
    Module.PrintFormatHello(inputText);
}


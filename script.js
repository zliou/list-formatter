
var Module = {
    onRuntimeInitialized: function() {
        document.getElementById("button-format").removeAttribute("disabled");
        console.log("Formatter ready!");
    }
};

function formatList() {
    inputText = document.getElementById("input").value;
    var result = Module.MakeOptionsAndReformat(
            inputText,
            document.getElementById("add-double-quotes").checked,
            document.getElementById("add-single-quotes").checked,
            document.getElementById("add-commas").checked,
            document.getElementById("add-spaces").checked,
            document.getElementById("add-newlines").checked,
            document.getElementById("sort-output").checked,
            document.getElementById("reverse-sort-output").checked);
    document.getElementById("output").innerHTML = result;
}

// TODO: Add "copy" button to index.html when HTTPS is supported. The Clipboard
//       API is only available over HTTPS contexts.
//       (https://developer.mozilla.org/en-US/docs/Web/API/Clipboard)
function writeOutputToClipboard() {
    navigator.clipboard.writeText(document.getElementById("output").value);
}


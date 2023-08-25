# Learning Notes

Created: 2023 August 24

Author: Zachary Liou

## Empscripten

To activate PATH variables:

```
cd emsdk
source ./emsdk_env.sh
```

To compile a C++ file with Emscripten:
```
emcc foo.cc
```

The above command will generate a JS file `a.out.js`, which can be included in the primary HTML file.

To output an HTML file for debugging:
```
emcc foo.cc -o foo.html
```

To use C++ functions in a JS file, functions must be bound, ...

```
// hello.cc
#include <emscripten/bind.h>

void PrintHello() {
    printf("Hello there!");
}

EMSCRIPTEN_BINDINGS(my_module) {
    emscripten::function("PrintHello", &PrintHello);
}
```

...imported asynchronously (for the WebAssembly compile time), ...
```
<!-- index.html -->
<script>
    var Module = {
        onRuntimeInitialized: function() {
            console.log(Module);
            Module.PrintHello();
        }
    };
</script>
```

... and then compiled with Embind or WebIDL:
```
emcc -lembind -o hello.js hello.cc
```

Note that (it seems like) you can only have one Embind JS file.

## C++

* `gcc` compiles without C++ STL libraries, while `g++` does.

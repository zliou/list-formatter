# List formatter

Created: 2023 August 18

Author: Zachary Liou

This is a C++ WASM library for formatting lists of strings.

## Instructions

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

To run it on a local server:

```
python3 -m http.server
```

Note that you may need to navigate to a particular URL, e.g. `http://0.0.0.0:8000/hello.html`.


#include <stdio.h>
#include <emscripten/bind.h>


void PrintHello() {
    printf("Hello there!");
}

int main() {
    printf("Hello, Emscripten!\n");
    return 0;
}

EMSCRIPTEN_BINDINGS(my_module) {
    emscripten::function("PrintHello", &PrintHello);
}


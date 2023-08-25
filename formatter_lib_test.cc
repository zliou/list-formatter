#include "formatter_lib.cc"

#include <iostream>


int main() {
    bool match = Quote::DOUBLE == TranslateQuoteFromOptions(true, false);
    std::cout << match << std::endl;
}

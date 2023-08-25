#include "formatter_lib.cc"

#include <iostream>
#include <string>


template<class T>
void Test(std::string description, T expected, T actual) {
    bool match = expected == actual;
    std::cout << "[";
    if (match) {
        std::cout << " pass ";
    } else {
        std::cout << "FAILED";
    }
    std::cout << "] " << description << std::endl;
}

void RunTests() {
    Test("DoubleQuoteTranslationSuccess",
         Quote::DOUBLE, TranslateQuoteFromOptions(/*add_double_quotes=*/true,
                                                  /*add_single_quotes=*/false));
    Test("SingleQuoteTranslationSuccess",
         Quote::SINGLE, TranslateQuoteFromOptions(/*add_double_quotes=*/false,
                                                  /*add_single_quotes=*/true));
}


int main() {
    RunTests();
    return 0;
}

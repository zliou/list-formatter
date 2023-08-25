#include "formatter_lib.cc"

#include <emscripten/bind.h>
#include <iostream>
#include <string>
#include <vector>


// Given an input and input/output Options, output the reformatted string.
std::string Reformat(std::string input,
                     Options input_options, Options output_options) {
    std::vector<std::string> tokens = Split(input, input_options.delimiter);
    if (output_options.quote != NONE) {
        for (std::string& s : tokens) {
            AddQuotes(s, output_options.quote);
        }
    }
    return Join(tokens, output_options.delimiter);
}

// Converts form-provided values to Option structs and calls Reformat.
std::string MakeOptionsAndReformat(
        std::string input,
        bool add_double_quotes_to_output,
        bool add_single_quotes_to_output,
        bool add_commas_to_output,
        bool add_spaces_to_output,
        bool add_newlines_to_output) {
    Options default_input_options(",", Quote::NONE);
    Options output_options(
            TranslateDelimiterFromOptions(add_commas_to_output,
                                          add_spaces_to_output,
                                          add_newlines_to_output),
            TranslateQuoteFromOptions(add_double_quotes_to_output,
                                      add_single_quotes_to_output));
    return Reformat(input, default_input_options, output_options);
}


EMSCRIPTEN_BINDINGS(my_module) {
    emscripten::function("Reformat", &Reformat);
    emscripten::function("MakeOptionsAndReformat", &MakeOptionsAndReformat);
}


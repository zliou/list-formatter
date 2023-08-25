//#include "formatter_lib.h"

#include <string>
#include <vector>


namespace {

enum Quote { NONE, SINGLE, DOUBLE };

struct Options {
    Options(std::string delimeter, Quote quote)
            : delimiter(delimeter), quote(quote) {}

    std::string delimiter = ",";
    Quote quote = NONE;
};

// Given a string s, return a vector<string> of s split by the provided
// delimiter.
std::vector<std::string> Split(
        const std::string& s, const std::string& delimiter) {
    std::vector<std::string> result;
    size_t left = 0;
    size_t right = s.find(delimiter, left);
    while (right != std::string::npos) {
        result.push_back(s.substr(left, right - left + 1));
        left = right + 1;
        right = s.find(delimiter, left);
    }
    result.push_back(s.substr(left));
    return result;
}

// Given a vector of strings, combine all strings into a single string,
// separated by the provided delimiter.
std::string Join(const std::vector<std::string>& strings,
                 const std::string& delimiter,
                 bool use_trailing_delimiter = false) {
    if (strings.empty()) {
        return "";
    }
    std::string result = strings[0];
    for (size_t i = 1; i < strings.size(); ++i) {
        result += delimiter;
        result += strings[i];
    }
    if (use_trailing_delimiter) {
        result += delimiter;
    }
    return result;
}

// Add quotes to a given string, in-place. Double quotes by default.
void AddQuotes(std::string& s, const Quote& quote_type) {
    char quote = '"';
    if (quote_type == SINGLE) {
        quote = '\'';
    }
    s.insert(s.begin(), quote);
    s.push_back(quote);
}

Quote TranslateQuoteFromOptions(
        bool add_double_quotes, bool add_single_quotes) {
    if (add_double_quotes) {
        return Quote::DOUBLE;
    } else if (add_single_quotes) {
        return Quote::SINGLE;
    } else {
        return Quote::NONE;
    }
}

std::string TranslateDelimiterFromOptions(
        bool add_commas, bool add_space, bool add_newline) {
    std::string delimiter = "";
    if (add_commas) {
        delimiter += ",";
    }
    if (add_space) {
        delimiter += " ";
    }
    if (add_newline) {
        delimiter += "\n";
    }
    return delimiter;
}

}  // namespace

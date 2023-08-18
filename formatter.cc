#import <string>
#import <vector>


namespace {

// Given a string s, return a vector<string> of s split by the provided
// delimiter.
std::vector<int> Split(const std::string& s, const std::string& delimiter) {
    std::vector<std::string> result;
    size_t left = 0;
    size_t right = s.find(delimiter, left);
    while (right != std::string::npos) {
        result.push_back(s.substr(left, right - left + 1));
        left = right + 1;
        right = s.find(delimiter, left);
    }
    result.push_back(std::stoi(s.substr(left)));
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
void AddQuotes(std::string& s, const Quote& quote) {
    char quote = '';
    if (quote == DOUBLE) {
        quote = '"';
    } else if (quote == SINGLE) {
        quote = '\'';
    }
    s.insert(0, quote);
    s.push_back(quote);
}

}  // namespace


enum Quote { NONE, SINGLE, DOUBLE };


struct Options {
    Options(std::string delimeter, Quote quote)
            : delimiter(delimiter), quote(quote) {}

    std::string delimiter = ",";
    Quote quote = NONE;
};


class Formatter {
  public:
    Formatter(Options input_options, Options output_options)
            : input_options_(input_options), output_options_(output_options) {}

    std::string Reformat(std::string input) {
        std::vector<std::string> tokens = Split(input, input_options_.delimiter);
        if (output_options_.quote != NONE) {
            for (std::string& s : tokens) {
                AddQuotes(s, output_options_.quote);
            }
        }
        return Join(tokens, output_options_.delimiter);
    }

  private:
    Options input_options_;
    Options output_options_;
}




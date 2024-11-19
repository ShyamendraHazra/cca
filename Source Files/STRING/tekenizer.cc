#include <String/tokenizer.h>

std::vector<std::string> string_tokenizer(std::string input_string, std::string delimiter) {
    

    std::vector<std::string> tokens;
    size_t pos = 0;
    std::string token;
    while ((pos = input_string.find(delimiter)) != std::string::npos) {
        token = input_string.substr(0, pos);
        tokens.push_back(token);
        input_string.erase(0, pos + delimiter.length());
    }
    tokens.push_back(input_string);
    return tokens;
}
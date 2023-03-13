#include <string>

std::string disemvowel(const std::string& str) {
    static const char vowels[5] = { 'a', 'e', 'o', 'u', 'i' };
    std::string disemvoweled = "";
    for (const char& c : str) {
        bool vowel = false;
        for (const char& v : vowels) {
            if (tolower(c) == v) {
                vowel = true;
                break;
            }
        }
        if (vowel) continue;
        else disemvoweled += c;
    }
    return disemvoweled;
}
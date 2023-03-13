#include <cstdint>
#include <string>

std::string add_binary(uint64_t a, uint64_t b) {
    uint64_t binsum = a + b;
    unsigned char tmp = 0;
    std::string result = "";
    do {
        tmp = binsum % 2;
        binsum /= 2;
        result += tmp + '0';
    } while (binsum > 0);
    std::reverse(result.begin(), result.end());
    return result;
}
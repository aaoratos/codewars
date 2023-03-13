#include <vector>

std::vector<std::vector<int>> pyramid(std::size_t n) {
    std::vector<std::vector<int>> result = {};
    std::vector<int> tmpv = {};
    while (n > 0) {
        for (std::size_t i = 0; i < n; i++) {
            tmpv.push_back(1);
        }
        result.insert(result.begin(), tmpv);
        --n;
        tmpv.clear();
    }
    return result;
}
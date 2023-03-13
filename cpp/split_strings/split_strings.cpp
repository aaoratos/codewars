#include <string>
#include <vector>

std::vector<std::string> solution(const std::string& s) {
	std::vector<std::string> result;
	for (size_t i = 0; i < s.length(); i += 2) {
		result.push_back(s.substr(i, 2));
	}
	if (s.length() % 2) {
		result[result.size() - 1] += "_";
	}
	return result;
}
#include <vector>

bool valid_braces(std::string braces) {
	std::vector<char> BracesStack = {};
	for (const char& c : braces)
		switch (c) {
			case '(': BracesStack.push_back(')'); break;
			case '[': BracesStack.push_back(']'); break;
			case '{': BracesStack.push_back('}'); break;
			default:
				if (BracesStack.empty() || c != BracesStack.back()) return false;
				else BracesStack.pop_back();
		}
	return true;
}
#include <cctype>

bool XO(const std::string& str) {
  char checksum = 0;
  for (const char& c : str)
    checksum += (std::tolower(c) == 'x') ? 1 : (std::tolower(c) == 'o') ? -1 : 0;
  return !checksum;
}
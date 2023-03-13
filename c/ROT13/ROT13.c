char *rot13(char *str_out, char *str_in) {
  char *cp = str_out;
  for (; *str_in != '\0'; cp++, str_in++) {
    if (*str_in >= 'A' && *str_in <= 'Z')
      *cp = 'A' + (*str_in - 'A' + 13) % 26;
    else if (*str_in >= 'a' && *str_in <= 'z')
      *cp = 'a' + (*str_in - 'a' + 13) % 26;
    else
      *cp = *str_in;
  }
  *cp = '\0';
  return str_out;
}
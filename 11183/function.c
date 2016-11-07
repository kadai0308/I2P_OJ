int ispal(char *str, int front, int end) {
  int distence = (end - front) / 2;
  int output = 0;
  for (int i = 0; i <= distence; ++i) {
    if (str[front + i] == str[end - i]) {
      output = 1;
    } else {
      return output = 0;
    }
  }
  return output;
}
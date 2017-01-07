void shift(char *start, char *end) {
  int d = end - start + 1;
  char tmp1, tmp2;
  if (d == 2) {
    tmp1 = *(start);
     *(start) = *(end);
     *(end) = tmp1;
  } else {
    for (int i = 0; i < d; ++i) {
      if (i == 0) {
        tmp1 = *(start);
        *(start) = *(end);
      } else {
        tmp2 = *(start+i);
        *(start+i) = tmp1;
        tmp1 = tmp2;
      }
    }
  }
}
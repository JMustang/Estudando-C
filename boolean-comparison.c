#include <stdbool.h>
#include <stdio.h>

int main() {

  bool val1 = true;
  bool val2 = false;

  if (val1 == true) {
    printf("%d \n", val1);
  } else {
    printf("%d \n", val2);
  }

  int num = 9;

  bool result = num > 10;
  printf("%d \n", result);

  return 0;
}

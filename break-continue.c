#include <stdio.h>

int main() {
  int i;
  for (i = 0; i < 10; i++) {
    if (i == 5) {
      break;
    } else {
      printf("%d\n", i);
    }
  }

  while (1) {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (number < 0) {
      break;
    }
    printf("%d\n", number);
  }
  return 0;
}

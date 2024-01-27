#include <cstdio>

int main() {
  char arr[50];

  scanf("%49[^\n]", arr);
  printf("%s", arr);
  return 0;
}
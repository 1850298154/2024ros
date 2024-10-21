#include <stdio.h>

struct MyStruct {
  int x;
  double y;
};

int main() {
  printf("Size of MyStruct: %zu\n", sizeof(struct MyStruct));
  printf("Size of MyStruct: %zu\n", sizeof(MyStruct));
  return 0;
}

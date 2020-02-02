#include <stdio.h>

// 当数组作为函数参数传入时，数组就自动退化为同类型的指针，64位系统中指针为8B
int getSize(int data[]) {
  return sizeof(data);
}

int main() {
  int data[] = {1,2,3,4,5};
  int size1 = sizeof(data);
  
  int* pointer_data = data;
  int size2 = sizeof(pointer_data);

  int size3 = getSize(data);

  printf("%d %d %d", size1, size2, size3);

  return 0;
}
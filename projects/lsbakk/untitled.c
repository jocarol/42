#include "stdio.h"

int main(void)
{
  char  testArray[] = "test";

  &testArray = &(testArray - 1);
  printf("%s", (testArray + 1));
  return (0);
}

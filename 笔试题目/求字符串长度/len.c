#include <stdlib.h>
#include <stdio.h>

size_t strlen(char*string)
{
  int length=0;
  while(*string++!='\0')
  length++;
  return length;
}

int main(int argc, char* argv[])
{
  char *p="liunx";
  printf("%d",strlen(p));
}

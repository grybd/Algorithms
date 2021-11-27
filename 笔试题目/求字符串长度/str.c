#include <stdio.h>

#define TRUE 1
#define FALSE 0

int find_char(char**strings,char value)
{
  char*string;
  while((string=*strings++)!=NULL)
  {
    while(*string!='\0')
    {
      if(*string++==value)
      {
        return TRUE;
      }
    }
  }
  return FALSE;
}

int main(int argc, char*argv[])
{
  char*string="hello";
  char a = 'o';
  printf("%d",find_char(&string,a));
}

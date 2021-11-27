#include <bits/stdc++.h>
using namespace std;

char *my_memcpy(char *dst, const char* src, int cnt)
{
    assert(dst != NULL && src != NULL);
    char *ret = dst;
    if (dst >= src && dst <= src+cnt-1) //�ڴ��ص����Ӹߵ�ַ��ʼ����
    {
        dst = dst+cnt-1;
        src = src+cnt-1;
        while (cnt--)
            *dst-- = *src--;
    }
    else    //����������ӵ͵�ַ��ʼ����
    {
        while (cnt--)
            *dst++ = *src++;
    }
    return ret;
}
char* strcpy(char*dst,const char*src)
{
    assert(dst != NULL && src != NULL);
    char *ret = dst;
    my_memcpy(dst, src, strlen(src)+1);
    return ret;
}

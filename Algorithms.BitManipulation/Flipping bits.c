#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t mask = 0xFFFFFFFF;
    int NUM,i;
    uint32_t x;
    
    scanf("%d",&NUM);

    for(i = 0;i<NUM;i++)
    {
        scanf("%u",&x);
        printf("%u\n",x ^ mask);
    }
    return 0;
}

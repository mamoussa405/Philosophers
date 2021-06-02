#include "philo_one.h"

int a, b;
void    *task(void* arg)
{
    if (*((int*)arg))
        while (1)
            a++;
    else
        while (1)
            b++;
    return NULL;
}

int main(void)
{
    int a = 1e6;
    int b;
    scanf("%d", &b);
    while (a--)
    {
        /* code */
    }

    return 0;
}
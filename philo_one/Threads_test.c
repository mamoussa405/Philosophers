#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include "philo_one.h"
typedef struct test
{
    size_t i;
} t_test;

void    copy_data(t_test *philo, size_t i)
{
    philo->i = i;
}
int main(void)
{
    t_test *ptr;

    ptr = (t_test*)malloc(sizeof(t_test) * 3);
    for (size_t i = 0; i < 3; ++i)
        copy_data(&ptr[i], i);
    for (size_t i = 0; i < 3; ++i)
        printf("%zu\n", ptr[i].i);
    return 0;
}
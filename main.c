#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

#include "libasm.h"

void test_strlen(void) {
    printf("----- ft_strlen -----\n");
    const char *strs[] = {"Hello", "", "42 is awesome", NULL};
    for (int i = 0; strs[i]; i++) {
        size_t mine = ft_strlen(strs[i]);
        size_t real = strlen(strs[i]);
        printf("[\"%s\"] ft_strlen = %zu | strlen = %zu\n", strs[i], mine, real);
    }
    printf("\n");
}

int main()
{
    test_strlen();
}
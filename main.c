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

void test_strcmp(void) {
    printf("----- ft_strcmp -----\n");
    const char *tests[][2] = {
        {"abc", "abc"},
        {"abc", "asd"},
        {"abc", "ab"},
        {"", ""},
        {"a", ""},
        {"", "a"},
        {NULL, NULL}
    };

    for (int i = 0; tests[i][0]; i++) {
        int mine = ft_strcmp(tests[i][0], tests[i][1]);
        int real = strcmp(tests[i][0], tests[i][1]);
        printf("ft_strcmp(\"%s\", \"%s\") = %d | strcmp = %d\n",
               tests[i][0], tests[i][1], mine, real);
    }
    printf("\n");
}

void test_strcpy(void) {
    printf("----- ft_strcpy -----\n");
    char buffer[100];

    const char *src = "Hello, world!";
    ft_strcpy(buffer, src);
    printf("ft_strcpy → \"%s\"\n", buffer);
    strcpy(buffer, "test");  // reset
    printf("strcpy    → \"%s\"\n\n", buffer);
    ft_strcpy(buffer, "test");
    printf("ft_strcpy → \"%s\"\n", buffer);
    strcpy(buffer, src);
    printf("strcpy    → \"%s\"\n\n", buffer);
}


int main()
{
    test_strlen();
    test_strcmp();
    test_strcpy();
}
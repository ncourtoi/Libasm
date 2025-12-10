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

void test_write(void) {
    printf("----- ft_write -----\n");
    ssize_t ret;

    errno = 0;
    ret = ft_write(1, "write: Hello world!\n", 21);
    printf("ft_write return = %zd, errno = %d\n", ret, errno);

    errno = 0;
    ret = write(1, "write: Hello world!\n", 21);
    printf("write    return = %zd, errno = %d\n", ret, errno);

    errno = 0;
    ret = ft_write(-1, "bad", 3);
    printf("ft_write (bad fd) = %zd, errno = %d\n", ret, errno);

    errno = 0;
    ret = write(-1, "bad", 3);
    printf("write    (bad fd) = %zd, errno = %d\n\n", ret, errno);
}

void test_read(void) {
    printf("----- ft_read -----\n");
    char buf[100] = {0};

    int fd = open("Makefile", O_RDONLY);
    errno = 0;
    ssize_t ret = ft_read(fd, buf, 21);
    close(fd);
    printf("ft_read returned %zd, errno = %d, buf = \"%*s\"\n", ret, errno, (int)ret, buf);

    memset(buf, 0, sizeof(buf));
    fd = open("Makefile", O_RDONLY);
    errno = 0;
    ret = read(fd, buf, 21);
    close(fd);
    printf("read    returned %zd, errno = %d, buf = \"%*s\"\n", ret, errno, (int)ret, buf);

    errno = 0;
    ret = ft_read(-1, buf, 10);
    printf("ft_read (bad fd) = %zd, errno = %d\n", ret, errno);

    errno = 0;
    ret = read(-1, buf, 10);
    printf("read    (bad fd) = %zd, errno = %d\n\n", ret, errno);
}



void test_strdup(void) {
    printf("----- ft_strdup -----\n");
    char *original = "Libasm is fun!";
    char *mine = ft_strdup(original);
    char *real = strdup(original);

    printf("ft_strdup → \"%s\"\n", mine);
    printf("strdup    → \"%s\"\n", real);

    free(mine);
    free(real);

    mine = ft_strdup("");
    real = strdup("");
    printf("ft_strdup (empty) → \"%s\"\n", mine);
    printf("strdup    (empty) → \"%s\"\n\n", real);

    free(mine);
    free(real);
}

int main()
{
    test_strlen();
    test_strcmp();
    test_strcpy();
    test_write();
    test_read();
    test_strdup();
    return 0;
}
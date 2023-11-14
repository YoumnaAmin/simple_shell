#include "main.h"

char *_strchr(const char *str, int character)
 {
    while (*str != '\0') 
    {
        if (*str == (char)character) 
            return ((char *)str);
        str++;
    }
    return NULL;
}

char *_strtok(char *str, const char *delim) 
{
    static char *ptr;
    int i;

    if (str != NULL)
        ptr = str;


    while (*ptr != '\0' && _strchr(delim, *ptr) != NULL) {
        ptr++;
    }

    if (*ptr == '\0') {
        return NULL;
    }


    for (i = 0; ptr[i] != '\0'; i++) {
        if (_strchr(delim, ptr[i]) != NULL) {
            ptr[i] = '\0';
            ptr = &ptr[i + 1]; 
            return (ptr - i - 1);
        }
    }

    ptr = &ptr[i];
    return (ptr - i);
}
#include <stdio.h>
#include <stdlib.h>

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
    if (!(*lineptr))
    {
        *n = 0;
    }

    size_t pos = 0;
    int ch;

    while ((ch = fgetc(stream)) != EOF && ch != '\n')
    {
        if (pos + 1 >= *n)
        {
            size_t new_size = *n + 128;
            char *new_line = (char *)realloc(*lineptr, new_size);
            if (!new_line)
            {
                free(*lineptr);
                *lineptr = NULL;
                return -1;
            }
            *lineptr = new_line;
            *n = new_size;
        }
        (*lineptr)[pos++] = ch;
    }

    if (ch == EOF && pos == 0)
    {
        return -1;
    }

    (*lineptr)[pos] = '\0';
    return pos;
}


#include "incl/support.h"
#include "incl/tools.h"

int kvazi_puts(char *arr)
{
    check(arr != nullptr, EOF_error)

    int ch = 0;
    size_t count = 0;

    while ( ( ch = putchar(arr[count++]) ) != '\0' && (ch != EOF));
    return (count == 0) ? EOF_error : no_error;
}

int kvazi_strchr(const char *arr, char findin)
{
    hard_check(arr != nullptr)

    int count = 0;

    while (*(arr + count) != findin)
    {
        if (*(arr + count) == '\0')
        {
            printf(RED("В строке нет такого символа!\n"));
            return 0;
        }

        count++;
    }

    return ++count;
}

size_t kvazi_strlen(const char *arr)
{
    size_t count = 0;

    while (*(arr + count) != '\0')
    {
        count++;
    }

    return count;
}

char* kvazi_strcpy(char *in, const char *out) //каждое применение этой функции требует использования check'а с проверкой неравенства указателя и nullptr
{
    hard_check(out != nullptr)
    hard_check(in != nullptr)

    int count = 0;

    while (*(out + count) != '\0')
    {
        *(in + count) = *(out + count);
        count++;
    }

    *(in + count) = '\0';

    return in;
}

char* kvazi_strncpy(char *in, const char *out, size_t end)
{
    hard_check(out != nullptr)
    hard_check(in != nullptr)

    size_t count = 0;

    while (count < end)
    {
        if (*(out + count) == '\0') {
            break;
        }

        *(in + count) = *(out + count);
        count++;
    }

    *(in + count) = '\0';

    return in;
}


char* kvazi_strcat (char *begin, const char *added)
{
    hard_check(begin != nullptr)
    hard_check(added != nullptr)

    // проверяем, сколько элементов в начальной строке
    size_t count = kvazi_strlen(begin);
    size_t num   = 0;

    //со следующего элемента можно начинать записывать
    do
    {
        *(begin + count + num) = *(added + num);
        num++;
    } while (*(added + num) != '\0');

    *(begin + num + count) = '\0';

    return begin;
}

char* kvazi_strncat (char *begin, const char *added, size_t end)
{
    hard_check(begin != nullptr)
    hard_check(added != nullptr)

    size_t count = kvazi_strlen(begin);
    size_t num   = 0;


    //со следующего элемента можно начинать записывать
    do
    {
        *(begin + count + num) = *(added + num);
        num++;
    } while ( (*(added + num) != '\0') && (num < end) );


    return begin;
}

char* kvazi_fgets(char *arr, size_t length_of_array, FILE *data_src)
{
    hard_check(arr != nullptr)
    hard_check(data_src != nullptr)

    int ch = 0;
    size_t count = 0;

    do
    {
        ch = getc(data_src);

        *(arr + count) = (char)ch;
        count++;

        if (count >= length_of_array)
        {
            printf("\033[91mОшибка. Считываемая строка длиннее максимального размера строки, которая была указана в аргументе функции kvazi_fgets\n\033[39m");
            return arr;
        }
    } while ((ch != '\n') && (ch != EOF));

    return (count == 0) ? 0 : arr;
}

char* kvazi_strdup(char *pointer, size_t size_of_array)
{
    hard_check(pointer != nullptr)

    char *arr = (char*) calloc(size_of_array, sizeof(char));

    size_t size = kvazi_strlen(pointer);
    kvazi_strncpy(arr, pointer, size);

    return arr;
}

ssize_t kvazi_getline(char **lineptr, size_t *n, FILE *stream)
{
    check(n != NULL, arg_function_is_nullptr);

    int ch = 0;
    size_t count = 0;

    if (*lineptr == NULL) {
        *lineptr = (char *)calloc(*n, sizeof (char));
    }

    do
    {
        ch = getc(stream);

        (*lineptr)[count] = (char)ch;
        count++;

        if (count >= *n)
        {
            *n *= 2; //новый размер !!!!!!!!!!!!!!!!!!!!!!!!!!
            *lineptr = (char *)realloc(*lineptr, *n);
        }
    } while ((ch != '\n') && (ch != EOF));

    (*lineptr)[count] = '\0';
    return 0;
}











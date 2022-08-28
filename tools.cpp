#include "incl/support.h"
#include "incl/tools.h"

int kvazi_puts(char *mass)
{
    check(mass != nullptr, EOF_error)

    char ch = ' ';
    size_t count = 0;

    while ( ( ch = putchar(mass[count]) ) != '\0' && (ch != EOF))
    {
        count++;
    }
    return (count == 0) ? EOF_error : no_error;
}

int kvazi_strchr(const char *mass, char findin)
{
    hard_check(mass != nullptr)

    int count = 0;

    while (*(mass + count) != findin)
    {
        if (*(mass + count) == '\0')
        {
            printf("\033[91mВ строке нет такого символа!\n\033[39m");
            return 0;
        }
        else
        {
            ;
        }

        count++;
    }

    return ++count;
}

size_t kvazi_strlen(const char *mass)
{
    size_t count = 0;

    while (*(mass+count) != '\0')
    {
        count++;
    }

    return count;
}

size_t kvazi_strlen_for_notconst(char *mass)
{
    size_t count = 0;

    while (*(mass+count) != '\0')
    {
        count++;
    }

    return count;
}

char* kvazi_strcpy(char *in, const char *out) //каждое применение этой функции требует использования check'а с проверкой неравенства указателя и nullptr
{
    hard_check(out != nullptr)
    hard_check(in != nullptr)

    int size = kvazi_strlen_for_notconst(in);
    int count = 0;

    while (count < size)
    {
        *(in + count) = '\0';
        count++;
    }
    count = 0;

    while (*(out + count) != '\0')
    {
        *(in + count) = *(out + count);
        count++;
    }
    return in;
}

char* kvazi_strncpy(char *in, const char *out, size_t end)
{
    hard_check(out != nullptr)
    hard_check(in != nullptr)

    int size = kvazi_strlen_for_notconst(in);
    size_t count = 0;

    while (count < end)
    {
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

    size_t count = 0;

    // проверяем, сколько элементов в начальной строке
    count = kvazi_strlen_for_notconst(begin);

    size_t num = 0;

    //со следующего элемента можно начинать записывать
    do
    {
        *(begin + count + num) = *(added + num);
        num++;
    } while (*(added + num) != '\0');

    *(begin + num + count) = '\0';

    return begin;
}

char* kvazi_strcat (char *begin, const char *added, size_t end)
{
    hard_check(begin != nullptr)
    hard_check(added != nullptr)

    size_t count = kvazi_strlen_for_notconst(begin);

    size_t num = 0;

    //со следующего элемента можно начинать записывать
    do
    {
        *(begin + count + num) = *(added + num);
        num++;
    } while ( (*(added + num) != '\0') && (num < end) );


    return begin;
}

char* kvazi_fgets(char *mass, size_t length_of_array, FILE *data_src)
{
    hard_check(mass != nullptr)
    hard_check(data_src != nullptr)

    char ch[1] = {};
    size_t count = 0;

    do
    {
        fscanf(data_src, "%c", ch);

        *(mass + count) = *ch;


        count++;

        if (count >= length_of_array)
        {
            printf("\033[91mОшибка. Считываемая строка длиннее максимального размера строки, которая была указана в аргументе функции kvazi_fgets\n\033[39m");
            return mass;
        }
    } while ((*ch != '\n') && (*ch != EOF));

    return (count == 0) ? 0 : mass;
}




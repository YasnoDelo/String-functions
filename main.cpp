#include "incl/support.h"
#include "incl/tools.h"

int main()
{
    char file_name[100] = {};
    char mass[100] = {};
    size_t num = 100;

    FILE *file_pointer;

    printf("Введите название файла:\n");
    scanf("%s", file_name);

    printf("Вот название файла\n");
    kvazi_puts(file_name);
    putchar('\n');

    file_pointer = fopen(file_name, "r"); // ругается на то, что аргументы должны быть константами

    kvazi_fgets(mass, num, file_pointer);

    printf("Вот что было в файле: %s", mass);

    fclose(file_pointer);

    const char *test_array = "123456789qwertyuiopasdfghjklzxcvbnm";

    printf("Семёрка в тестовой строке находится на месте № %d", kvazi_strchr(test_array, '7'));

    putchar('\n');

    printf("Всего тестовая строка состоит из 9ти цифр и 26ти букв, то есть всего %ld знаков", kvazi_strlen(test_array));

    putchar('\n');

    printf("Теперь в массиве, отвечающем за имя файла, следующее(это я его содержимое просто вывел, честное слово): %s\n", kvazi_strcpy(file_name, test_array));

    printf("Теперь в массиве, отвечающем за имя файла, следующее(это я его содержимое просто вывел, честное слово. там первые 10 символов должно быть): %s\n",
           kvazi_strncpy(file_name, test_array, 10));

    printf("Теперь в массиве, отвечающем за имя файла, следующее(это я его содержимое просто вывел, честное слово): %s\n", kvazi_strcat(file_name, test_array));

    printf("Теперь в массиве, отвечающем за имя файла, следующее(это я его содержимое просто вывел, честное слово): %s\n",
           kvazi_strcat(file_name, test_array, 10));

    return 0;
}

#include "incl/support.h"
#include "incl/tools.h"

int main()
{
    const size_t size_of_array = 100;

    char file_name[size_of_array] = {};
    char *arr = (char *)calloc(size_of_array, sizeof (char));
    size_t num = size_of_array;

    FILE *file_pointer;

    printf("Введите название файла:\n");
    scanf("%s", file_name);

    printf("Вот название файла\n");
    kvazi_puts(file_name);
    putchar('\n');

    file_pointer = fopen(file_name, "r"); // ругается на то, что аргументы должны быть константами

    kvazi_getline(&arr, &num, file_pointer);

    printf("%s", arr);

    kvazi_fgets(arr, num, file_pointer);

    printf("Вот что было в файле: %s", arr);


    fclose(file_pointer);

    const char *test_array = "123456789qwertyuiopasdfghjklzxcvbnm";

    printf("Семёрка в тестовой строке находится на месте № %d", kvazi_strchr(test_array, '7'));

    putchar('\n');

    printf("Всего тестовая строка состоит из 9ти цифр и 26ти букв, то есть всего %zu знаков", kvazi_strlen(test_array));

    putchar('\n');

    printf("Теперь в массиве, отвечающем за имя файла, следующее(это я его содержимое просто вывел, честное слово): %s\n", kvazi_strcpy(file_name, test_array));

    printf("Теперь в массиве, отвечающем за имя файла, следующее(это я его содержимое просто вывел, честное слово. там первые 10 символов должно быть): %s\n",
           kvazi_strncpy(file_name, test_array, 10));

    printf("Теперь в массиве, отвечающем за имя файла, следующее(это я его содержимое просто вывел, честное слово): %s\n", kvazi_strcat(file_name, test_array));

    printf("Теперь в массиве, отвечающем за имя файла, следующее(это я его содержимое просто вывел, честное слово): %s\n",
           kvazi_strncat(file_name, test_array, 10));

    char* arr2 = kvazi_strdup(file_name, size_of_array);
    printf("А сейчас я вывел содержимое arr2: %s\n", arr2);

    free(arr);
    free(arr2);

    return 0;
}

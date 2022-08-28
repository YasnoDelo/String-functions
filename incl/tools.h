#ifndef tools
#define tools

int kvazi_puts(char *mass);

char* kvazi_fgets(char *mass, size_t length_of_array, FILE *data_src);

int kvazi_strchr(const char *mass, char ch);

size_t kvazi_strlen(const char *mass);

char *kvazi_strcpy(char *out, const char *in);

char* kvazi_strncpy(char *in, const char *out, size_t end);

char* kvazi_strcat (char *destination, const char *append);

char* kvazi_strncat (char *begin, const char *added, size_t num);

char* kvazi_strdup(char *pointer, size_t size_of_array);

ssize_t kvazi_getline(char **lineptr, size_t *n, FILE *stream);


#endif

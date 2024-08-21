#include <stdio.h>
#include <stdlib.h>
#define SIZE 200

int main(int argc, char *argv[])
{
    char name_target[SIZE] = {0};
    char name_source[SIZE] = {0};
    char encoding_sourse[SIZE] = {0};
    FILE *fs = NULL;
    FILE *ft = NULL;
    int counter = 0;
    int read_symbol = 0;
    int zero_byte = 0;
    int first_byte = 0;
    int second_byte = 0;
    int third_byte = 0;
    int unicode_offset = 0;

    if(argc < 2)
    {
       fprintf(stdout, "Enter a name for the source file (or empty text to complete):\n");
       for (counter = 0; (read_symbol = getc(stdin)) != '\n'; counter++)
            name_source[counter] = read_symbol;
       fprintf(stdout, "Enter a name for the source encoding (or empty text to complete):\n");
       for (counter = 0; (read_symbol = getc(stdin)) != '\n'; counter++)
            encoding_sourse[counter] = read_symbol;
       fprintf(stdout, "Enter a name for the target file (or empty text to complete):\n");
       for (counter = 0; (read_symbol = getc(stdin)) != '\n'; counter++)
            name_target[counter] = read_symbol;
       if(strcmp(encoding_sourse, "cp1251") == 0)
          unicode_offset = 848;
       if(strcmp(encoding_sourse, "koi8") == 0)
          unicode_offset = 879;
       if(strcmp(encoding_sourse, "iso-8859-5") == 0)
          unicode_offset = 228;
       while (*name_source != '\0')
       {
          if ((fs = fopen(name_source, "rb")) == NULL)
          {
            fprintf(stderr, "Can't open file %s\n", name_source);
            goto end_circle;
          }
          if ((ft = fopen(name_target, "wb")) == NULL)
          {
            fprintf(stderr, "Can't open file %s\n", name_source);
            goto end_circle;
          }
          while((read_symbol = getc(fs)) != EOF)
          {
             if(read_symbol >= 128)
                read_symbol = read_symbol + unicode_offset;
             if(0 <= read_symbol && read_symbol <= 127)
             {
                putc(read_symbol, ft);
             }
             if(128 <= read_symbol && read_symbol <= 2047)
             {
                zero_byte = (read_symbol & 63);
                zero_byte = (zero_byte | 128);
                first_byte = (read_symbol & 1984);
                first_byte >>= 6;
                first_byte = (first_byte | 192);
                putc(first_byte, ft);
                putc(zero_byte, ft);
             }
             if(2048 <= read_symbol && read_symbol <= 65535)
             {

             }
             if(65536 <= read_symbol && read_symbol <= 2097152)
             {

             }
          }


          if(fclose(fs) != 0)
            printf("Error closing file %s\n", name_source);
          if(fclose(ft) != 0)
            printf("Error closing file %s\n", name_target);
          end_circle:
          memset(name_source, 0, SIZE);


          fprintf(stdout, "Enter a name for the source file (or empty text to complete):\n");
          for (counter = 0; (read_symbol = getc(stdin)) != '\n'; counter++)
              name_source[counter] = read_symbol;
          fprintf(stdout, "Enter a name for the source encoding (or empty text to complete):\n");
          for (counter = 0; (read_symbol = getc(stdin)) != '\n'; counter++)
              encoding_sourse[counter] = read_symbol;
          fprintf(stdout, "Enter a name for the target file (or empty text to complete):\n");
          for (counter = 0; (read_symbol = getc(stdin)) != '\n'; counter++)
              name_target[counter] = read_symbol;
       }
    }
    if(argc == 4)
    {

    }
    printf("Hello world!\n");
    return 0;
}

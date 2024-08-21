#include <stdio.h>
#include <stdlib.h>
#define SIZE 200

int unicode_offset_koi8(int read_symbol);

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
    int flag_koi8 = 0;

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
          flag_koi8 = 1;
       if(strcmp(encoding_sourse, "iso-8859-5") == 0)
          unicode_offset = 864;
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
             if(flag_koi8 == 1)
                unicode_offset = unicode_offset_koi8(read_symbol);
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
int unicode_offset_koi8(int read_symbol)
{
    int unicode_offset = 0;
    switch(read_symbol)
    {
       case 192: unicode_offset = 910; //�
                 break;
       case 193:                       //�
       case 194: unicode_offset = 879; //�
                 break;
       case 195: unicode_offset = 899; //�
                 break;
       case 196:                       //�
       case 197: unicode_offset = 880; //�
                 break;
       case 198: unicode_offset = 894; //�
                 break;
       case 199: unicode_offset = 876; //�
                 break;
       case 200: unicode_offset = 893; //�
                 break;
       case 201:                       //�
       case 202:                       //�
       case 203:                       //�
       case 204:                       //�
       case 205:                       //�
       case 206:                       //�
       case 207:                       //�
       case 208: unicode_offset = 879; //�
                 break;
       case 209: unicode_offset = 894; //�
                 break;
       case 210:                       //�
       case 211:                       //�
       case 212:                       //�
       case 213: unicode_offset = 878; //�
                 break;
       case 214: unicode_offset = 865; //�
                 break;
       case 215: unicode_offset = 859; //�
                 break;
       case 216: unicode_offset = 884; //�
                 break;
       case 217: unicode_offset = 882; //�
                 break;
       case 218: unicode_offset = 861; //�
                 break;
       case 219: unicode_offset = 877; //�
                 break;
       case 220: unicode_offset = 881; //�
                 break;
       case 221: unicode_offset = 876; //�
                 break;
       case 222: unicode_offset = 873; //�
                 break;
       case 223: unicode_offset = 875; //�
                 break;
    }
    return unicode_offset;
}

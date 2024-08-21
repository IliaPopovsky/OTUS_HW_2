#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    if(argc < 4)
    {
       printf("Only %d arguments have been entered, but there should be 4\n", argc);
       goto end;
       /*
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
            fprintf(stderr, "Can't open file %s\n", name_target);
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
                zero_byte = (read_symbol & 63);
                zero_byte = (zero_byte | 128);
                first_byte = (read_symbol & 4032);
                first_byte >>= 6;
                first_byte = (first_byte | 128);
                second_byte = (read_symbol & 61440);
                second_byte >>= 12;
                second_byte = (second_byte | 224);
                putc(second_byte, ft);
                putc(first_byte, ft);
                putc(zero_byte, ft);
             }
             if(65536 <= read_symbol && read_symbol <= 2097152)
             {
                zero_byte = (read_symbol & 63);
                zero_byte = (zero_byte | 128);
                first_byte = (read_symbol & 4032);
                first_byte >>= 6;
                first_byte = (first_byte | 128);
                second_byte = (read_symbol & 258048);
                second_byte >>= 12;
                second_byte = (second_byte | 128);
                third_byte = (read_symbol & 1835008);
                third_byte >>= 18;
                third_byte = (third_byte | 240);
                putc(third_byte, ft);
                putc(second_byte, ft);
                putc(first_byte, ft);
                putc(zero_byte, ft);
             }
          }


          if(fclose(fs) != 0)
            printf("Error closing file %s\n", name_source);
          if(fclose(ft) != 0)
            printf("Error closing file %s\n", name_target);
          end_circle:
          memset(name_source, 0, SIZE);
          memset(name_target, 0, SIZE);
          memset(encoding_sourse, 0, SIZE);
          counter = 0;
          read_symbol = 0;
          zero_byte = 0;
          first_byte = 0;
          second_byte = 0;
          third_byte = 0;
          unicode_offset = 0;
          flag_koi8 = 0;


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
       */
    }
    if(argc == 4)
    {
       if(strcmp(argv[2], "cp1251") == 0)
           unicode_offset = 848;
       else if(strcmp(argv[2], "koi8") == 0)
                flag_koi8 = 1;
            else if(strcmp(argv[2], "iso-8859-5") == 0)
                     unicode_offset = 864;
                 else
                 {
                     printf("The program %s cannot process the encoding %s\n", argv[0], argv[2]);
                     goto end;
                 }

       if(*argv[1] != '\0')
       {
          if ((fs = fopen(argv[1], "rb")) == NULL)
          {
            fprintf(stderr, "Can't open file %s\n", argv[1]);
            goto end;
          }
          if ((ft = fopen(argv[3], "wb")) == NULL)
          {
            fprintf(stderr, "Can't open file %s\n", argv[3]);
            goto end;
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
                zero_byte = (read_symbol & 63);
                zero_byte = (zero_byte | 128);
                first_byte = (read_symbol & 4032);
                first_byte >>= 6;
                first_byte = (first_byte | 128);
                second_byte = (read_symbol & 61440);
                second_byte >>= 12;
                second_byte = (second_byte | 224);
                putc(second_byte, ft);
                putc(first_byte, ft);
                putc(zero_byte, ft);
             }
             if(65536 <= read_symbol && read_symbol <= 2097152)
             {
                zero_byte = (read_symbol & 63);
                zero_byte = (zero_byte | 128);
                first_byte = (read_symbol & 4032);
                first_byte >>= 6;
                first_byte = (first_byte | 128);
                second_byte = (read_symbol & 258048);
                second_byte >>= 12;
                second_byte = (second_byte | 128);
                third_byte = (read_symbol & 1835008);
                third_byte >>= 18;
                third_byte = (third_byte | 240);
                putc(third_byte, ft);
                putc(second_byte, ft);
                putc(first_byte, ft);
                putc(zero_byte, ft);
             }
          }

          if(fclose(fs) != 0)
            printf("Error closing file %s\n", argv[1]);
          if(fclose(ft) != 0)
            printf("Error closing file %s\n", argv[3]);
       }
    }
    end:
    printf("This program exits!\n");
    return 0;
}
int unicode_offset_koi8(int read_symbol)
{
    int unicode_offset = 0;
    switch(read_symbol)
    {
       case 192: unicode_offset = 910; //þ
                 break;
       case 193:                       //à
       case 194: unicode_offset = 879; //á
                 break;
       case 195: unicode_offset = 899; //ö
                 break;
       case 196:                       //ä
       case 197: unicode_offset = 880; //å
                 break;
       case 198: unicode_offset = 894; //ô
                 break;
       case 199: unicode_offset = 876; //ã
                 break;
       case 200: unicode_offset = 893; //õ
                 break;
       case 201:                       //è
       case 202:                       //é
       case 203:                       //ê
       case 204:                       //ë
       case 205:                       //ì
       case 206:                       //í
       case 207:                       //î
       case 208: unicode_offset = 879; //ï
                 break;
       case 209: unicode_offset = 894; //ÿ
                 break;
       case 210:                       //ð
       case 211:                       //ñ
       case 212:                       //ò
       case 213: unicode_offset = 878; //ó
                 break;
       case 214: unicode_offset = 864; //æ
                 break;
       case 215: unicode_offset = 859; //â
                 break;
       case 216: unicode_offset = 884; //ü
                 break;
       case 217: unicode_offset = 882; //û
                 break;
       case 218: unicode_offset = 861; //ç
                 break;
       case 219: unicode_offset = 877; //ø
                 break;
       case 220: unicode_offset = 881; //ý
                 break;
       case 221: unicode_offset = 876; //ù
                 break;
       case 222: unicode_offset = 873; //÷
                 break;
       case 223: unicode_offset = 875; //ú
                 break;
       //////////////////////////////////
       case 224: unicode_offset = 846; //Þ
                 break;
       case 225:                       //À
       case 226: unicode_offset = 815; //Á
                 break;
       case 227: unicode_offset = 835; //Ö
                 break;
       case 228:                       //Ä
       case 229: unicode_offset = 816; //Å
                 break;
       case 230: unicode_offset = 830; //Ô
                 break;
       case 231: unicode_offset = 812; //Ã
                 break;
       case 232: unicode_offset = 829; //Õ
                 break;
       case 233:                       //È
       case 234:                       //É
       case 235:                       //Ê
       case 236:                       //Ë
       case 237:                       //Ì
       case 238:                       //Í
       case 239:                       //Î
       case 240: unicode_offset = 815; //Ï
                 break;
       case 241: unicode_offset = 830; //ß
                 break;
       case 242:                       //Ð
       case 243:                       //Ñ
       case 244:                       //Ò
       case 245: unicode_offset = 814; //Ó
                 break;
       case 246: unicode_offset = 800; //Æ
                 break;
       case 247: unicode_offset = 795; //Â
                 break;
       case 248: unicode_offset = 820; //Ü
                 break;
       case 249: unicode_offset = 818; //Û
                 break;
       case 250: unicode_offset = 797; //Ç
                 break;
       case 251: unicode_offset = 813; //Ø
                 break;
       case 252: unicode_offset = 817; //Ý
                 break;
       case 253: unicode_offset = 812; //Ù
                 break;
       case 254: unicode_offset = 809; //×
                 break;
       case 255: unicode_offset = 811; //Ú
                 break;

    }
    return unicode_offset;
}

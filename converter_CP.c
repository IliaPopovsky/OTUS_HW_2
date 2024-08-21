#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 200

int unicode_offset_koi8(int read_symbol);

int main(int argc, char *argv[])
{
    FILE *fs = NULL;
    FILE *ft = NULL;
    int read_symbol = 0;
    int zero_byte = 0;
    int first_byte = 0;
    int second_byte = 0;
    int third_byte = 0;
    int unicode_offset = 0;
    int flag_koi8 = 0;

    if(argc != 4)
    {
       printf("Only %d arguments have been entered, but there should be 4\n", argc);
       goto end;
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
       case 214: unicode_offset = 864; //�
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
       //////////////////////////////////
       case 224: unicode_offset = 846; //�
                 break;
       case 225:                       //�
       case 226: unicode_offset = 815; //�
                 break;
       case 227: unicode_offset = 835; //�
                 break;
       case 228:                       //�
       case 229: unicode_offset = 816; //�
                 break;
       case 230: unicode_offset = 830; //�
                 break;
       case 231: unicode_offset = 812; //�
                 break;
       case 232: unicode_offset = 829; //�
                 break;
       case 233:                       //�
       case 234:                       //�
       case 235:                       //�
       case 236:                       //�
       case 237:                       //�
       case 238:                       //�
       case 239:                       //�
       case 240: unicode_offset = 815; //�
                 break;
       case 241: unicode_offset = 830; //�
                 break;
       case 242:                       //�
       case 243:                       //�
       case 244:                       //�
       case 245: unicode_offset = 814; //�
                 break;
       case 246: unicode_offset = 800; //�
                 break;
       case 247: unicode_offset = 795; //�
                 break;
       case 248: unicode_offset = 820; //�
                 break;
       case 249: unicode_offset = 818; //�
                 break;
       case 250: unicode_offset = 797; //�
                 break;
       case 251: unicode_offset = 813; //�
                 break;
       case 252: unicode_offset = 817; //�
                 break;
       case 253: unicode_offset = 812; //�
                 break;
       case 254: unicode_offset = 809; //�
                 break;
       case 255: unicode_offset = 811; //�
                 break;
    }
    return unicode_offset;
}

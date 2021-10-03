#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

const int BLOCKSIZE = 512;
int count = 0;


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Can't open file\n");
        return 1;
    }

    BYTE buffer[BLOCKSIZE];
    char filename[8];
    FILE *img = NULL;
    while (fread(&buffer, sizeof(BYTE), 512, file) >= 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count != 0)
            {
                fclose(img);
            }
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
            fwrite(&buffer, sizeof(BYTE), 512, img);
            count++;
        }
        else
        {
            if (img != NULL)
            {
                fwrite(&buffer, sizeof(BYTE), 512, img);
            }
        }
    }
    fclose(img);
    fclose(file);

    FILE *test = fopen("000.jpg", "r");
    fread(&buffer, sizeof(BYTE), 512, test);
    printf("%x %x %x %x\n", buffer[0], buffer[1], buffer[2], buffer[3]);
    fclose(test);
}
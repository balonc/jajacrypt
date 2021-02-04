#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *binarization(char *filename)
{
    int counter = 0;
    while (filename[counter] != '\0')
    {
        if (filename[counter] == 'J' || filename[counter] == 'j')
        {
            filename[counter] = '0';
        } 
        else if (filename[counter] == 'A' || filename[counter] == 'a')
        {
             filename[counter] = '1';
        }
        counter++;
    }

    return filename;
}

unsigned long binaryToDecimal(char *binary, int length)
{
    int i;
    unsigned long decimal = 0;
    unsigned long weight = 1;
    binary += length - 1;
    weight = 1;
    for(i = 0; i < length; ++i, --binary)
    {
        if(*binary == '1')
            decimal += weight;
        weight *= 2;
    }
    return decimal;
}

void binaryToText(char *binary, int binaryLength, char *text, int symbolCount)
{
    int i;
    for(i = 0; i < binaryLength; i+=8, binary += 8)
    {
        char *byte = binary;
        byte[8] = '\0';
        
        *text++ = binaryToDecimal(byte, 8);
    }
    text -= symbolCount;
}

int main(int argc, char **argv)
{
    char *filename;
    char *argument;
    char *crypt = "crypt";
    char *decrypt = "decrypt";
    argument = argv[1];  
    filename = argv[2];

    binarization(filename);

    if (strcmp(argument,crypt) == 0)
    {
        printf("Crypting\n");
    }
    else if (strcmp(argument,decrypt) == 0)
    {
        char *text;
        int binaryLength, symbolCount;

        binaryLength = strlen(filename);
        symbolCount = binaryLength / 8 + 1;
        text = malloc(symbolCount + 1);

        binaryToText(filename, binaryLength, text, symbolCount);
        printf("%s\n", text);
        
        free(text);
    }

    return 0;
}
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

char* decimalToBinary(long decimal)
{
    char *binary = malloc(65);
    if(binary == NULL)
        exit(1);
    binary += 64;
    *binary = '\0';
    if(decimal == 0)
    {
        --binary;
        *binary = '0';
    }
    while(decimal > 0)
    {
        --binary;
        *binary = decimal % 2 + '0';
        decimal = decimal / 2;
    }
    return binary;
}

void textToBinary(char *text, int textLength, char *binary, int binaryLength)
{
    char *octet = malloc(9);
    if(octet == NULL)
        exit(1);
    while(*text)
    {
        decimalToBinary(*text);
        while(*octet)
            *binary++ = *octet++;
        *binary++ = ' ';
        ++text;
        octet -= 8;
    }
    *binary = '\0';
    binary -= binaryLength;
    free(octet);
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
        char text[101];
        char *binary;
        int textLength, binaryLength;
        
        scanf("%100[^\n]s", text);
        textLength = strlen(text);
        binaryLength = textLength * 9;      // 8 binary digits + 1 space separator
        binary = malloc(binaryLength + 1);  // + 1 null terminator
        if (binary == NULL) exit(1);
        
        textToBinary(text, textLength, binary, binaryLength);
        printf("Your binary encoding is:\n%s\n", binary);
        
        free(binary);
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
#include <stdio.h>

int main(int argc, char **argv)
{
    char *filename;
    int counter = 0;
    filename = argv[1];
    printf("The string is: %s", filename);

    while(filename[counter] != '\0')
    {
        if(filename[counter] == 'J')
        {
            filename[counter] = '0';
        } 
        else if (filename[counter] == 'A')
        {
             filename[counter] = '1';
        }
        counter++;
    }
    printf("\nBinary string: %s\n", filename);

    return 0;
}
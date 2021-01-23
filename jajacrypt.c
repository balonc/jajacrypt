#include <stdio.h>

char *binarization(char *filename)
{
    int counter = 0;
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

    return filename;

}

int main(int argc, char **argv)
{
    char *filename;    
    filename = argv[1];
    printf("The string is: %s", filename);

    binarization(filename);

    printf("\nBinary string: %s\n", filename);

    return 0;
}
#include <stdio.h>

int main(int argc, char **argv)
{
    char *filename;
    int counter;
    filename = argv[1];
    printf("The filename is: %s", filename);

    // while(filename[counter] != '\0')
    // {
    //     if(filename[counter] == 'a')
    //     {
    //         filename[counter] = '*';
    //     }
    //     counter++;
    // }
    // printf("\nReplaced Character in String: %s\n", filename);

    return 0;
}
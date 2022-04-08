#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }
    //Open file
    FILE *rawImageFile = fopen(argv[1], "r");
    if (rawImageFile == NULL)
    {
        printf("Couldn't open file");
        return 2;
    }
    //Declare variable array buffer 512kb
    unsigned char buffer[512];
    //Declare pics count
    int pics_number = 0;
    //Initilize resulting file
    FILE *output_file = NULL;
    char *filename = malloc(8 * sizeof(char));
    //Looking for jpg sequence
    while (fread(buffer, sizeof(char), 512, rawImageFile) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //write into file name in form 001.jpg, 002.jpg and so on
            sprintf(filename, "%03i.jpg", pics_number);

            //open filename for writing
            output_file = fopen(filename, "w");

            //count number of image found
            pics_number++;
        }
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    free(filename);
    fclose(rawImageFile);
    fclose(output_file);
    return 0;
}
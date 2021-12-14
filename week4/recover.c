#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t BYTE; // sets BYTE to 8 bits

int main(int argc, char *argv[])
{
    if (argc != 2) // if more or less than 2 cla gives error message
    {
        printf("need only 1 cla argument");
        return 1;
    }

    FILE *inptr = fopen(argv[1], "r");  //opens up the file in cla [1] to read
    if (!inptr) //if unable to open file gives error
    {
        printf("can not open argv1 file");
        return 2;
    }

    FILE *outptr = NULL; //sets outptr file to null

    BYTE buffer[512]; //sets the buffer to 512 bytes the length of a block

    int jpeg = 0; //initiates the picture counter starting a 0

    char filename[8] = {0}; //creates the string for filename an array that starts a 0

    while (fread(buffer, sizeof(BYTE) * 512, 1, inptr)) //reads the input file for one block
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) //looks to check if the
            //one block that was read start with the four bytes of a jpeg if so...
        {
            if (outptr != NULL) // if the output is not empty or has data then close
            {
                fclose(outptr);
            }
            sprintf(filename, "%03d.jpg", jpeg++); // creates the new file name based on count adds to the counter

            outptr = fopen(filename, "w"); // sets outptr to open the current filename and write
        }

        if (outptr != NULL) //if not empty goes on to write
        {
            fwrite(buffer, sizeof(BYTE) * 512, 1, outptr); //writes the buffer or block of input file to output file
        }
    }
    return 0; // end program with no error
}

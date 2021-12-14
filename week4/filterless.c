#include "helpers.h"
//#include "bmp.h"
#include <math.h>
#include <cs50.h>
#include <stdio.h>
#include <stdint.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) // starts grayscale fxn input of height, width. and
//RGBTRIPLE image height and width
//RGBTRIPLE gets byte for red, blue , gree
//goal of grayscal is to get the average for each pixel
{
    //need to open files to start with look to filters.c to get open code
    //char *infile = argv[optind]; does not work no argv input , included input == height width image if i use image maybe we dont need
    //these other files?
    //char *outfile = argv[optind + 1];

    float rgbtGray;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //if (image[i][j] > 0);

            //print test to check if we get three colors for each pixel

            float n = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            rgbtGray = round(n);

            image[i][j].rgbtRed = rgbtGray;
            image[i][j].rgbtGreen = rgbtGray;
            image[i][j].rgbtBlue = rgbtGray;

            //printf("Grayscale number: %f\n", rgbtGray);


            //get three color values using RGBTRIPLE
            //printf("Blue: %i\n", rgbtBlue); states undeclared for Blue Red and Green
            //printf("Green: %i\n", rgbtGreen);
            //printf("Red: %i\n", rgbtRed);
            //float avg = (rgbtRed + rgbtGreen + rgbtBlue) / 3;
            //round avg;
            //printf("%f\n", avg);

        }
    }
    return;
}



// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // run for loop with i for height and j for width looking at each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //call sepia colors
            float sepiaRed;
            float sepiaBlue;
            float sepiaGreen;

            //apply sepia red equation
            float r = (.393 * image[i][j].rgbtRed) + (.769 * image[i][j].rgbtGreen) + (.189 * image[i][j].rgbtBlue);
            sepiaRed = round(r);
            //round(sepiaRed);

            //set to max of 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            //apply sepia green equation
            float g = (.349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) + (.168 * image[i][j].rgbtBlue);
            sepiaGreen = round(g);
            //round(sepiaGreen);

            //set max at 255
            if (sepiaGreen >255)
            {
                sepiaGreen = 255;
            }

            //apply sepia blue equation
            float b = (.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) + (.131 * image[i][j].rgbtBlue);
            sepiaBlue = round(b);
            //round(sepiaBlue);

            //set max to 255
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            //change orginal colors to new sepia colors
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp[3];
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width / 2; j++) //why was the /2 nessecarry? so only goes through have the width of the pic
        {
            temp[0] = image[i][j].rgbtRed; //creates a temp array that holds the orginal RGB
            temp[1] = image[i][j].rgbtGreen;
            temp[2] = image[i][j].rgbtBlue;

            // get length?
            //printf("width: %i\n", j );
            //get orginal postition
           // printf("width: %i\n", width); //600 to get 0 to 600 = j + width
            //for j 1 + width - j
           //int n = (width - j) - 1;

           //changes the orgianl RGB to the new location

            image[i][j].rgbtRed = image[i][(width - j) - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][(width - j) - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][(width - j) - 1].rgbtBlue;

            //changes what was in the new location to the temp or orginal pixels
            image[i][(width - j) - 1].rgbtRed = temp[0];
            image[i][(width - j) - 1].rgbtGreen = temp[1];
            image[i][(width - j) - 1].rgbtBlue = temp[2];

            //image[i][j].rgbtRed = image[i][j - width].rgbtRed;
           // image[i][j].rgbtGreen = image[i][j - width].rgbtGreen;
           // image[i][j].rgbtBlue = image[i][j - width].rgbtBlue;

            //move far left to far right

        }
    }
    return;
}



void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //need to make a temp file like the red and blue glasses

    RGBTRIPLE temp[height][width]; //sets temp image

    //make i and j array
    for (int i = 0; i < height; i++) //makes height array with i
    {
        for (int j = 0; j < width; j++) //makes width array with j
        {
            //sets the sum for RGB and counter to 0
            float sumRed = 0;
            float sumGreen = 0;
            float sumBlue = 0;
            float counter = 0;

            for (int r = -1; r < 2; r++) //makes the array of r of the 9 grid i side
            {
                for (int c = -1; c < 2; c++) // makes the array of c for the 9 grid j side
                {
                    if (r + i < 0 || r + i > height - 1) // if the r compared element plus the i. current elemet are less than
                    //0 or greater that the height -1 continue
                    //ex think through if current element is [2][3] with a h of 5 and w 6 then 9 grid would be
                    //[1][2], [1][3], 1[4], [2][2], [2][3], [2][4], [3][2], [3][3], [3][4]
                    //so i would be 2 j would be 3; r would be -1 so new sum would be -1, 2, 3 for i , for j 2, 3, 4
                    //if less than 0 or greater that 6 -1 or 5 moves on?
                    {
                        continue; //what does continue do exatlly in a if loop? it hops the next step in the loop with out doing any
                        //thing.
                    }
                    if (c + j < 0 || c + j > width - 1) // same but for width with c and j
                    {
                        continue;
                    }
                    sumRed += image[i + r][j + c].rgbtRed; //creates the sum of red
                    sumGreen += image[i + r][j + c].rgbtGreen; // green
                    sumBlue += image[i + r][j + c].rgbtBlue; //blue
                    counter++; //adds count to counter
                }
            }
            //set the tempt to the sum

            temp[i][j].rgbtRed =  round(sumRed / counter);
            temp[i][j].rgbtGreen = round(sumGreen / counter);
            temp[i][j].rgbtBlue = round(sumBlue / counter);

        }
    }

        //set orginal to temp

        for (int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                image[i][j].rgbtRed = temp[i][j].rgbtRed;
                image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
                image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            }
        }

    //
    return;
}

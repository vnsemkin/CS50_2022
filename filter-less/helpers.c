#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Doing grayscale algoritm
            float average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            image[i][j].rgbtBlue = round(average);
            image[i][j].rgbtGreen = round(average);
            image[i][j].rgbtRed = round(average);
        }
    }
    return;
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Doing Sepia algoritm
            float sepiaRed = image[i][j].rgbtRed * .393 + image[i][j].rgbtGreen * .769 + image[i][j].rgbtBlue * .189;
            float sepiaGreen = image[i][j].rgbtRed * .349 + image[i][j].rgbtGreen * .686 + image[i][j].rgbtBlue * .168;
            float sepiaBlue = image[i][j].rgbtRed * .272 + image[i][j].rgbtGreen * .534 + image[i][j].rgbtBlue * .131;
            //Rooud value to 0 - 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            //Convert float to integer
            image[i][j].rgbtRed = round(sepiaRed);
            image[i][j].rgbtGreen = round(sepiaGreen);
            image[i][j].rgbtBlue = round(sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            //Making copy of original image to copy to the left side
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;
            //Reflect left side of image to the right
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            //Reflect right side to the left
            image[i][width - j - 1].rgbtRed = originalRed;
            image[i][width - j - 1].rgbtGreen = originalGreen;
            image[i][width - j - 1].rgbtBlue = originalBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Template for temp pic
    RGBTRIPLE tempImage[height][width];
    //Iterate through 2D array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Itterate surrounding pixels
            int count = 0;
            float averageRed = 0;
            float averageGreen = 0;
            float averageBlue = 0;
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int columns = i + x;
                    int row = j + y;
                    //Check borders
                    if (columns < 0 || columns > (height - 1) || row < 0 || row > (width - 1))
                    {
                        continue;
                    }
                    //Calculate average value surrounding pixels
                    averageRed += image[columns][row].rgbtRed;
                    averageGreen += image[columns][row].rgbtGreen;
                    averageBlue += image[columns][row].rgbtBlue;
                    count++;


                }
            }
            //Find the average value for colors
            int red = round(averageRed / count);
            int green = round(averageGreen / count);
            int blue = round(averageBlue / count);
            //Check value is correct and less than 255
            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }
            //Copy new value of color to temp pic
            tempImage[i][j].rgbtRed = red;
            tempImage[i][j].rgbtGreen = green;
            tempImage[i][j].rgbtBlue = blue;
        }
    }
    //Itterate temp pic with blur effect to original one
    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            image[a][b].rgbtRed = tempImage[a][b].rgbtRed;
            image[a][b].rgbtGreen = tempImage[a][b].rgbtGreen;
            image[a][b].rgbtBlue = tempImage[a][b].rgbtBlue;
        }
    }
    return;
}

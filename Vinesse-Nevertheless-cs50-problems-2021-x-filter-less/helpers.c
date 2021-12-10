#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

//Prototypes
void interiorBlur(int startRow, int startCol, int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE copy[height][width]);
void leftTopCornerBlur(int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE copy[height][width]);
void leftBottomCornerBlur(int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE copy[height][width]);
void rightTopCornerBlur(int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE copy[height][width]);
void rightBottomCornerBlur(int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE copy[height][width]);
void topBorderBlur(int startCol, int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE copy[height][width]);
void bottomBorderBlur(int startCol, int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE copy[height][width]);
void leftBorderBlur(int startRow, int startCol, int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE copy[height][width]);
void rightBorderBlur(int startRow, int startCol, int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE copy[height][width]);
void addBlurredPixel(int startRow, int startCol, int div, int height, int width, RGBTRIPLE image[height][width]);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avg = 0.0;
    int shade_of_gray = 0;

    //average the red, green and blue color values for each pixel together and then replace colored pixel with gray pixel
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            avg = (image[r][c].rgbtRed + image[r][c].rgbtGreen + image[r][c].rgbtBlue) / 3.0;
            shade_of_gray = round(avg);
            image[r][c].rgbtRed = shade_of_gray;
            image[r][c].rgbtGreen = shade_of_gray;
            image[r][c].rgbtBlue = shade_of_gray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepRed = 0;
    int sepGreen = 0;
    int sepBlue = 0;

    //Use following formula to determine RGB sepia value for pixel
    for (int r = 0; r < width; r++)
    {
        for (int c = 0; c < width; c++)
        {
            sepRed = round(image[r][c].rgbtRed * 0.393
                   + image[r][c].rgbtGreen * 0.769
                   + image[r][c].rgbtBlue * 0.189);

            sepGreen = round(image[r][c].rgbtRed * 0.349
                   + image[r][c].rgbtGreen * 0.686
                   + image[r][c].rgbtBlue * 0.168);

            sepBlue = round(image[r][c].rgbtRed * 0.272
                   + image[r][c].rgbtGreen * 0.534
                  + image[r][c].rgbtBlue * 0.131);

            //If RGB sepia value is greater than 255, reassign it to 255
            if (sepRed > 255)
            {
                sepRed = 255;
            }
            if (sepGreen > 255)
            {
                sepGreen = 255;
            }
            if (sepBlue > 255)
            {
                sepBlue = 255;
            }

            image[r][c].rgbtRed = sepRed;
            image[r][c].rgbtGreen = sepGreen;
            image[r][c].rgbtBlue = sepBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //swap pixels
    for (int r = 0; r < width; r++)
    {
        for (int c = 0, opp = width - 1; c < height; c++, opp--)
        {
            //create a temp place to store the pixels on the left side of photo
            int tempR = image[r][c].rgbtRed;
            int tempG = image[r][c].rgbtGreen;
            int tempB = image[r][c].rgbtBlue;

            //Stop swapping pixels if you are halfway thru the width of the photo
            if (c + 1 <= width / 2)
            {
                image[r][c].rgbtRed = image[r][opp].rgbtRed;
                image[r][c].rgbtGreen = image[r][opp].rgbtGreen;
                image[r][c].rgbtBlue = image[r][opp].rgbtBlue;

                image[r][opp].rgbtRed = tempR;
                image[r][opp].rgbtGreen = tempG;
                image[r][opp].rgbtBlue = tempB;
            }
        }
    }
    return;
}

// Blur image

//Global variables
float sumR = 0;
float sumG = 0;
float sumB = 0;

//Constants
float div4 = 4.0;
float div6 = 6.0;
float div9 = 9.0;

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*copy)[width] = calloc(height, width * (2 * sizeof(RGBTRIPLE)));
//copy image
    for (int r = 0; r < width; r++)
    {
        for (int c = 0; c < width; c++)
        {
            copy[r][c].rgbtRed = image[r][c].rgbtRed;
            copy[r][c].rgbtGreen = image[r][c].rgbtGreen;
            copy[r][c].rgbtBlue =  image[r][c].rgbtBlue;
        }
    }
    //call blur methods depending on where you are in the image
    for (int r = 0; r < width; r++)
    {
        for (int c = 0; c < height; c++)
        {
            if (c == 0)
            {
                leftTopCornerBlur(height, width, image, copy);

            }
            if (r == 0 && (c > 0 && c < height - 1))
            {
                topBorderBlur(c, height, width, image, copy);
            }
            if (c == height - 1)
            {
                rightTopCornerBlur(height, width, image, copy);

            }
            if (r > 0 && c < 2)
            {
                leftBorderBlur(r, c, height, width, image, copy);
            }
            if ((r > 0 && r < width -1) && c >= width - 2)
            {
                rightBorderBlur(r, c, height, width, image, copy);
            }
            if (r >= width - 2)
            {
                leftBottomCornerBlur(height, width, image, copy);
                rightBottomCornerBlur(height, width, image, copy);
            }
            if (r == width - 1 && (c > 0 && c < height - 1))
            {
                bottomBorderBlur(c, height, width, image, copy);
            }
            if ((r > 0 && r < width - 1) && (c > 0 && c < height - 1))
            {
                interiorBlur(r, c, height, width, image, copy);
            }
        }
    }
    free(copy);
    return;
}

//Methods compute the blurs for the corners, borders, interior of photo using cs50 specs

void leftTopCornerBlur(int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE copy[height][width])
{
    for (int r = 0; r < 2; r++)
    {
        for (int c = 0; c < 2; c++)
        {
            sumR += copy[r][c].rgbtRed;
            sumG += copy[r][c].rgbtGreen;
            sumB += copy[r][c].rgbtBlue;
        }
    }

    addBlurredPixel(0, 0, div4, height, width, image);

    return;

}


void leftBorderBlur(int startRow, int startCol, int height, int width, RGBTRIPLE image[height][width],
                    RGBTRIPLE copy[height][width])
{
    for (int r = startRow - 1 ; r < startRow + 2; r++)
    {
        for (int c = 0; c < 2; c++)
        {
            sumR += copy[r][c].rgbtRed;
            sumG += copy[r][c].rgbtGreen;
            sumB += copy[r][c].rgbtBlue;
        }
    }

    addBlurredPixel(startRow, startCol, div6, height, width, image);

}
void leftBottomCornerBlur(int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE copy[height][width])
{
    for (int r = width - 2; r < width; r++)
    {
        for (int c = 0; c < 2; c++)
        {
            sumR += copy[r][c].rgbtRed;
            sumG += copy[r][c].rgbtGreen;
            sumB += copy[r][c].rgbtBlue;
        }
    }

    addBlurredPixel(width - 1, 0, div4, height, width, image);

    return;

}

void rightTopCornerBlur(int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE copy[height][width])
{
    for (int r = 0; r < 2; r++)
    {
        for (int c = height - 2 ; c < height; c++)
        {
            sumR += copy[r][c].rgbtRed;
            sumG += copy[r][c].rgbtGreen;
            sumB += copy[r][c].rgbtBlue;
        }
    }

    addBlurredPixel(0, height - 1, div4, height, width, image);

    return;

}
void rightBottomCornerBlur(int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE copy[height][width])
{
    for (int r = width - 2; r <= width - 1; r++)
    {
        for (int c = height - 2; c <= height - 1; c++)
        {
            sumR += copy[r][c].rgbtRed;
            sumG += copy[r][c].rgbtGreen;
            sumB += copy[r][c].rgbtBlue;
        }
    }

    addBlurredPixel(width-1, height - 1, div4, height, width, image);

    return;

}
void topBorderBlur(int startCol, int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE copy[height][width])
{
    for (int r = 0; r < 2; r++)
    {
        for (int c = startCol - 1; c < startCol + 2; c++)
        {
            sumR += copy[r][c].rgbtRed;
            sumG += copy[r][c].rgbtGreen;
            sumB += copy[r][c].rgbtBlue;
        }
    }

    addBlurredPixel(0, startCol, div6, height, width, image);

}

void rightBorderBlur(int startRow, int startCol, int height, int width, RGBTRIPLE image[height][width],
                    RGBTRIPLE copy[height][width])
{
    for (int r = startRow - 1 ; r < startRow + 2; r++)
    {
        for (int c = height - 2 ; c < height; c++)
        {
            sumR += copy[r][c].rgbtRed;
            sumG += copy[r][c].rgbtGreen;
            sumB += copy[r][c].rgbtBlue;
        }
    }

    addBlurredPixel(startRow, startCol, div6, height, width, image);

}

void bottomBorderBlur(int startCol, int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE copy[height][width])
{
    for (int r = width - 2; r < width; r++)
    {
        for (int c = startCol - 1; c < startCol + 2; c++)
        {
            sumR += copy[r][c].rgbtRed;
            sumG += copy[r][c].rgbtGreen;
            sumB += copy[r][c].rgbtBlue;
        }
    }

    addBlurredPixel(width - 1, startCol, div6, height, width, image);

}

void interiorBlur(int startRow, int startCol, int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE copy[height][width])
{
    for (int r = startRow - 1; r < startRow + 2; r++)
    {
        for (int c = startCol - 1; c < startCol + 2; c++)
        {
            sumR += copy[r][c].rgbtRed;
            sumG += copy[r][c].rgbtGreen;
            sumB += copy[r][c].rgbtBlue;
        }
    }

    addBlurredPixel(startRow, startCol, div9, height, width, image);

    return;

}

//Replace regular pixel with blurred pixel
void addBlurredPixel(int startRow, int startCol, int div, int height, int width, RGBTRIPLE image[height][width])
{
    image[startRow][startCol].rgbtRed = round(sumR / div);
    image[startRow][startCol].rgbtGreen = round(sumG / div);
    image[startRow][startCol].rgbtBlue = round(sumB / div);

    sumR = 0.0;
    sumG = 0.0;
    sumB = 0.0;

    return;

}

#include <math.h>
#include <stdio.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int temp = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = temp;
            image[i][j].rgbtGreen = temp;
            image[i][j].rgbtBlue = temp;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < round(width / 2); j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Create temp to blur on
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Handle top row pixels
            if (i == 0)
            {
                if (j == 0)
                {
                    image[i][j].rgbtRed = round((temp[i][j].rgbtRed + temp[i][j + 1].rgbtRed + temp[i + 1][j].rgbtRed + temp[i + 1][j + 1].rgbtRed) /
                                                4.0);
                    image[i][j].rgbtGreen = round((temp[i][j].rgbtGreen + temp[i][j + 1].rgbtGreen + temp[i + 1][j].rgbtGreen + temp[i + 1][j +
                                                   1].rgbtGreen) / 4.0);
                    image[i][j].rgbtBlue = round((temp[i][j].rgbtBlue + temp[i][j + 1].rgbtBlue + temp[i + 1][j].rgbtBlue + temp[i + 1][j + 1].rgbtBlue)
                                                 / 4.0);
                }
                else if (j == (width - 1))
                {
                    image[i][j].rgbtRed = round((temp[i][j].rgbtRed + temp[i][j - 1].rgbtRed + temp[i + 1][j].rgbtRed + temp[i + 1][j - 1].rgbtRed) /
                                                4.0);
                    image[i][j].rgbtGreen = round((temp[i][j].rgbtGreen + temp[i][j - 1].rgbtGreen + temp[i + 1][j].rgbtGreen + temp[i + 1][j -
                                                   1].rgbtGreen) / 4.0);
                    image[i][j].rgbtBlue = round((temp[i][j].rgbtBlue + temp[i][j - 1].rgbtBlue + temp[i + 1][j].rgbtBlue + temp[i + 1][j - 1].rgbtBlue)
                                                 / 4.0);
                }
                else
                {
                    image[i][j].rgbtRed = round((temp[i][j - 1].rgbtRed + temp[i][j].rgbtRed + temp[i][j + 1].rgbtRed + temp[i + 1][j - 1].rgbtRed +
                                                 temp[i + 1][j].rgbtRed + temp[i + 1][j + 1].rgbtRed) / 6.0);
                    image[i][j].rgbtGreen = round((temp[i][j - 1].rgbtGreen + temp[i][j].rgbtGreen + temp[i][j + 1].rgbtGreen + temp[i + 1][j -
                                                   1].rgbtGreen + temp[i + 1][j].rgbtGreen + temp[i + 1][j + 1].rgbtGreen) / 6.0);
                    image[i][j].rgbtBlue = round((temp[i][j - 1].rgbtBlue + temp[i][j].rgbtBlue + temp[i][j + 1].rgbtBlue + temp[i + 1][j - 1].rgbtBlue
                                                  + temp[i + 1][j].rgbtBlue + temp[i + 1][j + 1].rgbtBlue) / 6.0);
                }
            }
            //Handle bottom row pixels
            else if (i == (height - 1))
            {
                if (j == 0)
                {
                    image[i][j].rgbtRed = round((temp[i][j].rgbtRed + temp[i][j + 1].rgbtRed + temp[i - 1][j].rgbtRed + temp[i - 1][j + 1].rgbtRed) /
                                                4.0);
                    image[i][j].rgbtGreen = round((temp[i][j].rgbtGreen + temp[i][j + 1].rgbtGreen + temp[i - 1][j].rgbtGreen + temp[i - 1][j +
                                                   1].rgbtGreen) / 4.0);
                    image[i][j].rgbtBlue = round((temp[i][j].rgbtBlue + temp[i][j + 1].rgbtBlue + temp[i - 1][j].rgbtBlue + temp[i - 1][j + 1].rgbtBlue)
                                                 / 4.0);
                }
                else if (j == (width - 1))
                {
                    image[i][j].rgbtRed = round((temp[i][j].rgbtRed + temp[i][j - 1].rgbtRed + temp[i - 1][j].rgbtRed + temp[i - 1][j - 1].rgbtRed) /
                                                4.0);
                    image[i][j].rgbtGreen = round((temp[i][j].rgbtGreen + temp[i][j - 1].rgbtGreen + temp[i - 1][j].rgbtGreen + temp[i - 1][j -
                                                   1].rgbtGreen) / 4.0);
                    image[i][j].rgbtBlue = round((temp[i][j].rgbtBlue + temp[i][j - 1].rgbtBlue + temp[i - 1][j].rgbtBlue + temp[i - 1][j - 1].rgbtBlue)
                                                 / 4.0);
                }
                else
                {
                    image[i][j].rgbtRed = round((temp[i][j - 1].rgbtRed + temp[i][j].rgbtRed + temp[i][j + 1].rgbtRed + temp[i - 1][j - 1].rgbtRed +
                                                 temp[i - 1][j].rgbtRed + temp[i - 1][j + 1].rgbtRed) / 6.0);
                    image[i][j].rgbtGreen = round((temp[i][j - 1].rgbtGreen + temp[i][j].rgbtGreen + temp[i][j + 1].rgbtGreen + temp[i - 1][j -
                                                   1].rgbtGreen + temp[i - 1][j].rgbtGreen + temp[i - 1][j + 1].rgbtGreen) / 6.0);
                    image[i][j].rgbtBlue = round((temp[i][j - 1].rgbtBlue + temp[i][j].rgbtBlue + temp[i][j + 1].rgbtBlue + temp[i - 1][j - 1].rgbtBlue
                                                  + temp[i - 1][j].rgbtBlue + temp[i - 1][j + 1].rgbtBlue) / 6.0);
                }
            }
            else
            {
                //Handle left column pixels
                if (j == 0)
                {
                    image[i][j].rgbtRed = round((temp[i - 1][j].rgbtRed + temp[i][j].rgbtRed + temp[i + 1][j].rgbtRed + temp[i - 1][j + 1].rgbtRed +
                                                 temp[i][j + 1].rgbtRed + temp[i + 1][j + 1].rgbtRed) / 6.0);
                    image[i][j].rgbtGreen = round((temp[i - 1][j].rgbtGreen + temp[i][j].rgbtGreen + temp[i + 1][j].rgbtGreen + temp[i - 1][j +
                                                   1].rgbtGreen + temp[i][j + 1].rgbtGreen + temp[i + 1][j + 1].rgbtGreen) / 6.0);
                    image[i][j].rgbtBlue = round((temp[i - 1][j].rgbtBlue + temp[i][j].rgbtBlue + temp[i + 1][j].rgbtBlue + temp[i - 1][j + 1].rgbtBlue
                                                  + temp[i][j + 1].rgbtBlue + temp[i + 1][j + 1].rgbtBlue) / 6.0);
                }
                //Handle right colum pixels
                else if (j == (width - 1))
                {
                    image[i][j].rgbtRed = round((temp[i - 1][j].rgbtRed + temp[i][j].rgbtRed + temp[i + 1][j].rgbtRed + temp[i - 1][j - 1].rgbtRed +
                                                 temp[i][j - 1].rgbtRed + temp[i + 1][j - 1].rgbtRed) / 6.0);
                    image[i][j].rgbtGreen = round((temp[i - 1][j].rgbtGreen + temp[i][j].rgbtGreen + temp[i + 1][j].rgbtGreen + temp[i - 1][j -
                                                   1].rgbtGreen + temp[i][j - 1].rgbtGreen + temp[i + 1][j - 1].rgbtGreen) / 6.0);
                    image[i][j].rgbtBlue = round((temp[i - 1][j].rgbtBlue + temp[i][j].rgbtBlue + temp[i + 1][j].rgbtBlue + temp[i - 1][j - 1].rgbtBlue
                                                  + temp[i][j - 1].rgbtBlue + temp[i + 1][j - 1].rgbtBlue) / 6.0);
                }
                else
                {
                    image[i][j].rgbtRed = round((temp[i - 1][j - 1].rgbtRed + temp[i - 1][j].rgbtRed + temp[i - 1][j + 1].rgbtRed + temp[i][j -
                                                 1].rgbtRed + temp[i][j].rgbtRed + temp[i][j + 1].rgbtRed + temp[i + 1][j - 1].rgbtRed + temp[i + 1][j].rgbtRed + temp[i + 1][j +
                                                         1].rgbtRed) / 9.0);
                    image[i][j].rgbtGreen = round((temp[i - 1][j - 1].rgbtGreen + temp[i - 1][j].rgbtGreen + temp[i  - 1][j + 1].rgbtGreen + temp[i][j -
                                                   1].rgbtGreen + temp[i][j].rgbtGreen + temp[i][j + 1].rgbtGreen + temp[i + 1][j - 1].rgbtGreen + temp[i + 1][j].rgbtGreen + temp[i +
                                                           1][j + 1].rgbtGreen) / 9.0);
                    image[i][j].rgbtBlue = round((temp[i - 1][j - 1].rgbtBlue + temp[i - 1][j].rgbtBlue + temp[i - 1][j + 1].rgbtBlue + temp[i][j -
                                                  1].rgbtBlue + temp[i][j].rgbtBlue + temp[i][j + 1].rgbtBlue + temp[i + 1][j - 1].rgbtBlue + temp[i + 1][j].rgbtBlue + temp[i + 1][j
                                                          + 1].rgbtBlue) / 9.0);
                }
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Init kernels
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Create temp image
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Loop through image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int h = 0;
            int v = 0;
            int sobel = 0;

            if (i == 0)
            {
                if (j == 0)
                {
                    // Red
                    h = temp[i][j].rgbtRed * gx[1][1] + temp[i][j + 1].rgbtRed * gx[1][2] + temp[i + 1][j].rgbtRed * gx[2][1] + temp[i + 1][j +
                            1].rgbtRed * gx[2][2];
                    v = temp[i][j].rgbtRed * gy[1][1] + temp[i][j + 1].rgbtRed * gy[1][2] + temp[i + 1][j].rgbtRed * gy[2][1] + temp[i + 1][j +
                            1].rgbtRed * gy[2][2];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtRed = 255;
                    }
                    else
                    {
                        image[i][j].rgbtRed = sobel;
                    }

                    // Green
                    h = temp[i][j].rgbtGreen * gx[1][1] + temp[i][j + 1].rgbtGreen * gx[1][2] + temp[i + 1][j].rgbtGreen * gx[2][1] + temp[i +
                            1][j + 1].rgbtGreen * gx[2][2];
                    v = temp[i][j].rgbtGreen * gy[1][1] + temp[i][j + 1].rgbtGreen * gy[1][2] + temp[i + 1][j].rgbtGreen * gy[2][1] + temp[i +
                            1][j + 1].rgbtGreen * gy[2][2];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtGreen = 255;
                    }
                    else
                    {
                        image[i][j].rgbtGreen = sobel;
                    }

                    //Blue
                    h = temp[i][j].rgbtBlue * gx[1][1] + temp[i][j + 1].rgbtBlue * gx[1][2] + temp[i + 1][j].rgbtBlue * gx[2][1] + temp[i + 1][j +
                            1].rgbtBlue * gx[2][2];
                    v = temp[i][j].rgbtBlue * gy[1][1] + temp[i][j + 1].rgbtBlue * gy[1][2] + temp[i + 1][j].rgbtBlue * gy[2][1] + temp[i + 1][j +
                            1].rgbtBlue * gy[2][2];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtBlue = 255;
                    }
                    else
                    {
                        image[i][j].rgbtBlue = sobel;
                    }
                }

                else if (j == width - 1)
                {
                    // Red
                    h = temp[i][j].rgbtRed * gx[1][1] + temp[i][j - 1].rgbtRed * gx[1][0] + temp[i + 1][j].rgbtRed * gx[2][1] + temp[i + 1][j -
                            1].rgbtRed * gx[2][0];
                    v = temp[i][j].rgbtRed * gy[1][1] + temp[i][j - 1].rgbtRed * gy[1][0] + temp[i + 1][j].rgbtRed * gy[2][1] + temp[i + 1][j -
                            1].rgbtRed * gy[2][0];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtRed = 255;
                    }
                    else
                    {
                        image[i][j].rgbtRed = sobel;
                    }

                    // Green
                    h = temp[i][j].rgbtGreen * gx[1][1] + temp[i][j - 1].rgbtGreen * gx[1][0] + temp[i + 1][j].rgbtGreen * gx[2][1] + temp[i + 1][j -
                            1].rgbtGreen * gx[2][0];
                    v = temp[i][j].rgbtGreen * gy[1][1] + temp[i][j - 1].rgbtGreen * gy[1][0] + temp[i + 1][j].rgbtGreen * gy[2][1] + temp[i + 1][j -
                            1].rgbtGreen * gy[2][0];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtGreen = 255;
                    }
                    else
                    {
                        image[i][j].rgbtGreen = sobel;
                    }

                    //Blue
                    h = temp[i][j].rgbtBlue * gx[1][1] + temp[i][j - 1].rgbtBlue * gx[1][0] + temp[i + 1][j].rgbtBlue * gx[2][1] + temp[i + 1][j -
                            1].rgbtBlue * gx[2][0];
                    v = temp[i][j].rgbtBlue * gy[1][1] + temp[i][j - 1].rgbtBlue * gy[1][0] + temp[i + 1][j].rgbtBlue * gy[2][1] + temp[i + 1][j -
                            1].rgbtBlue * gy[2][0];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtBlue = 255;
                    }
                    else
                    {
                        image[i][j].rgbtBlue = sobel;
                    }
                }
                else
                {
                    // Red
                    h = temp[i][j - 1].rgbtRed * gx[1][0] + temp[i][j].rgbtRed * gx[1][1] + temp[i][j + 1].rgbtRed * gx[1][2] + temp[i + 1][j -
                            1].rgbtRed * gx[2][0] + temp[i + 1][j].rgbtRed * gx[2][1] + temp[i + 1][j + 1].rgbtRed * gx[2][2];
                    v = temp[i][j - 1].rgbtRed * gy[1][0] + temp[i][j].rgbtRed * gy[1][1] + temp[i][j + 1].rgbtRed * gy[1][2] + temp[i + 1][j -
                            1].rgbtRed * gy[2][0] + temp[i + 1][j].rgbtRed * gy[2][1] + temp[i + 1][j +  1].rgbtRed * gy[2][2];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtRed = 255;
                    }
                    else
                    {
                        image[i][j].rgbtRed = sobel;
                    }

                    // Green
                    h = temp[i][j - 1].rgbtGreen * gx[1][0] + temp[i][j].rgbtGreen * gx[1][1] + temp[i][j + 1].rgbtGreen * gx[1][2] + temp[i + 1][j -
                            1].rgbtGreen * gx[2][0] + temp[i + 1][j].rgbtGreen * gx[2][1] + temp[i + 1][j + 1].rgbtGreen * gx[2][2];
                    v = temp[i][j - 1].rgbtGreen * gy[1][0] + temp[i][j].rgbtGreen * gy[1][1] + temp[i][j + 1].rgbtGreen * gy[1][2] + temp[i + 1][j -
                            1].rgbtGreen * gy[2][0] + temp[i + 1][j].rgbtGreen * gy[2][1] + temp[i + 1][j + 1].rgbtGreen * gy[2][2];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtGreen = 255;
                    }
                    else
                    {
                        image[i][j].rgbtGreen = sobel;
                    }

                    // Blue
                    h = temp[i][j - 1].rgbtBlue * gx[1][0] + temp[i][j].rgbtBlue * gx[1][1] + temp[i][j + 1].rgbtBlue * gx[1][2] + temp[i + 1][j -
                            1].rgbtBlue * gx[2][0] + temp[i + 1][j].rgbtBlue * gx[2][1] + temp[i + 1][j + 1].rgbtBlue * gx[2][2];
                    v = temp[i][j - 1].rgbtBlue * gy[1][0] + temp[i][j].rgbtBlue * gy[1][1] + temp[i][j + 1].rgbtBlue * gy[1][2] + temp[i + 1][j -
                            1].rgbtBlue * gy[2][0] + temp[i + 1][j].rgbtBlue * gy[2][1] + temp[i + 1][j + 1].rgbtBlue * gy[2][2];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtBlue = 255;
                    }
                    else
                    {
                        image[i][j].rgbtBlue = sobel;
                    }
                }
            }
            else if (i == height - 1)
            {
                if (j == 0)
                {
                    // Red
                    h = temp[i][j].rgbtRed * gx[1][1] + temp[i][j + 1].rgbtRed * gx[1][2] + temp[i - 1][j].rgbtRed * gx[0][1] + temp[i - 1][j +
                            1].rgbtRed * gx[0][2];
                    v = temp[i][j].rgbtRed * gy[1][1] + temp[i][j + 1].rgbtRed * gy[1][2] + temp[i - 1][j].rgbtRed * gy[0][1] + temp[i - 1][j +
                            1].rgbtRed * gy[0][2];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtRed = 255;
                    }
                    else
                    {
                        image[i][j].rgbtRed = sobel;
                    }

                    // Green
                    h = temp[i][j].rgbtGreen * gx[1][1] + temp[i][j + 1].rgbtGreen * gx[1][2] + temp[i - 1][j].rgbtGreen * gx[0][1] + temp[i - 1][j +
                            1].rgbtGreen * gx[0][2];
                    v = temp[i][j].rgbtGreen * gy[1][1] + temp[i][j + 1].rgbtGreen * gy[1][2] + temp[i - 1][j].rgbtGreen * gy[0][1] + temp[i - 1][j +
                            1].rgbtGreen * gy[0][2];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtGreen = 255;
                    }
                    else
                    {
                        image[i][j].rgbtGreen = sobel;
                    }

                    //Blue
                    h = temp[i][j].rgbtBlue * gx[1][1] + temp[i][j + 1].rgbtBlue * gx[1][2] + temp[i - 1][j].rgbtBlue * gx[0][1] + temp[i - 1][j +
                            1].rgbtBlue * gx[0][2];
                    v = temp[i][j].rgbtBlue * gy[1][1] + temp[i][j + 1].rgbtBlue * gy[1][2] + temp[i - 1][j].rgbtBlue * gy[0][1] + temp[i - 1][j +
                            1].rgbtBlue * gy[0][2];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtBlue = 255;
                    }
                    else
                    {
                        image[i][j].rgbtBlue = sobel;
                    }
                }
                else if (j == width - 1)
                {
                    // Red
                    h = temp[i][j].rgbtRed * gx[1][1] + temp[i][j - 1].rgbtRed * gx[1][0] + temp[i - 1][j].rgbtRed * gx[0][1] + temp[i - 1][j -
                            1].rgbtRed * gx[0][0];
                    v = temp[i][j].rgbtRed * gy[1][1] + temp[i][j - 1].rgbtRed * gy[1][0] + temp[i - 1][j].rgbtRed * gy[0][1] + temp[i - 1][j -
                            1].rgbtRed * gy[0][0];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtRed = 255;
                    }
                    else
                    {
                        image[i][j].rgbtRed = sobel;
                    }

                    // Green
                    h = temp[i][j].rgbtGreen * gx[1][1] + temp[i][j - 1].rgbtGreen * gx[1][0] + temp[i - 1][j].rgbtGreen * gx[0][1] + temp[i - 1][j -
                            1].rgbtGreen * gx[0][0];
                    v = temp[i][j].rgbtGreen * gy[1][1] + temp[i][j - 1].rgbtGreen * gy[1][0] + temp[i - 1][j].rgbtGreen * gy[0][1] + temp[i - 1][j -
                            1].rgbtGreen * gy[0][0];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtGreen = 255;
                    }
                    else
                    {
                        image[i][j].rgbtGreen = sobel;
                    }

                    //Blue
                    h = temp[i][j].rgbtBlue * gx[1][1] + temp[i][j - 1].rgbtBlue * gx[1][0] + temp[i - 1][j].rgbtBlue * gx[0][1] + temp[i - 1][j -
                            1].rgbtBlue * gx[0][0];
                    v = temp[i][j].rgbtBlue * gy[1][1] + temp[i][j - 1].rgbtBlue * gy[1][0] + temp[i - 1][j].rgbtBlue * gy[0][1] + temp[i - 1][j -
                            1].rgbtBlue * gy[0][0];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtBlue = 255;
                    }
                    else
                    {
                        image[i][j].rgbtBlue = sobel;
                    }
                }
                else
                {
                    // Red
                    h = temp[i][j - 1].rgbtRed * gx[1][0] + temp[i][j].rgbtRed * gx[1][1] + temp[i][j + 1].rgbtRed * gx[1][2] + temp[i - 1][j -
                            1].rgbtRed * gx[0][0] + temp[i - 1][j].rgbtRed * gx[0][1] + temp[i - 1][j + 1].rgbtRed * gx[0][2];
                    v = temp[i][j - 1].rgbtRed * gy[1][0] + temp[i][j].rgbtRed * gy[1][1] + temp[i][j + 1].rgbtRed * gy[1][2] + temp[i - 1][j -
                            1].rgbtRed * gy[0][0] + temp[i - 1][j].rgbtRed * gy[0][1] + temp[i - 1][j + 1].rgbtRed * gy[0][2];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtRed = 255;
                    }
                    else
                    {
                        image[i][j].rgbtRed = sobel;
                    }

                    // Green
                    h = temp[i][j - 1].rgbtGreen * gx[1][0] + temp[i][j].rgbtGreen * gx[1][1] + temp[i][j + 1].rgbtGreen * gx[1][2] + temp[i - 1][j -
                            1].rgbtGreen * gx[0][0] + temp[i - 1][j].rgbtGreen * gx[0][1] + temp[i - 1][j + 1].rgbtGreen * gx[0][2];
                    v = temp[i][j - 1].rgbtGreen * gy[1][0] + temp[i][j].rgbtGreen * gy[1][1] + temp[i][j + 1].rgbtGreen * gy[1][2] + temp[i - 1][j -
                            1].rgbtGreen * gy[0][0] + temp[i - 1][j].rgbtGreen * gy[0][1] + temp[i - 1][j + 1].rgbtGreen * gy[0][2];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtGreen = 255;
                    }
                    else
                    {
                        image[i][j].rgbtGreen = sobel;
                    }

                    // Blue
                    h = temp[i][j - 1].rgbtBlue * gx[1][0] + temp[i][j].rgbtBlue * gx[1][1] + temp[i][j + 1].rgbtBlue * gx[1][2] + temp[i - 1][j -
                            1].rgbtBlue * gx[0][0] + temp[i - 1][j].rgbtBlue * gx[0][1] + temp[i - 1][j + 1].rgbtBlue * gx[0][2];
                    v = temp[i][j - 1].rgbtBlue * gy[1][0] + temp[i][j].rgbtBlue * gy[1][1] + temp[i][j + 1].rgbtBlue * gy[1][2] + temp[i - 1][j -
                            1].rgbtBlue * gy[0][0] + temp[i - 1][j].rgbtBlue * gy[0][1] + temp[i - 1][j + 1].rgbtBlue * gy[0][2];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtBlue = 255;
                    }
                    else
                    {
                        image[i][j].rgbtBlue = sobel;
                    }
                }
            }
            else
            {
                if (j == 0)
                {
                    h = temp[i - 1][j].rgbtRed * gx[0][1] + temp[i - 1][j + 1].rgbtRed * gx[0][2] + temp[i][j].rgbtRed * gx[1][1] + temp[i][j +
                            1].rgbtRed * gx[1][2] + temp[i + 1][j].rgbtRed * gx[2][1] + temp[i + 1][j + 1].rgbtRed * gx[2][2];
                    v = temp[i - 1][j].rgbtRed * gy[0][1] + temp[i - 1][j + 1].rgbtRed * gy[0][2] + temp[i][j].rgbtRed * gy[1][1] + temp[i][j +
                            1].rgbtRed * gy[1][2] + temp[i + 1][j].rgbtRed * gy[2][1] + temp[i + 1][j + 1].rgbtRed * gy[2][2];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtRed = 255;
                    }
                    else
                    {
                        image[i][j].rgbtRed = sobel;
                    }

                    // Green
                    h = temp[i - 1][j].rgbtGreen * gx[0][1] + temp[i - 1][j + 1].rgbtGreen * gx[0][2] + temp[i][j].rgbtGreen * gx[1][1] + temp[i][j +
                            1].rgbtGreen * gx[1][2] + temp[i + 1][j].rgbtGreen * gx[2][1] + temp[i + 1][j + 1].rgbtGreen * gx[2][2];
                    v = temp[i - 1][j].rgbtGreen * gy[0][1] + temp[i - 1][j + 1].rgbtGreen * gy[0][2] + temp[i][j].rgbtGreen * gy[1][1] + temp[i][j +
                            1].rgbtGreen * gy[1][2] + temp[i + 1][j].rgbtGreen * gy[2][1] + temp[i + 1][j + 1].rgbtGreen * gy[2][2];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtGreen = 255;
                    }
                    else
                    {
                        image[i][j].rgbtGreen = sobel;
                    }

                    //Blue
                    h = temp[i - 1][j].rgbtBlue * gx[0][1] + temp[i - 1][j + 1].rgbtBlue * gx[0][2] + temp[i][j].rgbtBlue * gx[1][1] + temp[i][j +
                            1].rgbtBlue * gx[1][2] + temp[i + 1][j].rgbtBlue * gx[2][1] + temp[i + 1][j + 1].rgbtBlue * gx[2][2];
                    v = temp[i - 1][j].rgbtBlue * gy[0][1] + temp[i - 1][j + 1].rgbtBlue * gy[0][2] + temp[i][j].rgbtBlue * gy[1][1] + temp[i][j +
                            1].rgbtBlue * gy[1][2] + temp[i + 1][j].rgbtBlue * gy[2][1] + temp[i + 1][j + 1].rgbtBlue * gy[2][2];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtBlue = 255;
                    }
                    else
                    {
                        image[i][j].rgbtBlue = sobel;
                    }
                }
                else if (j == width - 1)
                {
                    // Red
                    h = temp[i - 1][j - 1].rgbtRed * gx[0][0] + temp[i - 1][j].rgbtRed * gx[0][1] + temp[i][j - 1].rgbtRed * gx[1][0] +
                        temp[i][j].rgbtRed * gx[1][1] + temp[i + 1][j - 1].rgbtRed * gx[2][0] + temp[i + 1][j].rgbtRed * gx[2][1];
                    v = temp[i - 1][j - 1].rgbtRed * gy[0][0] + temp[i - 1][j].rgbtRed * gy[0][1] + temp[i][j - 1].rgbtRed * gy[1][0] +
                        temp[i][j].rgbtRed * gy[1][1] + temp[i + 1][j - 1].rgbtRed * gy[2][0] + temp[i + 1][j].rgbtRed * gy[2][1];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtRed = 255;
                    }
                    else
                    {
                        image[i][j].rgbtRed = sobel;
                    }

                    // Green
                    h = temp[i - 1][j - 1].rgbtGreen * gx[0][0] + temp[i - 1][j].rgbtGreen * gx[0][1] + temp[i][j - 1].rgbtGreen * gx[1][0] +
                        temp[i][j].rgbtGreen * gx[1][1] + temp[i + 1][j - 1].rgbtGreen * gx[2][0] + temp[i + 1][j].rgbtGreen * gx[2][1];
                    v = temp[i - 1][j - 1].rgbtGreen * gy[0][0] + temp[i - 1][j].rgbtGreen * gy[0][1] + temp[i][j - 1].rgbtGreen * gy[1][0] +
                        temp[i][j].rgbtGreen * gy[1][1] + temp[i + 1][j - 1].rgbtGreen * gy[2][0] + temp[i + 1][j].rgbtGreen * gy[2][1];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtGreen = 255;
                    }
                    else
                    {
                        image[i][j].rgbtGreen = sobel;
                    }

                    // Blue
                    h = temp[i - 1][j - 1].rgbtBlue * gx[0][0] + temp[i - 1][j].rgbtBlue * gx[0][1] + temp[i][j - 1].rgbtBlue * gx[1][0] +
                        temp[i][j].rgbtBlue * gx[1][1] + temp[i + 1][j - 1].rgbtBlue * gx[2][0] + temp[i + 1][j].rgbtBlue * gx[2][1];
                    v = temp[i - 1][j - 1].rgbtBlue * gy[0][0] + temp[i - 1][j].rgbtBlue * gy[0][1] + temp[i][j - 1].rgbtBlue * gy[1][0] +
                        temp[i][j].rgbtBlue * gy[1][1] + temp[i + 1][j - 1].rgbtBlue * gy[2][0] + temp[i + 1][j].rgbtBlue * gy[2][1];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtBlue = 255;
                    }
                    else
                    {
                        image[i][j].rgbtBlue = sobel;
                    }
                }
                else
                {
                    // Red
                    h = temp[i - 1][j - 1].rgbtRed * gx[0][0] + temp[i - 1][j].rgbtRed * gx[0][1] + temp[i - 1][j + 1].rgbtRed * gx[0][2] + temp[i][j -
                            1].rgbtRed * gx[1][0] + temp[i][j].rgbtRed * gx[1][1] + temp[i][j + 1].rgbtRed * gx[1][2] + temp[i + 1][j - 1].rgbtRed * gx[2][0] +
                        temp[i + 1][j].rgbtRed * gx[2][1] + temp[i + 1][j + 1].rgbtRed * gx[2][2];
                    v = temp[i - 1][j - 1].rgbtRed * gy[0][0] + temp[i - 1][j].rgbtRed * gy[0][1] + temp[i - 1][j + 1].rgbtRed * gy[0][2] + temp[i][j -
                            1].rgbtRed * gy[1][0] + temp[i][j].rgbtRed * gy[1][1] + temp[i][j + 1].rgbtRed * gy[1][2] + temp[i + 1][j - 1].rgbtRed * gy[2][0] +
                        temp[i + 1][j].rgbtRed * gy[2][1] + temp[i + 1][j + 1].rgbtRed * gy[2][2];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtRed = 255;
                    }
                    else
                    {
                        image[i][j].rgbtRed = sobel;
                    }

                    // Green
                    h = temp[i - 1][j - 1].rgbtGreen * gx[0][0] + temp[i - 1][j].rgbtGreen * gx[0][1] + temp[i - 1][j + 1].rgbtGreen * gx[0][2] +
                        temp[i][j - 1].rgbtGreen * gx[1][0] + temp[i][j].rgbtGreen * gx[1][1] + temp[i][j + 1].rgbtGreen * gx[1][2] + temp[i + 1][j -
                                1].rgbtGreen * gx[2][0] + temp[i + 1][j].rgbtGreen * gx[2][1] + temp[i + 1][j + 1].rgbtGreen * gx[2][2];
                    v = temp[i - 1][j - 1].rgbtGreen * gy[0][0] + temp[i - 1][j].rgbtGreen * gy[0][1] + temp[i - 1][j + 1].rgbtGreen * gy[0][2] +
                        temp[i][j - 1].rgbtGreen * gy[1][0] + temp[i][j].rgbtGreen * gy[1][1] + temp[i][j + 1].rgbtGreen * gy[1][2] + temp[i + 1][j -
                                1].rgbtGreen * gy[2][0] + temp[i + 1][j].rgbtGreen * gy[2][1] + temp[i + 1][j + 1].rgbtGreen * gy[2][2];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtGreen = 255;
                    }
                    else
                    {
                        image[i][j].rgbtGreen = sobel;
                    }

                    // Blue
                    h = temp[i - 1][j - 1].rgbtBlue * gx[0][0] + temp[i - 1][j].rgbtBlue * gx[0][1] + temp[i - 1][j + 1].rgbtBlue * gx[0][2] + temp[i][j
                            - 1].rgbtBlue * gx[1][0] + temp[i][j].rgbtBlue * gx[1][1] + temp[i][j + 1].rgbtBlue * gx[1][2] + temp[i + 1][j - 1].rgbtBlue *
                        gx[2][0] + temp[i + 1][j].rgbtBlue * gx[2][1] + temp[i + 1][j + 1].rgbtBlue * gx[2][2];
                    v = temp[i - 1][j - 1].rgbtBlue * gy[0][0] + temp[i - 1][j].rgbtBlue * gy[0][1] + temp[i - 1][j + 1].rgbtBlue * gy[0][2] + temp[i][j
                            - 1].rgbtBlue * gy[1][0] + temp[i][j].rgbtBlue * gy[1][1] + temp[i][j + 1].rgbtBlue * gy[1][2] + temp[i + 1][j - 1].rgbtBlue *
                        gy[2][0] + temp[i + 1][j].rgbtBlue * gy[2][1] + temp[i + 1][j + 1].rgbtBlue * gy[2][2];
                    sobel = round(sqrt(pow(h, 2) + pow(v, 2)));

                    // Cap at 255
                    if (sobel > 255)
                    {
                        image[i][j].rgbtBlue = 255;
                    }
                    else
                    {
                        image[i][j].rgbtBlue = sobel;
                    }
                }
            }
        }
    }
    return;
}
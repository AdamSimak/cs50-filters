#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int height_index = 0; height_index < height; height_index++)
    {

        for (int width_index = 0; width_index < width; width_index++)
        {
            int color_sum = image[height_index][width_index].rgbtBlue + image[height_index][width_index].rgbtGreen +
                            image[height_index][width_index].rgbtRed;
            int avg_color = round(color_sum / 3.0);

            image[height_index][width_index].rgbtBlue = avg_color;
            image[height_index][width_index].rgbtGreen = avg_color;
            image[height_index][width_index].rgbtRed = avg_color;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int height_index = 0; height_index < height; height_index++)
    {

        for (int width_index = 0; width_index < width; width_index++)
        {

            BYTE orig_red = image[height_index][width_index].rgbtRed;
            BYTE orig_blue = image[height_index][width_index].rgbtBlue;
            BYTE orig_green = image[height_index][width_index].rgbtGreen;

            int new_red = round(.393 * orig_red + .769 * orig_green + .189 * orig_blue);
            if (new_red > 255)
            {
                new_red = 255;
            }
            int new_blue =round(.272 * orig_red + .534 * orig_green + .131 * orig_blue);
            if (new_blue> 255)
            {
                new_blue = 255;
            }
            int new_green =round(.349 * orig_red + .686 * orig_green + .168 * orig_blue);
            if (new_green > 255)
            {
                new_green = 255;
            }

            // asign new colors to struct
            image[height_index][width_index].rgbtRed = new_red;
            image[height_index][width_index].rgbtBlue = new_blue;
            image[height_index][width_index].rgbtGreen = new_green;

        }
    }


    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int height_index = 0; height_index < height; height_index++)
    {

        // making two variables, one for left side pixel and one for right side pixel
        //left variable is going up, right variable going down
        for (int width_index = 0, back_width = width - 1; width_index < width / 2; width_index++, back_width--)
        {
            RGBTRIPLE temp = image[height_index][width_index];
            image[height_index][width_index] = image[height_index][back_width];
            image[height_index][back_width] = temp;
        }
    }


    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // creating copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }


    // main loop for each pixel
    for (int height_index = 0; height_index < height; height_index++)
    {

        for (int width_index = 0; width_index < width; width_index++)
        {
            float neighbor_counter = 0;

            // variables for sum of each color
            int red_sum = 0;
            int blue_sum = 0;
            int green_sum = 0;


            // loop for neighbor pixels
            for (int neigh_height = height_index - 1; neigh_height <= height_index + 1; neigh_height++)
            {
                for (int neigh_width = width_index - 1; neigh_width <= width_index + 1; neigh_width++)
                {

                    // check if pixel has correct height
                    if (neigh_height >= height || neigh_height < 0)
                    {
                        continue;
                    }

                    // check if pixel has correct width
                    else if (neigh_width >= width || neigh_width < 0)
                    {
                        continue;
                    }

                    // if it´s existing pixel, add it´s rgb values to sum and neighbour_count++
                    red_sum += copy[neigh_height][neigh_width].rgbtRed;
                    blue_sum += copy[neigh_height][neigh_width].rgbtBlue;
                    green_sum += copy[neigh_height][neigh_width].rgbtGreen;
                    neighbor_counter += 1;

                }
            }

            // make avg of each rgb color and store it to original color pixel
            int new_red = round (red_sum / neighbor_counter);
            int new_blue = round (blue_sum / neighbor_counter);
            int new_green = round (green_sum / neighbor_counter);

            image[height_index][width_index].rgbtRed = new_red;
            image[height_index][width_index].rgbtBlue = new_blue;
            image[height_index][width_index].rgbtGreen = new_green;

        }
    }

    return;
}

#include "helpers.h"
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        for (int p = 0; p < width; p++){
            float favg = (image [i][p].rgbtRed + image [i][p].rgbtBlue + image [i][p].rgbtGreen) / 3;
            int avg = round(favg);
            image [i][p].rgbtRed = image [i][p].rgbtBlue = image [i][p].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        for (int p = 0; p < width; p++){
        //get the original RGB
        int originalRed = image[i][p].rgbtRed;
        int originalBlue = image[i][p].rgbtBlue;
        int originalGreen = image[i][p].rgbtGreen;
        //convert the original RGB to Sepia RGB
        int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
        int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
        int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
        //check
        if (sepiaRed > 225){
            sepiaRed = 225;
        }
        if (sepiaBlue > 225){
            sepiaBlue = 225;
        }
        if (sepiaGreen > 225){
            sepiaGreen = 225;
        }

        //convert to sepia image
        image[i][p].rgbtRed = sepiaRed;
        image[i][p].rgbtBlue = sepiaBlue;
        image[i][p].rgbtGreen = sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
     for (int i = 0; i < height; i++){
        for (int p = 0; p < (width/2); p++){
        RGBTRIPLE temp = image[i][p];
        image[i][p] = image[i][width- (p+1)];
        image[i][width- (p+1)] = temp;
        }}
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //temporary storage of the original image
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++){
        for (int p = 0; p < height; p++){
            temp[i][p] = image[i][p];
        }
    }
    for (int i = 0; i < height; i++){
     for (int p = 0; p < height; p++){
        int sumR = 0;
        int sumG = 0;
        int sumB = 0;
        int counter = 0;
      //looping through the 3X3 grid of a pixel
      for(int x = -1; x < 2; x++){
          for (int y = -1; y < 2; y++){
              int currentx = i + x;
              int currenty = p + y;
              //if neighbouring pixels are valid
              if(currentx < 0 || currentx > height-1 || currenty < 0 || currenty > width-1){
                continue;
              }
            sumR = sumR + temp[currentx][currenty].rgbtRed;
            sumG = sumG + temp[currentx][currenty].rgbtGreen;
            sumB = sumB + temp[currentx][currenty].rgbtBlue;

            counter++;
         }
    }
    image[i][p].rgbtRed = round(sumR/counter);
    image[i][p].rgbtGreen = round(sumG/counter);
    image[i][p].rgbtBlue = round(sumB/counter);
}
}
    return;
}

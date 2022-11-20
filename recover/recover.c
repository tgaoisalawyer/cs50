#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(int argc, char *argv[])
{
 //check if the user is providing one argument
 if (argc != 2){
    return 1;}

//open the file and check validity
FILE *input_file = fopen(argv[1], "r");
if (input_file == NULL){
    return 2;
    printf("Error: file cannot be opened");
}
//declare variables
unsigned char buffer[512]; //buffer for an image of 512 bytes
int counter = 0; //number of images generated
FILE *output_file = NULL; //file pointer for recovered images
char *filename = malloc(8 * sizeof(char)); //allocate memory for filenames

//detect images and copy
while(fread(buffer, sizeof(char), 512, input_file)){
    //detect image
    if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){
    //create filename
    sprintf(filename, "%03i.jpg", counter);
    //open the file to write in
    output_file = fopen(filename, "w");
    }
    //track the number of images
    counter++;
}
    //write in
    if (output_file != NULL){
        fwrite(buffer, sizeof(char), 512, output_file);
}
//close files and release memory
fclose(input_file);
fclose(output_file);
free(filename);

return 0;


}
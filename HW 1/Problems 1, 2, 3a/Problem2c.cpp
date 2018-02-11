 // This sample code reads in image data from a RAW image file and // writes it into another file// NOTE:	The code assumes that the image is of size 256 x 256 and is in the//			RAW format. You will need to make corresponding changes to//			accommodate images of different sizes and/or types////////////////////////////////////////////// Name : SHILPASHREE RAO// USC ID: 5636765972// EMAIL ID: shilpasr@usc.edu// Submission Date: 2/4/2018// EE569 HW 1////////////////////////////////////////////////#include <stdio.h>#include <iostream>#include <stdlib.h>using namespace std;int main(int argc, char *argv[]){	// Define file pointer and variables	FILE *f1;	FILE *f2;	FILE *f3;	FILE *file;	int BytesPerPixel;	int Height = 256 , Width = 256;		if (argc < 2){		cout << "Syntax Error - Incorrect Parameter Usage:" << endl;		//cout << "program_name input_image.raw output_image.raw [BytesPerPixel = 1] [Size = 256]" << endl;		cout << "program_name input_image.raw [BytesPerPixel = 1] [Height = 256] [Width = 256]" << endl;		return 0;	}		// Check if image is grayscale or color	if (argc < 3){		BytesPerPixel = 1; // default is grey image	} 	else {		BytesPerPixel = atoi(argv[2]);	}	// Check if height is specified	if (argc == 4) {		Width = atoi(argv[3]);	}	else {		// Check if width is specified		Width = atoi(argv[3]);		Height = atoi(argv[4]);	}		// Allocate image data array	unsigned char Imagedata[Height][Width][BytesPerPixel];	// Read image (filename specified by first argument) into image data matrix	if (!(file=fopen(argv[1],"rb"))) {		cout << "Cannot open file: " << argv[1] <<endl;		exit(1);	}	fread(Imagedata, sizeof(unsigned char), Height*Width*BytesPerPixel, file);	fclose(file);	///////////////////////// INSERT YOUR PROCESSING CODE HERE /////////////////////////	unsigned char InversionImage[Height][Width][BytesPerPixel];	for(int  k = 0; k < 3; k++){		for(int i = 0; i < Height; i++){			for(int j = 0; j < Width; j++){				InversionImage[i][Width-j-1][k] = 255 - Imagedata[i][j][k];			}                             		}	}	unsigned char FilmImage[Height][Width][BytesPerPixel];	for(int i = 0; i < Height; i++) {		for(int j = 0; j < Width; j++) {			FilmImage[i][j][0] = static_cast<unsigned char>((static_cast<unsigned int>(InversionImage[i][j][0])/255.0)*(255-75)+75);			FilmImage[i][j][1] = static_cast<unsigned char>((static_cast<unsigned int>(InversionImage[i][j][1])/255.0)*(200-25)+25);			FilmImage[i][j][2] = static_cast<unsigned char>((static_cast<unsigned int>(InversionImage[i][j][2])/255.0)*(175-25)+25);		}	}			f1 = fopen("Film_image.raw","wb");	fwrite(FilmImage, sizeof(unsigned char), Height*Width*BytesPerPixel, f1);	fclose(f1);	return 0;}
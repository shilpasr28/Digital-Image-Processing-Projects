 // This sample code reads in image data from a RAW image file and 
// writes it into another file

// NOTE:	The code assumes that the image is of size 256 x 256 and is in the
//			RAW format. You will need to make corresponding changes to
//			accommodate images of different sizes and/or types
////////////////////////////////////////////
// Name : SHILPASHREE RAO
// USC ID: 5636765972
// EMAIL ID: shilpasr@usc.edu
// Submission Date: 2/4/2018
// EE569 HW 1
////////////////////////////////////////////////
///Code for 512 colors//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <valarray>
#include <vector>

using namespace std;

int maxRepeating(vector<unsigned int>& arr, int n)
{
	int valcount[255] = {0};
    for (int i = 0; i < n; i++)
    	valcount[arr[i]]++;

    int max = valcount[0], result = 0;
    for (int i = 1; i < 255; i++)
    {
        if (valcount[i] > max)
        {
            max = valcount[i];
            result = i;
        }
    }

    return result;
}

int main(int argc, char *argv[]){
	// Define file pointer and variables
	FILE *f1;
	FILE *f2;
	FILE *f3;
	FILE *file;
	int BytesPerPixel;
	int windowSize;
	int Height = 256 , Width = 256;
	
	// Check for proper syntax
	if (argc < 2){
		cout << "Syntax Error - Incorrect Parameter Usage:" << endl;
		//cout << "program_name input_image.raw output_image.raw [BytesPerPixel = 1] [Size = 256]" << endl;
		cout << "program_name input_image.raw [BytesPerPixel = 1] [Height = 256] [Width = 256] [Window Size = 5]" << endl;
		return 0;
	}
	
	// Check if image is grayscale or color
	if (argc < 3){
		BytesPerPixel = 1; // default is grey image
	} 
	else {
		BytesPerPixel = atoi(argv[2]);
	}

	// Check if height is specified
	if (argc == 4) {
		Width = atoi(argv[3]);
	}
	else {
		// Check if width is specified
		Width = atoi(argv[3]);
		Height = atoi(argv[4]);
	}

	if(argc < 6) {
		windowSize = 5;
	}
	else{
		windowSize = atoi(argv[5]);
	}
	
	// Allocate image data array
	unsigned char Imagedata[Height][Width][BytesPerPixel];

	// Read image (filename specified by first argument) into image data matrix
	if (!(file=fopen(argv[1],"rb"))) {
		cout << "Cannot open file: " << argv[1] <<endl;
		exit(1);
	}
	fread(Imagedata, sizeof(unsigned char), Height*Width*BytesPerPixel, file);
	fclose(file);

	///////////////////////// INSERT YOUR PROCESSING CODE HERE /////////////////////////

	////////Step 1/////////////

	unsigned char quantizedImage[Height][Width][BytesPerPixel];
	unsigned int histogramBin[BytesPerPixel][256] = {0};
	unsigned int pixelSum[BytesPerPixel][256] = {0};
	for(int k = 0; k < 3; k++){
		for(int i = 0; i < Height; i++){
			for(int j = 0; j < Width; j++){
				histogramBin[k][Imagedata[i][j][k]]++;
				pixelSum[k][Imagedata[i][j][k]] += static_cast<unsigned int>(Imagedata[i][j][k]);
			}
		}
	}

	float pixelsInEachBin = (Height * Width)/8.0;
	int binNumber;
	unsigned int start[8][BytesPerPixel] = {0};
	unsigned int Mean[8][BytesPerPixel];
	unsigned int sumOfFrequencies[BytesPerPixel] = {0};
	unsigned int sumOfPixels[BytesPerPixel] = {0};
	for(int k = 0; k < 3; k++){
		binNumber = 0;
		//start[0][k] = static_cast<unsigned char>(0);
		for(int i = 0; i < 256; i++){
			sumOfFrequencies[k] += histogramBin[k][i];
			sumOfPixels[k] += pixelSum[k][i];
			if (((sumOfFrequencies[k] >= static_cast<int>(pixelsInEachBin)) && (binNumber < 7)) || (i == 255)){
				Mean[binNumber][k] = sumOfPixels[k]/sumOfFrequencies[k];
				binNumber += 1;
				start[binNumber][k] = static_cast<unsigned char>(i + 1);
				sumOfFrequencies[k] = 0;
				sumOfPixels[k] = 0;
			}
		}
	}
	for(int i = 0; i < 8; i++) {
		cout << Mean[i][0] << " ";
	}
	for(int k = 0; k < 3; k++){
		for(int i = 0; i < Height; i++) {
			for(int j = 0; j < Width; j++) {
				if(Imagedata[i][j][k] < start[1][k])
					quantizedImage[i][j][k] = static_cast<unsigned char>(Mean[0][k]);
				else if(start[1][k] <= Imagedata[i][j][k] && Imagedata[i][j][k] < start[2][k])
					quantizedImage[i][j][k] = static_cast<unsigned char>(Mean[1][k]);
				else if(start[2][k] <= Imagedata[i][j][k] && Imagedata[i][j][k] < start[3][k])
					quantizedImage[i][j][k] = static_cast<unsigned char>(Mean[2][k]);
				else if(start[3][k] <= Imagedata[i][j][k] && Imagedata[i][j][k] < start[4][k])
					quantizedImage[i][j][k] = static_cast<unsigned char>(Mean[3][k]);
				else if(start[4][k] <= Imagedata[i][j][k] && Imagedata[i][j][k] < start[5][k])
					quantizedImage[i][j][k] = static_cast<unsigned char>(Mean[4][k]);
				else if(start[5][k] <= Imagedata[i][j][k] && Imagedata[i][j][k] < start[6][k])
					quantizedImage[i][j][k] = static_cast<unsigned char>(Mean[5][k]);
				else if(start[6][k] <= Imagedata[i][j][k] && Imagedata[i][j][k] < start[7][k])
					quantizedImage[i][j][k] = static_cast<unsigned char>(Mean[6][k]);
				else if(start[7][k] <= Imagedata[i][j][k])
					quantizedImage[i][j][k] = static_cast<unsigned char>(Mean[7][k]);
			}
		}	
	}

	///////Step 2/////////

	unsigned int paddedImage[Height+windowSize-1][Width+windowSize-1][BytesPerPixel] = {0};
	unsigned char oilPainted[Height][Width][BytesPerPixel];
	for(int k = 0; k < 3; k++){
		for(int i = 0; i < Height+windowSize-1; i++) {
			for(int j = 0; j < Width+windowSize-1; j++) {
				paddedImage[i][j][k] = 300;
			}
		}
	} 
	for(int k = 0; k < 3; k++){
		for(int i = 0; i < Height; i++) {
			for(int j = 0; j < Width; j++) {
				paddedImage[i+(windowSize-1)/2][j+(windowSize-1)/2][k] = static_cast<unsigned int>(quantizedImage[i][j][k]);
			}
		}
	} 

	//unsigned int windowElements[windowSize][windowSize];
	//unsigned int stretchedArray[windowSize*windowSize];
	vector<unsigned int> stretchedArray;
	for(int k = 0; k < 3; k++){
		for(int i = (windowSize-1)/2; i < Height+(windowSize-1)/2; i++) {
			for(int j = (windowSize-1)/2; j < Width+(windowSize-1)/2; j++) {
				for(int x = -1*((windowSize-1)/2); x <= (windowSize-1)/2; x++) {
					for(int y = -1*((windowSize-1)/2); y <= (windowSize-1)/2; y++) {
						//windowElements[x+(windowSize-1)/2][y+(windowSize-1)/2] = static_cast<unsigned int>(paddedImage[i+x][j+y][k]);
						if(paddedImage[i+x][j+y][k] != 300) 
							stretchedArray.push_back(paddedImage[i+x][j+y][k]);
					}
				}
				oilPainted[i-(windowSize-1)/2][j-(windowSize-1)/2][k] = static_cast<unsigned char>(maxRepeating(stretchedArray, stretchedArray.size()));
				while(!stretchedArray.empty()) {
					stretchedArray.pop_back();
				}
			}
		}
	}

	// Write image data (filename specified by second argument) from image data matrix

	//if (!(file=fopen(argv[2],"wb"))) {
	//	cout << "Cannot open file: " << argv[2] << endl;
	//	exit(1);
	///}
	/*cout << Mean[0][0] << " " << Mean[1][0] << " " << Mean[2][0] << " " << Mean[3][0] << " ";
	cout << Mean[0][1] << " " << Mean[1][1] << " " << Mean[2][1] << " " << Mean[3][1] << " ";
	cout << Mean[0][2] << " " << Mean[1][2] << " " << Mean[2][2] << " " << Mean[3][2] << " ";*/
	 f1 = fopen("Quantized_output_512.raw","wb");
	 fwrite(quantizedImage, sizeof(unsigned char), Height*Width*BytesPerPixel, f1);
	 fclose(f1);
	 f2 = fopen("OilPainted_output_512.raw","wb");
	 fwrite(oilPainted, sizeof(unsigned char), Height*Width*BytesPerPixel, f2);
	 fclose(f2);
	// f2 = fopen("M_output.raw","wb");
	// fwrite(M, sizeof(unsigned char), Height*Width*1, f2);
	// fclose(f2);
	// f3 = fopen("Y_output.raw","wb");	
	// fwrite(Y, sizeof(unsigned char), Height*Width*1, f3);	
	// fclose(f3);

	return 0;
}

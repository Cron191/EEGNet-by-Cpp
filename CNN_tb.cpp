#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <fstream>
#include <iostream>
#include "CNN.h"
#include "Conv.h"
#include "Pool.h"
#include "Dense.h"
#define NumberOfPicture 1000
#define d 1
int main()
{
	float OutModel0[1] = {0};
	float *Weights = (float *)malloc(2001 * sizeof(float));
	float tmp;
	FILE *Weight = fopen("Float_Weights.txt", "r");
	for (int i = 0; i < 2001; i++)
	{
		fscanf(Weight, "%f", &tmp);
		*(Weights + i) = tmp;
	}
	fclose(Weight);
	////read Input
	float *InModel = (float *)malloc((NumberOfPicture * d * 18 * 512) * sizeof(float));
	FILE *Input = fopen("Valid_Input_1000.txt", "r");
	for (int i = 0; i < NumberOfPicture * d * 18 * 512; i++)
	{
		fscanf(Input, "%f", &tmp);
		*(InModel + i) = tmp;
	}
	fclose(Input);
	// Read Label
	float *Label = (float *)malloc((NumberOfPicture * 1) * sizeof(float));
	FILE *Output = fopen("Valid_Label_1000.txt", "r");
	for (int i = 0; i < NumberOfPicture * 1; i++)
	{
		fscanf(Output, "%f", &tmp);
		*(Label + i) = tmp;
	}
	fclose(Output);
	float *OutArray = (float *)malloc((NumberOfPicture * 1) * sizeof(float));
	for (int i = 0; i < NumberOfPicture; i++)
	{
		float Image[18 * 512] = {};
		int startIndex = i * 18 * 512;
		for (int k = 0; k < 18 * 512; k++)
		{
			Image[k] = *(InModel + startIndex + k);
		}
		CNN(Image, OutModel0, Weights);
		std::cout<<OutModel0[0]<<" "<<Label[i]<<'\n';
		*(OutArray + i) = OutModel0[0];
	}
	float countTrue = 0;
	for (int i = 0; i < NumberOfPicture * 1; i++)
	{
		int labelValue = (int)*(Label + i);
		int PredictValue = *(OutArray + i) >= 0.5 ? 1 : 0;
		if (labelValue == PredictValue)
		{
			countTrue = countTrue + 1;
		}
	}
	float accuracy = (float)((countTrue / (NumberOfPicture * 1)) * 100);
	std::cout << "accuracy of Model: " << accuracy << "%\n";
	return 0;
}

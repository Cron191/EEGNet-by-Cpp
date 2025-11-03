#include "Conv.h"
#include "Pool.h"
#include "Dense.h"
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <math.h>
void CNN(float InModel[9216], float OutModel0[1], float Weights[2001])
{
	float OutPadConv0[11502];
	float conv2d[73728];
	float batch_normalization[73728];
	float depthwise_conv2d[8192];
	float batch_normalization_1[8192];
	float activation[8192];
	float average_pooling2d[2048];
	float OutPadConv2[2288];
	float separable_conv2d[2048];
	float batch_normalization_2[2048];
	float activation_1[2048];
	float average_pooling2d_1[256];
	float global_average_pooling2d[16];
	float Output_S_D[2048];
	Padding_Conv2D_0(InModel, OutPadConv0);
	Conv2D_0(OutPadConv0, conv2d, &Weights[0]);
	BatchNorm2D_0(conv2d, batch_normalization, &Weights[1024], &Weights[1032], &Weights[1040], &Weights[1048]);
	DepthWise_Con(batch_normalization, depthwise_conv2d, &Weights[1056]);
	BatchNorm2D_1(depthwise_conv2d, batch_normalization_1, &Weights[1344], &Weights[1360], &Weights[1376], &Weights[1392]);
	Activation0(batch_normalization_1, activation);
	average_Pool2D_0(activation, average_pooling2d);
	Padding_Conv2D_2(average_pooling2d, OutPadConv2);
	Separable_Depthwise(OutPadConv2, Output_S_D, &Weights[1408]);
	Separable_Pointwise(Output_S_D, separable_conv2d, &Weights[1664]);
	BatchNorm2D_2(separable_conv2d, batch_normalization_2, &Weights[1920], &Weights[1936], &Weights[1952], &Weights[1968]);
	Activation1(batch_normalization_2, activation_1);
	average_Pool2D_1(activation_1, average_pooling2d_1);
	GlobalAveragePool2D_0(average_pooling2d_1, global_average_pooling2d);
	Dense_0(global_average_pooling2d, OutModel0, &Weights[2000], &Weights[1984]);
}

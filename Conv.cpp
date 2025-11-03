void Padding_Conv2D_0(float input_Pad_Conv[9216], float output_Pad_Conv[11502])
{
	for (int n = 0; n < 18; n++)
	{
		for (int i = 0; i < 639; i++)
		{
			if (i < 63)
				output_Pad_Conv[639 * n + i] = 0;
			else if (i >= 63 && i < 575)
				output_Pad_Conv[639 * n + i] = input_Pad_Conv[512 * n + i - 63];
			else
				output_Pad_Conv[639 * n + i] = 0;
		}
	}
}
void Conv2D_0(float Input_Conv[11502], float Output_Conv[73728], float kernel[1024])
{
	for (int n = 0; n < 8; n++)
	// Số kernel
	{
	loop_for_bp2D_0:
		for (int x = 0; x < 18; x++)
		// Số kênh
		{
		loop_for_ap2D_0:
			for (int y = 0; y < 512; y++)
			// Kích thước mỗi kênh input
			{
				float s = 0;
				for (int j = 0; j < 128; j++)
				// Kích thước kernel
				{
					s = s + kernel[n + j * 8] * Input_Conv[x * 639 + y + j];
				}
				Output_Conv[18 * 512 * n + 512 * x + y] = s;
			}
		}
	}
}
#include <cmath>
void BatchNorm2D_0(float Input_BatchNorm[73728], float Output_BatchNorm[73728], float gamma[8], float beta[8], float MovMean[8], float MovVar[8])
{
	float eps = 0.001;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 9216; j++)
		{
			Output_BatchNorm[9216 * i + j] = ((Input_BatchNorm[9216 * i + j] - MovMean[i]) / (sqrt(MovVar[i] + eps))) * gamma[i] + beta[i];
		}
	}
}
void DepthWise_Con(float Input_Conv[73728], float Output_Conv[8192], float kernel[288])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int x = 0; x < 512; x++)
			{
				float s = 0;
				for (int y = 0; y < 18; y++)
				{
					s = s + kernel[i * 2 + j + y * 16] * Input_Conv[i * 9216 + y * 512 + x];
				}
				Output_Conv[(2 * i + j) * 512 + x] = s;
			}
		}
	}
}
#include <cmath>
void BatchNorm2D_1(float Input_BatchNorm[8192], float Output_BatchNorm[8192], float gamma[16], float beta[16], float MovMean[16], float MovVar[16])
{
	float eps = 0.001;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 512; j++)
		{
			Output_BatchNorm[512 * i + j] = ((Input_BatchNorm[512 * i + j] - MovMean[i]) / (sqrt(MovVar[i] + eps))) * gamma[i] + beta[i];
		}
	}
}
void Activation0(float Input_Activation[8192], float Output_Activation[8192])
{
	for (int i = 0; i < 8192; i++)
	{
		float x = Input_Activation[i];
		Output_Activation[i] = x > 0 ? x : (expf(x) - 1);
	}
}
void Padding_Conv2D_2(float input_Pad_Conv[2048], float output_Pad_Conv[2288])
{
loop_for_3_channel_pad_2:
	for (int c = 0; c < 16; c++)
	{
		for (int i = 0; i < 143; i++)
		{
			if (i < 7)
				output_Pad_Conv[143 * c + i] = 0;
			else if (i >= 7 && i < 135)
				output_Pad_Conv[143 * c + i] = input_Pad_Conv[128 * c + i - 7];
			else
				output_Pad_Conv[143 * c + i] = 0;
		}
	}
}
void Separable_Depthwise(float Input_Conv[2288], float Output_Conv[2048], float kernel[256])
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			float s = 0;
			for (int x = 0; x < 16; x++)
			{
				s = s + kernel[i + x * 16] * Input_Conv[i * 143 + j + x];
			}
			Output_Conv[i * 128 + j] = s;
		}
	}
}
void Separable_Pointwise(float Input_Conv[2048], float Output_Conv[2048], float kernel[256])
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			float s = 0;
			for (int x = 0; x < 16; x++)
			{
				s += kernel[x * 16 + i] * Input_Conv[x * 128 + j];
			}
			Output_Conv[i * 128 + j] = s;
		}
	}
}
#include <cmath>
void BatchNorm2D_2(float Input_BatchNorm[2048], float Output_BatchNorm[2048], float gamma[16], float beta[16], float MovMean[16], float MovVar[16])
{
	float eps = 0.001;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			Output_BatchNorm[128 * i + j] = ((Input_BatchNorm[128 * i + j] - MovMean[i]) / (sqrt(MovVar[i] + eps))) * gamma[i] + beta[i];
		}
	}
}
void Activation1(float Input_Activation[2048], float Output_Activation[2048])
{
	for (int i = 0; i < 2048; i++)
	{
		Output_Activation[i] = Input_Activation[i] > 0 ? Input_Activation[i] : (expf(Input_Activation[i]) - 1);
	}
}

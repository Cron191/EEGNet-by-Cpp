void average_Pool2D_0(float input_AveragePooling[8192], float output_AveragePooling[2048])
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			float s = 0;
			for (int x = 0; x < 4; x++)
			{
				s += input_AveragePooling[i * 512 + j * 4 + x];
			}
			output_AveragePooling[i * 128 + j] = s / 4;
		}
	}
}
void average_Pool2D_1(float input_AveragePooling[2048], float output_AveragePooling[256])
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			float s = 0;
			for (int x = 0; x < 8; x++)
			{
				s += input_AveragePooling[i * 128 + j * 8 + x];
			}
			output_AveragePooling[i * 16 + j] = s / 8;
		}
	}
}
void GlobalAveragePool2D_0(float input_GlobalAveragePool2D[256], float output_GlobalAveragePool2D[16])
{
	for (int i = 0; i < 16; i++)
	{
		float avg = 0;
		for (int k = 0; k < 16; k++)
		{
			avg += input_GlobalAveragePool2D[16 * i + k];
		}
		output_GlobalAveragePool2D[i] = avg / (1 * 16);
	}
}

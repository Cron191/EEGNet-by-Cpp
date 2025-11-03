#include <cmath>
void Dense_0(float input_Dense[16], float output_Dense[1], float bias[1], float weight[16])
{
	float out_Dense[1];
loop_for_a_Dense_0:
	for (int i = 0; i < 1; i++)
	{
		float s = 0;
	loop_for_b_Dense_0:
		for (int j = 0; j < 16; j++)
		{
			s += input_Dense[j] * weight[j * 1 + i];
		}
		out_Dense[i] = s + bias[i];
	}
	for (int i = 0; i < 1; i++)
	{
		output_Dense[i] = 1 / (1 + exp(-out_Dense[i]));
	}
}

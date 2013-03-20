#include <iostream>
#define FORMAT_OFFSET 44

int main(){

  char *input_signal = new char [2];
  short int input_signal_short;
  char output_byte;
  int count = 0;
  int i_count = 0;
  double d_delay = 0;
  double dd_delay = 0;
  double pre_quantization_signal=0;
  int quantized_signal=0;
  int tmp_output[7];

  while (std::cin.read(input_signal,2) != 0)
    {
      if (count >= FORMAT_OFFSET){
	*((char*)(&input_signal_short))=input_signal[0];
	*((char*)(&input_signal_short) + 1)=input_signal[1];
	pre_quantization_signal=((double)input_signal_short+32768.0)/65536.0 + d_delay*2 - dd_delay;
	if (pre_quantization_signal >= 0.5)
	  quantized_signal = 1;
	else
	  quantized_signal = 0;
	dd_delay = d_delay;
	d_delay = pre_quantization_signal - quantized_signal;
	tmp_output[i_count]=quantized_signal;
	i_count = i_count + 1;

	if (i_count>7){
	  output_byte = 64*tmp_output[0] + 32*tmp_output[1] + 
	    16*tmp_output[2] + 8*tmp_output[3] + 4*tmp_output[4] +
	    2*tmp_output[5] + tmp_output[6];
	  output_byte=output_byte - 128;
	  std::cout.write(&output_byte,1);
	  i_count = 0;
	}
      }
      count = count + 1;
    }
}

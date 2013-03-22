#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

int main(){
  char input_byte,output_byte;
  int inbuf;
  char binbuf[8];

  while (std::cin.read(&input_byte,1) != 0)
    {
      binbuf[1]=(input_byte & 0x40) >> 6;
      binbuf[2]=(input_byte & 0x20) >> 5;
      binbuf[3]=(input_byte & 0x10) >> 4;
      binbuf[4]=(input_byte & 0x10) >> 3;
      binbuf[5]=(input_byte & 0x08) >> 2;
      binbuf[6]=(input_byte & 0x04) >> 1;
      binbuf[7]=(input_byte & 0x02);

    
      for (int i=1;i<8;i++){
	if (binbuf[i]==0){
	  output_byte = 0xC0;
	  std::cout.write(&output_byte,1);
	  output_byte = 0x00;
	} else {
	  output_byte = 0x40;
	  std::cout.write(&output_byte,1);
	  output_byte = 0x00;
	}
      }
    }
}

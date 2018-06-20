#include <iostream>
#include <math.h>

using namespace std;

#define CHANNELS 3
__global__ 
void blurKernel(unsigned char* in, unsigned char* out, int w, int h) {
	int Col  = blockIdx.x * blockDim.x + threadIdx.x;
	int Row  = blockIdx.y * blockDim.y + threadIdx.y;

	if (Col < w && Row < h) {
		int pixVal = 0;
		int pixels = 0;

		// Get the average of the surrounding 2xBLUR_SIZE x 2xBLUR_SIZE box
		for(int blurRow = -BLUR_SIZE; blurRow < BLUR_SIZE+1; ++blurRow) {
			for(int blurCol = -BLUR_SIZE; blurCol < BLUR_SIZE+1; ++blurCol) {

				int curRow = Row + blurRow;
				int curCol = Col + blurCol;
				// Verify we have a valid image pixel
				if(curRow > -1 && curRow < h && curCol > -1 && curCol < w) {
					pixVal += in[curRow * w + curCol];
					pixels++; // Keep track of number of pixels in the accumulated total
				}
			}
		}

		// Write our new pixel value out
		out[Row * w + Col] = (unsigned char)(pixVal / pixels);
	}
}

int main(int argc, char** argv){
	
	if (argc < 3){
		cout << "Usage: " << argv[0] << " <input.png>" << " <output.png>" << endl;
		exit(1);
	}
	
	string input_file;
	string output_cuda_file  = "../input.png";
	
	input_file  = string(argv[1]);
	output_cuda_file = string(argv[2]);



	return 0;

}

#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
	Scalar_<int> blue(255, 0, 0);

	cout << blue[0] << blue[1] << blue[2] << blue[3] << endl;
}
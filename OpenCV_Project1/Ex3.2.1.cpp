#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main() {
	float data[] = {
		1.2f, 2.3f, 3.2f,
		4.5f, 4.9f, 6.5f
	};

	//Mat 按眉 急攫 规过
	Mat m1(2, 3, CV_8UC1);
	Mat m2(2, 3, CV_8UC1, Scalar(300));
	Mat m3(2, 3, CV_16S, Scalar(300));
	Mat m4(2, 3, CV_32F, data);

	//Size_ 按眉肺 Mat 急攫 规过
	Size sz(2, 3);
	Mat m5(Size(2, 3), CV_64F);
	Mat m6(sz, CV_32F, data);

	cout << "[m1] = " << endl << m1 << endl;
	cout << "[m2] = " << endl << m2 << endl;
	cout << "[m3] = " << endl << m3 << endl;
	cout << "[m4] = " << endl << m4 << endl << endl;
	cout << "[m5] = " << endl << m5 << endl;
	cout << "[m6] = " << endl << m6 << endl;
	return 0;
		
	}
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
	Mat m1(3, 5, CV_32S), m2(3, 5, CV_32S);

	for (int i = 0, k = 0; i < m1.rows; i++) {
		for (int j = 0; j < m1.cols; j++, k++) {
			m1.at<int>(i, j) = k;
			m1.at<short>(i, j) = k;
		}
	}

	cout << "[m1] = " << endl << m1 << endl << endl;
	cout << "[m2] = " << endl << m2 << endl;

	return 0;
}
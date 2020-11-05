#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat image;

int threshold1,threshold2;

string title = "canny edge";

void onChange(int value, void* userdata) {
	Mat canny;
	Canny(image, canny, threshold1, threshold2);	//캐니에지
	imshow(title, canny);
}

int main() {
	image = imread("image/bit_test.jpg", 0);

	namedWindow(title);

	createTrackbar("th1", title, &threshold1, 255, onChange);
	createTrackbar("th2", title, &threshold2, 255, onChange);

	waitKey(0);
	return 0;
}
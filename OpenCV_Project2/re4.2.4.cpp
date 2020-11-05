#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

string title = "밝기변경", bar_name = "발기값";
Mat img;

void onChange(int value, void* userdata) {
	int add_value = value - 128;
	cout << "추가 화소값" << add_value << endl;

	Mat tmp = img + add_value;
	imshow(title, tmp);
}

int main_k() {
	int value = 128;
	img = Mat(300, 400, CV_8UC1, Scalar(128));

	namedWindow(title, WINDOW_NORMAL);
	createTrackbar(bar_name, title, &value, 255, onChange);

	imshow(title, img);
	waitKey(0);
	return 0;
}
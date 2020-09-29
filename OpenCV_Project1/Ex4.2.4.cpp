#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

string title = "밝기변경", bar_name = "밝기 값";
Mat image;

void onChange(int value, void* userdata) {			//callback함수의 이름은 사용자가 임의로 정할 수 있으나 매개변수는 지정된걸 써야함.
	int add_value = value - 128;
	cout << "추가 화소값" << add_value << endl;
	
	Mat tmp = image + add_value;
	imshow(title, tmp);
}

void onMouse(int event, int x, int y, int flags, void* param) {
	if (event == EVENT_RBUTTONDOWN) {
		add(image, 10, image);
		setTrackbarPos(bar_name, title, image.at<uchar>(0));
		imshow(title, image);
	}
	else if (event == EVENT_LBUTTONDOWN) {
		subtract(image, 10, image);
		setTrackbarPos(bar_name, title, image.at<uchar>(0));
		imshow(title, image);
	}
}

int main() {
	int value = 130;
	image = Mat(300, 500, CV_8UC1, Scalar(120));

	namedWindow(title, WINDOW_AUTOSIZE);
	createTrackbar(bar_name, title, &value, 255, onChange);
	setMouseCallback(title, onMouse, 0);

	imshow(title, image);
	waitKey(0);

	return 0;
}
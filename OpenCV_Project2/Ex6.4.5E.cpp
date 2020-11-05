#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Range th(50, 100);
Mat hue;
Mat HSV, hsv[3];
Mat result, result1, result2;

string title = "result";

void onThreshold(int value, void* userdata) {

	result = Mat(hue.size(), CV_8U, Scalar(0));

	threshold(hue, result1, th.start, 255, THRESH_BINARY);	//th.start보다 크면 255 작으면0
	threshold(hue, result2, th.end, 255, THRESH_BINARY_INV);	//th.end보다 작으면 255 크면 0
	bitwise_and(result1, result2, result);	//비트연산 and

	imshow(title, result);
}

int main() {
	Mat BGR_img = imread("image/woman1.jpg", 1);
	CV_Assert(BGR_img.data);

	
	cvtColor(BGR_img, HSV, COLOR_BGR2HSV);
	split(HSV, hsv);
	hsv[0].copyTo(hue);

	namedWindow("result", WINDOW_AUTOSIZE);

	createTrackbar("Hue_th1", title, &th.start, 255, onThreshold);
	createTrackbar("Hue_th2", title, &th.end, 255, onThreshold);

	onThreshold(0,0);
	imshow("BGR_img", BGR_img);
	waitKey(0);
	return 0;
}
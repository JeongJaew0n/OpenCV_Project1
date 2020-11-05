#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

Mat x, y;
string title = "test";

int main() {
	Mat image = imread("image/logo.jpg",1);
	Mat bgr[3], blue_img, green_img, red_img, zero(image.size(), CV_8U, Scalar(0));
	split(image, bgr);

	Mat blue[] = { bgr[0], zero, zero };
	Mat green[] = { zero, bgr[1], zero };
	Mat red[] = { zero, zero, bgr[2] };
	merge(blue, 3, blue_img);
	merge(green, 3, green_img);
	merge(red, 3, red_img);

	imshow("image", image);
	imshow("blue", blue_img);
	imshow("green", green_img);
	imshow("red", red_img);
	waitKey(0);
	return 0;
}
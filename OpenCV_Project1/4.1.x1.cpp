#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
	Mat image1(300, 400, CV_8UC3, Scalar(255, 255, 255));
	Mat image2(300, 400, CV_8UC3, Scalar(100, 100, 100));
	string title1 = "창크기변경1-AUTOSIZE";
	string title2 = "창크기변경2-NORMAL";

	namedWindow(title1, WINDOW_AUTOSIZE);
	namedWindow(title2, WINDOW_NORMAL);

	resizeWindow(title1, 500, 200);
	resizeWindow(title2, 500, 200);

	imshow(title1, image1);
	imshow(title2, image2);
	moveWindow(title1, 100, 200);
	
	

	waitKey();
	destroyAllWindows();

	return 0;

}
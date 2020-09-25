#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main_ee() {
	Mat image(300, 500, CV_8UC3, Scalar(255)); //하나의 채널을 갖는 8비트 
	Point2f center(250, 150), pts[4];
	Size2f size(300, 100);
	RotatedRect rot_rect(center, size, 20);
	//B G R
	Rect bound_rect = rot_rect.boundingRect();
	rectangle(image, bound_rect, Scalar(0,0,255,255), 1);
	circle(image, rot_rect.center, 1, Scalar(0), 2);
	rot_rect.points(pts);
	for (int i = 0; i < 4; i++) {
		circle(image, pts[i], 40, Scalar(0,0,255,0), 2);
		line(image, pts[i], pts[(i + 1) % 4], Scalar(0,0,255,0), 2);
	}

	imshow("회전사각형", image);
	waitKey(0);
	return 0;
}
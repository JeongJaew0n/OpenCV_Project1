#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

//문제를 해결하지 못해 그냥 클릭시 영상 반전효과만 있습니다...

Mat image;
string title = "Excercise16";

void onMouse(int event, int x, int y, int flags, void* userdata) {
	Mat img = image.clone();	//img에 image에 있는 이미지 복사
	if (event == EVENT_LBUTTONDOWN || event == EVENT_RBUTTONDOWN) {
		bitwise_not(img, img);	//색상반전
		
	}
	imshow(title, img);
}

int main() {

	image = imread("image/bit_test.jpg", IMREAD_COLOR);
	
	namedWindow(title);

	setMouseCallback(title,onMouse);

	waitKey(0);
	return 0;
}
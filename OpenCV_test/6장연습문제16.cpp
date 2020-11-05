#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

//������ �ذ����� ���� �׳� Ŭ���� ���� ����ȿ���� �ֽ��ϴ�...

Mat image;
string title = "Excercise16";

void onMouse(int event, int x, int y, int flags, void* userdata) {
	Mat img = image.clone();	//img�� image�� �ִ� �̹��� ����
	if (event == EVENT_LBUTTONDOWN || event == EVENT_RBUTTONDOWN) {
		bitwise_not(img, img);	//�������
		
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
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// image
Mat img;

// sub_image
Mat sub_img;
int threshold1 = 50;
int threshold2 = 100;

void onTrackbar(int, void*)
{
	// Canny ����
	Mat edges;
	Canny(img, edges, threshold1, threshold2);

	// show image
	imshow("Canny", edges);
}

int main()
{
	// GRAYSCALE�� ����
	img = imread("image/bit_test.jpg", IMREAD_GRAYSCALE);

	// Assert -> img.data
	CV_Assert(img.data);

	// set window name
	namedWindow("Canny", WINDOW_AUTOSIZE);

	// trackbar�� �ΰ�������
	// �Լ��� window�� �������� ��ħ
	// max_val = 255
	createTrackbar("th1", "Canny", &threshold1, 255, onTrackbar);
	createTrackbar("th2", "Canny", &threshold2, 255, onTrackbar);

	// �ѹ� ���� -> imshow
	onTrackbar(0, 0);
	waitKey();
	return 0;
}
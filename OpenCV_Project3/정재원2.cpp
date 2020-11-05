#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void minMaxFilter(Mat img, Mat& dst, int size, int flag = 1) {	//1�̸� �ִ� 0�̸� �ּ�
	dst = Mat(img.size(), CV_8U, Scalar(0));
	Size msize(size, size);
	Point h_m = msize / 2;

	for (int i = h_m.y; i < img.rows - h_m.y; i++) {
		for (int j = h_m.x; j < img.cols - h_m.x; j++) {
			Point start = Point(j, i) - h_m;
			Rect roi(start, msize);
			Mat mask = img(roi);

			double minVal, maxVal;
			minMaxLoc(mask, &minVal, &maxVal);
			dst.at<uchar>(i, j) = (flag) ? maxVal : minVal;
		}
	}
}

int main() {
	Mat image = imread("image/bit_test.jpg", 0);
	CV_Assert(image.data);

	Mat max_img, result;
	minMaxFilter(image, max_img, 5, 1);
	copyMakeBorder(max_img, result, 1, 1, 1, 1, BORDER_REFLECT, Scalar(0));
	//border������ ���� �̹����� ���� ���� ���� ��,��,��,�� 1�� ��ġ�� BORDER_REFLECT������ �µθ��� ���� 0(������)�� �׵θ� ����

	imshow("MaxImage", max_img);
	imshow("MaxImage with BORDER_REFLECT", result);

	waitKey(0);
	return 0;
}
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void minMaxFilter(Mat img, Mat& dst, int size, int flag = 1) {	//1이면 최대 0이면 최소
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
	//border설정을 위해 이미지를 새로 만든 다음 상,하,좌,우 1의 위치에 BORDER_REFLECT형태의 태두리로 색이 0(검은색)인 테두리 설정

	imshow("MaxImage", max_img);
	imshow("MaxImage with BORDER_REFLECT", result);

	waitKey(0);
	return 0;
}
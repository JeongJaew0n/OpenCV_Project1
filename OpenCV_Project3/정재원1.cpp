#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;


void filter(Mat img, Mat& dst, Mat mask) {	
	dst = Mat(img.size(), CV_32F, Scalar(0));	
	Point h_m = mask.size() / 2;	

	for (int i = h_m.y; i < img.rows - h_m.y; i++) {
		for (int j = h_m.x; j < img.cols - h_m.x; j++) {
			float sum = 0;
			for (int u = 0; u < mask.rows; u++) {
				for (int v = 0; v < mask.cols; v++) {
					int y = i + u - h_m.y;
					int x = j + v - h_m.x;
					sum += mask.at<float>(v, u) * img.at<uchar>(y, x);	
				}
			}
			dst.at<float>(i, j) = sum;
		}
	}
}
/*흑백은 하나의 채널만 가지고 있고 컬러는 3개의 채널을 가지고있음 b,g,r에 각각 filter처리를 해준 뒤 합치면 컬러 샤프닝
*/
void color_filter(Mat img, Mat &dst, Mat mask) {

	Mat bgr[3],change_bgr[3];

	split(img, bgr);
	for (int i = 0; i < 3; i++) {
		filter(bgr[i], change_bgr[i], mask);
	}
	merge(change_bgr,3, dst);
}

int main() {
	Mat image = imread("image/bit_test.jpg", IMREAD_COLOR);
	CV_Assert(image.data);

	float data1[] = {
	0, -1, 0,
	-1, 5, -1,
	0, -1, 0,
	};
	float data2[] = {
		-1, -1, -1,
		-1, 9, -1,
		-1, -1, -1,
	};

	Mat mask1(3, 3, CV_32F, data1);
	Mat mask2(3, 3, CV_32F, data2);
	Mat sharpen1, sharpen2;
	color_filter(image, sharpen1, mask1);
	color_filter(image, sharpen2, mask2);
	sharpen1.convertTo(sharpen1, CV_8U);
	sharpen2.convertTo(sharpen2, CV_8U);

	imshow("sharpen1", sharpen1);
	imshow("sharpen2", sharpen2);
	imshow("image", image);
	waitKey();
	return 0;
}
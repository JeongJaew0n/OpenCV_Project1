#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void filter(Mat img, Mat& dst, Mat mask) {	//회선 수행함수
	dst = Mat(img.size(), CV_32F, Scalar(0));	//회선 결과 저장 행렬
	Point h_m = mask.size() / 2;	//마스크 중심 좌표

	cout << "at의 위치: "  << mask.at<float>(2, 0) << endl;

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

int main() {
	Mat image = imread("image/bit_test.jpg",IMREAD_GRAYSCALE);
	CV_Assert(image.data);

	float data[] = {
		1 / 9.f ,1 / 9.f ,1 / 9.f,
		1 / 9.f, 1 / 9.f, 1 / 9.f,
		1 / 3.f, 1 / 9.f, 1 / 9.f
	};
	Mat mask(3, 3, CV_32F, data);
	Mat blur;
	filter(image, blur, mask);
	blur.convertTo(blur, CV_8U);

	imshow("image", image), imshow("blur", blur);
	waitKey();
	return 0;
}
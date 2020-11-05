#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Mat image1;
Mat image2;
Mat add_img;

string title = "image";

void onChange(int value, void* userdata) {
	double alpha = (double)value / 100;
	double beta = 1 - alpha;

	int I_alpha = alpha * 100;
	int I_beta = beta * 100;

	addWeighted(image1, alpha, image2, beta, 0, add_img);

	cout << "[alpha]: " << alpha << endl;
	cout << "[beta]: " << beta << endl << "------------" << endl;

	imshow(title, add_img);
}

int main() {
	
	image1 = imread("image/m1_woman1.jpg", IMREAD_GRAYSCALE);		//중요! 가로세로각 같은 이미지를 불러와야함!
	image2 = imread("image/m2_woman1.jpg", IMREAD_GRAYSCALE);
	CV_Assert(!(image1.empty() || image2.empty()));

	add_img = image1 * 0.5 + image2 * 0.5;;

	int value = 50;

	imshow(title, add_img);

	createTrackbar("alpha", title, &value, 100, onChange);

	waitKey(0);
	return 0;
}
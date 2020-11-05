#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Mat image;

Rect roi;
Size s(5, 3);

void onMouse(int event, int x, int y,int flags, void* param) {
	if (event == EVENT_LBUTTONDOWN || event == EVENT_RBUTTONDOWN) {
		roi = Rect(Point(x,y), s);
		Mat roi_img = image(roi);

		cout << "[roi img] / " << flags << endl;

		for (int i = 0; i < roi_img.rows; i++) {
			for (int j = 0; j < roi_img.cols; j++) {
				cout.width(5);
				cout << (int)roi_img.at<uchar>(i, j);
			}
			cout << endl;
		}

		rectangle(image, roi, Scalar(255), 1);

		imshow("image", image);
	}


}

int main() {
	image = imread("image/woman1.jpg",IMREAD_GRAYSCALE);
	if (image.empty()) {
		cout << "경로 제대로 설정하거나 이미지 제대로 들고와라." << endl;
		exit(1);
	}

	//Rect roi(Point(135,95),s);

	//Mat roi_img = image(roi);

	//cout << "[roi img]" << endl;

	//for (int i = 0; i < roi_img.rows; i++) {
	//	for (int j = 0; j < roi_img.cols; j++) {
	//		cout.width(5);
	//		cout << (int)roi_img.at<uchar>(i, j);
	//	}
	//	cout << endl;
	//}

	//rectangle(image, roi, Scalar(255), 1);

	imshow("image", image);	//imshow는 무조건 콜백전에 선언!!

	setMouseCallback("image", onMouse, 0);

	waitKey(0);
	return 0;
}
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

/*
	문제를 해결하지 못해 예제 그대로 입니다...
*/

int main() {
	while (1) {
		int no;
		cout << "차량 영상 번호( 0:종료)";
		cin >> no;
		if (no == 0) break;
	
		string fname = format("../test_car/bitwise_", no);
		Mat image = imread(fname, 1);
		if (image.empty()) {
			cout << to_string(no) + "번 영상 파일이 없습니다. " << endl;
			continue;
		}

		Mat gray, sobel, th_img, morph;
		Mat kernel(5, 31, CV_8UC1, Scalar(1));		
		cvtColor(image, gray, COLOR_BGR2GRAY);		

		blur(gray, gray, Size(5, 5));					
		Sobel(gray, gray, CV_8U, 1, 0, 3);			

		threshold(gray, th_img, 120, 255, THRESH_BINARY);	
		morphologyEx(th_img, morph, MORPH_CLOSE, kernel);	

		imshow("image", image);
		imshow("이진 영상", th_img), imshow("열림 연산", morph);
		waitKey();
	}
}
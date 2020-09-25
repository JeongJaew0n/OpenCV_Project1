#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
	Point pt1(10);

	Size2d sz1(20, 30);

	Mat m1 = Mat::ones(2, 3, CV_8UC1);
	Mat_<int> m2(2, 3, CV_8UC1);
	m2 << 1, 2, 3, 4, 5;

	Rect rect1(2, 3, 30, 60);
	Rect2d rect2(pt1, sz1);
	Rect2f rec3(pt1, pt1);

	//초기화 

	Matx<int, 2, 3> mx1(1, 2, 3, 4, 5);

	//5개의 원소를 갖는 float배열, 이 배열을 이용해 vector클래스 생성 및 초기화
	float arrf[] = { 1,2,3,4,5 };
	vector<float> vf(arrf, arrf + sizeof(arrf) / sizeof(float));


	cout << "vector float : ";
	for (int i = 0; i < sizeof(arrf) / sizeof(float); i++) {
		cout << vf[i] << " ,";
	}
	cout << endl;
	


	cout << mx1 << endl;

	cout << m2 << endl;
	cout << pt1 << endl;
	cout << sz1 << endl;

	return 0;
}
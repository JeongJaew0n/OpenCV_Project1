#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main_depth() {
	Mat m1(4, 3, CV_32FC1,2);	//채널수에 따라 값이 바뀜
	cout << "차원 수 " << m1.dims << endl;
	cout << "행 개수 " << m1.rows << endl;
	cout << "열 개수 " << m1.cols << endl;
	cout << "행렬 크기 " << m1.size() << endl << endl;

	cout << "전체 원소 개수 = " << m1.total() << endl;
	cout << "한 원소의 크기 = " << m1.elemSize() << endl;
	cout << "채널당 한 원소의 크기 = " << m1.elemSize1() << endl;

	cout << "타입  = " << m1.type() << endl;
	cout << "타입(채널 수|깊이) = " << ((m1.channels() - 1) << 3) + m1.depth() << endl;
	cout << "깊이 = " << m1.depth() << endl;
	cout << "채널 = " << m1.channels() << endl << endl;

	cout << "step = " << m1.step << endl;
	cout << "step1() = " << m1.step1() << endl;

	Mat m2(4,3, CV_32FC3,Scalar(255,5,1));	//채널 수에 따라 출력했을때 원소 갯수가 바뀌는데 채널에 대해 더 공부해보자.
	cout << m2 << endl;

	return 0;
}
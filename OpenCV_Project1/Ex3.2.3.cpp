#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {
	double a = 32.12345678, b = 2.7;
	short c = 400;
	float d = 10.f, e = 11.f, f = 13.f;

	Mat_<int> m1(2, 4);
	Mat_<uchar> m2(3, 4, 100);
	Mat_<short> m3(4, 5, c);

	m1 << 1, 2, 3, 4, 5, 6;
	Mat m4 = (Mat_<double>(2, 3) << 1, 2, 3, 4, 5, 6);
	Mat m5 = (Mat_<float>(2, 3) << a, b, c, d, e, f);

	cout << m1.dims << endl;
	cout << "[m1] = " << endl << m1 << endl;
	cout << "[m2] = " << endl << m2 << endl << endl;
	cout << "[m3] = " << endl << m3 << endl << endl;
	cout << "[m4] = " << endl << m4 << endl;
	cout << "[m5] = " << endl << m5 << endl;
	return 0;
}

/*이후에 예제 3.2.4 있긴한데 안쓰고 안걸 요약해보자면
Mat, Mat_, Matx 선언가능 Mat을 Mat::ones,zeros,eye로 초기화가능, Mat_는 들어갈 타입 지정가능하여 초기화가 쉬움, Matx는 작은 크기의 행렬 1*1 ~ 6*6까지 만들기 쉬움(초기화가 쉽단뜻)
Matx<Type, i,j> 변수이름(i*j개의 원소) 형태로 선언과 초기화 바로 가능. 혹은 간편 선언방식으로 MatxijType 변수이름(i*j개의원소)>>예를 들어 Mat23d m1(1,2,3,4,5,6) >> 로 선언이 가능하다.
Mat::과 Matx는 초기화되지 않은 원소는 0으로 지정하고 Mat과 Mat_은 초기화되지 않은 원소는 임의의 값이 들어감.


행렬 원소 접근에는 그냥 변수이름으로 전체를 출력하거나 행렬변수이름(i,j)의 >> ex) m1(0,0)>> 형태로 원하는 자리의 원소를 접근및 출력가능*/
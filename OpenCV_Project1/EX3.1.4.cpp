#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
 
int main() {
	Size2d sz(100.5, 60.6);
	Point2f pt1(20.f, 30.f), pt2(100.f, 200.f);

	// Rect_ 객체 기본 선언 방식
	Rect_<int> rect1(10, 10, 30, 50);
	Rect_<float> rect2(pt1, pt2);
	Rect_<double> rect3(Point2d(20.5, 10), sz);

	// 간결선언 방식& 연산 적용
	Rect rect4 = rect1 + (Point)pt1;
	Rect2f rect5 = rect2 + (Size2f)sz;
	Rect2d rect6 = rect1 & (Rect)rect2;

	Rect rect7 = rect1 & rect4;

	//결과출력
	cout << "rect3 = " << rect3.x << ", " << rect3.y << ", ";
	cout << rect3.width << "x" << rect3.height << endl;
	cout << "rect4 시작좌표(좌측상단) : " << rect4.tl() << " rect4 끝좌표(우측하단) : " << rect4.br() << endl;
	cout << "rect5 크기 = " << rect5.size() << endl;
	cout << "rect7의 시작좌표:  " << rect7.tl() << "rect7의 끝 좌표" << rect7.br() << endl;
	cout << "[rect6] = " << rect6 << endl;
	cout << "contains test yes=1 no =0 -> " << rect4.contains(Point(30,40)) << endl;\

	return 0;
}
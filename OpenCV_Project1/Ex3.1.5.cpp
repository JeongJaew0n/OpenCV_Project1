#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {
	Vec<int, 2> v1(5, 12);
	Vec<double, 3> v2(40, 130.7, 125.6);
	Vec2b v3(10, 10);
	Vec6f v4(40.f, 230.25f, 525.6f);
	Vec3i v5(200, 240, 250);

	//객체 연산 및 형변환
	Vec3d v6 = v2 + (Vec3d)v5;
	Vec2b v7 = (Vec2b)v1 + v3;
	Vec6f v8 = v4 * 20.0f;

	Point pt1 = v1 + (Vec2i)v7;
	Point3_<double> pt2 = v2;	//책에는 <int>라고하는데 double로 해줘야 맞음.

	cout << "[v3] = " << v3 << endl;
	cout << "[v7] = " << v7 << endl;
	cout << "[v3 * v7] = " << v3.mul(v7) << endl;
	cout << "v8 = " << v8 << endl;
	cout << "v8[0] = " << v8[0] << endl;
	cout << "v8[1] = " << v8[1] << endl;
	cout << "v8[2] = " << v8[2] << endl;
	cout << "pt2 = " << pt2 << endl;

	return 0;
}
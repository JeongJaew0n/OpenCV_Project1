#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {
	Vec <int, 2> v1(5, 12);
	Vec <double, 3> v2(40, 130.7, 125.6);
	Vec2b v3(10, 10);
	Vec6f v4(40.f, 230.25f, 525.6f);
	Vec3i v5(200, 230, 250);

	Vec3d v6 = v2 + (Vec3d)v5;

	cout << "Hellow world" << endl;

	return 0;
}
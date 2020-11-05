#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
	vector<Point3f> rect_pt1, rect_pt2;
	rect_pt1.push_back(Point3f(200, 50, 1)), rect_pt1.push_back(Point3f(400, 50, 1));
	rect_pt1.push_back(Point3f(400, 250, 1)), rect_pt1.push_back(Point3f(200, 250, 1));
	
	float theta = 45 * CV_PI / 180;
	Matx33f m;
	m << cos(theta), -sin(theta), 0, sin(theta), cos(theta), 0, 0, 0, 1;

	Mat t1 = Mat::eye(3, 3, CV_32F);
	Mat t2 = Mat::eye(3, 3, CV_32F);

	Point3f delta = (rect_pt1[2] - rect_pt1[0]) / 2.0f;
	Point3f center = rect_pt1[0] + delta;

	//for (int i = 0; i < 4; i++) {
	//	rect_pt1[i] -= center;
	//}

	//transform(rect_pt1, rect_pt2, m);

	//for (int i = 0; i < 4; i++) {
	//	rect_pt1[i] += center;
	//	rect_pt2[i] += center;
	//}
	
	gemm(rect_pt1, t1, 1.0, noArray(), 1.0, rect_pt2);
	
	/*t1과 t2를 활용해서 평행이동을 하는 방법을 여러가지 시도해봤는데 도저히 안됩니다...
	* 감을 전혀 못잡겠는데 답을 가르쳐주시면 감사하겠습니다.
	*/

	Mat image(400, 500, CV_8UC3, Scalar(255, 255, 255));

	for (int i = 0; i < 4; i++) {
		Point pt1(rect_pt1[i].x, rect_pt1[i].y);
		Point pt2(rect_pt1[(i + 1) % 4].x, rect_pt1[(i + 1) % 4].y);
		Point pt3(rect_pt2[i].x, rect_pt2[i].y);
		Point pt4(rect_pt2[(i + 1) % 4].x, rect_pt2[(i + 1) % 4].y);

		line(image, pt1, pt2, Scalar(0, 0, 0), 2);
		line(image, pt3, pt4, Scalar(255, 0, 0), 2);

		cout << "rect_pt1[" + to_string(i) + "]=" << rect_pt1[i] << "\t";
		cout << "rect_pt2[" + to_string(i) + "]=" << rect_pt2[i] << endl;
	}
	imshow("image", image);
	waitKey(0);
	return 0;
}
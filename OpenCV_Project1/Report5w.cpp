#include<opencv2/opencv.hpp>
#include<math.h>	//atan()�Լ��� ����ϱ� �����Լ�.
using namespace cv;
using namespace std;

string title = "image";
vector<Point2f> rect_pt1, rect_pt2,rect_pt2s;	//rect_pt2s�� �ι�°�� �Է¹��� ��ǥ�� ���� �ӽ÷� �����ϱ� ���� ����.
Mat image(400, 500, CV_8UC3, Scalar(255, 255, 255));

void onMouse(int event, int x, int y, int flags, void* param) {
	static int check = 0;	//ù��° Ŭ���� �ι��� Ŭ���� �����ϱ� ���� ����.
	if (event == EVENT_LBUTTONDOWN || event == EVENT_RBUTTONDOWN) {
		if (check == 0) {
			rect_pt1.push_back(Point(x, y));
			rect_pt1.push_back(Point(x + 200, y));
			rect_pt1.push_back(Point(x + 200, y + 200)) ;
			rect_pt1.push_back(Point(x, y + 200));

			for (int i = 0; i < 4; i++) {
				line(image, rect_pt1[i], rect_pt1[(i + 1) % 4], Scalar(0, 0, 0), 1);
				cout << "rect_pt1[" + to_string(i) + "]=" << rect_pt1[i] << endl;
			}
			imshow(title, image);
			check++;
		}
		else {
			rect_pt2s.push_back(Point(x, y));	//rect_pt2s�� ������ ����ϱ����� ù��° ��ǥ���� ������ ��. 

			/* ������ 180 / CV_PI �����ָ� ��.
			 * ������ �������� ù��° �Է� ��ǥ�� �ι�° �Է� ��ǥ ������ ������ ��ũź��Ʈ�� ����Ͽ� ����Ͽ���. */
			float theta = atanf(rect_pt2s[0].y / rect_pt2s[0].x) - atanf(rect_pt1[0].y / rect_pt1[0].x); 

			Matx22f m(cos(theta), -sin(theta), sin(theta), cos(theta));
			transform(rect_pt1, rect_pt2, m);

			for (int i = 0; i < 4; i++) {
				line(image, rect_pt2[i], rect_pt2[(i + 1) % 4], Scalar(255, 0, 0), 2);
				cout << "rect_pt2[" + to_string(i) + "]=" << rect_pt2[i] << endl;
			}
			imshow(title, image);
		}
	}
}
	int main() {
	imshow(title, image);
	setMouseCallback(title, onMouse, 0);
	waitKey();
	return 0;
}
#include<opencv2/opencv.hpp>
#include<math.h>	//atan()함수를 사용하기 위한함수.
using namespace cv;
using namespace std;

string title = "image";
vector<Point2f> rect_pt1, rect_pt2,rect_pt2s;	//rect_pt2s는 두번째로 입력받은 좌표의 값을 임시로 저장하기 위한 변수.
Mat image(400, 500, CV_8UC3, Scalar(255, 255, 255));

void onMouse(int event, int x, int y, int flags, void* param) {
	static int check = 0;	//첫번째 클릭과 두번재 클릭을 구별하기 위한 변수.
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
			rect_pt2s.push_back(Point(x, y));	//rect_pt2s는 각도를 계산하기위해 첫번째 좌표값만 있으면 됨. 

			/* 각도는 180 / CV_PI 곱해주면 됨.
			 * 원점을 기준으로 첫번째 입력 좌표와 두번째 입력 좌표 사이의 각도를 아크탄젠트를 사용하여 계산하였음. */
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
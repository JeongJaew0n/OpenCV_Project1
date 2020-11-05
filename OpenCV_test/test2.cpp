#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
   vector<Point3f> rect_pt1, rect_pt2;
   rect_pt1.push_back(Point3f(200, 50, 1));
   rect_pt1.push_back(Point3f(400, 50, 1));
   rect_pt1.push_back(Point3f(400, 250, 1));
   rect_pt1.push_back(Point3f(200, 250, 1));

   float theta = 45 * CV_PI / 180;

   // 오일러 회전이라 실상은 3차원에 2차원 행렬을 묻힌거나 마찬가지
   Matx33f m;
   m << cos(theta), -sin(theta), 0,
      sin(theta), cos(theta), 0,
      0, 0, 1;

   // 평행이동
   Mat t1 = Mat::eye(3, 3, CV_32F);

   // 역 평행이동
   Mat t2 = Mat::eye(3, 3, CV_32F);

   // 중점
   Point3f delta = (rect_pt1[2] - rect_pt1[0]) / 2.0f;
   
   // 센터
   Point3f center = rect_pt1[0] + delta;

   t1.at<float>(0, 2) = -center.x;
   t1.at<float>(1, 2) = -center.y;
   t1.at<float>(2, 2) = -center.z;

   t2.at<float>(0, 2) = -center.x;
   t2.at<float>(1, 2) = -center.y;
   t2.at<float>(2, 2) = -center.z;

   transform(rect_pt1, rect_pt2, t1);
   transform(rect_pt2, rect_pt2, m);
   transform(rect_pt2, rect_pt2, t2);

   Mat image(400, 500, CV_8UC3, Scalar(255, 255, 255));
   for (int i = 0; i < 4; i++)
   {
      Point pt1(rect_pt1[i].x, rect_pt1[i].y);
      Point pt2(rect_pt1[(i + 1) % 4].x, rect_pt1[(i + 1) % 4].y);

      Point pt3(rect_pt2[i].x, rect_pt2[i].y);
      Point pt4(rect_pt2[(i + 1) % 4].x, rect_pt2[(i + 1) % 4].y);

      line(image, pt1, pt2, Scalar(0, 0, 0), 2, LINE_AA);
      line(image, pt3, pt4, Scalar(255, 0, 0), 2, LINE_AA);

      cout << "rect_pt1[" + to_string(i) + "]=" << rect_pt1[i] << "\t";
      cout << "rect_pt2[" + to_string(i) + "]=" << rect_pt2[i] << endl;
   }

   imshow("image", image);
   waitKey();

   return 0;
}
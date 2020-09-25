#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void print_mainInfo(string name, Mat m) {	//����� Ÿ�Կ� ���� ������ִ� �Լ�
	string mat_type;
	if (m.depth() == CV_8U) mat_type = "CV_8U";			//dpeth()�� �ش� ����� Ÿ��(8U�� 0���ͽ����� 64F���� 1�� �ö�.) type()�� ä�������� depth�� �Ѵ� ������.
	else if (m.depth() == CV_8S) mat_type = "CV_8S";
	else if (m.depth() == CV_16U) mat_type = "CV_16U";
	else if (m.depth() == CV_16S) mat_type = "CV_16S";
	else if (m.depth() == CV_32S) mat_type = "CV_32S";
	else if (m.depth() == CV_32F) mat_type = "CV_32F";
	else if (m.depth() == CV_64F) mat_type = "CV_64F";

	cout << name << "ũ��" << m.size() << ", ";
	cout << " �ڷ���" << mat_type << "C" << m.channels() << endl;
	cout << m << endl << endl;

}

int main_cl() {
	Mat m1, m2, m3, m4(2, 6, CV_8UC1);
	Mat add1(2, 3, CV_8UC1, Scalar(100));
	Mat add2 = Mat::eye(4, 3, CV_8UC1);
	m1.push_back(100), m1.push_back(200), m2.push_back(100.5), m2.push_back(200.6);	//push_back�Լ� ���� �Ѱ��� ���ڰ��� Ÿ������ �ش� ����� Ÿ���� �����ȴ�.
	//���⼭ m1�� 100�̹Ƿ� int(32S), m2�� 100.5�̹Ƿ� float(32F)�̴�.

	m3.push_back(add1);
	m3.push_back(add2);

	m4.push_back(add1.reshape(1, 1));
	m4.push_back(add2.reshape(1, 2));

	print_mainInfo("m1", m1), print_mainInfo("m2", m2);
	print_mainInfo("m3", m3), print_mainInfo("m4", m4);

	m1.pop_back(1);
	m2.pop_back(2);
	m3.pop_back(3);
	cout << "m1" << endl << m1 << endl;
	cout << "m2" << endl << m2 << endl;
	cout << "m3" << endl << m3 << endl;
	return 0;

}
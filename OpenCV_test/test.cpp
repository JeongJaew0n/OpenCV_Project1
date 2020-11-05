#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {
	Mat ch0(3, 4, CV_8U, Scalar(10));
	Mat ch1(3, 4, CV_8U, Scalar(20));
	Mat ch2(3, 4, CV_8U, Scalar(30));
	Mat ch_012;

	vector<Mat> vec_012;
	vec_012.push_back(ch0);
	vec_012.push_back(ch1);
	vec_012.push_back(ch2);
	merge(vec_012, ch_012);

	Mat ch_13(ch_012.size(), CV_8UC2);
	Mat ch_2(ch_012.size(), CV_8UC1);
	Mat ch_t(ch_012.size(), CV_8UC1);
	Mat out[] = { ch_13,ch_2 ,ch_t};
	int from_to[] = { 4,0,1,1,2,3 };
	mixChannels(&ch_012, 3, out, 3, from_to, 3);
	//���� ������ �ٷδ� �ڿ��� out�� �迭�̹Ƿ� �ּ� ����ü�� ����Ű�Ƿ� �־��� ������ 3���� �������ָ� �����ּҿ��� ���� 3�������� �ּҸ� �ҷ����ڴٴ°Ŵ�.
	//�׷��� �������δ� ���⼭ 3��� 2�� �ְ� ä���� �÷��� ���� �־��൵ ������ �ȵɰŴ�.ch_t�� ���� �ְ� ����غ��ٴ� �´�. ���� �ȵȴ� �׷��� �̹��� �ٽ� 3���ιٲٰڴ�
	//�ȴ�!!! ������ �´�.
	// out������ �Ű������δ� out�� �ּҸ� �Ѱܹް� �� ���� ���° �ּұ��� ���� �о� ���ϱ��̴�. �׷� ù���絵 ���������� ch_012�� �ּҸ� �о�´����� �� ����1���� �����ϰڴٴ°Ŵ�.



	
	cout << "[ch_123] = " << endl << ch_012 << endl << endl;
	cout << "[ch_13] = " << endl << ch_13 << endl;
	cout << "[ch_2] = " << endl << ch_2 << endl;
	cout << "out test = " << endl << out[2] << endl;
	return 0;
}
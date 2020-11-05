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
	//내가 이해한 바로는 뒤에서 out은 배열이므로 주소 그자체를 가르키므로 넣어준 다음에 3개를 지정해주면 시작주소에서 부터 3개까지의 주소를 불러오겠다는거다.
	//그래서 예상으로는 여기서 3대신 2를 넣고 채널을 늘려서 값을 넣어줘도 변경이 안될거다.ch_t에 값을 넣고 출력해보겟다 맞다. 역시 안된다 그러면 이번엔 다시 3으로바꾸겠다
	//된다!!! 내말이 맞다.
	// out다음의 매개변수로는 out의 주소를 넘겨받고 그 다음 몇번째 주소까지 값을 읽어 들일까이다. 그럼 첫번재도 마찬가지로 ch_012의 주소를 읽어온다음에 그 다음1까지 참조하겠다는거다.



	
	cout << "[ch_123] = " << endl << ch_012 << endl << endl;
	cout << "[ch_13] = " << endl << ch_13 << endl;
	cout << "[ch_2] = " << endl << ch_2 << endl;
	cout << "out test = " << endl << out[2] << endl;
	return 0;
}
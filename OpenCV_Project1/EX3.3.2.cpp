#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//벡터에 대한 원소 출력은 지원하지 않음. MAT으로 형변환 후 출력할 필요가 있음.

void print_vectorInfo(string v_name, vector<int> v) {
	cout << "[" << v_name << "] = ";
	if (v.empty()) cout << "벡터가 비어있습니다." << endl;
	else cout << ((Mat)v).reshape(1,1) << endl;	//벡터를 Mat으로 형변환해서 출력하면 N행 1열(Point라면 원소 갯수)의 형태로 출력이됨. 

	cout << ".size() = " << v.size() << endl;
}

int main_su() {
	int arr[] = { 10, 20, 30, 40, 50 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

	print_vectorInfo("v1", v1);

	v1.insert(v1.begin() + 2, 100);
	print_vectorInfo("v1 insert", v1);
	cout << ".capacity() = " << v1.capacity() << endl << endl;

	v1.erase(v1.begin() + 3);
	print_vectorInfo("v1 erase", v1);
	cout << ".capacity() = " << v1.capacity() << endl;

	v1.insert(v1.begin() + 2, 44);
	v1.insert(v1.begin() + 2, 99);
	v1.insert(v1.begin() + 2, 123);
	print_vectorInfo("v1 insert", v1);
	cout << ".capacity() = " << v1.capacity() << endl << endl;	
	//원소가 늘어나면 capacity를 알아서 늘려주는 듯 > 메모리 재활당이 발생하는 것임. 이렇게 되면 비효율적이다. reserve()를 이용해 해결. 다음예제에서 보자.

	v1.clear();
	print_vectorInfo("v1, clear()", v1);

	return 0;
}
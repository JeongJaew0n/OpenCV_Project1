#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//���Ϳ� ���� ���� ����� �������� ����. MAT���� ����ȯ �� ����� �ʿ䰡 ����.

void print_vectorInfo(string v_name, vector<int> v) {
	cout << "[" << v_name << "] = ";
	if (v.empty()) cout << "���Ͱ� ����ֽ��ϴ�." << endl;
	else cout << ((Mat)v).reshape(1,1) << endl;	//���͸� Mat���� ����ȯ�ؼ� ����ϸ� N�� 1��(Point��� ���� ����)�� ���·� ����̵�. 

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
	//���Ұ� �þ�� capacity�� �˾Ƽ� �÷��ִ� �� > �޸� ��Ȱ���� �߻��ϴ� ����. �̷��� �Ǹ� ��ȿ�����̴�. reserve()�� �̿��� �ذ�. ������������ ����.

	v1.clear();
	print_vectorInfo("v1, clear()", v1);

	return 0;
}
#include<iostream>
#include<string>
using namespace std;

class Trace{
	static string DEBUG[100];
	static string Tag[100];
	static int i;
public:
	static void put(string tag,string data){
		DEBUG[i] = data;
		Tag[i] = tag;
		i++;
	}
	static void print(string tag="���")
	{
		if (tag != "���")
		{
			cout << "---------" << tag << "�±��� Trace ������ ����մϴ�" << "---------" << endl;
			for (int j = 0; j < i; j++)
			{
				if (Tag[j] == tag)
					cout << Tag[j] << ':' << DEBUG[j]<<endl;
					
			}
		}
		else{
			cout << "---------" << tag << "Trace ������ ����մϴ�" << "---------" << endl;
			for (int j = 0; j < i; j++)
			{
				cout << Tag[j] << ':' << DEBUG[j] << endl;
			}

		}
	}
};
int Trace::i = 0;
string Trace::DEBUG[100];
string Trace::Tag[100];
void f(){
	int a, b, c;
	cout << "�� ���� ������ �Է��ϼ���";
	cin >> a >> b;
	Trace::put("f()", "������ �Է� �޾���");
	c = a + b;
	Trace::put("f()", "�� ���");
	cout << "����" << c << endl;
}
int main()
{
	Trace::put("main()","���α׷� �����մϴ�");
	f();
	Trace::put("main()", "����");
	Trace::print("f()");
	Trace::print();

}
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
	static void print(string tag="모든")
	{
		if (tag != "모든")
		{
			cout << "---------" << tag << "태그의 Trace 정보를 출력합니다" << "---------" << endl;
			for (int j = 0; j < i; j++)
			{
				if (Tag[j] == tag)
					cout << Tag[j] << ':' << DEBUG[j]<<endl;
					
			}
		}
		else{
			cout << "---------" << tag << "Trace 정보를 출력합니다" << "---------" << endl;
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
	cout << "두 개의 정수를 입력하세요";
	cin >> a >> b;
	Trace::put("f()", "정수를 입력 받았음");
	c = a + b;
	Trace::put("f()", "합 계산");
	cout << "합은" << c << endl;
}
int main()
{
	Trace::put("main()","프로그램 시작합니다");
	f();
	Trace::put("main()", "종료");
	Trace::print("f()");
	Trace::print();

}
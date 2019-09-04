
/* version 1:

	�ǣ�

		f[i].before Ϊǰ i �������ڵ� i ̨�������ڵ� i+1 ̨�������˵����������ֵ�͵����ֵ

		f[i].after Ϊǰ i �������ڵ� i ̨�������ڵ� i+1 ̨�������˵����������ֵ�͵����ֵ

	��Ȼ������

		f[1].before=a[1] , f[1].after=b[1]

	���������Ѿ�֪���� f[i-1].before �� f[i-1].after �����ڵ� i ��λ��û�˺����˵������ǰ i-1 ����������ֵ�����

	���� f[i].before ���ԣ� ���� i+1 �������ϻ�û����ʱ����ô���ǵ� i �������͵� i-1 ���������˵�ʱ��˳��

		����� i ���������˺��ڵ� i-1 ���������ˣ���ô��Ȼ���� i ������������ֵΪ b[i] ����Ϊ����������ұ�û��

		��ǰ i-1 �����������ڵ� i ���������ڵ� i-1 ���������ˣ���ʱ f[i].before = f[i-1].before+b[i]

		����� i �������������ڵ� i-1 ���������ˣ���ô f[i].before = f[i-1].after+a[i]

  	ͬ����� f[i].after �� f[i].after = max( f[i-1].before+c[i] , f[i-1].after+b[i] )�����ǵ� i ̨�͵� i-1 ̨�������˵�˳������

	�������� i>=2 ��������

		f[i].before = max( f[i-1].before+b[i] , f[i-1].after+a[i] )---(1)

		f[i].after = max( f[i-1].before+c[i] , f[i-1].after+b[i] )---(2)

	������ȥ�����ڵ� n ̨�����ұ�ʼ��Ϊ�գ��������ˣ�������Ϊ f[n].before

*/

#include <iostream>
#define MAX 10000
using namespace std;

struct Condition
{
	int before, after;
};


int main()

{

	int n;
	int a[MAX + 1], //���Ҷ����� both
		b[MAX + 1], //��������� either
		c[MAX + 1]; //���Ҷ����� neither
	struct Condition F[MAX + 1];
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)
		cin >> b[i];

	for (int i = 1; i <= n; i++)
		cin >> c[i];

	F[1].before = a[1];
	F[1].after = b[1];

	for (int i = 2; i <= n; i++)
	{

		F[i].before = max(F[i - 1].before + b[i], F[i - 1].after + a[i]);

		F[i].after = max(F[i - 1].before + c[i], F[i - 1].after + b[i]);
	}

	cout << F[n].before;
}

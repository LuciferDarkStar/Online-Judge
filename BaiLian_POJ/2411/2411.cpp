//Mondriaan's Dream
#include <algorithm>
#include <cstring>
#include <iostream>
#define AND &&
#define OR ||
#define NOT !
//�淶, ����λ����״̬����ͳһ����ǰ׺ bit_
using namespace std;

int height, width;
long long F[1005][2050];//�����Χ�Ǳ����
//F[i][bit_j] ��ʾ���� i ��, �� i-1 �ж�����Ӱ���� bit_j ��ʱ��ķ�������i <= width , 0 <= bit_j < 2^height

void Construct(int i, int j, int bit_state, int bit_next) //DFS
//�� i ��, ö�ٵ��˵� j ��(0 -> height - 1), ��ǰ״̬�� bit_state, ����һ�е�Ӱ���� bit_next
{
    if (j == height) //����ö�ٽ���
    {
        F[i + 1][bit_next] += F[i][bit_state];
        return;
    }
    if (((1 << j) & bit_state) > 0)               //��� bit_state �ĵ� j+1 λ�� 1, �����λ���Ѿ�����һ����ռ��
        Construct(i, j + 1, bit_state, bit_next); //ֱ������

    if (((1 << j) & bit_state) == 0)                         //��� bit_state �ĵ� j+1 λ�� 0, �����λ���ǿյ�
        Construct(i, j + 1, bit_state, bit_next | (1 << j)); //���Է�һ�� 1*2 ��, ��Ӧ�ı� state ��Ϊ�����������Ӱ��

    if ((j + 1 < height) AND(((1 << j) & bit_state) == 0) AND(((1 << (j + 1)) & bit_state) == 0)) //������λ���Լ���һ��λ�ö��ǿյ�
        Construct(i, j + 2, bit_state, bit_next);                                                 //���Է�һ��2*1��
    return;
}

int main()
{
    while (cin >> height >> width)
    {
        memset(F, 0, sizeof(F));
        if ((height == 0) AND(width == 0))
            break;
        F[0][0] = 1;
        for (int i = 0; i < width; i++)
        {
            for (int bit_state = 0; bit_state < (1 << height); bit_state++)
                if (F[i][bit_state])
                {
                    Construct(i, 0, bit_state, 0);
                }
        }
        cout << F[width][0] << endl;
    }
}

//ʵ���߾�����
#include <stdio.h>
#include <string.h>
#define AND &&
#define OR ||
#define NOT !
#define MOD %
#define DIGIT 200 //���ó�������󳤶�

char *HAA_Times(char *_A, char *_B)
{
    int i, j;
    char A[DIGIT + 10], B[DIGIT + 10];
    char a[DIGIT + 10], b[DIGIT + 10];
    char c[2 * DIGIT + 30];
    char static C[2 * DIGIT + 30];
    int length_A = strlen(_A);
    int length_B = strlen(_B);
    int length_decimal_A = 0;
    int length_decimal_B = 0;

    strcpy(A, _A);
    strcpy(B, _B);

    if (strchr(A, '.') != NULL)
    {
        length_decimal_A = strlen(strchr(A, '.')) - 1;                   //С��λ����
        for (i = length_A - length_decimal_A - 1; i < length_A - 1; i++) //ȥ��С����
            A[i] = A[i + 1];
        A[i] = '\0';
        length_A -= 1;
    }
    if (strchr(B, '.') != NULL)
    {
        length_decimal_B = strlen(strchr(B, '.')) - 1;                   //С��λ����
        for (i = length_B - length_decimal_B - 1; i < length_B - 1; i++) //ȥ��С����
            B[i] = B[i + 1];
        B[i] = '\0';
        length_B -= 1;
    }

    memset(C, 0, (2 * DIGIT + 30) * sizeof(char));
    memset(c, 0, (2 * DIGIT + 30) * sizeof(char));

    for (i = length_A - 1, j = 0; i >= 0; i--) //���ã����ַ�ת��
        a[j++] = A[i] - '0';
    for (i = length_B - 1, j = 0; i >= 0; i--)
        b[j++] = B[i] - '0';

    for (i = 0; i < length_B; i++) //ѭ�����
    {
        for (j = 0; j < length_A; j++)
        {
            c[i + j] += b[i] * a[j];
            if (c[i + j] >= 10) //��ʱ��λ
            {
                c[i + j + 1] += c[i + j] / 10;
                c[i + j] %= 10;
            }
        }
    }

    for (i = 0; i < length_A + length_B + 2; i++) //��λ
        if (c[i] >= 10)
        {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }

    for (i = length_A + length_B + 2; (c[i] == 0) AND(i > length_decimal_A + length_decimal_B); i--) //���˵���λ������0
        ;

    if (i >= 0)
    {
        for (j = 0; i >= 0; i--, j++)
            C[j] = c[i] + '0';
        for (i = j; i > j - (length_decimal_A + length_decimal_B); i--)
            C[i] = C[i - 1];
        C[i] = '.';
        for (; ((C[j] == '0') AND(j > i)) OR(i == j); j--) //���˵�λС��0
            C[j] = '\0';
    }
    else
    {
        C[0] = '0';
        C[1] = '\0';
    }

    return (C);
}

int main()
{
    int n;
    int i;
    char S[DIGIT + 10];
    char Power[2 * DIGIT + 30] = "1";
    while (scanf("%s%d", S, &n) ==2)
    {
        strcpy(Power, "1");
        for (i = 0; i < n; i++)
        {
            strcpy(Power, HAA_Times(Power, S));
        }
        if (Power[0] == '0') //Ӧ��ĿҪ��.ǰ����0
        {
            for (i = 0; i < strlen(Power) - 1; i++)
                Power[i] = Power[i + 1];
            Power[i] = '\0';
        }
        puts(Power);
    }
    return (0);
}
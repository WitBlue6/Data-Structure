#include<stdio.h>
#include<math.h>
#include <stdlib.h>
double sqr(double x);
double T[11] = {0, 8.99, 2.48, 1.59, 1.24, 1.05, 0.93, 0.84, 0.77, 0.72}; 
int main()
{
	int n;
	double a[101], sum, ave, bessel, sum1, disconfirmA, disconfirmB, result;
	printf("���������ݸ���\n");
	scanf("%d", &n);
	printf("������%d������\n", n);  
	int i;
	for(i = 1;i <= n; i++) scanf("%lf", &a[i]);
	
	// ��ƽ���� 
	for(i = 1;i <= n; i++)
	{
		sum = sum + a[i];
	}
	ave =  sum / n;
	
	//���������ݼ�ȥƽ������ƽ���� 
	for(i = 1;i <= n; i++)
	{
		sum1 = sum1 + sqr(a[i] - ave); 
	}
	bessel = sqrt(sum1 / (n - 1));
	disconfirmA = bessel / sqrt(n);
	printf("ƽ��ֵΪ��%lf", ave);
	printf("��������ʽ��ֵ��%lf\n", bessel);
	printf("A�಻ȷ����Ϊ��%lf\n", disconfirmA);
	printf("TIPS:��Ҫ���ǵ�λ\n");
	system("pause");
}	

double sqr(double x)
{
	return x*x; 
}


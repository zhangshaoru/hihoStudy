#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int best[501][1025];
int rubbish[1000];
int tmpArr[1025];

int main(){
	//��������
	int binaryOneSum(int a);
	int test(int n,int m,int q);
	int debug(int a);


	int n,m,q;//��λ,����,�˿�����
	scanf("%d %d %d",&n,&m,&q);
	int i;
	for(i=0;i < n;i++)
	{
		scanf("%d",&rubbish[i]);
	}

	//��¼���Ϲ�������
	for(i = 0;i<1024;i++)
	{
		if(binaryOneSum(i) <= q)
		{
			tmpArr[i] = 1;
		}else{
			tmpArr[i] = 0;
		}
	}
	test(n,m,q);
	int max = pow(2,m);
	int tmp =0 ;
	for(i = 0;i<max;i++)
	{
		if(tmpArr[i] == 1)
		{
			tmp = best[n][i]>tmp?best[n][i]:tmp;
		}
	}

	printf("%d\n",tmp);
	return 0;
}

//��������Ƶķ���
int binaryOneSum(int a)
{
	int sum =0;
	int b = 0;
	while(a>0)
	{
		sum = sum+a%2;
		a = a/2;
	}
	return sum;
}
//������
int test(int n,int m,int q)
{
	int debug(int a);
	int debugtxt();
	int i,j,z;
	double max,max2,max3,max4;
	max  = pow(2,m); //jѭ���Ĵ���
	max2 = max/2;
	//��ʼ�������һ��
	for(i = 0;i<=max;i++)
	{
		if(i >= max2)
		{
			best[1][i] = rubbish[0];
			//debug(best[1][i]);
			continue;
		}
		best[1][i] = 0;
	}
	for(i=2;i<=n;i++)
	{
		for(j = 0;j<max;j++)
		{
			if(tmpArr[j] == 1)
			{
				if(j >= max2)
				{
					z=(j-max2)*2;
					if(tmpArr[z+1] == 1){
						z = z+1;
						best[i][j] = best[i-1][z]>best[i-1][z-1]?best[i-1][z]+rubbish[i-1]:best[i-1][z-1]+rubbish[i-1];
					}else{
						best[i][j] = best[i-1][z] + rubbish[i-1];
					}
				}else{
					z = j*2;
					if(tmpArr[z+1] == 1)
					{
						z = z+1;
						best[i][j] = best[i-1][z]>best[i-1][z-1]?best[i-1][z]:best[i-1][z-1];
					}else{
						best[i][j] = best[i-1][z];
					}
				}
			}else{
				best[i][j] = 0;
			}
		}
	}
	return 0;
}

int debug(int a)
{
	printf("****%d\n",a);
	return 0;
}
int debugtxt()
{
	printf("---------------------\n");
	return 0;
}

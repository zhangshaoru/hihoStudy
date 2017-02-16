#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[1001];
int arr[4];//atcg

int main()
{
	int selout(int k);

	int n,k,i;
	int tmp[10];
	scanf("%d",&n);
	for(i = 0;i<n;i++)
	{
		scanf("%s",str);
		scanf("%d",&k);
		tmp[i] = selout(k);
	}
	for(i = 0;i<n;i++)
		printf("%d\n",tmp[i]);


	return 0;
}

/**
 *比较方法atcg
 */
int selout(int k)
{
	int len = 0;//字符串长度
	len = strlen(str);
	int i,j;
	//重置数组
	int max = 0;
	int tmp = 0;
	int sum;
	int _len;
	_len = len-k<k?len-k:k;

	for(i = 0;i<_len;i++)
	{

		for(j = 0;j<4;j++)
		{
			arr[j] = 0;
		}

		tmp = 0;
		j = i;
		sum = 0;
		while(true)
		{
			if(str[j] == 'A')
				arr[0]++;
			else if(str[j] == 'T')
				arr[1]++;
			else if(str[j] == 'C')
				arr[2]++;
			else
				arr[3]++;

			sum++;
			j = j+(len-k);


			if(j >= len)
				break;
		}

		//计算最大值并累加
		for(j = 0;j<4;j++)
		{
			tmp = tmp>arr[j]?tmp:arr[j];
		}
		max = sum-tmp+max;
	}

	return max;
}
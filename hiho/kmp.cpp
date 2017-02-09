#include <stdio.h>
#include <string.h>

char str[1000001];
char pattern[10001];
int nextArr[10001];

int main()
{
	int next(); 
	int kmp();

	int n ,i;
	int tmp[20];
	for(i=0;i<20;i++)
	{
		tmp[i] = -1;
	}
	scanf("%d",&n);

	for(i = 0;i<n;i++)
	{
		scanf("%s",&pattern);
		scanf("%s",&str);
		next();
		tmp[i] = kmp();
	}

	for(i = 0;i<n;i++)
		printf("%d\n",tmp[i]);

	
	return 0;
}

/**
 获取偏移数组
 **/
int next()
{
	int len;
	int _nextArr[10001];
	len = strlen(pattern);
	pattern[len] = '#';
	len = len+1;
	int i;
	for(i = 0;i < len;i++)
	{
		if(i == 0)
		{
			_nextArr[i] = 0;
		}
		else
		{
			if(pattern[_nextArr[i-1]] == pattern[i])
			{
				_nextArr[i] = _nextArr[i-1]+1;
			}
			else
			{
				_nextArr[i] = 0;
			}
		}
	}

	for(i = 0;i < len;i++)
	{
		if(i== 0)
		{
			nextArr[i] = -1;
		}
		else
		{
			nextArr[i] = _nextArr[i-1];
		}
	}
	return 0;
}

int kmp()
{
	int slen,plen;
	slen = strlen(str);//源字符串长度
	str[slen] = '#';
	slen = slen + 1;
	plen = strlen(pattern);//模式串长度
	int i = 0,j = 0 ,tmp = 0;
	while(j<plen && i<slen)
	{
		//比对到最后一个字符串
		//printf("****j = %d\n",j);

		if(pattern[j] == '#')
		{
			tmp = tmp + 1;
		}
		//printf("****tmp = %d\n",tmp);
		//printf("*************\n");

		//字符串尾终止
		if(str[i] == '#')
		{
			break;
		}

		if(j==-1 || str[i] == pattern[j])
		{
			i++;
			j++;
			
		}
		else
		{
			j = nextArr[j];
		}
	}

	return tmp;
}
#include <stdio.h>
#include <string.h>

int main()
{
	int debug(char *str);
	int test(char *dlr,char *ldr,char *lrd,int key);
	char dlr[26];//先序遍历
	char ldr[26];//中序遍历
	char lrd[26];
	int i;
	for(i = 0;i<26;i++)
	{
		lrd[i] = '\0';
	}
	scanf("%s",dlr);
	scanf("%s",ldr);
	test(dlr,ldr,lrd,0);
	int len = strlen(lrd)>26?26:strlen(lrd);
	printf("reason=%s\n",lrd);
	for(i = len-1;i>=0;i--)
	{
		printf("%c",lrd[i]);
	}
	printf("\n");
	return 0;
}

/**
 *处理函数
 */
int test(char *dlr,char *ldr,char *lrd,int key)
{
	int debug(char *str);
	char tmp;
	char rdlr[26],ldlr[26];
	char rldr[26],lldr[26];
	lrd[key] = dlr[0];
	tmp = dlr[0];
	int i;
	bool flag = false; //是否为根节点的标识
	bool leaveFlag = false;
	int left = 0;
	int right = 0;
	for(i = 0;i<26;i++)
	{
		rdlr[i] = '\0';
		rldr[i] = '\0';
		ldlr[i] = '\0';
		lldr[i] = '\0';

	}
	//取出左右子树的两种遍历方式

    if(strlen(dlr) > 1)
	{
		for(i = 1;i<strlen(dlr);i++)
		{
			if(flag == false && ldr[0] == tmp){
				flag = true;
			}
			//左右子树
			if(flag)
			{
				rdlr[right] = dlr[i];
				rldr[right] = ldr[i];
				right++;
				left++;
			}
			else
			{
				ldlr[left] = dlr[i];
				lldr[left] = ldr[i-1];
				left++;
			}
			if(ldr[i] == tmp)
			{
				flag = true;
			}
		}
	}

	printf("lrd = %s\n",lrd);
	printf("dlr=%s\n",dlr);
	printf("ldr=%s\n",ldr);
	printf("rdlr=%s\n",rdlr);
	printf("rldr=%s\n",rldr);
	printf("ldlr=%s\n",ldlr);
	printf("lldr=%s\n",lldr);
	printf("**************\n");

	if(strlen(dlr) > 1)
	{
		//如果已经为空则不进行迭代
		if(strlen(rdlr)>0){
			key = key+1;
			key = test(rdlr,rldr,lrd,key);
		}
		if(strlen(ldlr) > 0)
		{
			key = key+1;
			key=test(ldlr,lldr,lrd,key);
		}
	}
	return key;
}

/**
 *调试函数
 */
int debug(char *str)
{
	printf("**%s**\n",str);
	return 0;
}
//dp+二分
/*
假设要寻找最长上升子序列的序列是a[n]，然后寻找到的递增子序列放入到数组b中。

（1）当遍历到数组a的第一个元素的时候，就将这个元素放入到b数组中，以后遍历到的元素都和已经放入到b数组中的元素进行比较；

（2）如果比b数组中的每个元素都大，则将该元素插入到b数组的最后一个元素，并且b数组的长度要加1；

（3）如果比b数组中最后一个元素小，就要运用二分法进行查找，查找出第一个比该元素大的最小的元素，然后将其替换。

在这个过程中，只重复执行这两步就可以了，最后b数组的长度就是最长的上升子序列长度。例如：如该数列为：

5 9 4 1 3 7 6 7

那么：

5 //加入
5 9 //加入
4 9 //用4代替了5
1 9 //用1代替4
1 3 //用3代替9
1 3 7 //加入
1 3 6 //用6代替7
1 3 6 7 //加入

最后b中元素的个数就是最长递增子序列的大小，即4。

要注意的是最后数组里的元素并不就一定是所求的序列，

例如如果输入 2 5 1

那么最后得到的数组应该是 1 5

而实际上要求的序列是 2 5


*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 10050 
using namespace std;
	int p[N];
	int n;
int lis()
{
	int B[N];
	int len=0;
	memset(B,0,sizeof(B));
	B[0]=p[0];
	for(int i=1;i<n;i++)
	{
		if(p[i]>B[len]){
			B[++len]=p[i];
		} 
		else 
		{
			int pos=lower_bound(B,B+len,p[i])-B;
			B[pos]=p[i];
			
		}
	}
	return len+1; 
}
int main()
{
	#ifdef dyr
		freopen("input.txt","r",stdin);
	#endif
	
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&p[i]);
		}
		printf("%d\n",lis());	
	}
	 
}

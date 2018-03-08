#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 10050
using namespace std;
char p[N];//mode string 
char t[N];//target string
int next[N];
int n;
int m;
void predoing()
{
	int i=-1,j=0;
	next[0]=-1;//初始为-1代表无法再向右 
	while(j<m)
	{
		if(i==-1||t[i]==t[j])
		{
			next[++j]=++i;
		}
		else 
			i=next[i];
	}
}
bool KMP(int& start,int &end)
{
	int i=0,j=0;
	while(i<n-1&&j<m-1)
	{
		if(p[i]==t[j]||j==-1)
		{
			i++;j++;
		}
		else 
		{
			j=next[j];
		}
	}
	if(j==m-1)
		{
			start=i-j+1;end=start+m-1;
			return true;
		}
	else return false;
}
int main()
{
	#ifdef dyr	
		freopen("input.txt","r",stdin);
	#endif 
	int start, end;
	scanf("%s%s",p,t);
	n=strlen(p);
	m=strlen(t);
	printf("%d %d\n",n,m);
	predoing();
	if(KMP(start,end))
	{
		printf("%d %d\n",start,end);
	}
	else 
		printf("No\n");
	
}


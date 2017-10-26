#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 10050 
using namespace std;
struct oneline
{
	string vs[10];
	int capacity;
	int high;
	oneline()
	{
		high=0;
		capacity=20;
	}
}q[N];
void comsort(oneline p[],int cnt)
{
	
	for(int i=0;i<cnt;i++)
	{	
		int cap=20;
		for(int j=0;j<p[i].high;j++)
		{
		
			if(j==p[i].high-1)
			{
				for(int m=0;m<cap-p[i].vs[j].length();m++)
					p[i].vs[j+1]+=" ";
					if(p[i].high!=1)
						swap(p[i].vs[j+1],p[i].vs[j]);
					p[i].high++;
					break;
			}
			else 
			{
				p[i].vs[j]+=" ";
				cap-=p[i].vs[j].length();
			}		
		}
		
	}
}
bool judge(const string &other,const int cnt)
{
	int n=q[cnt].capacity;
	int m=other.length();
	if(n>=m)
	{
		return true;
	}
	else {
		return false;
		
	}
	
}
int main()
{

	#ifdef dyr
		//freopen("input.txt","r",stdin);
	#endif 
	char p[N];
	gets(p);
	p[strlen(p)+1]='\0';
	p[strlen(p)]=32;

	string word[N];
	int sum=0;
	for(int i=0;p[i]!='\0';i++)
	{
		
		if(p[i]==32||p[i]=='\n')
		{
			sum++;
		}
		else word[sum]+=p[i];
	}
	int cnt=0;
	for(int i=0;i<sum;i++)
	{
		if(judge(word[i],cnt)){
			q[cnt].vs[q[cnt].high++]=word[i];
			q[cnt].capacity-=(word[i].length()+1);
		}	
		else
		{
			cnt++;
			q[cnt].vs[q[cnt].high++]=word[i];
			q[cnt].capacity-=(word[i].length()+1);
		} 
	}
	comsort(q,cnt);
	for(int i=0;i<=cnt;i++)
	{
		for(int j=0;j<q[i].high;j++)
			cout<<q[i].vs[j];
	
			cout<<endl;
	}
}



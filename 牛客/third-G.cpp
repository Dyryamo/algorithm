#include<iostream>
#include<cstdio>
#define LL long long
int main(){
	LL n;
	while(~scanf("%lld",&n)){

	LL a,b,c,d;
	a=n/2;b=n/5;c=n/11;d=n/13;
	LL e,f,g,h,i,j;
	e=n/10;f=n/22;g=n/26;h=n/55;i=n/65;j=n/143;
	LL k,l,m,o;
	k=n/110;l=n/130;m=n/286;o=n/715;
	LL p;
	p=n/1430;
	n-=((a+b+c+d)-(e+f+g+h+i+j)+(k+l+m+o)-p);
	printf("%lld\n",n);
	}
	return 0;

}

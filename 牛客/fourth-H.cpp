#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 8
using namespace std;
int p[N];
void print(){
    for(int i=0;i<N-1;i++){
        printf("%d ",p[i]);
    }
    printf("%d\n",p[N-1]);

}
int main(){

    for(int i=0;i<N;i++){
        p[i]=i+1;
    }
    do {
        print();

    }while(next_permutation(p,p+N));
    return 0;
}

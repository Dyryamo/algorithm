#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
#define N 1000005
int p[N];
int q[N];
vector<int>ans;
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++){
            scanf("%d",&p[i]);
        }
        for(int i=0;i<m;i++){
            scanf("%d",&q[i]);
        }
        sort(p,p+n);
        sort(q,q+n);
        int fp=0,fq=0;
        while(fp<n&&fq<m){
            if(p[fp]==q[fq]){
               ans.push_back(p[fp]);
                fp++;fq++;
            }
            else if(p[fp]<q[fq]){
                fp++;
            }
            else fq++;
        }
        if(ans.empty()){
            printf("empty\n");
            continue;
        }

        for(vector<int>::iterator it=ans.begin();it!=ans.end()-1;it++){
            printf("%d ",*it);
        }
        printf("%d\n",*(ans.end()-1));
        ans.clear();
    }
}

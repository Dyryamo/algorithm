#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

#define inf 1000010

struct ST{
int to, val;
ST( int t, int v ) {
to = t;
val = v;
}
};
vector<ST> vec[100];
int cost[110];
int vis[110];

int c, n, m;

void dijkstra( int d ) {
fill(cost, cost+110, inf);
for ( int i = 0 ; i < vec[d].size() ; ++ i ) {
cost[vec[d][i].to] = vec[d][i].val;
}
memset( vis, 0, sizeof(vis) );
vis[d] = 1;
cost[d] = 0;
while ( 1 ) {
int k = -1;
int min = inf;
for ( int i = 1 ; i <= m ; ++ i ) {
if ( !vis[i] && min > cost[i] ) {
min = cost[i];
k = i;
}
}
if ( k == -1 ) break;
vis[k] = 1;
for ( int i = 0 ; i < vec[k].size() ; ++ i ) {
int t = vec[k][i].to;
int v = vec[k][i].val;
if ( !vis[t] && cost[k]+v < cost[t] ) {
cost[t] = cost[k]+v;
}
}
}
}

bool ok() {
long long res = 0;
for ( int i = 1 ; i <= m ; ++ i ) {
if ( cost[i] == inf ) {
return false;
}
res += cost[i];
}
return res <= c;
}

void print()
{
for ( int i = 1 ; i <= m ; ++ i ) {
printf( "%d ", cost[i] );
}
puts("");
}

bool judge() {
for ( int i = 1 ; i <= m ; ++ i ) {
dijkstra(i);
// print();
if ( ok() ) {
return true;
}
}
return false;
}

int main()
{
int x, y, v;
int f1, f2;
while ( scanf( "%d%d%d", &c, &n, &m ) != EOF ) {
memset( vec, 0, sizeof(vec) );
for ( int i = 0 ; i < n ; ++ i ) {
scanf( "%d%d%d", &x, &y, &v );
f1 = 0, f2 = 0;
for ( int i = 0 ; i < vec[x].size() ; ++ i ) {
if ( vec[x][i].to == y ) {
if ( vec[x][i].val > v ) f1 = i;
else f1 = -1;
}
}
for ( int i = 0 ; i < vec[y].size() ; ++ i ) {
if ( vec[y][i].to == x ) {
if ( vec[y][i].val > v ) f2 = i;
else f2 = -1;
}
}
if ( f1 > 0 ) {
vec[x][f1].val = v;
} else if (f1 == 0) {
vec[x].push_back(ST(y,v));
}
if ( f2 > 0 ) {
vec[y][f2].val = v;
} else if (f2==0) {
vec[y].push_back(ST(x,v));
}
}
if ( judge() ) {
puts("Yes");
} else {
puts("No");
}
}
return 0;
}

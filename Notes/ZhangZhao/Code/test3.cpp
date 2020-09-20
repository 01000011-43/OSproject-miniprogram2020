#include <iostream>
//#include <vector>
//#include <unordered_set>
//#include <string>
//#include <algorithm>
using namespace std;

#define maxn 33000
int pre[maxn], num[maxn];	//i�ĸ����Ϊpre[i], i����ͼ�а���num[i]���ڵ㡣 
int a[maxn];
void init(int n){
	for(int i = 0; i < n; ++i){
		pre[i] = i;
		num[i] = 1;
	}
}
int find(int x){
	if(x == pre[x])
		return x;
	
	pre[x] = find(pre[x]);	//�ݹ�ز��ҵ�ǰ��ͨͼ�ĸ��ڵ� 
	return pre[x];
}
void join(int x, int y){
	int px = find(x), py = find(y);
	if(px != py){
		pre[px] = py;	//����������ͼ 
		num[py] += num[px];	//����������ͼ�Ľڵ� 
	}
}

int main(){
	int n, m;		
	while(scanf("%d %d", &n, &m), m || n){
		init(n);
		for(int i = 0; i < m; ++i){
			int k;	
			scanf("%d", &k);
			for(int j = 0; j < k; ++j)			
				scanf("%d", &a[j]);
			for(int j = 0; j < k - 1; ++j)			
				join(a[j], a[j + 1]);			
		}
		int root = find(0);
		printf("%d\n", num[root]);		
	}
	return 0;
}

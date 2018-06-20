#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
vector<int> v[101];
bool visit[101];
vector<int> ans;
void dfs(int cur){
	visit[cur]=true;
	for(int i=0;i<v[cur].size();i++){
		if(!visit[v[cur][i]])dfs(v[cur][i]);
	}
	ans.push_back(cur);
}
int main(){
	int n;
	unsigned long long m;
	while(true){
		for(int i=1;i<=100;i++)v[i].clear();
		ans.clear();
		memset(visit,false,sizeof(visit));
		cin >> n >> m;
		if(n==0&&m==0){
			break;
		}
		for(int i=1;i<=m;i++){
			int t1,t2;
			cin >> t1 >> t2;
			v[t1].push_back(t2);
		}
		for(int i=1;i<=n;i++){
			if(!visit[i]){
				dfs(i);
			}
		}
		for(int i=ans.size()-1;i>=0;i--){
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}

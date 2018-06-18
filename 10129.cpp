#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>
using namespace std;
int in[26];
int out[26];
bool node[26];
bool edge[26][26];
vector<int> v[26];
void dfs(int cur){
	node[cur]=false;
	for(int i=0;i<v[cur].size();i++){
		if(node[v[cur][i]])dfs(v[cur][i]);
	}
}
int main(){
	int t,n;
	string s;
	cin >> t;
	for(int i=0;i<t;i++){
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		memset(node,false,sizeof(node));
		memset(edge,false,sizeof(edge));
		for(int j=0;j<26;j++)v[j].clear();
		cin >> n;
		for(int j=0;j<n;j++){
			cin >> s;
			out[s[0]-97]++;
			in[s[s.length()-1]-97]++;
			node[s[0]-97]=true;
			node[s[s.length()-1]-97]=true;
			v[s[0]-97].push_back(s[s.length()-1]-97);
			v[s[s.length()-1]-97].push_back(s[0]-97);
			//pair<int,bool> p;
			//p.first=s[s.length()-1]-97;
			//p.second=false;
			//v[s[0]-97].push_back(p);
		}
		bool start=false;
		int startpos=-1;
		bool end=false;
		//int endpos=-1;
		bool next=false;
		for(int j=0;j<26;j++){
			if(in[j]==out[j])continue;
			else if(in[j]==out[j]+1){
				if(end==true){
					cout << "The door cannot be opened." << endl;
					next=true;break;
				}
				end=true;
				//endpos=j;
			}else if(in[j]+1==out[j]){
				if(start==true){
					cout << "The door cannot be opened." << endl;
					next=true;break;
				}
				start=true;
				startpos=j;
			}else{
				cout << "The door cannot be opened." << endl;
				next=true;break;
			}
		}
		if(next)continue;
		if((start&&!end)||(!start&&end)){
			cout << "The door cannot be opened." << endl;
			continue;
		}
		if(startpos==-1){
			int initial=-1;
			for(int j=0;j<26;j++){
				if(v[j].size()>0){
					initial=j;
					break;
				}
			}
			dfs(initial);
			
		}else{
			dfs(startpos);
			
		}
		bool haveans=false;
			for(int j=0;j<26;j++){
				if(node[j]){
					haveans=true;
					cout << "The door cannot be opened." << endl;
					break;
				}
			}
			if(!haveans){
				cout << "Ordering is possible." << endl;
			}
	}
}

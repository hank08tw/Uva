#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>
#include <cstdio>
#include <memory.h>
#include <stdio.h>
using namespace std;
long double d[5][5][5][5][5][5][5][5][5]={0};
//d[0][0][0][0][0][0][0][0][0]=1;
bool s[5][5][5][5][5][5][5][5][5];
//s[0][0][0][0][0][0][0][0][0]=true;
vector<char> v[9];
long double dfs(int* w){
	if(s[w[0]][w[1]][w[2]][w[3]][w[4]][w[5]][w[6]][w[7]][w[8]]){
		return d[w[0]][w[1]][w[2]][w[3]][w[4]][w[5]][w[6]][w[7]][w[8]];
	}
	s[w[0]][w[1]][w[2]][w[3]][w[4]][w[5]][w[6]][w[7]][w[8]]=true;
	long double total=0;
	int count=0;
	for(int i=0;i<8;i++){
		for(int j=i+1;j<9;j++){
			if(w[i]>0&&w[j]>0&&v[i][w[i]-1]==v[j][w[j]-1]){
				count++;
				//cout << ".";
				int tmp[9];
				for(int k=0;k<9;k++){
					if(k==i||k==j){
						tmp[k]=w[k]-1;
					}else tmp[k]=w[k];
				}
				total+=dfs(tmp);
				//cout << total << endl;
			}
		}
	}
	
	if(total==0)return d[w[0]][w[1]][w[2]][w[3]][w[4]][w[5]][w[6]][w[7]][w[8]]=0;
	return d[w[0]][w[1]][w[2]][w[3]][w[4]][w[5]][w[6]][w[7]][w[8]]=total/count;;
}
int main(){
	string s1,s2,s3,s4;
	while(cin >> s1 >> s2 >> s3 >> s4){//scanf("%s%s%s%s",&s1,&s2,&s3,&s4)!=EOF){
		memset(d,0,sizeof(d));
		memset(s,false,sizeof(s));
		for(int i=0;i<9;i++)v[i].clear();
		d[0][0][0][0][0][0][0][0][0]=1.0;
		s[0][0][0][0][0][0][0][0][0]=true;
		v[0].push_back(s1[0]);
		v[0].push_back(s2[0]);
		v[0].push_back(s3[0]);
		v[0].push_back(s4[0]);
		//cout << v[0][0] << " " << v[0][1] << " " << v[0][2] << " " << v[0][3] << endl;
		for(int i=1;i<9;i++){
			//scanf("%s%s%s%s",&s1,&s2,&s3,&s4);
			cin >> s1 >> s2 >> s3 >> s4;
			v[i].push_back(s1[0]);
			v[i].push_back(s2[0]);
			v[i].push_back(s3[0]);
			v[i].push_back(s4[0]);
			//cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << " " << v[i][3] << endl;
		}
		int w[9]={4,4,4,4,4,4,4,4,4};
		dfs(w);
		cout << d[4][4][4][4][4][4][4][4][4] << endl;
	}
}

#include <iostream>
#define NUM 256
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <memory.h>
using namespace std;
vector<int> sol;
bool visit[NUM+1];
bool path[NUM+1][NUM+1];
int n;
bool findans= false;
using namespace std;
void dfs(int tmp){
    if(tmp==n+1){
        if(path[sol.back()][sol[0]]) {
            for (int i = 0; i < sol.size (); i++) {
                printf("%d ",sol[i]);
            }
            printf("%d\n",sol[0]);
            findans=true;
        }
    }
    else{
        for(int i=1;i<=n;i++){
            if(!visit[i] and path[sol.back()][i]){
                visit[i]=true;
                sol.push_back (i);
                dfs(tmp+1);
                if(findans)return;
                sol.pop_back ();
                visit[i]=false;
            }
        }
    }
}
int main() {
    while(scanf("%d", &n)!=EOF){
        memset(visit,false, sizeof (visit));
        memset(path,false,sizeof(path));
        sol.clear();
        findans=false;
        int a,b;
        while(scanf("%d%d",&a,&b)==2){
            path[a][b]=true;
            path[b][a]=true;
        }
        getchar();
        sol.push_back (1);
        visit[1]=true;
        dfs(2);
        if(!findans)printf("N\n");
    }
    return 0;
}
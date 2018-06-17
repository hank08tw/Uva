#include <iostream>
#include <cstdlib>
#include <memory.h>
using namespace std;
#define NUM 50
int step[NUM+1][NUM+1];
bool go[NUM+1][NUM+1];
int x[8]={1,2,2,1,-1,-2,-2,-1};
int y[8]={-2,-1,1,2,2,1,-1,-2};
struct node{
    node(int x,int y){
        this->x=x;
        this->y=y;
    }
    int x;
    int y;
};
int n,ud,lr;
bool dfs(int tmpx,int tmpy,int total){
    if(total==n*n){
        if((abs(ud-tmpy)==1 &&abs(lr-tmpx)==2)||(abs(ud-tmpy)==2 &&abs(lr-tmpx)==1)){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    printf("%5d",step[i][j]);
                }
                printf("\n");
            }
            return true;
        }
        return false;
    }
    for(int i=0;i<8;i++){
        int nexty=tmpy+y[i];
        int nextx=tmpx+x[i];
        if(nexty<=n && nexty>=1 && nextx<=n && nextx>=1 && !go[nexty][nextx]){
            go[nexty][nextx]=true;
            step[nexty][nextx]=total+1;
            if(dfs(nextx,nexty,total+1)){
                return true;
            }
            go[nexty][nextx]=false;
            step[nexty][nextx]=-1;
        }
    }
    return false;
}

int main() {
    while(scanf("%d %d %d",&n,&ud,&lr)!=EOF){
        memset(go,false, sizeof (go));
        memset(step,-1,sizeof(step));
        go[ud][lr]=true;
        step[ud][lr]=1;
        if(!dfs(ud,lr,1)){
            printf("No Circuit Tour.\n");
        }
        printf("\n");
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
struct node{
    int val;
    node* next;
};
int binary_search(int left,int right,vector<int>& last,int target,vector<int>& pos){
    if(last[(left+right)/2]<target&&last[(left+right)/2+1]>target){
        return (left+right)/2+1;
    }
    if(last[(left+right)/2]>target&&last[(left+right)/2-1]<target){
        return (left+right)/2;
    }
    if(last[(left+right)/2]>target&&last[(left+right)/2-1]>target){
        return binary_search(left,left+right/2,last,target,pos);
    }
    if(last[(left+right)/2]<target&&last[(left+right)/2+1]<target){
        return binary_search((left+right)/2,right,last,target,pos);
    }
    if(last[(left+right)/2]==target){
        pos.push_back ((left+right)/2);
    }
    else if(last[(left+right)/2-1]==target){
        pos.push_back ((left+right)/2-1);
    }
    else if(last[(left+right)/2+1]==target){
        pos.push_back ((left+right)/2+1);
    }
    return -1;

}
int main() {
    int tmp;
    vector<int> nums;
    while(cin >> tmp){
        nums.push_back(tmp);
    }
    if(nums.empty())return 0;
    vector<int> last(1,nums[0]);//last紀錄每種長度的increasing subsequence末尾的最小元素
    vector<int> pos(1,0);

    for(int i=1;i<nums.size();i++){
        if(nums[i]>last.back()){
            last.push_back(nums[i]);
            pos.push_back((int)last.size()-1);
        }
        else{
            if(nums[i]<last.front()){
                last[0]=nums[i];
                pos.push_back(0);
            }
            else{
                int tmp2=binary_search(0,last.size(),last,nums[i],pos);
                if(tmp2!=-1){
                    last[tmp2]=nums[i];
                    pos.push_back(tmp2);
                }

            }
        }
    }
    /*
    for(int i=0;i<pos.size();i++){
        cout << pos[i] << "pp" << endl;
    }
     */
    cout << last.size() << endl;
    cout << "-" << endl;
    node* ans=new node;
    ans->val=-2147483647;
    ans->next=nullptr;
    int cur=last.size()-1;
    for(int i=pos.size()-1;i>=0;i--){
        if(cur<0)break;
        if(pos[i]==cur){
            if(ans->val!=-2147483647){
                node* tmp2=new node;
                tmp2->val=nums[i];
                tmp2->next=ans;
                ans=tmp2;
            }
            else{
                ans->val=nums[i];
            }
            cur--;
        }
    }

    while(ans->next!= nullptr){
        cout << ans->val << endl;
        ans=ans->next;
    }
    cout << ans->val;
}
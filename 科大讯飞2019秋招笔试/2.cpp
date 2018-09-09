#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    int num[100005];
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&num[i]);
    }
    vector<int> v1;
    vector<int> v2;
    for(int i = n-1;i>0;i--){
        if(i>0 && num[i-1]>num[i]){
            if(i == 1)
                v1.push_back(num[0]);
        	
            	continue;
        }
        v1.push_back(num[i]);
    }
    if(v1.size() == n-1){
        cout<<0;
        return 0;
    }
    int ans = 1;
    bool flag = false;
    while(v1.size() > 1 && flag == false){
        flag = true;
        for(size_t i = 0;i<v1.size()-1;i++){
            if(v1[i]<v1[i+1])
                continue;
            else{
                flag = false;
                break;
            }
        }
        for(size_t i = 0;i<v1.size()-1;i++){
            if(i < v1.size()-1 && v1[i] < v1[i+1]){
                if(i == v1.size()-2)
                    v2.push_back(v1[v1.size()-1]);
                
                	continue;
            }
            v2.push_back(v1[i]);
        }
        v1 = v2;
        v2.clear();
        ans++;
    }
    cout<<ans;
    return 0;
}

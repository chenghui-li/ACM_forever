#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int coss[1005];
int pay[1005];
int main(){
    int a[1005];
    string s;
    cin>>s;
    int len = s.size();
    int swap = 0;
    int j = 0;
    for(int i = 0;i<len;i++){
        if(s[i] == ','){
            coss[j++] = swap;
            swap = 0;
            continue;
        }
        char c = s[i];
        int t = c-'0';
        swap = swap * 10 +t;
    }
   // if(swap)
    	coss[j++] = swap;
    for(int i = 0;i<j;i++){
        pay[i] = 1000;
    }
    for(int i = 0;i<j;i++){
        if(i == 0 ){
            pay[i] = coss[i];
        }
        else if(i == 1){
            pay[i] = min(pay[i-1]+coss[i],coss[i]);
        }else{
            pay[i] = min(pay[i-1]+coss[i],pay[i-2]+coss[i]);
        }
        //printf("%d ",pay[i]);
    }
    cout<<pay[j-1];
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    vector<string> v;
    int n;
    scanf("%d",&n);
    string al = "";
    for(int i = 0;i<n;i++){
        scanf("%d",&a);
        int flag = 1;
        string swap = "";
        for(int j = 0;j<8;j++){
            if(flag & a)
                swap = "1"+swap;
            else
                swap = "0"+swap;
            flag = flag << 1;
        }
        v.push_back(swap);
        //cout<<swap<<endl;
        al = al+swap;
    }
    //cout<<al<<endl;
    if(n == 1){
        if(v[0][0] == '0')
            cout<<1;
        else
            cout<<0;
        return 0;
    }
    else{
        int sw = n;
        bool flag = true;
        for(int i = 0;i<sw&&i<al.size();i++){
            if(al[i] == '0'){
                flag = false;
                break;
            }
        }
        if(flag)
            if(al[sw] == '1')
                flag = false;
        if(flag){
            for(int i = 1;i<n;i++){
                if(v[i][0]!='1' || v[i][1] != '0'){
                    flag = false;
                    break;
                }
            }
        }
        if(flag == true)
            cout<<1;
        else
            cout<<0;
    }
    return 0;
}

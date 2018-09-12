#include<iostream>
#include<string>
#include<vector>
#include<map> 
using namespace std;
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    string s = "";
    int c = a/b;
    int mod = a%b;
    cout<<c;
    int index = 1;
    if(mod)
        cout<<".";
    vector<int> v;
    map<int,int> mp;
    while(mod != 0){
    	if(mp[mod] != 0)
    		break;
    	//cout<<mod<<endl;
        mp[mod] = index;
        a = mod * 10;
        v.push_back(a/b);
        //s += a/b;
        mod = a%b;
        index++;
    }
    
    if(mod){
    int end = mp[mod];
    //cout<<end<<endl;
    for(int i = 0;i<end-1;i++){
        cout<<v[i];
    }
	
    cout<< "(";
    for(int i = end-1 ;i<v.size();i++)
        cout<<v[i];
    cout<<")";
        }
        else{
        	for(int i = 0;i<v.size();i++)
        		cout<<v[i];
		}
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int last[256];
	memset(last,-1,sizeof(last));
	cin>>s;
	int len = s.size();
	int start = 0;
	int nmax = 0;
	for(int i = 0;i<len;i++){
		if(last[s[i]] >= start){
			nmax = max(i-start,nmax);
			start = last[s[i]]+1;
		}
		last[s[i]] = i;
	}
	nmax = max(nmax,len-start);
	cout<<nmax;
	return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
struct meeting{
	int s;
	int f;
	int len;
};
bool cmp(struct meeting a,struct meeting b){
	return a.len == b.len?a.s<b.s:a.len>b.len;
}
bool cmp2(struct meeting a,struct meeting b){
	return a.f<b.f;
}
int main(){
	int s,f;
	vector<struct meeting> v;
	vector<struct meeting> v2;
	int a[30];
	memset(a,0,sizeof(a));
	while(1){
		scanf("%d,%d",&s,&f);
		if(s == 0 && f == 0)
			break;
		struct meeting now;
		now.s = s;
		now.f = f;
		now.len = f - s;
		v.push_back(now);
	}
	sort(v.begin(),v.end(),cmp);
	//printf("%d,%d\n",v[0].s,v[0].f);
	v2.push_back(v[0]);
	int nowend = v[0].f;
	int nowbeg = v[0].s;
	for(int i = nowbeg;i<nowend;i++)
		a[i] = 1;
	for(int i = 1;i<v.size();i++){
		nowbeg = v[i].s;
		nowend = v[i].f;
		int sum = 0;
		for(int i = nowbeg;i<nowend;i++){
			sum+=a[i];
		}
		if(sum == 0){
			v2.push_back(v[i]);
			for(int i = nowbeg;i<nowend;i++)
				a[i] = 1;
		}
		
	}
	sort(v2.begin(),v2.end(),cmp2);
	for(int i = 0;i<v2.size();i++){
		printf("%d,%d\n",v2[i].s,v2[i].f);
	}
	return 0;
}

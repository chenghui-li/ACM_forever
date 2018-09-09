#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
typedef struct data{
	int offset;
	int datalen;
}data;
int main(){
	int len;
	int insert;
	vector<data> v;
	cin>>len>>insert;
	char sin[100];
	while(1){
		cin>>sin;
		if(strcmp(sin,"end") == 0)
			break;
		int offset,datalen;
		sscanf(sin,"%d,%d",&offset,&datalen);
		data newdata;
		newdata.datalen = datalen;
		newdata.offset = offset;
		v.push_back(newdata);
	}
	int flag = 0;
	if(v[0].offset>=insert){
		v[0].offset-=insert;
		v[0].datalen += insert;
	}else{
		int last = len - (v[0].datalen + v[0].offset)+v[0].offset;
		if(last >= insert){
			v[0].datalen += insert;
			v[0].offset = v[0].offset + len - (v[0].datalen + v[0].offset) - insert;
		}else{
			last += v[1].offset;
			
			if(last >= insert){
				int swap = v[1].offset;
				v[1].datalen = v[1].offset + v[1].datalen;
				v[1].offset = 0;
				v[0].offset = v[0].offset+v[1].offset-insert;
				v[0].datalen = v[0].datalen - swap+insert;
			}
			else
				flag = 1;
		}
	}
	if(flag == 1){
		printf("0,%d\n",insert);
	}
	for(int i = 0;i<v.size();i++){
		printf("%d,%d\n",v[i].offset,v[i].datalen);
	}
	return 0;
}

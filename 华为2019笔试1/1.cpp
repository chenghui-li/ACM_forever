#include<iostream>

#include<queue>
struct item{
	int x;
	int y;
};
using namespace std;
int main(){
	char a[10][10];
	bool flag[10][10] = {false};
	for(int i = 0;i<10;i++){
		cin>>a[i];
	}
	int x,y;
	cin>>x>>y;
	queue<struct item> q;
	struct item beg;
	beg.x = x;
	beg.y = y;
	flag[beg.x][beg.y] = true;
	q.push(beg);
	while(!q.empty()){
		struct item now = q.front();
		q.pop();
		if(now.x == 0 || now.x == 9 || now.y == 0 || now.y == 9){
			cout<<1;
			return 0;
		}
		int newx,newy;
		newx = now.x;
		newy = now.y+1;
		if(a[newx][newy] == '0' && flag[newx][newy] == false){
			struct item newnode;
			newnode.x = newx;
			newnode.y = newy;
			flag[newx][newy] = true;
			q.push(newnode);
		}
		newy = now.y - 1;
		if(a[newx][newy] == '0' && flag[newx][newy] == false){
			struct item newnode;
			newnode.x = newx;
			newnode.y = newy;
			flag[newx][newy] = true;
			q.push(newnode);
		}
		newy = now.y;
		newx = now.x - 1;
		if(a[newx][newy] == '0' && flag[newx][newy] == false){
			struct item newnode;
			newnode.x = newx;
			newnode.y = newy;
			flag[newx][newy] = true;
			q.push(newnode);
		}
		newx = now.x + 1;
		if(a[newx][newy] == '0' && flag[newx][newy] == false){
			struct item newnode;
			newnode.x = newx;
			newnode.y = newy;
			flag[newx][newy] = true;
			q.push(newnode);
		}
	}
	cout<<0;
	return 0;
} 

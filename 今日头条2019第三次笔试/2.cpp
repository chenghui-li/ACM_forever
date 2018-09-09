#include<iostream>
#include<string.h> 
#include<queue>
using namespace std;
typedef struct location{
    int x;
    int y;
}location;
int main(){
    char a[1005][1005];
    bool flag[1005][1005];
    memset(flag,false,sizeof(flag));
    int m;
    scanf("%d",&m);
    for(int i = 0;i<m;i++){
        for(int j = 0;j<m;j++){
            cin>>a[i][j];
        }
    }
    queue<location> q;
    int ans = 0;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<m;j++){
            if(a[i][j] == '1' && flag[i][j] == false){
            	ans++;
                location l;
                l.x = i;
                l.y = j;
                flag[i][j] = true;
                q.push(l);
                while(!q.empty()){
                    location now = q.front();
                    q.pop();
                    int newx,newy;
                    newx = now.x;
                    newy = now.y-1;
                    if(newy >=0 && a[newx][newy] == '1' && flag[newx][newy] == false){
                        location swap;
                        swap.x = newx;
                        swap.y = newy;
                        q.push(swap);
                        flag[newx][newy] = true;
                    }
                    newy = now.y+1;
                    if(newy < m && a[newx][newy] == '1' && flag[newx][newy] == false){
                        location swap;
                        swap.x = newx;
                        swap.y = newy;
                        q.push(swap);
                        flag[newx][newy] = true;
                    }
                    newy = now.y;
                    newx = now.x-1;
                    if(newx >= 0 && a[newx][newy] == '1' && flag[newx][newy] == false){
                        location swap;
                        swap.x = newx;
                        swap.y = newy;
                        q.push(swap);
                        flag[newx][newy] = true;
                    }
                    newx = now.x + 1;
                    if(newx < m && a[newx][newy] == '1' && flag[newx][newy] == false){
                        location swap;
                        swap.x = newx;
                        swap.y = newy;
                        q.push(swap);
                        flag[newx][newy] = true;
                    }
                }
                
            }
        }
    }
    cout<<ans;
    return 0;
}


/*
5
1 0 0 1 1
1 0 0 1 1
0 0 1 0 0
0 0 1 0 0
0 0 1 0 0

*/

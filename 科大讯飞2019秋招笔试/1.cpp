#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int T,n,x;
    int num[1005];
    scanf("%d",&T);
    while(T--){
        memset(num,0,sizeof(num));
        int sum = 0;
        scanf("%d %d",&n,&x);
        for(int i = 0;i<n;i++){
            scanf("%d",&num[i]);
        	sum += num[i];
        }
        int j;
        for(j = 0;j<n;j++){
        	int avg = sum / n;
        	if(avg >= x)
                break;
            int min = num[0];
            for(int i = 1;i<n;i++){
                if(num[i] < min)
                    min = num[i];
            }
            int c = 100 - min;
            sum += c;
            avg = sum / n;
        }
        cout<<j<<endl;
    }
    return 0;
}

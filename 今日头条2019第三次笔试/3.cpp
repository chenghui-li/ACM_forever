#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 5;
char s[maxn];
int n = 0;
int ans = 0;
void dfs(int cur, int k)
{
    int res = 0;
    if(cur == n && k == 4)
    {
        ans++;
        return;
    }
    int cnt = 0, flag = 0;
    for(int i = cur; i < n; i++)
    {
        if(s[i] == '0' &&(!flag)) cnt++;
        else cnt = 0, flag = 1;
        res *= 10;
        res = res + s[i] - '0';
        if(i > cur && (s[cur] == '0' && s[i] != '0')) break;
        if(res > 255 || cnt >= 2)
        {
            break;
        }
        dfs(i + 1, k + 1);
    }
}
int main()
{
    scanf("%s", s);
    n = strlen(s);
    if(n > 12 || n < 4)
    {
        printf("0\n");
        return 0;
    }
    dfs(0, 0);
    printf("%d\n", ans);
    return 0;
}


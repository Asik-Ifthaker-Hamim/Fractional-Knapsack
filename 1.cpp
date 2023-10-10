#include <bits/stdc++.h>
using namespace std;
struct item
{
    int v,w;
};
bool cmp(struct item a, struct item b)
{
    double r1 = (double)a.v / a.w;
    double r2 = (double)b.v / b.w;
    return r1 >= r2;
}
double fracknapsack(struct item arr[],
                          int m, int n)
{
    sort(arr, arr + n, cmp);

    int curw = 0;
    double finalv = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (curw + arr[i].w <= m)
        {
            curw += arr[i].w;
            finalv += arr[i].v;
        }
        else
        {
            int r = m - curw;
            finalv += arr[i].v*((double)r/arr[i].w);
            break;
        }
    }
    return finalv;
}
int main()
{
    int n,m;
    cin>>n>>m;
    item arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].v>>arr[i].w;
    }
    cout << "Maximum profit = "<< fixed<<setprecision(2)<<fracknapsack(arr, m, n);

    return 0;
}
/*
3 20
25 18
24 15
15 10
*/


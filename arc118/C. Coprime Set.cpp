#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n; int a[n + 1]; for (int i = 1; i <= n; i++) cin >> a[i];
    int px[n + 1] = {0}, ps[n + 1] = {0};
    for (int i = 1; i <= n; i++)
        px[i] = px[i - 1] ^ a[i];
    for (int i = 1; i <= n; i++)
        ps[i] = ps[i - 1] + a[i];
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = i, r = n, j = -1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if ((ps[mid] - ps[i - 1]) == (px[mid] ^ px[i - 1]))
            {
                j = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if (j >= i)
            ans += j - i + 1;
    }
    cout << ans << "\n";
    return 0;
}
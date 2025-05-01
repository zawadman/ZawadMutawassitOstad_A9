#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    int amount;
    cin >> amount;

    const int INF = numeric_limits<int>::max() / 2;
    //dp[x] = min coins to make x
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;

    // Build up from 1 to amount
    for(int x = 1; x <= amount; x++){
        for(int c : coins){
            if(c <= x){
                dp[x] = min(dp[x], dp[x - c] + 1);
            }
        }
    }

    //if dp[amount] still INF.. no solution exists;
    //but per problem statement we assume its always possible
    cout << dp[amount] << "\n";
    return 0;
}

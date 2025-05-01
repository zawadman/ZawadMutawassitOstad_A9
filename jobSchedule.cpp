#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    struct Job { ll start, end, profit; };
    vector<Job> jobs(n);

    for(int i = 0; i < n; i++){
        cin >> jobs[i].start >> jobs[i].end >> jobs[i].profit;
    }

    //sort jobs by end time
    sort(jobs.begin(), jobs.end(),
         [](const Job &a, const Job &b){
             return a.end < b.end;
         });

    //extractend times for binary search
    vector<ll> ends(n);
    for(int i = 0; i < n; i++){
        ends[i] = jobs[i].end;
    }

    vector<ll> dp(n, 0);
    // Base case: best of taking job 0
    dp[0] = jobs[0].profit;

    for(int i = 1; i < n; i++){
        //skip job i
        ll best = dp[i-1];

        //take job i
        // find rightmost job j < i with end[j] <= start[i]
        ll p = jobs[i].profit;
        int idx = int(upper_bound(ends.begin(), ends.begin() + i, jobs[i].start)
                      - ends.begin()) - 1;
        if(idx >= 0) p += dp[idx];

        best = max(best, p);
        dp[i] = best;
    }

    cout << dp[n-1] << "\n";
    return 0;
}
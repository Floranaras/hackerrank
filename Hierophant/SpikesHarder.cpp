#include <bits/stdc++.h>
#define MOD 1000000007LL

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    vector<int> jumps(k);
    for (int i = 0; i < k; i++) {
        cin >> jumps[i];
    }
    
    vector<bool> safe(n + 1, true);
    for (int i = 0; i < (int)s.length(); i++) {  
		if (s[i] == '1') {
            safe[i + 1] = false;
        }
    }
    
    safe[1] = safe[n] = true;
    
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for (int jump : jumps) {
            int next = curr + jump;
            if (next >= 1 && next <= n && safe[next] && dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
    
    vector<long long> ways(n + 1, 0);
    ways[1] = 1;
    
    for (int i = 1; i <= n; i++) {
        if (!safe[i]) continue;
        
        for (int jump : jumps) {
            int next = i + jump;
            if (next <= n && safe[next]) {
                ways[next] = (ways[next] + ways[i]) % MOD;
            }
        }
    }
    
    if (dist[n] == -1) {
        cout << "-1 0" << endl;
    } else {
        cout << dist[n] << " " << ways[n] << endl;
    }
    
    return 0;
}

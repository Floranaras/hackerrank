#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main () 
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int N, K; cin >> N >> K;
    vector<long long> r, b;
    string c; long long p;
    
    while (N--) 
    { 
        cin >> c >> p; 
        (c == "red" ? r : b).push_back(p); 
    }
    
    sort(r.rbegin(), r.rend()); 
    sort(b.rbegin(), b.rend());
    
    vector<long long> pr(r.size()+1), pb(b.size()+1);
    for (size_t i=0; i<r.size(); i++) 
        pr[i+1] = pr[i] + r[i];
    for (size_t i=0; i<b.size(); i++) 
        pb[i+1] = pb[i] + b[i];
    
    int br=0; long long bt=0;
    for (int i = min(K,(int)r.size()); i >= 0 && K-i <= (int)b.size(); i--) 
    {
        long long t = pr[i] + pb[K-i];
        if (i > br || (i == br && t > bt)) 
            br = i, bt = t;
    }
    
    cout << br << " " << bt << "\n";
}
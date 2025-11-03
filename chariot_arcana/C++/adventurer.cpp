#include <bits/stdc++.h>
#define MAX_N 200000
using namespace std;
string duty_names[MAX_N]; // names of each duty
int duty_vals[MAX_N][2];  // for each entry, index 0 contains w_i, and index 1 
                          // contains c_i
/*
This function solves a test case.
Parameters:
n      : int        - number of duties available
t      : long long  - time to do duties in minutes
Returns:
A string containing the answer or "I need to find friends."             
*/
string solve(int n, long long t) {
    t = t * 60;
    
    vector<pair<int, int>> duties;
    for(int i = 0; i < n; i++) {
        int total_time = duty_vals[i][0] + duty_vals[i][1];
        duties.push_back({total_time, i});
    }
    
    sort(duties.begin(), duties.end());
    
    long long time_used = 0;
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        int total_time = duties[i].first;
        if(time_used + total_time <= t) {
            time_used += total_time;
            count++;
        }
    }
    
    if(count == 0) {
        return "I need to find friends.";
    }
    
    return to_string(count);
}
int main() {
    int n;
    long long t;
    string temp;
    
    scanf("%d%lld",&n,&t);
    getline(cin,temp);
    
    for(int i = 0; i < n; i++) {
        getline(cin,duty_names[i]);
        scanf("%d%d",&duty_vals[i][0],&duty_vals[i][1]);
        getline(cin,temp);
    }
    printf("%s\n",solve(n,t).c_str());
}
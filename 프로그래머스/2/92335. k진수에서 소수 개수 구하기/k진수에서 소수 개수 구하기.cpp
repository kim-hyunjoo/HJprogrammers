#include <bits/stdc++.h>

using namespace std;

bool isPrimeNumber(long n) {
    if(n == 0 || n == 1) return false;
    for(long i=2;i<=sqrt(n);i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

string calc(int n, int k) {
    vector<int> v;
    while(n > 0) {
        v.push_back(n % k);
        n /= k;
    }
    
    reverse(v.begin(), v.end());
    
    string str = "";
    
    for(int a : v) {
        str += to_string(a);
    }
        
    return str;
}
int solution(int n, int k) {
    int answer = 0;
    
    string str = calc(n, k);

    string buf = "";
    
    for(char c : str) {
        if(c != '0') {
            buf += c;
            continue;
        }
        if(buf.length() == 0) continue;
        long b = stol(buf);
        if(isPrimeNumber(b)) {
            answer++;
        }
        buf = "";
    }
    // 마지막 남은 수 체크
    if(buf.length() != 0) {
        long b = stol(buf);
        if(isPrimeNumber(b)) {
            answer++;
        }
    }       
    
    return answer;
}
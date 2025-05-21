#include <bits/stdc++.h>

using namespace std;

vector<char> calc(int number, int n) {
    char arr[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    vector<char> v;
    if(number == 0) {
        v.push_back('0');
        return v;
    }
    while(number > 0) {
        v.push_back(arr[number % n]);
        number /= n;
    }
    reverse(v.begin(), v.end());

    return v;
}
string solution(int n, int t, int m, int p) {
    string total = "";
    int number = 0;
    
    // t개 * m명 만큼은 충분히 필요
    while (total.length() < t * m) {
        vector<char> v = calc(number, n);
        for (char c : v) {
            total += c;
        }
        number++;
    }

    string answer = "";
    for (int i = 0; i < t; ++i) {
        answer += total[i * m + (p - 1)];
    }

    return answer;
}

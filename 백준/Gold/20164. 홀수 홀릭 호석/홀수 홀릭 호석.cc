#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


int min_answer = INT_MAX;
int max_answer = INT_MIN;

void solution(int N, int count) {
        string str = to_string(N);
        vector<int> v;
        
        //하나씩 분리해서 vector에 넣기
        while(N > 0) {
            int num = N % 10;
            if(num % 2 == 1) {
                count++;
            }
            v.push_back(num);
            N /= 10;
        }
        reverse(v.begin(), v.end());
        
        //수가 한 자리이면 더 이상 아무것도 하지 못하고 종료한다.
        if(v.size() == 1) {
            min_answer = min(min_answer, count);
            max_answer = max(max_answer, count);
            return;
        }
        //수가 두 자리이면 2개로 나눠서 합을 구하여 새로운 수로 생각한다.
        else if(v.size() == 2) {
            solution(v[0] + v[1], count);
        }
        //수가 세 자리 이상이면 임의의 위치에서 끊어서 3개의 수로 분할하고, 3개를 더한 값을 새로운 수로 생각한다.
        else {
            for(int i=0;i<v.size()-2;i++) {
                for(int j=i+1;j<v.size()-1;j++) {
                    int start = stoi(str.substr(0,i+1));// 0 ~ i 까지
                    int middle = stoi(str.substr(i+1,j-i));// i+1 ~ j 까지
                    int end = stoi(str.substr(j+1));// j+1 ~ 끝까지
                    solution(start + middle + end, count);
                }
            }
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("input.txt", "r", stdin);

    int N;
    cin >> N;

    solution(N, 0);

    cout << min_answer << ' ' << max_answer << '\n';

    return 0;
}

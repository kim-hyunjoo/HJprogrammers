//https://programmers.co.kr/learn/courses/30/lessons/42748

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> arr;
    for(vector<int> v : commands) {
        int i = v[0];
        int j = v[1];
        int k = v[2];

        //자르기
        arr.assign(array.begin()+i-1, array.begin()+j);
        //정렬
        sort(arr.begin(), arr.end());
        //k번째 수
        answer.push_back(arr[k-1]);

    }
    return answer;
}

int main() {
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};

    vector<int> answer = solution(array, commands);
    for(int i : answer)
        cout<<i<<endl;
}
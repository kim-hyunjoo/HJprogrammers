//https://programmers.co.kr/learn/courses/30/lessons/42746

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//서로의 문자열을 더해서 더 큰 값이 만들어지는게 앞에 오도록 한다
bool cmp (string a, string b) {
    return a+b>b+a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;

    //문자열 백터로 바꿔주기
    for(int i : numbers) {
        v.push_back(to_string(i));
    }

    //숫자가 더 커지도록 정렬
    sort(v.begin(), v.end(),cmp);

    //0,0,0으로 이루어질 경우 0으로 리턴
    if(v[0]=="0") return "0";

    for(string s : v) {
        answer+=s;
    }

    return answer;
}

int main() {
    vector<int> numbers1 = {6,10,2};
    vector<int> numbers2 = {3, 30, 34, 5, 9};
    cout<<solution(numbers1)<<endl;
    cout<<solution(numbers2)<<endl;
}
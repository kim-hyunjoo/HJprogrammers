//https://programmers.co.kr/learn/courses/30/lessons/42860

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(string name) {
    int answer = 0;
    unordered_map<char,int> map;
    string first_name = "";

    for(int i=0; i<name.length();i++) {
        first_name+="A";
    }

    //알파벳 맵 만들기
    int count = 0;
    for(int i=65; i<=78;i++) {
        char c = i;
     //   cout << c << " ";
        map.emplace(c,count++);
    }

    count = 12;
    for(int i=79; i<=90;i++) {
        char c = i;
     //   cout << c << " ";
        map.emplace(c,count--);
    }


    //A BCDEFGHIJKLM  N OPQRSTUVWXYZ
    //N은 어디로가나 똑같이 13
    //hash 사용?
    //처음위치에서 조작후 왼,오 결정하기.
    for(int i=0;i<name.length();i++) {
        char c = name[i];
        answer+=map[c];

        //BAACAU

        //왼쪽이나 오른쪽에 A가 있으면 안가도됨.
        //A가 있는 위치는 안가도됨. 미리 A위치 파악하기?
        
        //왼쪽,오른쪽? 어디로갈지?
        char left, right;
        if(i == 0) { //첫번째 위치에서 왼쪽으로 이동하면 마지막 문자로 감
            left = name[name.length()-1];
        }
        else {
            left = name[i-1];
        }      
        if(i == name.length()-1) { //마지막 위치에서 오른쪽으로 이동하면 첫번째 문자로 감
            right = name[0];
        }
        else {
            right = name[i+1];
        }

        if(left == 'A') {

        }
        
        
    }


    return answer;
}

int main() {
    cout<<solution("JEROEN")<<endl;
    cout<<solution("JAN")<<endl;
}
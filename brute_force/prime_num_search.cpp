//https://programmers.co.kr/learn/courses/30/lessons/42839

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

bool isPrime(int n) { 
    if (n < 2) 
        return false; 
    for (int i = 2; i * i <= n; i++) { 
        if (n % i == 0) 
            return false; 
    } 
    return true; 
}


int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end());

    //중복되는 값을 거르기 위해서
    set<int> temp;


        do {
            string str="";
            for(int i=0;i<numbers.size();i++) {
                str+= numbers[i];
                temp.insert(stoi(str));
            }
            
        } while (next_permutation(numbers.begin(), numbers.end()));

    

    for(int i : temp) {
        if(isPrime(i))
            answer++;
        cout<<i<<endl;
    }
    cout<<"======"<<endl;



    return answer;
}

int main() {
    string numbers1 = "17";
    string numbers2 = "011";
    cout<<solution(numbers1)<<endl;
    cout<<solution(numbers2)<<endl;
}
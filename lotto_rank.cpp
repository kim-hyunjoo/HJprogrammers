#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    unordered_map<int,int> map;
    
    for(int i : win_nums){
        map[i]=1;
    }
    
    int zero_count = 0;
    int count=0;
    for(int lotto : lottos) {
        if(lotto==0) {
            zero_count++;
        }
            
        else if(map.find(lotto)!=map.end()){
            count++;
        }
    }

    answer.push_back(min(7-(count+zero_count),6));
    answer.push_back(min(7- count,6));
    
    return answer;
}

int main() {
    vector<int> lottos1 = {44, 1, 0, 0, 31, 25};
    vector<int> lottos2 = {0, 0, 0, 0, 0, 0};
    vector<int> lottos3 = {45, 4, 35, 20, 3, 9};
    vector<int> win_nums1 = {31, 10, 45, 1, 6, 19};
    vector<int> win_nums2 = {38, 19, 20, 40, 15, 25};
    vector<int> win_nums3 = {20, 9, 3, 45, 4, 35};

    vector<int> result1 = solution(lottos1, win_nums1);
    vector<int> result2 = solution(lottos2, win_nums2);
    vector<int> result3 = solution(lottos3, win_nums3);

    for(int i : result1)
        cout<<i<<endl;
    for(int i : result2)
        cout<<i<<endl;
    for(int i : result3)
        cout<<i<<endl;
}
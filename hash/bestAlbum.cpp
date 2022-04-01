//https://programmers.co.kr/learn/courses/30/lessons/42579


#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp( pair<string,int> a, pair<string,int> b) {
	return a.second > b.second;
}

bool cmp_pair(pair<int,int> a, pair<int,int> b) {
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    //장르별 노래의 재생횟수 및 고유번호
    unordered_map<string, vector<pair<int,int>>> map;
    //장르명 - 통합재생수
    unordered_map<string, int> count;
    
    
    for(int i=0;i<genres.size();i++) {
        map[genres[i]].push_back(make_pair(plays[i],i));
        count[genres[i]]+=plays[i];
    }

    // 장르 재생 횟수 내림차순 정렬
    vector<pair<string,int>> sort_vec(count.begin(), count.end());      // count 정렬을 위한 벡터
    sort(sort_vec.begin(), sort_vec.end(), cmp);
    // 장르별 속한 곡 재생 횟수 내림차순 정렬
    for(auto &m : map){ //백터 하나씩 갖고와서...
        sort(m.second.begin(), m.second.end(), cmp_pair);
    }

    for(auto au : sort_vec) {
        string g = au.first;
        for(int i=0;i<2 && i<map[g].size();i++) { //곡의 개수가 1개인 장르는 1개만..
            answer.push_back(map[g][i].second);
        }

    }

    return answer;
}

int main() {
    vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays = { 500, 600, 150, 800, 2500 };
    vector<int> answer = solution(genres, plays);
    for(int i : answer)
        cout<< i<< endl;
}
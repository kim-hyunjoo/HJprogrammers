#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> map;
    for(int i : plays) {
        map.insert(make_pair(genres[i],plays[i]));
    }
    return answer;
}

int main() {
    vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays = { 500, 600, 150, 800, 2500 };
    solution(genres, plays);
}
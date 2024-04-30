#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("input.txt", "r", stdin);

    int test_case;

    cin >> test_case;

    for(int t=0; t<test_case; t++) {
        int n;
        cin >> n;
        unordered_map<string, int> map;
        for(int i=0;i<n;i++) {
            string name, type;
            cin >> name >> type;
            
            map[type]++;
        } 

        int answer = 1;

        for(auto el : map){
            answer *= (el.second+1);
        }

        
        cout<<answer-1<<'\n';
    }
    

    return 0;
}
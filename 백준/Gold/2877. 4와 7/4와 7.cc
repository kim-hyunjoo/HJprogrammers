#include <iostream>
#include <cmath>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("input.txt", "r", stdin);

    int K;
    cin >> K;

    int num_count = 0;
    int sum = 1;
    while(sum <= K) {
        num_count++;
        sum += pow(2, num_count);
    }

    int start = sum - pow(2,num_count);
    int end = sum - 1;

    string str = "";

    for(int i=0;i<num_count;i++) {
        int middle = (start + end - 1)/2;
        if(K <= middle) {
            str += "4";
            end = middle;
        }
        else {
            str += "7";
            start = middle+1;
        }
    }
    
    
    cout << str;

    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrimeNumber(int num) {
    if(num == 1) {
        return false;
    }

    for(int i=2; i<=sqrt(num); i++) {
        if(num % i == 0) {
            return false;
        }
    }

    return true;
}

bool isPalindrome(string num) {
    if(num.length() == 1) {
        return true;
    }


        for(int i=0; i<num.length() / 2; i++) {
            if(num[i] != num[num.length() - i - 1]) {
                return false;
            }
        }
    

    return true;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("input.txt", "r", stdin);

    int N;
    cin >> N;

    while(true) {
        if(isPrimeNumber(N) && isPalindrome(to_string(N))) {
            break;
        }
        N++;
    }

    cout << N;

    return 0;
}

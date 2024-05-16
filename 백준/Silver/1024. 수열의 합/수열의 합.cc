#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("input.txt", "r", stdin);

    int N, L;

    cin >> N >> L;

    while(L <= 100) {
        if(L % 2 == 0) {
            //시작
            int start = int(N / L) - L / 2 + 1;
            //끝
            int end = start + L - 1;
            if(N % L == L / 2 && start >= 0) {
                for(int i=start; i<end; i++) {
                    cout << i << ' ';
                }
                cout << end;
                return 0;
            }
        }
        else {
            //시작
            int start = int(N / L) - int(L / 2);
            //끝
            int end = start + L - 1;
            if(N % L == 0 && start >= 0) {
                for(int i=start; i<end; i++) {
                    cout << i << ' ';
                }
                cout << end;
                return 0;
            }
        }
        L++;
    }

    cout << -1;

    return 0;
}

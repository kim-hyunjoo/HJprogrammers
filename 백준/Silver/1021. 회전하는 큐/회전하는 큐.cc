#include <iostream>
#include <vector>
#include<deque>
using namespace std;

int findIndex(deque<int> queue, int item) {
    for(int i=0;i<queue.size(); i++) {
        if(item == queue[i]) {
            return i;
        }
    }   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   // freopen("input.txt", "r", stdin);

    int N, M;
    cin >> N >> M;

    int arr[M];
    for(int i=0; i<M; i++) {
       cin >> arr[i];
    }

    deque<int> queue(N);
    for(int i=0; i<N; i++) {
       queue[i] = i+1;
    }

    int answer = 0;

    for(int el : arr) {
        if(findIndex(queue, el) <= queue.size() / 2) {
            //왼쪽으로 이동
            while(true) {
                int item = queue.front();
                queue.pop_front();
                if(item == el) {
                    break;
                }
                queue.push_back(item);
                answer++;
            }
        }
        else {
            //오른쪽으로 이동
            while(true) {
                int item = queue.back();
                queue.pop_back();
                if(item == el) {
                    answer++;
                    break;
                }
                queue.push_front(item);
                answer++;
            }
        }
    }

    cout << answer;

    

    return 0;
}
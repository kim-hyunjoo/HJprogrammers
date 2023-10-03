class MinHeap {
    constructor() {
        this.heap = [null];
    }
    //요소 추가
    push(data) {
        this.heap.push(data);
        let currIndex = this.heap.length - 1;
        let parentIndex = Math.floor(currIndex / 2);
        
        while(parentIndex !==0 && this.heap[parentIndex] > data) {
            const temp = this.heap[parentIndex];
            this.heap[parentIndex] = data;
            this.heap[currIndex] = temp;
            
            currIndex = parentIndex;
            parentIndex = Math.floor(currIndex / 2);
        }
    }
    //삭제
    pop() {
        const data = this.heap[1];
        if(this.heap.length == 2) 
            return this.heap.pop();
        this.heap[1] = this.heap.pop();
        
        let currIndex = 1;
        let leftIndex = 2;
        let rightIndex = 3;
        
        while(
            this.heap[currIndex] > this.heap[leftIndex] ||
            this.heap[currIndex] > this.heap[rightIndex]
        ) {
            if(this.heap[leftIndex] > this.heap[rightIndex]) {
                const temp = this.heap[currIndex];
                this.heap[currIndex] = this.heap[rightIndex];
                this.heap[rightIndex] = temp;
                currIndex = rightIndex;
            }
            else {
                const temp = this.heap[currIndex];
                this.heap[currIndex] = this.heap[leftIndex];
                this.heap[leftIndex] = temp;
                currIndex = leftIndex;
            }
            leftIndex = currIndex * 2;
            rightIndex = currIndex * 2 + 1;
        }
        return data;
    }
}

function solution(scoville, K) {
    let answer = 0;
    const heap = new MinHeap();
    
    for(const data of scoville) {
        heap.push(data);
    }

    //이미 전부 K 이상일경우 0리턴
    if(heap.heap[1] >= K) {
        return 0;
    }
    
    while(true){

        if(heap.heap[1] >= K) break;
        if(heap.heap.length <= 2 && heap.heap[1] < K) {
            answer = -1;
            break;
        }
        let first = heap.pop();
        let second = heap.pop();
        let newScoville = first + second * 2;
        heap.push(newScoville);
        answer++;        
    }
    
    return answer;
}
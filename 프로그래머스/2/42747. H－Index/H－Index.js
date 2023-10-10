function solution(citations) {
    var answer = 1;
    citations.sort((a,b) => b-a); //내림차순 정렬
    
    let h = citations[0]; //H-Index
    let count = 0; //h편 이상 인용된 논문의 개수
    
    while(count < h) {
        citations.forEach(citation => {
            if(citation < h) { //현재 논문의 인용된 수가 h보다 작으면 멈추고 판단
                return false;
            }
            count++;
        })
        
        if(count >= h) { //만약 h번 이상 인용된 논문이 h편 이상이면
            answer = h;
            break;  
        }
        h--; //H-index를 감소시켜가면서 h의 최댓값을 찾는다.
        count = 0;
    }      

    return h;
}
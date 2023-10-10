function solution(citations) {
    citations.sort((a,b) => b-a); //내림차순 정렬
    
    let h = 0;

    citations.forEach((citation, index) => {
        let count = index+1; //논문의 개수
        if(count <= citation) { 
            h = count;
        }
    })

    return h;
}
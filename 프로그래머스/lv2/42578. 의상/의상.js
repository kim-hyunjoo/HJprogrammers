function solution(clothes) {
    let answer = 1;
    //각 종류 별로 옷은 입거나, 안 입거나 둘 중 하나의 경우로 나뉜다.
    //입는 경우, 해당 종류의 옷 개수로 경우의 수가 생긴다.
    //ex : A종류 옷 1벌 - 입기/안입기 총 2가지
    //A종류 옷 2벌 - 입기(a1입기/a2입기)/안입기 총 3가지
    //A종류 옷 3벌 - 입기(a1입기/a2입기/a3입기)/안입기 총 4가지
    // 각 종류별 (옷의 개수 + 1) 끼리 전부 곱하면 경우의 수 모두 완성...
    
    const map = new Map();
    clothes.map(cloth=>cloth[1]).forEach((type, index)=> {
        if(map.has(type)) {
            map.set(type,map.get(type)+1)
        }
        else {
            map.set(type,2);
        }
    })
    
    for(const value of map.values()) {
        answer *= value;
    }
    
    return answer-1; //최소 한 개의 의상은 입어야 하므로 아무 것도 안 입는 경우 제외
}
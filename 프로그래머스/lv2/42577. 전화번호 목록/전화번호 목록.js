function solution(phone_book) {
    var answer = true;
    const map = new Map();
    phone_book.forEach((number, index) => {
        map.set(number, 1);
    })
    
    for(const number of phone_book) {
        for(let i=1;i<number.length;i++){
            if(map.has(number.slice(0,i))) {
                return false;
            }
        }
    }
    
    return answer;
}
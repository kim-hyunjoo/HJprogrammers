function solution(word) {
    var answer = 0;
    
    const dic = ['A','E','I','O','U']
    const weight = [781, 156, 31, 6, 1]
    const arr = [...word]
    arr.forEach((char, index) => {
        const alphaIndex = dic.findIndex( el => el === char);
        answer += weight[index] * alphaIndex
    })
    answer += word.length
    
    return answer;
}
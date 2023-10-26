function solution(begin, target, words) {
    if(!words.includes(target)) return 0;
    
    var answer = 0;
    
    const queue = []
    queue.push([begin, 0])
    const visit = []
    
    while(queue.length > 0) {
        const [popWord, count] = queue.shift()
        if(popWord === target) {
            answer = count
            break;
        }
        words.forEach((word, i) => {
            if([...word].filter((char, i) => char !== popWord[i]).length === 1) {
                queue.push([word, count+1])
                words.splice(i,1)
            }
        })
        console.log(popWord)
        console.log(queue)
        answer++
    }
    
    return answer;
}
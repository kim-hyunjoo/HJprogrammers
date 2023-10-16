function dfs(numbers, target, sum, depth) {
    if(depth === numbers.length) {
        if(sum === target) {
            return 1;
        }
        return 0;
    } 
    let count = 0;
    count += dfs(numbers, target, sum + numbers[depth], depth+1);
    count += dfs(numbers, target, sum - numbers[depth], depth+1);
    return count;
}

function solution(numbers, target) {
    return dfs(numbers, target, 0,0)
}
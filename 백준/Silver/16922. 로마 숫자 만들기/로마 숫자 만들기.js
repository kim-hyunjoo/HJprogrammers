
const fs = require("fs");
const input = fs.readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt").toString().trim().split('\n')

//const [C, N] = input[0].split(" ").map(Number);
const N = Number(input[0]);

//const arr = input.slice(1).map(Number);
//const map = input.slice(1).map(_ => _.trim().split(''));

let answer = 0;
const RomanNum = [1,5,10,50];
const visited = new Array(1001).fill(false);

function dfs(depth, sum, index) {
    if(depth === N) {
        //이미 계산되었던 수는 pass
        if(visited[sum] !== true) {
            answer++;
            visited[sum] = true;
        } 
        return;
    }

    for(let i=index;i<RomanNum.length;i++) {
        dfs(depth+1, sum + RomanNum[i], i); // 중복된 숫자 합을 방지하기 위해 현재 index 정보를 넘긴다.
    }
}

function main() {
    dfs(0,0,0); //depth, sum, index
    console.log(answer)
}

main();
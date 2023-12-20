
const fs = require("fs");
const input = fs.readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt").toString().trim().split('\n')

const [N, S] = input[0].split(" ").map(Number);
//const N = Number(input[0]);

const arr = input[1].split(' ').map(Number);
//const arr = input.slice(1).map(Number);
//const map = input.slice(1).map(_ => _.trim().split(''));

let answer = 0;

function dfs(depth, sum) {   
    //끝까지 왔을 때 체크
    if(depth === N) {
        if(sum === S) {
            answer++;
        }
        return;
    }
    
    //현재 원소 부분집합에 넣기
    dfs(depth+1, sum+arr[depth])
    //현재 원소 부분집합에 안넣기
    dfs(depth+1, sum);
}

function main() {
    //합이 S가 되는 부분 수열의 개수
    dfs(0,0);

    if(S === 0) { //합이 0인 경우에는 공집합도 들어가게 되므로... 제외시켜주기
        answer--;
    }
    console.log(answer)
}

main();
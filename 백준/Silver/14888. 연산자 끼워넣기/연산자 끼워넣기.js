const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");

//const [N, S] = input[0].split(" ").map(Number);
const N = Number(input[0]);

const arr = input[1].split(" ").map(Number);
//const arr = input.slice(1).map(Number);
//const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));
const op = input[2].split(" ").map(Number);

let maxSum = Number.MIN_SAFE_INTEGER;
let minSum = Number.MAX_SAFE_INTEGER;

function dfs(depth, sum, operator) {
  //console.log(arr[depth], sum, operator);
  // + - * /
  if (depth === N) {
    if (minSum > sum) {
      minSum = sum;
    }
    if (maxSum < sum) {
      maxSum = sum;
    }
    return;
  }

  const op = [...operator];
  const [plus, minus, multiple, divide] = op;

  if (plus > 0) {
    op[0]--; // 해당 연산자를 사용한 버전으로 넘겨주기
    dfs(depth + 1, sum + arr[depth], op);
    op[0]++; //밑에선 안사용했다고 가정해야하므로 다시 복구
  }
  if (minus > 0) {
    op[1]--;
    dfs(depth + 1, sum - arr[depth], op);
    op[1]++;
  }
  if (multiple > 0) {
    op[2]--;
    dfs(depth + 1, sum * arr[depth], op);
    op[2]++;
  }
  if (divide > 0) {
    op[3]--;
    dfs(depth + 1, parseInt(sum / arr[depth]), op);
    op[3]++;
  }
}

function main() {
  dfs(1, arr[0], op);
  console.log(maxSum === 0 ? 0 : maxSum);
  console.log(minSum === 0 ? 0 : minSum);
}

main();

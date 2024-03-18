const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");

const [A, K] = input[0].split(" ").map(Number);
//const T = Number(input[0]);

//const arr = input[1].split(" ").map(Number);
//const arr = input.slice(1);
//const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));

function main() {
  const answer = new Array(K + 1).fill(0);
  const queue = [K];

  while (queue.length > 0) {
    const item = queue.shift();
    if (item === A) {
      console.log(answer[item]);
      return;
    }

    if (!answer[item - 1]) {
      answer[item - 1] = answer[item] + 1;
      queue.push(item - 1);
    }
    if (item % 2 === 0 && item / 2 >= A && !answer[item / 2]) {
      answer[item / 2] = answer[item] + 1;
      queue.push(item / 2);
    }
  }
}

main();

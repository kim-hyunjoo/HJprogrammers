const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");

const [N, T] = input[0].split(" ").map(Number);
//const N = Number(input[0]);

//const arr = input[1].split(" ").map(Number);
const arr = input.slice(1);
const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));

function main() {
  const time = new Array(1000).fill(0);

  arr.forEach((item) => {
    if (item.length === 1) return;
    const [from, to] = item.split(" ").map(Number);
    for (let t = from; t < to; t++) {
      time[t] += 1;
    }
  });

  let sum = 0;
  for (let i = 0; i < T; i++) {
    sum += time[i];
  }

  let max_time = sum;
  let max_from = 0;
  let max_to = T;

  for (i = 1; i < time.length; i++) {
    sum = sum - time[i - 1] + time[i + T - 1];
    if (sum > max_time) {
      max_time = sum;
      max_from = i;
      max_to = i + T;
    }
  }
  console.log(max_from, max_to);
}

main();

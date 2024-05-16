const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

let [N, L] = input[0].split(" ").map(Number);
//const gimbaps = input.slice(1).map(Number);
//const [M] = input[1].split(" ").map(Number);
//const arr = input[1].split("");
//const map = input.slice(2, M + 2).map((_) => _.trim().split(" ").map(Number));
//const [start, end] = input[M + 2].split(" ").map(Number);

function main() {
  const answer = [];

  while (L <= 100) {
    if (L % 2 === 0) {
      //시작
      const start = Math.floor(N / L) - L / 2 + 1;
      //끝
      const end = start + L - 1;
      if (N % L === L / 2 && start >= 0) {
        for (let i = start; i <= end; i++) {
          answer.push(i);
        }
        break;
      }
    } else {
      //시작
      const start = Math.floor(N / L) - Math.floor(L / 2);
      //끝
      const end = start + L - 1;
      if (N % L === 0 && start >= 0) {
        for (let i = start; i <= end; i++) {
          answer.push(i);
        }
        break;
      }
    }
    L++;
  }

  if (answer.length === 0) {
    console.log(-1);
  } else {
    console.log(answer.join(" "));
  }
}

main();

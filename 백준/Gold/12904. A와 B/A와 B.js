const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

//const [T] = input[0].split(" ").map(Number);
//const [N, M] = input[0].split(" ").map(Number);
//const [M] = input[2].split(" ").map(Number);
//const arr = input.slice(1).map(Number);
//const arr = input[1].split(" ").map(Number);
//const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));
//const [start, end] = input[M + 2].split(" ").map(Number);
const S = input[0];
const T = input[1].split("");

function main() {
  while (S.length !== T.length) {
    if (T[T.length - 1] === "A") {
      T.pop();
    } else {
      T.pop();
      T.reverse();
    }
  }

  console.log(S === T.join("") ? 1 : 0);
}

main();

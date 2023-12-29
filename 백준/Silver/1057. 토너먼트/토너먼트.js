const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");

const [N, KIM, LIM] = input[0].split(" ").map(Number);
//const N = Number(input[0]);

//const arr = input[1].split(" ").map(Number);
//const arr = input.slice(1).map(Number);
//const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));

function main() {
  let kim = KIM,
    lim = LIM,
    count = 0;
  while (kim != lim) {
    kim = Math.ceil(kim / 2); //번호가 1/2 당겨진다.
    lim = Math.ceil(lim / 2); // 번호가 1/2 당겨진다.
    count++;
  }
  console.log(count);
}

main();

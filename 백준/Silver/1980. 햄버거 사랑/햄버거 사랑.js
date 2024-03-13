const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");

const [n, m, t] = input[0].split(" ").map(Number);
//const N = Number(input[0]);

//const arr = input[1].split(" ").map(Number);
//const arr = input.slice(1);
//const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));

function main() {
  // 일단 콜라가 0인게 더 중요하니까 n, m 의 조합으로 t를 만들 수 있는지 보고
  // 만약에 없으면 그때 콜라를 1씩 처묵음
  let time = t;
  let min = Math.min(n, m);
  let max = Math.max(n, m);
  if (time % min === 0) {
    console.log(t / min, 0);
    return;
  }

  let max_count = 1;

  while (max * max_count <= time) {
    if ((time - max * max_count) % min === 0) {
      console.log((time - max * max_count) / min + max_count, 0);
      return;
    }
    max_count++;
  }

  //이걸로 안되면 콜라 마셔야함

  let coke = 1;
  while (time > 0) {
    time--;
    if (time % min === 0) {
      console.log(time / min, coke);
      return;
    }
    max_count = 1;
    while (max * max_count <= time) {
      if ((time - max * max_count) % min === 0) {
        console.log((time - max * max_count) / min + max_count, coke);
        return;
      }
      max_count++;
    }
    coke++;
  }
}

main();

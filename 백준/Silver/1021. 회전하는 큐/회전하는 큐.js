const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N, M] = input[0].split(" ").map(Number);
const arr = input[1].split(" ").map(Number);
//const clothes = input.slice(2).map((_) => _.trim().split(" "));

function main() {
  const queue = Array.from({ length: N }, (v, i) => i + 1);
  let answer = 0;
  arr.forEach((el) => {
    if (queue.indexOf(el) < queue.length / 2) {
      //왼쪽으로 이동
      while (true) {
        const item = queue.shift();
        if (item === el) {
          break;
        }
        queue.push(item);
        answer++;
      }
    } else {
      //오른쪽으로 이동
      while (true) {
        const item = queue.pop();
        if (item === el) {
          answer++;
          break;
        }
        queue.unshift(item);
        answer++;
      }
    }
  });

  console.log(answer);
}

main();

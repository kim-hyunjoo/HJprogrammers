const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");

//const [n, m, t] = input[0].split(" ").map(Number);
const N = Number(input[0]);

const arr = input[1].split(" ").map(Number);
//const arr = input.slice(1);
//const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));

function main() {
  let index = 1;
  const startStack = arr.reverse();
  const middleStack = [];
  while (index <= N) {
    if (startStack.length === 0) {
      break;
    }
    const startItem = startStack[startStack.length - 1];

    if (index === startItem) {
      index++;
      startStack.pop();
      continue;
    }

    if (middleStack.length > 0) {
      const middleItem = middleStack[middleStack.length - 1];

      if (index === middleItem) {
        index++;
        middleStack.pop();
        continue;
      }
    }

    startStack.pop();
    middleStack.push(startItem);
  }

  while (index <= N) {
    const item = middleStack.pop();
    if (index === item) {
      index++;
      continue;
    }
    console.log("Sad");
    return;
  }
  console.log("Nice");
}

main();

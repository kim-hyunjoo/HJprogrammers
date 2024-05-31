const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

//const [test_case] = input[0].split(" ").map(Number);
//const [R, C, K] = input[0].split(" ").map(Number);
//const numbers = input[1].split(" ").map(Number);
//const [M] = input[1].split(" ").map(Number);
//const map = input.slice(1).map((_) => _.trim().split(""));
//const [start, end] = input[M + 2].split(" ").map(Number);

function main() {
  const test_case = Number(input.shift());
  for (let t = 0; t < test_case; t++) {
    const length = Number(input.shift());
    const trees = input.shift().split(" ").map(Number);
    trees.sort((a, b) => a - b);
    const mid = trees[length - 1];
    const newTrees = Array.from({ length: length });
    newTrees[Math.floor(length / 2)] = mid;
    //console.log(newTrees);
    for (let i = 0; i <= Math.floor(length / 2) - 1; i++) {
      newTrees[i] = trees[i * 2];
      newTrees[length - 1 - i] = trees[i * 2 + 1];
    }
    //console.log(newTrees);
    let answer = 0;
    for (let i = 0; i < length - 1; i++) {
      answer = Math.max(answer, Math.abs(newTrees[i] - newTrees[i + 1]));
    }
    console.log(answer);
  }
}

main();

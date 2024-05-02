const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N] = input[0].split(" ").map(Number);
const arr = input[1].split("");
//const clothes = input.slice(2).map((_) => _.trim().split(" "));

function main() {
  let answer = 0;
  for (let i = 0; i < arr.length - 1; i++) {
    if (arr[i] + arr[i + 1] === "EW") {
      answer++;
    }
  }
  console.log(answer);
}

main();

const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [T] = input.shift().split(" ").map(Number);
//const [M] = input[0].split(" ").map(Number);
//const arr = input.slice(1).map(Number);
//const arr = input[1].split(" ").map(Number);
//const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));
//const [start, end] = input[M + 2].split(" ").map(Number);

function main() {
  for (let t = 0; t < T; t++) {
    const W = input.shift().trim().split("");
    const K = Number(input.shift());

    //가장짧은경우도 맨앞과 뒤가 같을수밖에없다!
    const map = new Map();

    W.forEach((ch, index) => {
      if (!map.has(ch)) {
        const arr = [index];
        map.set(ch, arr);
      } else {
        const arr = [...map.get(ch), index];
        map.set(ch, arr);
      }
    });

    const wordLengths = [];

    map.forEach((value, _) => {
      if (value.length >= K) {
        //K개이상포함이니까...
        for (let i = value.length - 1; i >= K - 1; i--) {
          const length = value[i] - value[i - K + 1] + 1;
          wordLengths.push(length);
        }
      }
    });
    if (wordLengths.length === 0) {
      console.log(-1);
    } else {
      wordLengths.sort((a, b) => a - b);
      console.log(wordLengths[0] + " " + wordLengths[wordLengths.length - 1]);
    }
  }
}

main();

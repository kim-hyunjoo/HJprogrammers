const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

let [N] = input[0].split(" ").map(Number);
//const gimbaps = input.slice(1).map(Number);
//const [M] = input[1].split(" ").map(Number);
//const arr = input[1].split("");
//const map = input.slice(2, M + 2).map((_) => _.trim().split(" ").map(Number));
//const [start, end] = input[M + 2].split(" ").map(Number);

const isPrimeNumber = (num) => {
  if (num === 1) {
    return false;
  }

  for (let i = 2; i <= Math.sqrt(num); i++) {
    if (num % i === 0) {
      return false;
    }
  }
  return true;
};

const isPalindrome = (num) => {
  if (num.length % 2 === 0) {
    for (let i = 0; i < num.length / 2; i++) {
      if (num[i] !== num[num.length - i - 1]) {
        return false;
      }
    }
  } else {
    for (let i = 0; i < num.length / 2 - 1; i++) {
      if (num[i] !== num[num.length - i - 1]) {
        return false;
      }
    }
  }
  return true;
};

function main() {
  // 소수
  // 팰린드롬
  // N이상의 가장 작은 수
  while (true) {
    if (isPrimeNumber(N) && isPalindrome(Array.from(String(N), Number))) {
      break;
    }
    N++;
  }

  console.log(N);
}

main();

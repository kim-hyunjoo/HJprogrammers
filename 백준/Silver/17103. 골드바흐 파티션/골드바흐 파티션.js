const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [T] = input[0].split(" ").map(Number);
//const [N, M] = input[0].split(" ").map(Number);
//const [M] = input[2].split(" ").map(Number);
const arr = input.slice(1).map(Number);
//const arr = input[1].split(" ").map(Number);
//const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));
//const [start, end] = input[M + 2].split(" ").map(Number);

function isPrimeNumber(N) {
  for (let i = 2; i <= Math.sqrt(N); i++) {
    if (N % i === 0) {
      return false;
    }
  }
  return true;
}

function main() {
  const maxNum = Math.max(...arr);
  const primes = Array.from({ length: maxNum + 1 }, () => false);

  for (let i = 2; i <= maxNum; i++) {
    if (isPrimeNumber(i)) {
      primes[i] = true;
    }
  }

  for (let test_case = 0; test_case < T; test_case++) {
    let N = arr[test_case];
    let count = 0;
    for (let i = 2; i <= N / 2; i++) {
      if (primes[i] && primes[N - i]) {
        count++;
      }
    }
    console.log(count);
  }
}

main();

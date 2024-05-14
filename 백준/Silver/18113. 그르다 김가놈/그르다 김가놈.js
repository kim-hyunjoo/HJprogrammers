const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N, K, M] = input[0].split(" ").map(Number);
const gimbaps = input.slice(1).map(Number);
//const [M] = input[1].split(" ").map(Number);
//const arr = input[1].split("");
//const map = input.slice(2, M + 2).map((_) => _.trim().split(" ").map(Number));
//const [start, end] = input[M + 2].split(" ").map(Number);

function main() {
  const slicedgimbaps = gimbaps
    .map((gimbap) => {
      if (gimbap <= K || gimbap === 2 * K) {
        return -1;
      }
      if (gimbap < 2 * K) {
        return gimbap - K;
      }
      return gimbap - 2 * K;
    })
    .filter((el) => el !== -1)
    .sort();

  let start = 1;
  let end = 10 ** 9;
  let P = -1;

  while (start <= end) {
    let mid = Math.floor((start + end) / 2);
    let count = 0;

    slicedgimbaps.forEach((gimbap) => {
      count += Math.floor(gimbap / mid);
    });

    if (count < M) {
      end = mid - 1;
    } else {
      start = mid + 1;
      P = Math.max(mid, P);
    }
  }

  console.log(P);

}

main();

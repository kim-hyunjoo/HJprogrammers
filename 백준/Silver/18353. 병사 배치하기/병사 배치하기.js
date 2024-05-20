const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

let [N] = input[0].split(" ").map(Number);
const powers = input[1].split(" ").map(Number);
//const [M] = input[1].split(" ").map(Number);
//const map = input.slice(2, M + 2).map((_) => _.trim().split(" ").map(Number));
//const [start, end] = input[M + 2].split(" ").map(Number);

function main() {
  const dp = Array.from({ length: N + 1 }, () => 0);
  //dp[N - 2] = powers[N - 2] > powers[N - 1] ? 1 : 0;

  for (let i = N - 1; i >= 0; i--) {
    for (let j = i + 1; j < N; j++) {
      //console.log(powers[i], powers[j]);
      if (powers[j] < powers[i]) {
        dp[i] = Math.max(dp[i], dp[j] + 1);
      }
    }
    //dp[i] = powers.slice(i + 1, N).filter((power) => power < powers[i]) + 1;
    //뒤에 dp애들중에 나보다 작은 애들 중에서 max를 뽑아야함

    //console.log(dp);
  }

  console.log(N - Math.max(...dp) - 1);
}

main();

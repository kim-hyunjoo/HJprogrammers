const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N, M] = input[0].split(" ").map(Number);
const map = input.slice(1).map((_) => _.trim().split("").map(Number));

const dr = [1, 0, 1];
const dc = [0, 1, 1];

function main() {
  let answer = 1;
  for (let r = 0; r < N - 1; r++) {
    for (let c = 0; c < M - 1; c++) {
      let prevPoint = map[r][c];
      let dist = 1;
      while (r + dist < N && c + dist < M) {
        let plag = true;
        for (let i = 0; i < 3; i++) {
          let curPoint = map[r + dr[i] * dist][c + dc[i] * dist];
          //console.log(r + dr[i] * dist, c + dc[i] * dist);
          if (prevPoint !== curPoint) {
            plag = false;
            break;
          }
        }
        if (plag) {
          if (Math.pow(dist + 1, 2) > answer) {
            answer = Math.pow(dist + 1, 2);
          }
        }
        dist++;
      }
    }
  }

  console.log(answer);
}

main();

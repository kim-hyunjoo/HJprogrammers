const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");

//const test_case = Number(input.shift();
const [test_case] = input[0].split(" ").map(Number);
//const T = Number(input[0]);

//const arr = input[1].split(" ").map(Number);
//const arr = input.slice(1);
const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));

const dr = [0, 1, 0, -1];
const dc = [1, 0, -1, 0];

function main() {
  for (let t = 0; t < test_case; t++) {
    const [M, N, K] = map[0];
    const farm = Array.from({ length: N }, () => new Array(M).fill(0));
    map.shift();

    const posArr = [];
    for (let k = 0; k < K; k++) {
      const [c, r] = map[0];
      farm[r][c] = 1;
      posArr.push([r, c]);
      map.shift();
    }
    //console.log(farm);

    //여기서 이중 포문 돌아야하나?
    //아니면 start 지점으로만?
    let answer = 0;

    for (let p = 0; p < posArr.length; p++) {
      const [startR, startC] = posArr[p];

      //console.log(farm);
      if (farm[startR][startC] > 1) {
        continue;
      }

      //console.log(startR, startC);
      //console.log(farm);

      const queue = [[startR, startC]];
      // console.log(queue);
      while (queue.length > 0) {
        const [curR, curC] = queue.shift();
        //console.log(curR, curC);

        for (let i = 0; i < 4; i++) {
          const nextR = curR + dr[i];
          const nextC = curC + dc[i];

          if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= M) {
            continue;
          }

          if (farm[nextR][nextC] != 1) {
            //방문체크
            continue;
          }

          queue.push([nextR, nextC]);

          farm[nextR][nextC]++;
        }
      }
      answer++;
    }
    console.log(answer);
  }
}

main();

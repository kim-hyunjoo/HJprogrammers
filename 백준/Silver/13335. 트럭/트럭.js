const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [n, w, L] = input[0].split(" ").map(Number);
//const [M] = input[0].split(" ").map(Number);
//const arr = input.slice(1).map(Number);

const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));
map.pop();
//const [start, end] = input[M + 2].split(" ").map(Number);

function main() {
  const start = input[1].split(" ").map(Number);
  const middle = new Array(w).fill(0);
  const end = [];

  let answer = 0;

  while (end.length < n) {
    const curTruck = start[0];
    const outTruck = middle[0];

    //만약 다리의 맨 앞에 트럭이 존재하면 다리를 빠져나온다.
    if (outTruck !== 0) {
      end.push(outTruck);
    }

    //다리에 있는 트럭들 한 칸씩 앞으로 이동
    for (let i = 0; i < w - 1; i++) {
      middle[i] = middle[i + 1];
    }

    //다리의 맨 뒤는 비워진다.
    middle[w - 1] = 0;

    //다리의 길이, 다리의 최대 하중 조건을 모두 만족한다면
    if (
      middle.filter((el) => el !== 0).length < w &&
      middle.reduce((acc, cur) => acc + cur) + curTruck <= L
    ) {
      //출발하지 않은 트럭 하나를 다리의 맨 뒤로 보낸다.
      middle[w - 1] = curTruck;
      start.shift();
    }

    answer++;
  }

  console.log(answer);
}

main();

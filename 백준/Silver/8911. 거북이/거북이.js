const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [test_case] = input[0].split(" ").map(Number);
//const arr = input[1].split("");
const map = input.slice(1).map((_) => _.trim().split(""));

let dir = [
  [0, 1],
  [-1, 0],
  [0, -1],
  [1, 0],
];
function main() {
  for (let t = 0; t < test_case; t++) {
    let curX = 0;
    let curY = 0;
    //북쪽을 바라보며 시작
    let curIdx = 0;
    let [dx, dy] = dir[curIdx];

    let maxX = 0,
      maxY = 0,
      minX = 0,
      minY = 0;

    map[t].forEach((command) => {
      if (command === "F") {
        curX += dx;
        curY += dy;
      } else if (command === "B") {
        curX -= dx;
        curY -= dy;
      } else if (command === "L") {
        curIdx = (curIdx + 1) % 4;
        [dx, dy] = dir[curIdx];
      } else if (command === "R") {
        curIdx = (curIdx + 4 - 1) % 4;
        [dx, dy] = dir[curIdx];
      }
      curX < minX && (minX = curX);
      curX > maxX && (maxX = curX);
      curY < minY && (minY = curY);
      curY > maxY && (maxY = curY);
    });

    console.log(Math.abs(maxX - minX) * Math.abs(maxY - minY));
  }
}

main();

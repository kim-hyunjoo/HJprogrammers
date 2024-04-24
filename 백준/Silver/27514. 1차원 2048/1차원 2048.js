const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N] = input[0].split(" ").map(Number);
const arr = input[1].split(" ").map(Number);
//.filter((el) => el !== 0);
//const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));

const map = new Map();

function add(num) {
  if (map.has(num)) {
    map.delete(num);
    add(num * 2, 1);
  } else {
    map.set(num, 1);
  }
}

function main() {
  arr.forEach((el) => {
    if (el === 0) {
      return;
    }
    add(el);
  });
  console.log(BigInt(Math.max(...map.keys())).toString());
}
// function main() {
//   while (arr.length > 1) {
//     // 홀수가 아닌 가장 작은 수를 모은다..
//     const minNum = Math.min(...arr);

//     const minArr = [];
//     for (let i = 0; i < arr.length; i++) {
//       if (arr[i] === minNum) {
//         minArr.push(arr[i]);
//         arr.splice(i, 1);
//         i--;
//       }
//     }

//     if (minArr.length === 1) {
//       //1개면 짝을 못이루므로 그냥 없애
//       continue;
//     }
//     //console.log(minArr, arr);
//     //가장 작은 애들을 배열로 만들어서 가장 큰 수로 만들어
//     //console.log(minNum, minArr);
//     const newNum = minNum * (Math.floor(minArr.length / 2) * 2);
//     // console.log(newNum);
//     arr.push(newNum);
//     // console.log(arr);
//   }
//   console.log(arr[0]);
// }

main();

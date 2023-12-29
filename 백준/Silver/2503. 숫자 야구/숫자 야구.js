const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");

//const [N, KIM, LIM] = input[0].split(" ").map(Number);
const N = Number(input[0]);

//const arr = input[1].split(" ").map(Number);
//const arr = input.slice(1).map(Number);
const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));

function main() {
  const answer = new Array(1000).fill(true);

  //사전 작업. 중복 수와 0을 걸러준다.
  for (let i = 123; i <= 987; i++) {
    const [one, two, three] = i.toString().split("");
    if (one === two || two === three || three === one) {
      answer[i] = false;
    }
    if (one === "0" || two === "0" || three === "0") {
      answer[i] = false;
    }
  }

  for (let i = 0; i < N; i++) {
    //질문자가 생각하고 있는 숫자, 제출자가 답해준 strike, ball
    const [num, strike, ball] = map[i];

    //정답이 될 수 있는 숫자들을 탐색한다.
    for (let j = 123; j <= 987; j++) {
      let strikeCount = 0;
      let ballCount = 0;

      // 이미 false면 continue
      if (answer[j] === false) {
        continue;
      }

      // 질문자가 말한 숫자와 현재 정답이 될 수 있는 숫자를 비교한다.
      const questionNum = num.toString().split("");
      const answerNum = j.toString().split("");

      //두 숫자를 비교하여 strke, ball 개수를 센다.
      for (let a = 0; a < 3; a++) {
        for (let b = 0; b < 3; b++) {
          if (a === b) {
            if (questionNum[a] === answerNum[b]) {
              strikeCount++;
            }
          }
          if (a !== b) {
            if (questionNum[a] === answerNum[b]) {
              ballCount++;
            }
          }
        }
      }

      //만약 제출자가 답한 strike, ball 개수와 다르다면 그 숫자는 정답이 될 수 없으므로 false를 넣는다.
      if (strikeCount !== strike || ballCount !== ball) {
        answer[j] = false;
      }
    }
  }

  console.log(
    answer.filter((el, index) => index >= 123 && index <= 987 && el === true)
      .length
  );
}

main();

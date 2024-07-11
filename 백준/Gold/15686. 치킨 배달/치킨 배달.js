const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N, M] = input[0].split(" ").map(Number);
//const [M] = input[2].split(" ").map(Number);
//const arr = input.slice(1).map(Number);
//const arr = input[1].split(" ").map(Number);
const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));
//const [start, end] = input[M + 2].split(" ").map(Number);

const getCombinations = function (arr, selectNumber) {
  const results = [];
  if (selectNumber === 1) return arr.map((value) => [value]); // 1개씩 택할 때, 바로 모든 배열의 원소 return

  arr.forEach((fixed, index, origin) => {
    const rest = origin.slice(index + 1); // 해당하는 fixed를 제외한 나머지 뒤
    const combinations = getCombinations(rest, selectNumber - 1); // 나머지에 대해서 조합을 구한다.
    const attached = combinations.map((combination) => [fixed, ...combination]); //  돌아온 조합에 떼 놓은(fixed) 값 붙이기
    results.push(...attached); // 배열 spread syntax 로 모두다 push
  });

  return results; // 결과 담긴 results return
};

function main() {
  //만약에 치킨집이 m개 이하면 그냥 그대로 최솟값구하고
  //m개보다 많으면 줄여야하는데
  //현재 치킨집 중에 m개를 뽑은 경우의 수를 모두 구해서
  //각 경우마다 도시의 치킨거리 최솟값을 구하는데
  //이미 앞 경우보다 치킨거리 값이 커지면 continue

  //치킨집 좌표 구하기
  const chickenPos = [];
  //집 좌표 구하기
  const homePos = [];
  for (let r = 0; r < N; r++) {
    for (let c = 0; c < N; c++) {
      if (map[r][c] === 2) {
        chickenPos.push([r, c]);
      }
      if (map[r][c] === 1) {
        homePos.push([r, c]);
      }
    }
  }
  const cases = getCombinations(chickenPos, M);

  let cityTotalDist = 1000000;

  for (let i = 0; i < cases.length; i++) {
    let sum = 0;
    //집 위치들
    for (let k = 0; k < homePos.length; k++) {
      const [curHomeR, curHomeC] = homePos[k];
      let minDist = 102;

      //한 집당 각 치킨 집과의 거리를 비교해서 가장 짧은 거리 계산
      for (let j = 0; j < M; j++) {
        const [curChickenR, curChickenC] = cases[i][j];
        const curDist =
          Math.abs(curChickenR - curHomeR) + Math.abs(curChickenC - curHomeC);
        minDist = Math.min(minDist, curDist);
      }
      sum += minDist;
      if (sum > cityTotalDist) {
        break;
      }
    }

    cityTotalDist = Math.min(sum, cityTotalDist);
  }

  console.log(cityTotalDist);
}

main();

function solution(progresses, speeds) {
    var answer = [];
    let times = [];
    //각 progress가 완성되는데 걸리는 날짜(시간)를 계산해서 배열에 넣는다.
    progresses.forEach((progress, index) => {
        times.push(Math.ceil((100-progress)/speeds[index])); //올림처리
    });
    
    let maxTime = times[0]; 
    let count = 0; //하루에 같이 처리되는 progress의 개수
    //let time = times[0];
    
    while(times.length > 0) {  
        let time = times.shift(); //가장 앞의 요소를 가져와서
        if(maxTime >= time) { //만약 앞의 progress가 아직 안 끝난 상태라면
            count++;
        }
        else { //앞의 progress가 끝난 상태면
            answer.push(count); //해당 요소 뒤에 밀린 progress가 있다면 같이 처리한다.
            maxTime = time;
            count = 1;
        }
    }
    answer.push(count);
    return answer;
}
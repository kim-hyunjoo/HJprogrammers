//https://school.programmers.co.kr/learn/courses/30/lessons/92341?language=cpp

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

//주차요금 계산하는 함수 분리하기
int calculator(int inTime, int outTime, vector<int> fees) {
    int fee;
    int parkingTime = outTime - inTime;

    if(parkingTime <= fees[0]) { //기본요금만 내면 되는경우
        fee = fees[0];
    }
    else {
        int surCharge = ((parkingTime - fees[0])/fees[2])*fees[3];
        fee = fees[1] + surCharge;
    }
    return fee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    //출차된 내역이 없으면 23:59에 출차되었다고 간주함.
    
    //차번호와 IN 시간을 기록함
    unordered_map<string, string> parkingIN;
    //차번호와 총 요금 계산
    //unordered_map<string, int> result_fee;
    //차번호와 총 주차시간 기록
    unordered_map<string, int> parking_time;
    //들어온 차 리스트
    vector<string> car_list;

    //만약 3번째 원소가 IN 이라면 차번호와 들어온 시간 저장
    //만약 OUT이라면 그 차량의 IN했던 시간을 찾아서 계산함
    //다시 IN하게되면 또 기록 만약에 끝까지 OUT이 안나온경우.. 23:59 OUT으로 간주
    //현재 주차장 안에 있는 차량 리스트를 만든 뒤
    
    for(int i=0;i<records.size();i++) {
        stringstream ss(records[i]);
        string time, carNum, state; //시간, 차번호, 상태
        ss >> time >> carNum >> state; //문자열 나누기
        if(state == "IN") {
            parkingIN.emplace(carNum, time);
            car_list.push_back(carNum);
        }
        else {
            string in = parkingIN[carNum];
            //분단위로 계산
            int inTime = 60 * stoi(in.substr(0,2)) + stoi(in.substr(3,2));
            int outTime = 60 * stoi(time.substr(0,2)) + stoi(time.substr(3,2));
            
            int total = outTime - inTime;
            /*
            if(parkingTime <= fees[0]) { //기본요금만 내면 되는경우
                result_fee.emplace(carNum, fees[1]);
            }
            else {
                int surCharge = ((parkingTime - fees[0])/fees[2])*fees[3];
                result_fee.emplace(carNum, fees[1] + surCharge);
            }
            */
           //처음 주차 하는게 아니라 이미 있는거면 누적...
            if(parking_time.find(carNum)!= parking_time.end()) {
                parking_time[carNum] += total;
            }
            else {
                parking_time.emplace(carNum, total);
            }
            
            //주차장 리스트에서 삭제
            parkingIN.erase(carNum);
        }
    }
    //아직 IN에 남아있는 애들 23:59 OUT 으로 처리해서 계산
    unordered_map<string, string> :: iterator it;
    for(it = parkingIN.begin(); it != parkingIN.end(); it++) {
        //차를 어떻게 찾아내지...? 
        string carNum = it->first;
        string in = parkingIN[carNum];
        int inTime = 60 * stoi(in.substr(0,2)) + stoi(in.substr(3,2));
        int outTime = 60 * 23 + 59;
        int total = outTime - inTime;
        if(parking_time.find(carNum)!= parking_time.end()) {
            parking_time[carNum] += total;
        }
        else {
            parking_time.emplace(carNum, total);
        }
    }


    //각 차마다 주차요금 계산하기! 차량번호 순서대로 계산
    sort(car_list.begin(), car_list.end());
    car_list.erase(unique(car_list.begin(), car_list.end()), car_list.end());
    

    for(string carNum : car_list) {
        int fee = 0;
        int total = parking_time[carNum];
        if(total <= fees[0]) { //기본요금만 내면 되는경우
            fee = fees[1];
        }
        else {
            int tmp = (total - fees[0])/fees[2];
            if((total - fees[0])%fees[2] != 0){
                tmp+=1;
            }
            int surCharge = tmp * fees[3];
            fee = fees[1] + surCharge;
        }
        answer.push_back(fee);
    }

    return answer;
}

int main() {
    vector<int>fees1 = {180, 5000, 10, 600};
    vector<int>fees2 = {120, 0, 60, 591};
    vector<int>fees3 = {1, 461, 1, 10};

    vector<string> records1 = {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", 
    "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", 
    "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};
    vector<string> records2 = {"16:00 3961 IN","16:00 0202 IN","18:00 3961 OUT",
    "18:00 0202 OUT","23:58 3961 IN"};
    vector<string> records3 = {"00:00 1234 IN"};

    vector<int> result1 = solution(fees1, records1);
    vector<int> result2 = solution(fees2, records2);
    vector<int> result3 = solution(fees3, records3);

    for(int i : result1) {
        cout << i <<endl;
    }
    for(int i : result2) {
        cout << i <<endl;
    }
    for(int i : result3) {
        cout << i <<endl;
    }
}
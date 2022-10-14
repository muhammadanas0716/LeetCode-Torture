//You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the birth and death years of the ith person.
//The population of some year x is the number of people alive during that year. The ith person is counted in year x's population if x is in the inclusive range [birthi, deathi - 1]. Note that the person is not counted in the year that they die.
//Return the earliest year with the maximum population.
//
//
//Example 1:
//
//Input: logs = [[1993,1999],[2000,2010]]
//Output: 1993
//Explanation: The maximum population is 1, and 1993 is the earliest year with this population.
//Example 2:
//
//Input: logs = [[1950,1961],[1960,1971],[1970,1981]]
//Output: 1960
//Explanation: 
//The maximum population is 2, and it had happened in years 1960 and 1970.
//The earlier year between them is 1960.
// 
//
//Constraints:
//
//1 <= logs.length <= 100
//1950 <= birthi < deathi <= 2050

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int arr[101]={0};
        
        for(vector<int> log : logs){
            arr[log[0] - 1950]++;
            arr[log[1] - 1950]--;
        }
        int max = 0, year, cnt = 0;
        
        for(int i = 0; i < 101; i++){
            cnt += arr[i];
            if(cnt > max){
                max = cnt;
                year = i;
            }
        }
        return year + 1950;
    }
};

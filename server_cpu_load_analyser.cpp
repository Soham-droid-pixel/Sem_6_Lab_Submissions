/*
Problem: The Server CPU Load Analyzer
The Scenario: You are building a monitoring dashboard for a cloud provider. The server logs track the continuous change in CPU load every minute. A positive number means the load increased (e.g., +4 means a spike in traffic), and a negative number means the load decreased (e.g., -2 means tasks finished).

The DevOps team needs to find the specific continuous timeframe where the server experienced the most severe cumulative spike in CPU load.

You are given an array of these minute-by-minute changes: [ -2, 1, -3, 4, -1, 2, 1, -5, 4 ].

The Objective:
Write a function find_max_load_spike(vector<int>& logs) that returns the maximum total load accumulated during any continuous sequence of minutes.
*/
#include<bits/stdc++.h>
using namespace std;

int find_max_load_spike(const vector<int>& logs) {
     int current_load=0;
     int max_load=INT_MIN;
     for(int i=0;i<logs.size();i++){
        current_load+=logs[i];
        max_load=max(max_load,current_load);
        if(current_load<0){
            current_load=0;
        }
        
     }   
    
    return max_load; 
}

int main() {
    
    vector<int> logs = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    int max_spike = find_max_load_spike(logs);
    
    cout << "Calculated Max Spike: " << max_spike << endl;
    cout << "Expected Max Spike: 6" << endl;
    
    if (max_spike == 6) {
        cout << "Status: PASSED!" << endl;
    } else {
        cout << "Status: FAILED. Keep trying!" << endl;
    }
    
    return 0;
}
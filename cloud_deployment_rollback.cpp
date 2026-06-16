/*
Problem: The Cloud Deployment Rollback
The Scenario: You are managing the deployment pipeline for a large-scale course allocation web application. Throughout the day, your team has pushed n consecutive versions of the app to the live server. The versions are numbered sequentially from 1 to n.

A critical routing bug was just reported in the latest version. Because of how the code is structured, you know that once this bug was introduced in a specific version, every single version deployed after it is also broken.

You are provided with a pre-built helper function, bool is_broken(int version_number), which queries the server logs and returns true if that version contains the bug, and false if the version is stable.

Server query calls are expensive and slow. To minimize downtime, you need to find the exact version number where the bug was first introduced, making the absolute minimum number of calls to the is_broken() API.

The Operations:

is_broken(int version_number): Pre-existing API. Returns true or false. (You do not need to write this function, just call it).

find_first_broken_version(int n): The function you need to write. It receives the total number of versions (n) and must return the integer of the first broken version.*/
#include<bits/stdc++.h>
using namespace std;

int hidden_bug_version = 4; 

bool is_broken(int version_number) {
    if (version_number >= hidden_bug_version) {
        return true;
    }
    return false;
}

int main(){
    int n;
    cout << "Enter no of versions: " << endl;
    cin >> n;
    
    int left = 1;
    int right = n;
    int earliest_broken = -1;
    
    while(left <= right){
        int mid = left + (right - left) / 2;
        
        if(is_broken(mid)){
            earliest_broken = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    
    if (earliest_broken != -1) {
        cout << "The bug was first introduced in version: " << earliest_broken << endl;
    } else {
        cout << "Didn't find out the bug version" << endl;
    }
    
    return 0;
}
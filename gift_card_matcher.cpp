#include<bits/stdc++.h>
using namespace std;

int main() {
    int gift_card_balance;
    cout << "Enter gift card balance: " << endl;
    cin >> gift_card_balance;

    int n;
    cout << "Enter size of menu: " << endl;
    cin >> n;

    
    vector<int> menu_prices(n);
    cout << "Enter menu prices: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> menu_prices[i];
    }

    unordered_map<int, int> seen;
    
    for(int i = 0; i < n; i++) {
        int complement = gift_card_balance - menu_prices[i];
        
        
        if (seen.find(complement) != seen.end()) {
            cout << "Item indices found: " << endl;
            cout << seen[complement] << " and " << i << endl;
            return 0;
        }
        
        seen[menu_prices[i]] = i;
    }
    
    cout << "No matching pair found." << endl;
    return 0;
}
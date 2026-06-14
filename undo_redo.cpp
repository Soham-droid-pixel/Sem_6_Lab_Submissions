#include<bits/stdc++.h>
using namespace std;

stack<char> box1;
stack<char> box2;

void undo() {
    if (box1.empty()) {
        cout << "Nothing to undo!" << endl;
        return;
    }
    char last_action = box1.top(); 
    box2.push(last_action);
    box1.pop();
}

void redo() {
    if (box2.empty()) {
        cout << "Nothing to redo!" << endl;
        return;
    }
    char last_undone = box2.top();
    box1.push(last_undone);
    box2.pop();
}

void printText() {
    stack<char> temp = box1;
    string result = "";
    
    while (!temp.empty()) {
        result += temp.top();
        temp.pop();
    }
    
    reverse(result.begin(), result.end());
    cout << "Current Text: [" << result << "]" << endl;
}

int main() {
    string text;
    cout << "Enter text to type:" << endl;
    cin >> text;
    
    for(int i = 0; i < text.size(); i++){
        box1.push(text[i]);
    }
    
    printText();
    
    int flag;
    cout << "\nEnter 0 to Undo, 1 to Redo (or any other number to quit):" << endl;
    
    while (cin >> flag) {
        if (flag == 0) {
            undo();
        } else if (flag == 1) {
            redo();
        } else {
            break;
        }
        printText();
        cout << "\nEnter 0 to Undo, 1 to Redo (or any other number to quit):" << endl;
    }
    
    return 0;
}
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for(int i = 0; i < operations.size();i++){
            if(operations[i] == "C")s.pop();
            else if(operations[i] == "D")s.push(s.size() == 0 ? 0 : 2 * s.top());
            else if(operations[i] == "+"){
                if(s.size() > 1){
                    int aux = s.top();
                    s.pop();
                    int value = s.top() + aux;
                    s.push(aux);
                    s.push(value);
                }
                else s.push(s.top());
            }
            else s.push(stoi(operations[i]));
        }
        int ans = 0;
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};


// Python accept - stack in python

// class Solution:
//     def calPoints(self, operations: List[str]) -> int:
//         r, ans = [], 0
//         for operation in operations:
//             if operation == 'C':
//                 ans -= r[-1]
//                 r.pop()
//             elif operation == 'D':
//                 ans += 2 * r[-1]
//                 r.append(2 * r[-1])
//             elif operation == '+':
//                 ans += r[-1] + r[-2]
//                 r.append(r[-1] + r[-2])
//             else:
//                 r.append(int(operation))
//                 ans += int(operation)
//         return ans

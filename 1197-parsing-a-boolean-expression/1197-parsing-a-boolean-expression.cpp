class Solution {
public:

    bool evaluate(bool val, char op, char operand){
        bool operandVal;
        if(operand == 't') operandVal = true;
        else operandVal = false;

        if(op == '!') return !(operandVal);

        if(op == '&'){
            val = val and operandVal;
        }else{
            val = val or operandVal;
        }

        return val;
    }

    bool parseBoolExpr(string expression) {
        // expression[i] is one following characters: 
        // '(', ')', '&', '|', '!', 't', 'f', and ','.
        stack<char> operandStack;
        stack<char> operatorStack;

        int n = expression.length();
        int i = 0;
        while(i < n){
            char token = expression[i];

            if(token == '!' or token == '&' or token == '|'){
                operatorStack.push(token);
            }else if(token == 'f' or token == 't' or token == '('){
                operandStack.push(token);
            }else if(token == ')'){
                // So, now we need to evaluate the operands till we hit a (.
                // But which operator to use here? See, if operator is a !,
                // then we will have only one operand for sure (till we hit '(').

                char op = operatorStack.top(); operatorStack.pop();

                // Now, see AND OR NOT all are same L to R or R to L.
                // a ^ b = b ^ a also same for OR.

                bool val;

                if(op == '&') val = true;
                else if(op == '|') val = false;
                else val = true; // Does not matter for !.

                while(operandStack.top() != '('){
                    val = evaluate(val, op, operandStack.top());
                    operandStack.pop();
                }
                // So, operandStack.top(). is ( now. Pop it too.
                operandStack.pop();

                // Now, based on this value we push it in operandStack.
                if(val) operandStack.push('t');
                else operandStack.push('f');
            }else{
                // So, it is a comma. No need to do anything with it.
                cout << "It is a comma" << endl;
            }

            i++;
        }

        char ch = operandStack.top();
        if(ch == 't') return true;
        return false;
    }
};
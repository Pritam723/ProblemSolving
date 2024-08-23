class Solution {
    public:

        pair<int, int> getND(string fraction){
            // Thins will handle negative fractions also
            // Ex. -3/4 will give {-3,4}.
            int n = fraction.length();
            int i = 0;
            while(fraction[i] != '/') i++;
            // So, we can use substr function now.
            // Ex. 12/33 will have i = 2.
            int numerator = stoi(fraction.substr(0, i));
            int denominator = stoi(fraction.substr(i+1, n-i-1));

            return {numerator, denominator};
        }

        int getGCD(int a, int b){
            int t = max(a,b);
            b = min(a,b);
            a = t;
    
            // Always make a the bigger number, b the smaller.
            while(b > 0){
                if(a % b == 0) return b; // For example 64, 16.
                t = b; // So t is 16
                b = a - (a/b)*b; // Ex. a = 72, b = 16. So newb = 8.
                // And make a = oldb now.
                a = t;
            }
            return a;
        }

        string calculate(string op1, string op2){
            pair<int, int> nd1 = getND(op1);
            pair<int, int> nd2 = getND(op2);

            int numerator1 = nd1.first;
            int denominator1 = nd1.second;

            int numerator2 = nd2.first;
            int denominator2 = nd2.second;

            // Now to calculate we need LCM of denominators first.
            // Since we are multiplying, use long long for safety.
            int gcd = getGCD(denominator1, denominator2);
            long long lcm_long = ((long long)denominator1 * (long long)denominator2)/(long long)gcd;
            int lcm = (int)lcm_long; // As per question all operation will be in integer range.

            // Ex. 1/2 + 1/3 will have lcm = 6. Ans will be (3 + 2)/6

            int denominator = lcm;
            int numerator = (lcm/denominator1)*numerator1 + (lcm/denominator2)*numerator2; // We have made every operaor = "+".
            // if(operator == "+") numerator = (lcm/denominator1)*numerator1 + (lcm/denominator2)*numerator2;
            // else numerator = (lcm/denominator1)*numerator1 - (lcm/denominator2)*numerator2;

            // So, this is the new numerator. LCM is the new denominator. So, we can do one thing better.
            // Suppose we got 3/12, so we can make it 1/4 instead. For that we want gcd(n,d) first.
            // Also be careful about the sign of numerator. And also if numerator == 0, return rightaway.

            if(numerator == 0) return to_string(numerator) + "/1"; // Ex. we return 0/4 or 0/1 it is same thing.
            // Otherwise we can divide both with their gcd and then return.

            // bool isNegative = (numerator < 0);

            int gcd_nd = getGCD(abs(numerator), abs(denominator));

            return to_string(numerator/gcd_nd) + "/" + to_string(denominator/gcd_nd);
            // Negatives will be handled also so no need to worry.
        }
    
        string fractionAddition(string expression) {
            
            // pair<int, int> p = getND("-30/6");
            // cout << p.first << " " << p.second << endl;

            // cout << expression.substr(0,3) << " " << stoi("-334") << endl;
            // return "-1";
            // See, we have + and - only.
            // Both are Left associative. Also we do not have ( or )
            // So, No need to keep a stack. Just use op1 and op2
            // and a operator. new op1 will be = (op1 operator op2).
            // new op2 will be next operand at right.

            // Wrong approach:
            // expression = "-1/2+1/2+1/3". See there will never
            // be expression like -(-1/3), it will be 1/3 only.
            // So, + and - can be thought of as binary operator only.
            // For first - sign, just append a 0/1 infornt.
            // So, now each operand is positive only.
            
            // Problem: Say we have -3/4 + 1/2, so we make it
            // 0/1 - 3/4 and it gives -3/4 again and we add 0/1
            // again, so we fall in loop.
            
            // Correct Approach:
            //So, better to move the negative sign
            // to numerator only. And always use + as the operator.
            // Even for -1/2 - 1/3 we can treat it as (-1/2) + (-1/3).
            // That way we always need to perform addition only.


            // So, we have made a calculate function which does the job for 2
            // operators. operand will always be considered as "+" so no worry.
            // Just figure out the 2 operands with proper sign.
            if(expression[0] != '-') expression = "+" + expression;
            
            int n = expression.length();
            int i = 0;
            
            string op1, op2;
            // At each step we make the next op1 using calculate(op1, op2)
            // Also we figure out the op2 for this stage. op1 we get from
            // previous step only. Surely we can take op1 = "0/1" initially.
            op1 = "0/1";

            while(i < n){
                // If the start sign is +, no need to worry.
                // If it is -, consider it as part of numerator.
                char token = expression[i];
                string sign = "";
                if(token == '-') sign = "-";
                // In case the sign is + no need to worry.
                i = i + 1;
                // Now, surely we are standing at numerator's first char.
                int j = i;
                while(j < n && (expression[j] != '-' && expression[j] != '+')) j++;
                // We are here means either j is n or j is pointing to - or + i.e., next op.

                op2 = sign + expression.substr(i, j - i);

                i = j;
                // cout << op1 << " and " << op2 << " calling " << endl;
                op1 = calculate(op1, op2);
            }

            return op1;

        }
    };
class Solution {
public:
    char sol(int n, int k, int L){
        // L is the length actually.
        if(n == 1) return '0';
        int mid = (L+1)/2;
        if(k == mid) return '1';

        if(k < mid) return sol(n-1, k, (L-1)/2);
        // Can write L/2 too as it is interger division.

        // Otherwise k > mid. So, we need to see how far
        // it is from mid.
        // int dist = k - mid;
        // So, in S(i-1) it will be dist bit from last. Ex.
        // S4, k = 11, mid is 8. So, dist = 3. So, in S3
        // which has Size = L/2 (Integer Div), it will be
        // bit # = L/2 - 3 + 1 = 7-3+1 = bit 5.
        // So, actually we can write mid - dist = 2*mid - k.
        // That will take care of the reverse part, for inverse
        // we need to see what we are getting back. If we get '0'
        // return '1', opposite otherwise.

        char ch = sol(n-1, 2*mid - k, (L-1)/2);

        if(ch == '0') return '1';
        return '0';
    }
    char findKthBit(int n, int k) {
        // First of all reverse(inverse(x)) = inverse(reverse(x)).
        // See the pattern, Sn has length = 2^n - 1.
        // Now, see the idea here. Say we want S4's k = 11th bit.
        // WKT, S4 = S3 + "1" + rev(inv(S3)) has length = 15.
        // Now, since k > (15+1)/2 i.e., in the right part so,
        // Actual answer f(S4, 11) must be equal to inverse(f(S3, 5)).
        // Can write it 1 - f(S3, 5). Why 5-th bit of S3? Because S3 has
        // length 7. So, 5-th bit of S3 when reversed will become 3rd bit.
        // So, in S4 it contributes to bit no. 7 + 1 + 3 = 11.

        // If we wanted k = 8 of S4, i.e., k == (L+1)/2, we can directly return 1
        // because middle bit of any Si is 1. So, it is the base case.

        // Now, if we want k = 5 of S4. So, we know that f(S4, 5) must be
        // equal to f(S3, 5) only.

        // Also another base case is if n = 1, return "0" as S1 = "0" only.
        int L = pow(2, n) - 1;
        return sol(n,k,L);
        
    }
};
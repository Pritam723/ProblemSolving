class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int s = 0;
        int e = n - 1;

        // A container is made with width * height.
        // Height is always = min(height[s], height[e]).
        // And Width is e - s.
        // Surely we can stop when s == e.
        int maxArea = 0;
        while(s < e){
            int h = min(height[s], height[e]);
            int w = e - s;

            int area = h * w;

            maxArea = max(area, maxArea);

            // Now we need to move the pointers.

            if(height[s] <= height[e]) s++;
            else e--;
        }

        return maxArea;
    }
};
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int s = 0;
        int e = heights.size()-1;

        int maxArea = 0;

        while(s<e){
            int width = e-s;
            int height = min(heights[s],heights[e]);

            maxArea = max(maxArea,width*height);

            if(heights[s]<heights[e])s++;
            else e--;
        }

        return maxArea;
    }
};

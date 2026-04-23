class Solution {
public:
    int trap(vector<int>& height) {
        /*
        We have 2 cases for success:
            in an interval [l,r]
            either we reach first r where el[r] >= el[l] 
                then in we from el[l] we subtract each element in ]l,r[ and sum
                then we set l to r and continue searching
            or we didn't reach such element in that case we get first element el[r] > el[r+1]
                then sum the difference of each
                then we set l to r and continue 
        */
        int ans = 0;
        for(int l = 0; l < height.size(); l++) {
            int potential_ans = 0 , firstGreaterElement = -1;
            bool found_larger = false;
            for(int r = l + 1; r < height.size(); r++) {
                if(height[r] >= height[l]) {
                    ans += potential_ans;
                    found_larger = true;
                    l = r - 1;
                    break;
                } else {
                    potential_ans += height[l] - height[r];
                }
                if(height[r] > height[r - 1] && r - 1 != l) {
                    firstGreaterElement = r;
                }
            }
            for(int r = l + 1; found_larger == false && r < firstGreaterElement; r++) {
                ans += max(height[firstGreaterElement] - height[r],0);
                cout << firstGreaterElement << endl;
                l = firstGreaterElement;
            }

        }
        return ans;
    }
};

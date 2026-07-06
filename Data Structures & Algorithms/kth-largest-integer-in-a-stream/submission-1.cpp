#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
class KthLargest {
public:
    typedef tree<
        int,                                    
        null_type,                            
        greater_equal<int>,                             
        rb_tree_tag,                          
        tree_order_statistics_node_update     
    > ordered_set;
    ordered_set st;
    int value = 0;
    KthLargest(int k, vector<int>& nums) {
        this->value = k;
        for(auto x:nums) st.insert(x);
    }
    
    int add(int val) {
        st.insert(val);
        return *st.find_by_order(this->value - 1);
    }
};

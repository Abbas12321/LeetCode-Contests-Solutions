class Solution {
public:
    int lis(vector<int>& v){
        multiset<int> x= {v[0]};
        for(int i=1;i<v.size();i++){
            int largest= *(--x.end());
            if(v[i]>=largest) x.insert(v[i]);
            else{ auto tmp= x.upper_bound(v[i]);
                  x.erase(tmp); x.insert(v[i]);
            }
        }
        return v.size()-x.size();
    }
    int kIncreasing(vector<int>& arr, int k) {
        int ans=0;
        for(int i=0;i<k;i++){
            vector<int> sub;
            for(int j=i;j<arr.size();j+=k){ sub.push_back(arr[j]);}
            ans+= lis(sub);
        }
        return ans;
    }
};

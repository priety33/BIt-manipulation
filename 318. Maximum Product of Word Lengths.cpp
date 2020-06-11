class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans=0;
        vector<int> v;
        for(auto w: words) {
            int n=0;
            for(auto i: w) {
                n= n|1<<(i-'a');
            }
            v.push_back(n);
        }
        for(int i=0; i<v.size(); i++) {
            for(int j=i+1; j<v.size(); j++) {
                if((v[i]&v[j])==0) ans=max(ans, (int)words[i].size()*(int)words[j].size());
            }
        }
        return ans;
    }
};

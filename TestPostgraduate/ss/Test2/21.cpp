#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        vector<int> vec(mat[0]);
        for(int i = 1; i < mat.size(); i++){
            multiset<int> mu;
            for(int v: vec)
                for(int m: mat[i])
                    mu.insert(v + m);
            vec.assign(mu.begin(), mu.end());
            vec.resize(min(k, (int)vec.size()));
        }
        return vec[k-1];
    }
};
int main(){
    int m, n,data,k;
    vector<vector<int> > mat;
    cin>>m>>n;
    for(int i=0; i<m; i++){
        vector<int> row;
        for(int j=0; j<n; j++){
            cin>>data;
            row.push_back(data);
        }
        mat.push_back(row);
    }
    cin>>k;
    int res=Solution().kthSmallest(mat,k);
    cout<<res<<endl;
    return 0;
}

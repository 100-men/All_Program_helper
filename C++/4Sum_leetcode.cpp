//problem link : https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& ar, int k) {
        sort(ar.begin(),ar.end());
        vector<vector<int>> ans1;
        int n=ar.size();
        
        set<vector<int>> temp;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int l=j+1,h=n-1;
                long long int sum=ar[i]+ar[j];
                while(l<h && l<n && h<n)
                {
                    vector<int> ans;
                    if(sum+ar[l]+ar[h]==k)
                    {
                        ans.push_back(ar[i]);
                        ans.push_back(ar[j]);
                        ans.push_back(ar[l]);
                        ans.push_back(ar[h]);
                        temp.insert(ans);
                        l++,h--;
                        
                    }
                    else if(sum+ar[l]+ar[h]<k)
                    {
                        l++;
                    }
                    else
                    {
                        h--;
                    }
                }
            }
        }
        for(auto itr:temp)
        {
            ans1.push_back(itr);
        }
        return ans1;
    }
};

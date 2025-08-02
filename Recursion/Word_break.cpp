class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       vector<bool> dp(s.size()+1,false);
       int n=s.size();
       unordered_set<string> dict(wordDict.begin(),wordDict.end());
       dp[0]=true;
       for(int i=1;i<=n;i++ )
       {
        for(int j=0;j<i;j++)
        {
          if(dp[j] && dict.count(s.substr(j,i-j)))
          {
            dp[i]=true;
          }
        }
       }
       return dp[n];
    }
};
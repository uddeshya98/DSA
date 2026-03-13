class Solution {
public:
    
    bool valid(string s){
        if(s.size()>1 && s[0]=='0') return false;
        int num = stoi(s);
        return num>=0 && num<=255;
    }
    
    void solve(int idx,int parts,string s,string curr,vector<string>&ans){
        if(parts==4 && idx==s.size()){
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        
        if(parts>=4) return;
        
        for(int len=1; len<=3 && idx+len<=s.size(); len++){
            string part = s.substr(idx,len);
            if(valid(part)){
                solve(idx+len,parts+1,s,curr+part+".",ans);
            }
        }
    }
    
    vector<string> generateIp(string &s) {
        vector<string> ans;
        solve(0,0,s,"",ans);
        return ans;
    }
};
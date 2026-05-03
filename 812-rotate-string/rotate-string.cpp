class Solution {
public:
 bool rotateString(string p, string g) {
     if (p.size() != g.size()) 
     return false;
     
     string doubled = p + p;
     return doubled.find(g) != string::npos;
 }
};
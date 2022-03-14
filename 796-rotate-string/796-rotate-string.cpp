class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())return 0;
        goal+=goal;
        return goal.find(s)!=string::npos;
        // int i,j, k=0;
//         for( i=0, j=0; i<s.size();i++)
//         {
//             for(j=0;j<s.size();j++)
//                 if(goal[i+j]!=s[j])break;
//             if(j==s.size())return true;
//         }
        
//         return false;
    }
};
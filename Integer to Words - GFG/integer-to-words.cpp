// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
  string ones[20] = { "", "one ", "two ", "three ", "four ",
                 "five ", "six ", "seven ", "eight ",
                 "nine ", "ten ", "eleven ", "twelve ",
                 "thirteen ", "fourteen ", "fifteen ",
                 "sixteen ", "seventeen ", "eighteen ",
                 "nineteen " };
      
      string tens[10] = {"", "", "twenty ", "thirty ", "forty ",
                 "fifty ", "sixty ", "seventy ", "eighty ",
                 "ninety " };
    string fun(int n, string s)
    {
        if(n==0)
            return "";
        if(n>19)
            return tens[n/10]+ones[n%10]+s;
        return ones[n] + s;
    }
    string convertToWords(long n) {
        string ans="";
        ans+=fun((n/10000000)%100, "crore ");
        ans+=fun((n/100000)%100, "lakh ");
        ans+=fun((n/1000)%100, "thousand ");
        ans+=fun((n/100)%10, "hundred ");
        if(n>100 && n%100!=0)
            ans+="and ";
        ans+= fun((n)%100,"");
        return ans;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long n;
        cin >> n;
        Solution ob;
        auto ans = ob.convertToWords(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
class Solution {
public:

    // Encodes a URL to a shortened URL.
    const string c= "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    unordered_map<string,string> l2s, s2l;
    string create_code(){
        string code="";
        for(int i=0;i<6;i++)
        {
            code+= c[rand()%62];
        }
        return "http://tinyurl.com/"+code;
    }
    string encode(string longUrl) {
        if(l2s.find(longUrl)!=l2s.end())
            return l2s[longUrl];
        string c= create_code();
        while(s2l.find(c)!=s2l.end())
            c= create_code();
        l2s[longUrl]=c;
        s2l[c]=longUrl;
        return c;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return s2l[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
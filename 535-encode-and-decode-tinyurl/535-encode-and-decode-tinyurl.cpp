class Solution {
public:

    // Encodes a URL to a shortened URL.
    const string c= "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    unordered_map<string,string> l2s, db;
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
        while(db.find(c)!=db.end())
            c= create_code();
        l2s[longUrl]=c;
        db[c]=longUrl;
        return c;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return db[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
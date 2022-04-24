class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> check_In;// id, station, entry
    unordered_map<string, pair<int, int>> check_Out; //total_time, cnt;
    UndergroundSystem(){
    } 
    void checkIn(int id, string stationName, int t){
        check_In[id]= {stationName, t};
    }
    void checkOut(int id, string stationName, int t){
        auto &x= check_In[id];
        string route= x.first+"->"+stationName;
        check_Out[route].first+= t - x.second;
        check_Out[route].second+=1;
    }
    
    double getAverageTime(string startStation, string endStation){
        string route= startStation+"->"+endStation;
        auto &x= check_Out[route];
        return (double)x.first/x.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
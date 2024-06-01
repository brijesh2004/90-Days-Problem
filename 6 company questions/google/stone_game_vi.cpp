int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<pair<int , int>>v(aliceValues.size());
        for(int i=0;i<aliceValues.size();i++){
            v[i] = {aliceValues[i]+bobValues[i], i};
        }
       int alice = 0;
       int bob = 0;
       sort(v.begin() , v.end());
       for(int i=v.size()-1;i>=0;){
          alice+=aliceValues[v[i].second];
          i--;
          if(i>=0)
          bob+=bobValues[v[i].second];
          i--;
       }
    if(alice==bob) return 0;
    if(alice>bob) return 1;
    return -1;
         
    }
	bool isEularCircuitExist(int v, vector<int>adj[]){
	    vector<int> in(v,0);
        
        for(int i=0;i<v;i++){
            for(auto x: adj[i]){
                in[x]++;
            }
        }
        
        for(int i=0;i<v;i++){
            
            if(in[i]==2 || in[i]==0)continue;
            else return 0;
        }
        return 1;
	}
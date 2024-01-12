 // https://leetcode.com/problems/find-the-winner-of-the-circular-game/?source=submission-noac
 
 
 int findTheWinner(int n, int k) {

        // ********************** method 1 using all the steps *********************************
        // queue<int>q;
        // for(int i=1;i<=n;i++){
        //   q.push(i);
        // }
        // int t=0;
        // while(q.size()>1){
        //     t++;
        //     int c = q.front();
        //     q.pop();
        //     if(t==k){
        //       t=0;
        //     }
        //     else{
        //         q.push(c);
        //     }
        // }
        // return q.front();


        // ****************************** method 2 optimize the code *************************************
      int ans = 0;
       for(int i=1;i<=n;i++){
           ans = (ans+k)%i;
       }
       return ans+1;
        
    }
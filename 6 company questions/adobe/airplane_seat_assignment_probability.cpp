// https://leetcode.com/problems/airplane-seat-assignment-probability/

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1)
         return 1.00000;
         return 0.50000;

//          Assume P(n) := P[nth person gets seat n]. The 1st person can get any seat with probability 1/n.

// 1--- If 1st person gets seat one (prob = 1/n), then the nth person will for sure get nth seat;

// 2--- If the 1st person gets seat k (prob = 1/n) for some 2 <= k <= n-1, then persons from 2 to k-1 inclusive will get their corresponding seats. There are n - (k-2+1) seats left unselected. The kth shall randomly select one from seats [1, k+1, k+2, ..., n]. The nth person has a probability P(n-k+1) to get the last seat, i.e., the nth seat

// 3--- If the 1st person get seat n (with prob = 1/n), then the nth person has no chance to get nth seat.

// To sum up, we have for n >= 2 that

// P(n) = 1/n + 1/n * P(n-1) + 1/n * P(n-2) + 1/n * P( n - k + 1) + 1/n * P(2),

// i.e.,

// nP(n) = 1 + P(n-1) + P(n-2) + ... + P(2) ---(1)

// For n + 1, we have

// (n+1) P(n+1) = 1 + P(n) + P(n-1) + ... + P(2) ---(2)

// Then (2) - (1) gives

// (n+1) P(n+1) - n P(n) = P(n)

// i.e.,

// (n+1) P(n+1) = (n+) P(n),

// hence

// P(n+1) = P(n) = ... = P(2) = 1/2.

// Post remark:

// Due to 2---, and the rule of taking seats, we can always reduce to n = 2 case.
    }
};
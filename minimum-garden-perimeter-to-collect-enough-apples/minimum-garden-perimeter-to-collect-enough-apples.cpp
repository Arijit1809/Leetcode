class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long i=1;
        for(;neededApples>0;i++){
            neededApples-=3*i*4;   //  i*4+2*i*4   -> counting sum of i and 2*i
            neededApples-=(((2*i)*(2*i-1))/2-(i*(i+1))/2)*8;   //  summation using (n*(n+1))/2   -> counting sum of all numbers between i and 2*i
        }
        return (i-1)*8;
    }
};
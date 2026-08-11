class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        {
              long long a = x;
    long long k,s=0;
    while(a!=0)
    {
        k=a%10;
        s=k+s*10;
        a=a/10;
    }  
    if(x==s) return true;
    else return false;
        }
    }

};
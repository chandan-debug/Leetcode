class Solution 
{
public:
    bool isPalindrome(string s)
    {
        // Standard function to check whether Palindrome
        int l = 0;
        int r = s.length()-1;

        while(l<=r)
        {
            if(s[l]!=s[r]) return false;
            l++; r--;
        }

        return true;
    }
    bool func(int n, int div)
    {
        // Function to Convert Given Decimal to the Base i
        string b = "";
        while(n!=0)
        {
            b+=to_string(n%div);
            n/=div;
        }    
        // Check if the base equivalent of that Number is palindrome
        return isPalindrome(b);

    }
    bool isStrictlyPalindromic(int n) 
    {
        for(int i=2; i<=n-2;i++)
        {
            int ncopy = n;
            if(func(ncopy,i)==false)
            {
                return false;
            }
        }
        return true;
    }
};
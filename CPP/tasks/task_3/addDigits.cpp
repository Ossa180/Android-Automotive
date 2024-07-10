# #Add Digits LeetCode

#Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.


class Solution {
public:
    int addDigits(int num) {
        int Dnum=0;
        int Unum=0;
        int res;
        while(num>=10)
        {   
            Unum = num%10;
            num = num /10;
            res = Unum + num;
            num = res;
        }
        return num;
    }
};

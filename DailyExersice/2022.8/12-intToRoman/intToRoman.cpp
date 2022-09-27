#include <string>

using std::string;

class Solution{
public:
    string intToRoman(int num){
        string res = "";
        while (num >= 1000){
            res.push_back('M');
            num -= 1000;
        }

        if (num >= 900){
            res.append("CM");
            num -= 900;
        }
        else if (num >= 500){
            res.push_back('D');
            num -= 500;
        }
        else if (num >= 400){
            res.append("CD");
            num -= 400;
        }
        while (num >= 100){
            res.push_back('C');
            num -= 100;
        }

        if (num >= 90){
            res.append("XC");
            num -= 90;
        }
        else if (num >= 50){
            res.push_back('L');
            num -= 50;
        }
        else if (num >= 40){
            res.append("XL");
            num -= 40;
        }
        while (num >= 10){
            res.push_back('X');
            num -= 10;
        }
        
        if (num == 9){
            res.append("IX");
            num -= 9;
        }
        else if (num >= 5){
            res.push_back('V');
            num -= 5;
        }
        else if (num == 4){
            res.append("IV");
            num -= 4;
        }
        while (num >= 1){
            res.push_back('I');
            num -= 1;
        }

        return res;
    }
};
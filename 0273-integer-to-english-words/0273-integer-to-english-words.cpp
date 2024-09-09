class Solution {
public:
   map<int, string> createMap() {
    map<int, string> mp;

    // Numbers 1 to 19
    mp[1] = "One"; mp[2] = "Two"; mp[3] = "Three";
    mp[4] = "Four"; mp[5] = "Five"; mp[6] = "Six";
    mp[7] = "Seven"; mp[8] = "Eight"; mp[9] = "Nine";
    mp[10] = "Ten"; mp[11] = "Eleven"; mp[12] = "Twelve";
    mp[13] = "Thirteen"; mp[14] = "Fourteen"; mp[15] = "Fifteen";
    mp[16] = "Sixteen"; mp[17] = "Seventeen"; mp[18] = "Eighteen";
    mp[19] = "Nineteen";
    
    // Tens places
    mp[20] = "Twenty"; mp[30] = "Thirty"; mp[40] = "Forty";
    mp[50] = "Fifty"; mp[60] = "Sixty"; mp[70] = "Seventy";
    mp[80] = "Eighty"; mp[90] = "Ninety";
    
    return mp;
}

    string convertHundreds(int num, map<int, string>& mp) {
    string result = "";
    if (num >= 100) {
        int hundreds = num / 100;
        result += mp[hundreds] + " Hundred";
        num %= 100;
        if (num > 0) result += " ";
    }
    if (num > 0) {
        if (num <= 19) {
            result += mp[num];
        } else {
            int tens = (num / 10) * 10;
            result += mp[tens];
            num %= 10;
            if (num > 0) {
                result += " " + mp[num];
            }
        }
    }
    return result;
}

string numberToWords(int num) {
    if (num == 0) return "Zero";

    map<int, string> mp = createMap();
    string result = "";

    // Billion
    if (num >= 1000000000) {
        int billions = num / 1000000000;
        result += convertHundreds(billions, mp) + " Billion";
        num %= 1000000000;
        if (num > 0) result += " ";
    }

    // Million
    if (num >= 1000000) {
        int millions = num / 1000000;
        result += convertHundreds(millions, mp) + " Million";
        num %= 1000000;
        if (num > 0) result += " ";
    }

    // Thousand
    if (num >= 1000) {
        int thousands = num / 1000;
        result += convertHundreds(thousands, mp) + " Thousand";
        num %= 1000;
        if (num > 0) result += " ";
    }

    // Remaining hundreds, tens, and ones
    if (num > 0) {
        result += convertHundreds(num, mp);
    }

    return result;
}

};
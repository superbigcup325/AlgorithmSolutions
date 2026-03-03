#include<bits/stdc++.h>
using namespace std;

class  bigInt {
public:
    vector<int> digits;// 低位在前，高位在后
    bigInt () {}
    bigInt(long long num) {
        while (num>0) {
            digits.push_back(num%10);
            num/=10;
        }
        if (digits.size()==0) {
            digits.push_back(0);
        }
    }
    bigInt(string& num) {
        int len = num.length();
        for (int i=len-1;i>=0;i--) {
            digits.push_back(num[i]);
        }
    }
    bigInt operator+(const bigInt& other) const {
        bigInt result;
        long long alen=digits.size(),blen=other.digits.size();
        long long len=max(alen,blen);
        int carry=0;
        for (int i=0;i<len||carry;i++) {
            int sum=carry;
            if (i<alen) sum+=digits[i];
            if (i<blen) sum+=other.digits[i];
            result.digits.push_back(sum%10);
            carry=sum/10;
        }
        return result;
    }
    bigInt operator-(const bigInt& other) const {
        bigInt result=*this;
        int borrow=0;
        int len=result.digits.size(),olen=other.digits.size();
        for (int i=0;i<len;i++) {
            int sub=(i<olen? other.digits[i]:0)+borrow;
            if (sub>result.digits[i]) {
                result.digits[i]+=10-sub;
                borrow=1;
            }
            else {
                result.digits[i]-=sub;
                borrow=0;
            }
        }
        return result;
    }
    bigInt operator*(const bigInt& other) const {
        bigInt result;
        long long alen=digits.size(),blen=other.digits.size();
        result.digits.resize(alen+blen,0);
        for (int i=0;i<alen;i++) {
            long long carry=0;
            for (int j=0;j<blen||carry;j++) {
                long long sum=result.digits[i+j]+carry;
                if (j<blen) sum+=static_cast<long long>(digits[i])*other.digits[j];// 同加法一样进位处理
                result.digits[i+j]=sum%10;
                carry=sum/10;
            }
        }
        while (result.digits.size()>1&&result.digits.back()==0) {}
        return result;
    }
    bigInt operator/(int divisor) const {
        bigInt result;
        long long len=digits.size();
        long long remainder=0;
        for (int i=len-1;i>=0;i--) {
            remainder=remainder*10+digits[i];
            result.digits.insert(result.digits.begin(),remainder%divisor);
            remainder/=divisor;
        }
        while (result.digits.size()>1&&result.digits.back()==0) {
            result.digits.pop_back();
        }
        return result;
    }
    void print() const {
        int len=digits.size();
        for (int i=len-1;i>=0;i--) {
            cout<<digits[i];
        }
    }
};

signed main() {


    return 0;
}
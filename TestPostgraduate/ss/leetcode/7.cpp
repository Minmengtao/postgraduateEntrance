#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int pre = 0, rev = 0;
        while(x){
            if(rev > INT_MAX / 10 || (rev == INT_MAX && rev % 10 > 7))
                return 0;
            if(rev < INT_MIN / 10 || (rev == INT_MIN && rev % 10 > 8))
                return 0;
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }
};
int main(){
	int x;
	cin >> x;
	cout << Solution().reverse(x);
	return 0;
}

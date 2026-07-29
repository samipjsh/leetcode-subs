class Solution {
public:
    static const long long int LIM=1e18;
    
    long long comb(int n, int r) {
        if (r > n) return 0;
        r = min(r, n - r);

        __int128 ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans > LIM) return LIM;
        }
        return (long long)ans;
    }
    long long permutations(vector<int>& cnt) {
        int total = 0;
        for (int x : cnt)
            total += x;

        long long ways = 1;
        int rem = total;

        for (int x : cnt) {
            if (x == 0) continue;

            __int128 temp = (__int128)ways * comb(rem, x);

            if (temp > LIM)
                ways = LIM;
            else
                ways = (long long)temp;

            rem -= x;
        }

        return ways;
    }

    string smallestPalindrome(string s, long long k) {

        vector<int> freq(26,0);
        //  Count frequency of every character
        for (char c : s)
            freq[c - 'a']++;

        //Create half-frequency array
        vector<int> half(26, 0);

        //  Middle character (for odd length palindrome)
        string mid = "";

        //Build half[] and mid
        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;

            if (freq[i] % 2)
                mid.push_back('a' + i);
        }

        //Check permutations of half
        if (permutations(half) < k)
            return "";

        //Total letters in left half
        int total = 0;
        for (int x : half)
            total += x;

        string left;

        for (int j = 0; j < total; j++) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;

                long long ways = permutations(half);

                if (ways >= k) {
                    left.push_back('a' + c);
                    break;
                }

                k -= ways;

                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};
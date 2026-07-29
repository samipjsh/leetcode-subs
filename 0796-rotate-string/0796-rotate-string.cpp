class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        string check = s+s;
        return kmpSearch(check, goal);
    }

private:
    bool kmpSearch(string& text, string& pattern) {
        // Precompute the LPS (Longest Prefix Suffix) array for the pattern
        vector<int> lps = computeLPS(pattern);
        int textIndex = 0, patternIndex = 0;
        int textLength = text.size(), patternLength = pattern.size();

        // Loop through the text to find the pattern
        while (textIndex < textLength) {
            // If characters match, move both indices forward
            if (text[textIndex] == pattern[patternIndex]) {
                textIndex++;
                patternIndex++;
                // If we've matched the entire pattern, return true
                if (patternIndex == patternLength) return true;
            }
            // If there's a mismatch after some matches, use the LPS array to
            // skip unnecessary comparisons
            else if (patternIndex > 0) {
                patternIndex = lps[patternIndex - 1];
            }
            // If no matches, move to the next character in text
            else {
                textIndex++;
            }
        }
        // Pattern not found in text
        return false;
    }

    vector<int> computeLPS(string& pattern) {
        int patternLength = pattern.size();
        vector<int> lps(patternLength, 0);
        int length = 0, index = 1;

        // Build the LPS array
        while (index < patternLength) {
            // If characters match, increment length and set lps value
            if (pattern[index] == pattern[length]) {
                length++;
                lps[index++] = length;
            }
            // If there's a mismatch, update length using the previous LPS value
            else if (length > 0) {
                length = lps[length - 1];
            }
            // No match and length is zero
            else {
                lps[index++] = 0;
            }
        }
        return lps;
    }
};
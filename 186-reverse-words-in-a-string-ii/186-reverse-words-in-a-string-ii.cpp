class Solution {
public:

    // Summary: Reverse entire string. Then reverse each word within the string.
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());

        // 'start' points to the beginning of the current word
        // 'end' points to the position just after the current word
        int start = 0, end = 0;
        int n = s.size();

        while (start < n) {

            // Move 'right' to the position just after the current word
            while (end < n && s[end] != ' ')
                end++;

            // Note: in C++, reverse() operates on [start, end)
            // In other words, the leftmost element is included, while the rightmost element is not
            reverse(s.begin() + start, s.begin() + end);

            // Move 'start' and 'end' to the beginning of the next word
            end++;
            start = end;
        }
    }
};
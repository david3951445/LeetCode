#include <iostream>
using namespace std;

int lengthOfLongestSubstring(string s) {
	int len = 0; // length of each substring
	int max = 0; // max length of substrings
	int table[128] = { 0 }; // 128 is the amount of ascii code

	for (int j = 0; s[j] != '\0'; j++) {
		if (table[s[j]] != 0) { // found repeat char
			// update table (delete all char in front of table[s[j]])
			for (int i = table[s[j]] - 2; i >= j - len; i--)
				table[s[i]] = 0;

			len = j - table[s[j]] + 1; // update len
			table[s[j]] = j + 1; // update table (update table[s[j]])
		}
		else {
			table[s[j]] = j + 1;
			len++;
		}

		if (len > max)
			max = len;
	}

	return max;
}

int main()
{	
	string s = "abba";
    cout << lengthOfLongestSubstring(s) << endl;
}

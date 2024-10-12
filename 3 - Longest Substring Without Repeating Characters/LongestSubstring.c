#include <stdio.h>

#define ASCII_SIZE 128

int lengthOfLongestSubstring(char *s) {
	int last_seen[ASCII_SIZE];
	int start = 0;
	int max_length = 0;
	int index = 0;
	for (int i = 0; i < ASCII_SIZE; i++) {
		last_seen[i] = -1;
	}
	while (s[index]) {
		int ascii_index = (int)s[index];
		if (last_seen[ascii_index] >= start) {
			start = last_seen[ascii_index] + 1;
		}
		last_seen[ascii_index] = index;
		if (index - start + 1 > max_length) {
			max_length = index - start + 1;
		}
		index++;
	}
	return max_length;
}
# Maximum Length Substring With Two Occurrences

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | August 14, 2026 |
| **Tags** | Hash Table, String, Sliding Window |
| **Link** | [View Problem](https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/) |
| **Runtime** | 0 ms |
| **Memory** | 9.6 MB |

## Problem Description

Given a string <code>s</code>, return the <strong>maximum</strong> length of a <span data-keyword="substring" class=" cursor-pointer relative text-dark-blue-s text-sm"><button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-_r_r_" data-state="closed" class="">substring</button></span>&nbsp;such that it contains <em>at most two occurrences</em> of each character.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "bcbbbcba"</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>
The following substring has a length of 4 and contains at most two occurrences of each character: <code>"bcbb<u>bcba</u>"</code>.</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "aaaa"</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>
The following substring has a length of 2 and contains at most two occurrences of each character: <code>"<u>aa</u>aa"</code>.</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: 2 Approaches || All Substrings || Sliding Window
**Author**: [@AdityaRaj_cpp](https://leetcode.com/AdityaRaj_cpp/)
**Upvotes**: 24 👍
**Link**: [View Original Post](https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/solutions/4917055/)

---

# Checking All Substrings

### Approach
1. Iterate through each character of the string `s` using two nested loops. The outer loop iterates over the starting index of the substring`i`, and the inner loop iterates over the ending index of the substring`j`.
2. Count the frequency for each character and break the loop when any character appears the third time since the condition of having each character appear at most twice in the substring is violated.

```
class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++)
            {
                mp[s[j]]++;
                if (mp[s[j]] > 2)
                    break;
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
```

# Two Pointers and Sliding Window

### Approach
1. Iterates through the characters of the string s using a sliding window approach. At each step, update the map `mp` with the count of the current character.
2. If the count of the current character in the map becomes 3, enter a loop until it becomes 2. Within this loop, adjust the beginning of the substring (begin) to shrink the window until the character appears.
4. During each iteration of the loop, decrement the count of the character at the beginning of the substring in the map `mp`. If the count becomes 2 after decrementing, it indicates that the character no longer appears more than twice in the substring.

```
class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int n = s.size(), ans = 0, begin = 0, end = 0;
        map<char, int> mp;
        while (end < n)
        {
            mp[s[end]]++;
            while (mp[s[end]] == 3)
                mp[s[begin++]]--;
            ans = max(ans, end - begin + 1);
            end++;
        }
        return ans;
    }
};
```


</details>

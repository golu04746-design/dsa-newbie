# Reverse Words in a String

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 9, 2026 |
| **Tags** | Two Pointers, String |
| **Link** | [View Problem](https://leetcode.com/problems/reverse-words-in-a-string/) |
| **Runtime** | 16 ms |
| **Memory** | 50.5 MB |

## Problem Description

<p>Given an input string <code>s</code>, reverse the order of the <strong>words</strong>.</p>

<p>A <strong>word</strong> is defined as a sequence of non-space characters. The <strong>words</strong> in <code>s</code> will be separated by at least one space.</p>

<p>Return <em>a string of the words in reverse order concatenated by a single space.</em></p>

<p><b>Note</b> that <code>s</code> may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "the sky is blue"
<strong>Output:</strong> "blue is sky the"
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "  hello world  "
<strong>Output:</strong> "world hello"
<strong>Explanation:</strong> Your reversed string should not contain leading or trailing spaces.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "a good   example"
<strong>Output:</strong> "example good a"
<strong>Explanation:</strong> You need to reduce multiple spaces between two words to a single space in the reversed string.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> contains English letters (upper-case and lower-case), digits, and spaces <code>' '</code>.</li>
	<li>There is <strong>at least one</strong> word in <code>s</code>.</li>
</ul>

<p>&nbsp;</p>
<p><b data-stringify-type="bold">Follow-up:&nbsp;</b>If the string data type is mutable in your language, can&nbsp;you solve it&nbsp;<b data-stringify-type="bold">in-place</b>&nbsp;with&nbsp;<code data-stringify-type="code">O(1)</code>&nbsp;extra space?</p>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Easy and Simple C++ solution | Two Pointers ✅
**Author**: [@AyushBansalCodes](https://leetcode.com/AyushBansalCodes/)
**Upvotes**: 339 👍
**Link**: [View Original Post](https://leetcode.com/problems/reverse-words-in-a-string/solutions/5521484/)

---

# Approach

**1) Reverse the entire string:** The solution begins by reversing the entire input string `s`. This step ensures that words which were at the end of the original string are now at the beginning, and vice versa.

**2) Initialize pointers:** Three pointers are used: `left`, `right`, and `i`, all initialized to 0. The `left` and `right` pointers help in marking the start and end of each word, while `i` traverses the string.

**3) Skip leading spaces:** The outer `while` loop iterates over the string. The inner loop `while(i<n && s[i]==\' \') i++;` skips any leading spaces.

**4) Process each word:**

- **Identify word boundaries:** Once the leading spaces are skipped, the second inner loop `while(i<n && s[i]!=\' \')` identifies the current word and assigns characters to the correct position in the string starting from `right`.
- **Reverse the current word:** After identifying the word, it is reversed back to its original order within the reversed string. This reversal is done using the `reverse` function on the substring from `left` to `right`.
- **Add space after the word:** A space is added after the word to separate it from the next word.

**5) Resize the string:** After all words are processed, the string is resized to remove the trailing space added after the last word.

# Reason for the Approach

1. **Efficiency:** Reversing the entire string first allows the algorithm to process words in their final position. This avoids the need for additional data structures, making the in-place manipulation of the string possible.

2. **In-place manipulation:** This approach modifies the input string directly without requiring extra space, which is memory efficient.

3. **Simplicity:** The logic of reversing the entire string and then reversing individual words is straightforward and easy to understand.


# Complexity
- Time complexity: O(n)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(1)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

`Upvote! It only takes 1 click\uD83D\uDE09`

# Code
```
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int left = 0;
        int right = 0;
        int i = 0;
        while (i < n) {
            while (i < n && s[i] == \' \')
                i++;
            if (i == n)
                break;
            while (i < n && s[i] != \' \') {
                s[right++] = s[i++];
            }
            reverse(s.begin() + left, s.begin() + right);
            s[right++] = \' \';
            left = right;
            i++;
        }
        s.resize(right - 1);
        return s;
    }
};
```

![upvote.jpeg](https://assets.leetcode.com/users/images/48b755ae-c41b-474d-966e-aa5674e41ff4_1720943081.9620614.jpeg)

</details>

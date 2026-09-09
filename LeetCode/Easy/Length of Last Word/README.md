# Length of Last Word

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | September 9, 2026 |
| **Tags** | String |
| **Link** | [View Problem](https://leetcode.com/problems/length-of-last-word/) |
| **Runtime** | 0 ms |
| **Memory** | 9.9 MB |

## Problem Description

<p>Given a string <code>s</code> consisting of words and spaces, return <em>the length of the <strong>last</strong> word in the string.</em></p>

<p>A <strong>word</strong> is a maximal <span data-keyword="substring-nonempty" class=" cursor-pointer relative text-dark-blue-s text-sm"><button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-_r_t_" data-state="closed" class="">substring</button></span> consisting of non-space characters only.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "Hello World"
<strong>Output:</strong> 5
<strong>Explanation:</strong> The last word is "World" with length 5.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "   fly me   to   the moon  "
<strong>Output:</strong> 4
<strong>Explanation:</strong> The last word is "moon" with length 4.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "luffy is still joyboy"
<strong>Output:</strong> 6
<strong>Explanation:</strong> The last word is "joyboy" with length 6.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists of only English letters and spaces <code>' '</code>.</li>
	<li>There will be at least one word in <code>s</code>.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: 7-lines 4ms C++ Solution
**Author**: [@jianchao-li](https://leetcode.com/jianchao-li/)
**Upvotes**: 471 👍
**Link**: [View Original Post](https://leetcode.com/problems/length-of-last-word/solutions/21892/)

---

Well, the basic idea is very simple. Start from the tail of `s` and move backwards to find the first non-space character. Then from this character, move backwards and count the number of non-space characters until we pass over the head of `s` or meet a space character. The count will then be the length of the last word.

    class Solution {
    public:
        int lengthOfLastWord(string s) { 
            int len = 0, tail = s.length() - 1;
            while (tail >= 0 && s[tail] == ' ') tail--;
            while (tail >= 0 && s[tail] != ' ') {
                len++;
                tail--;
            }
            return len;
        }
    };

</details>

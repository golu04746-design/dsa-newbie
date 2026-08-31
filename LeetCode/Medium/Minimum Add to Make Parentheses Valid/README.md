# Minimum Add to Make Parentheses Valid

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | August 31, 2026 |
| **Tags** | String, Stack, Greedy, Bracket Sequences |
| **Link** | [View Problem](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/) |
| **Runtime** | 0 ms |
| **Memory** | 7.9 MB |

## Problem Description

<p>A parentheses string is valid if and only if:</p>

<ul>
	<li>It is the empty string,</li>
	<li>It can be written as <code>AB</code> (<code>A</code> concatenated with <code>B</code>), where <code>A</code> and <code>B</code> are valid strings, or</li>
	<li>It can be written as <code>(A)</code>, where <code>A</code> is a valid string.</li>
</ul>

<p>You are given a parentheses string <code>s</code>. In one move, you can insert a parenthesis at any position of the string.</p>

<ul>
	<li>For example, if <code>s = "()))"</code>, you can insert an opening parenthesis to be <code>"(<strong>(</strong>)))"</code> or a closing parenthesis to be <code>"())<strong>)</strong>)"</code>.</li>
</ul>

<p>Return <em>the minimum number of moves required to make </em><code>s</code><em> valid</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "())"
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "((("
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> is either <code>'('</code> or <code>')'</code>.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Beats 100% || Easy Self Explanatory Code || 3 Approaches
**Author**: [@Garv_Virmani](https://leetcode.com/Garv_Virmani/)
**Upvotes**: 57 👍
**Link**: [View Original Post](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/solutions/5889059/)

---

# 3 Approaches:
![image.png](https://assets.leetcode.com/users/images/23edaab9-1981-4d97-b13b-5f72e1d27c91_1728444291.3986533.png)

# Approach 1
**Time O(N) Space O(N)**
```cpp []
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> S;
        int c = 0;
        for (char i : s) {
            if (i == \'(\')
                S.push(i);
            else {
                if (S.empty())
                    c++;
                else
                    S.pop();
            }
        }
        return c + S.size();
    }
};
```

# Approach 2
**Time O(N) Space O(N)**
# Code
```cpp []
class Solution {
public:
    int minAddToMakeValid(string s) {
        string stck;
        for (auto c : s) {
            if (stck.empty())
                stck.push_back(c);

            else if (stck.back() == \'(\' && c == \')\') {
                stck.pop_back();
            } else {
                stck.push_back(c);
            }
        }
        return stck.size();
    }
};
```

# Approach 3
**Time O(N) Space O(1)**
``` cpp []
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;
        for (auto c : s) {
            if (c == \'(\') {
                open++;
            } else {
                if (open > 0)
                    open--;
                else
                    close++;
            }
        }
        return open + close;
    }
};
```

![image.png](https://assets.leetcode.com/users/images/23edaab9-1981-4d97-b13b-5f72e1d27c91_1728444291.3986533.png)



</details>

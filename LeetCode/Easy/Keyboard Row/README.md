# Keyboard Row

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | August 16, 2026 |
| **Tags** | Array, Hash Table, String |
| **Link** | [View Problem](https://leetcode.com/problems/keyboard-row/) |
| **Runtime** | 0 ms |
| **Memory** | 9.2 MB |

## Problem Description

<p>Given an array of strings <code>words</code>, return <em>the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below</em>.</p>

<p><strong>Note</strong> that the strings are <strong>case-insensitive</strong>, both lowercased and uppercased of the same letter are treated as if they are at the same row.</p>

<p>In the <strong>American keyboard</strong>:</p>

<ul>
	<li>the first row consists of the characters <code>"qwertyuiop"</code>,</li>
	<li>the second row consists of the characters <code>"asdfghjkl"</code>, and</li>
	<li>the third row consists of the characters <code>"zxcvbnm"</code>.</li>
</ul>
<img alt="" src="https://assets.leetcode.com/uploads/2018/10/12/keyboard.png" style="width: 800px; max-width: 600px; height: 267px;">
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">words = ["Hello","Alaska","Dad","Peace"]</span></p>

<p><strong>Output:</strong> <span class="example-io">["Alaska","Dad"]</span></p>

<p><strong>Explanation:</strong></p>

<p>Both <code>"a"</code> and <code>"A"</code> are in the 2nd row of the American keyboard due to case insensitivity.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">words = ["omk"]</span></p>

<p><strong>Output:</strong> <span class="example-io">[]</span></p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">words = ["adsdf","sfd"]</span></p>

<p><strong>Output:</strong> <span class="example-io">["adsdf","sfd"]</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 20</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><code>words[i]</code> consists of English letters (both lowercase and uppercase).&nbsp;</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: C++ easy solution, faster than 100%, with explaination
**Author**: [@Pooja0406](https://leetcode.com/Pooja0406/)
**Upvotes**: 32 👍
**Link**: [View Original Post](https://leetcode.com/problems/keyboard-row/solutions/373966/)

---

Have three sets each corresponding to each row of the keyboard.
For each word, check which set the first char belongs to, and set the temprory set to that set accordingly. We will then check for each char whether or not it belongs to this set and not any other set.
If yes, add to result.

*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Keyboard Row.
Memory Usage: 8.6 MB, less than 14.29% of C++ online submissions for Keyboard Row.*

```

vector<string> findWords(vector<string>& words) {
        
        unordered_set<char> set1{\'q\',\'w\',\'e\',\'r\',\'t\',\'y\',\'u\',\'i\',\'o\',\'p\'};
        unordered_set<char> set2{\'a\',\'s\',\'d\',\'f\',\'g\',\'h\',\'j\',\'k\',\'l\'};
        unordered_set<char> set3{\'z\',\'x\',\'c\',\'v\',\'b\',\'n\',\'m\'};
        vector<string> res;
            
        for(string word : words)
        {
            bool flag = true;
            unordered_set<char> setTemp;
            
            if(set1.find(tolower(word[0])) != set1.end())
                setTemp = set1;
            else if(set2.find(tolower(word[0])) != set2.end())
                setTemp = set2;
            else
                setTemp = set3;
            
            for(char ch : word)
            {
                if(setTemp.find(tolower(ch)) == setTemp.end())
                {
                    flag = false;
                    break;
                }
            }
            
            if(flag)
                res.push_back(word);
        }
        
        return res;
    }
	
	

</details>

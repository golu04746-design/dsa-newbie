# Add Binary

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | August 31, 2026 |
| **Tags** | Math, String, Bit Manipulation, Simulation |
| **Link** | [View Problem](https://leetcode.com/problems/add-binary/) |
| **Runtime** | 0 ms |
| **Memory** | 7.9 MB |

## Problem Description

<p>Given two binary strings <code>a</code> and <code>b</code>, return <em>their sum as a binary string</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> a = "11", b = "1"
<strong>Output:</strong> "100"
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> a = "1010", b = "1011"
<strong>Output:</strong> "10101"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= a.length, b.length &lt;= 10<sup>4</sup></code></li>
	<li><code>a</code> and <code>b</code> consist&nbsp;only of <code>'0'</code> or <code>'1'</code> characters.</li>
	<li>Each string does not contain leading zeros except for the zero itself.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: 1ms (Beats 100%)🔥🔥|| Full Explanation✅|| Append & Reverse✅|| C++|| Java|| Python3
**Author**: [@N7_BLACKHAT](https://leetcode.com/N7_BLACKHAT/)
**Upvotes**: 967 👍
**Link**: [View Original Post](https://leetcode.com/problems/add-binary/solutions/3183205/)

---

# Intuition :
- We have to add two binary numbers (made up of 0\'s and 1\'s) and returns the result in binary.
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach :
- We start at the right end of each binary number, adding the digits and any carry-over value, and storing the result in a new string. 
- Now we move to the next digit on the left and repeats the process until it has gone through all the digits in both binary numbers.
- If there is any carry-over value after adding all the digits,  append it to the end of the new string. 
- Finally, the new string is reversed and returned as the sum of the two binary numbers.
<!-- Describe your approach to solving the problem. -->
# Explanation to Approach :
- Suppose we want to add two binary numbers - "1010" and "1101". 
- To add these two numbers, we can use the given function as follows:
- First, we initialize a StringBuilder object to store the sum and two integer variables \'carry\' and \'i\' to keep track of the carry-over value and the current position in the first binary number (a), respectively. 
- We also initialize another integer variable \'j\' to keep track of the current position in the second binary number (b). Here is how the code initializes these variables:
```
StringBuilder sb = new StringBuilder();
int carry = 0;
int i = a.length() - 1;
int j = b.length() - 1;

```
- Next, we enter a while loop that iterates until we have processed all digits in both binary numbers and there is no more carry-over value left. In each iteration, we add the digits from both numbers at the current position and the carry-over value (if any), and append the result to the StringBuilder object. 
- We also update the carry-over value based on the sum of the digits. Here is the code for this step:
```
while (i >= 0 || j >= 0 || carry == 1) {
    if (i >= 0) {
        carry += a.charAt(i--) - \'0\';
    }
    if (j >= 0) {
        carry += b.charAt(j--) - \'0\';
    }
    sb.append(carry % 2);
    carry /= 2;
}

```
- In each iteration, the current position in each binary number is moved one digit to the left (if there are any digits left to process) by decrementing the value of i and j. 
- If there is a carry-over value from the previous iteration or the addition of the two digits produces a carry-over value, we set the value of \'carry\' to 1; otherwise, we set it to 0. 
- We also append the sum of the digits to the StringBuilder object by computing the remainder of \'carry\' divided by 2 (which is either 0 or 1). 
- Finally, we update the value of \'carry\' by dividing it by 2 (which gives either 0 or 1) so that we can carry over any remaining value to the next iteration.
- After the while loop completes, we reverse the StringBuilder object and convert it to a string using the toString() method. 
- This gives us the sum of the two binary numbers in binary format. Here is the final code:
```
return sb.reverse().toString();

```
# Example : the sum of "1010" and "1101
```
     1010
    +1101
    ______
    10111
```

# Complexity
- Time complexity : O(max|a|,|b|)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity : O(max|a|,|b|)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
# Please Upvote\uD83D\uDC4D\uD83D\uDC4D
```
Thanks for visiting my solution.\uD83D\uDE0A
```
# Codes [C++ |Java |Python3] 
```C++ []
class Solution {
 public:
  string addBinary(string a, string b) {
    string ans;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
      if (i >= 0)
        carry += a[i--] - \'0\';
      if (j >= 0)
        carry += b[j--] - \'0\';
      ans += carry % 2 + \'0\';
      carry /= 2;
    }

    reverse(begin(ans), end(ans));
    return ans;
  }
};
```
```Java []
class Solution 
{
  public String addBinary(String a, String b) 
  {
    StringBuilder sb = new StringBuilder();
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry == 1) 
    {
      if(i >= 0)
        carry += a.charAt(i--) - \'0\';
      if(j >= 0)
        carry += b.charAt(j--) - \'0\';
      sb.append(carry % 2);
      carry /= 2;
    }
    return sb.reverse().toString();
  }
}
```
```Python3 []
class Solution:
  def addBinary(self, a: str, b: str) -> str:
    s = []
    carry = 0
    i = len(a) - 1
    j = len(b) - 1

    while i >= 0 or j >= 0 or carry:
      if i >= 0:
        carry += int(a[i])
        i -= 1
      if j >= 0:
        carry += int(b[j])
        j -= 1
      s.append(str(carry % 2))
      carry //= 2

    return \'\'.join(reversed(s))
```
# Please Upvote\uD83D\uDC4D\uD83D\uDC4D
![ezgif-3-22a360561c.gif](https://assets.leetcode.com/users/images/fe5d77d5-39f2-4839-9fcf-41c50106b04f_1676347139.1033723.gif)



</details>

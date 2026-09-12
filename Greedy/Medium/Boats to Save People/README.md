# Boats to Save People

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 12, 2026 |
| **Tags** | Array, Two Pointers, Greedy, Sorting, Timsort |
| **Link** | [View Problem](https://leetcode.com/problems/boats-to-save-people/) |
| **Runtime** | 25 ms |
| **Memory** | 45.9 MB |

## Problem Description

<p>You are given an array <code>people</code> where <code>people[i]</code> is the weight of the <code>i<sup>th</sup></code> person, and an <strong>infinite number of boats</strong> where each boat can carry a maximum weight of <code>limit</code>. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most <code>limit</code>.</p>

<p>Return <em>the minimum number of boats to carry every given person</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> people = [1,2], limit = 3
<strong>Output:</strong> 1
<strong>Explanation:</strong> 1 boat (1, 2)
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> people = [3,2,2,1], limit = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> 3 boats (1, 2), (2) and (3)
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> people = [3,5,3,4], limit = 5
<strong>Output:</strong> 4
<strong>Explanation:</strong> 4 boats (3), (3), (4), (5)
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= people.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= people[i] &lt;= limit &lt;= 3 * 10<sup>4</sup></code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: ✅ C++ || 2 Pointer || Easy || Simple & Short || Algorithm
**Author**: [@knockcat](https://leetcode.com/knockcat/)
**Upvotes**: 175 👍
**Link**: [View Original Post](https://leetcode.com/problems/boats-to-save-people/solutions/1877845/)

---

# 881. Boats to Save People
**KNOCKCAT**

```
1. Easy C++
2. Line by Line Explanation with Comments.
3. Detailed Explanation \u2705
4. Inituton is to use two pointer approach,
   to make pair of lightest & heaviest person by sorting vector first.
5. Please Upvote if it helps\u2B06\uFE0F
6. Link to my Github Profile contains a repository of Leetcode with all my Solutions. \u2B07\uFE0F
	// \uD83D\uDE09If you Like the repository don\'t foget to star & fork the repository\uD83D\uDE09
```
``` ```
[LeetCode](http://github.com/knockcat/Leetcode) **LINK TO LEETCODE REPOSITORY**
``` ```

Please upvote my comment so that i get to win the 2022 giveaway and motivate to make such discussion post.
**Happy new Year 2023 to all of you**
**keep solving keep improving**
Link To comment
[Leetcode Give away comment](https://leetcode.com/discuss/general-discussion/2946993/2022-Annual-Badge-and-the-Giveaway/1734919)


**ALGORITHM**
* **Sort the Vector.**
* We can make the **lightest & heaviest person to go together.**
* using **Two pointer appraoch** **i is the lightest person** & j **is the heaviest.**
* Traversing t**ill start <= end**.
	* if **sum of lightest & heaviest person are under limit** then **both can go together** , **updating i & j both**.
	* **If sum exceeds the limit**, then **heaviest person will go alone**, hence **updating only  the j pointer.**
	* **increment the count .**
* **Return cnt.**

ANALYSIS:-
* **TIME COMPLEXITY** :- O(NlogN)
* **SPACE COMPLEXITY** :-  O(1)

``` ```
**CODE WITH EXPLANATION**
```
				// \uD83D\uDE09\uD83D\uDE09\uD83D\uDE09\uD83D\uDE09Please upvote if it helps \uD83D\uDE09\uD83D\uDE09\uD83D\uDE09\uD83D\uDE09
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
       
        // sort vector
        sort(people.begin(),people.end());
        
        int i = 0, j = people.size() - 1,cnt = 0;
        
        while(i <= j)
        {   
            // lightest person + heaviest person sum <= limit
            // they can go together
            if(people[i] + people[j] <= limit)
            {
                ++i;
                --j;
            }
            // if sum is over the limit,
            // heaviest will go alone.
            else
                --j;
            
            ++cnt;  // number of boats
        }
        
        return cnt;
        
    }
	// for github repository link go to my profile.
};
```

</details>

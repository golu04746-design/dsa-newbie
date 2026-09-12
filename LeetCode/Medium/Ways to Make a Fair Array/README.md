# Ways to Make a Fair Array

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 12, 2026 |
| **Tags** | Array, Prefix Sum |
| **Link** | [View Problem](https://leetcode.com/problems/ways-to-make-a-fair-array/) |
| **Runtime** | 2 ms |
| **Memory** | 98.3 MB |

## Problem Description

<p>You are given an integer array&nbsp;<code>nums</code>. You can choose <strong>exactly one</strong> index (<strong>0-indexed</strong>) and remove the element. Notice that the index of the elements may change after the removal.</p>

<p>For example, if <code>nums = [6,1,7,4,1]</code>:</p>

<ul>
	<li>Choosing to remove index <code>1</code> results in <code>nums = [6,7,4,1]</code>.</li>
	<li>Choosing to remove index <code>2</code> results in <code>nums = [6,1,4,1]</code>.</li>
	<li>Choosing to remove index <code>4</code> results in <code>nums = [6,1,7,4]</code>.</li>
</ul>

<p>An array is <strong>fair</strong> if the sum of the odd-indexed values equals the sum of the even-indexed values.</p>

<p>Return the <em><strong>number</strong> of indices that you could choose such that after the removal, </em><code>nums</code><em> </em><em>is <strong>fair</strong>. </em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,1,6,4]
<strong>Output:</strong> 1
<strong>Explanation:</strong>
Remove index 0: [1,6,4] -&gt; Even sum: 1 + 4 = 5. Odd sum: 6. Not fair.
Remove index 1: [2,6,4] -&gt; Even sum: 2 + 4 = 6. Odd sum: 6. Fair.
Remove index 2: [2,1,4] -&gt; Even sum: 2 + 4 = 6. Odd sum: 1. Not fair.
Remove index 3: [2,1,6] -&gt; Even sum: 2 + 6 = 8. Odd sum: 1. Not fair.
There is 1 index that you can remove to make nums fair.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong>&nbsp;You can remove any index and the remaining array is fair.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 0
<strong>Explanation:</strong>&nbsp;You cannot make a fair array after removing any index.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: WEEB EXPLAINS PYTHON/C++ DP/PREFIX SUM SOLN
**Author**: [@Skywalker5423](https://leetcode.com/Skywalker5423/)
**Upvotes**: 9 👍
**Link**: [View Original Post](https://leetcode.com/problems/ways-to-make-a-fair-array/solutions/1775588/)

---

My initial sketch for the question:
	![image](https://assets.leetcode.com/users/images/94558118-21a7-4852-a0f9-3779e1db24dc_1645019174.655498.png)

Here is my explanation for my messy sketch:
	![image](https://assets.leetcode.com/users/images/3639fac0-969c-440d-b033-4122f1754064_1645019230.8336735.png)
	Correction : 
	- At odd idx, prefixOdd at current idx == prefixOdd at the **next** idx (not previous idx)
	- At even idx, prefixEven at current idx == prefixEven at the **next** idx (not previous idx)
	![image](https://assets.leetcode.com/users/images/5fcfd53f-b816-46ba-a7ba-e740c7edeed8_1645019248.8864274.png)


**Python**

	class Solution:
		def waysToMakeFair(self, nums: List[int]) -> int:
			if len(nums) == 1:
				return 1

			if len(nums) == 2:
				return 0

			prefixEven = sum(nums[2::2])
			prefixOdd = sum(nums[1::2])
			result = 0

			if prefixEven == prefixOdd and len(set(nums)) == 1:
				result += 1

			for i in range(1,len(nums)):
				if i == 1:
					prefixOdd, prefixEven = prefixEven, prefixOdd 

				if i > 1:
					if i % 2 == 0:
						prefixEven -= nums[i-1]
						prefixEven += nums[i-2]

					else:
						prefixOdd -= nums[i-1]
						prefixOdd += nums[i-2]

				if prefixOdd == prefixEven:
					result += 1

			return result

**C++**

	class Solution {
	public:
		int waysToMakeFair(vector<int>& nums) {
			if (nums.size() == 1) return 1;

			if (nums.size() == 2) return 0;

			long int prefixEven = 0;
			long int prefixOdd = 0;
			set<int> set;
			int result = 0;

			for (int i=1; i < nums.size(); i++){
				if (i % 2 == 1) prefixOdd += nums[i];

				else{
					prefixEven += nums[i];
				}

				if (set.find(nums[i]) == set.end()) set.insert(nums[i]);
			}

			if (prefixOdd == prefixEven){
				if (set.size() == 1) result++;
			}


			for (int i=1; i < nums.size(); i++){
				if (i == 1){
					long int temp = prefixEven;
					prefixEven = prefixOdd;
					prefixOdd = temp;

				}

				if (i > 1){
					if (i % 2 == 0){
						prefixEven -= nums[i-1];
						prefixEven += nums[i-2];
					}

					else{
						prefixOdd -= nums[i-1];
						prefixOdd += nums[i-2];
					}
				}

				if (prefixEven == prefixOdd) result++;
			}

			return result;
		}
	};

Enough coding, dp takes a toll on your brain
Especially this one, its just one BIG pattern spotting question
Have a break, watch some anime instead
Check out **\u30EF\u30FC\u30AD\u30F3\u30B0!! (Working!!)**

# Episodes: 13 (1st Season) + 13 (2nd Season) + 14 (3rd Season)
# Genres: Comedy, Romance, Slice of Life
# Demographic: Seinen

There is an alternative setting for this anime, its called  **WWW.Working!!** which is a side story of this anime.
Anyways, watch this show to kill some time.
Also, please give this an upvote if u find this post useful, tq

</details>

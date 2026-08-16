# Asteroid Collision

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | August 16, 2026 |
| **Tags** | Array, Stack, Simulation |
| **Link** | [View Problem](https://leetcode.com/problems/asteroid-collision/) |
| **Runtime** | 0 ms |
| **Memory** | 8.3 MB |

## Problem Description

<p>We are given an array <code>asteroids</code> of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.</p>

<p>For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.</p>

<p>Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> asteroids = [5,10,-5]
<strong>Output:</strong> [5,10]
<strong>Explanation:</strong> The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> asteroids = [8,-8]
<strong>Output:</strong> []
<strong>Explanation:</strong> The 8 and -8 collide exploding each other.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> asteroids = [10,2,-5]
<strong>Output:</strong> [10]
<strong>Explanation:</strong> The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
</pre>

<p><strong class="example">Example 4:</strong></p>

<pre><strong>Input:</strong> asteroids = [3,5,-6,2,-1,4]​​​​​​​
<strong>Output:</strong> [-6,2,4]
<strong>Explanation:</strong> The asteroid -6 makes the asteroid 3 and 5 explode, and then continues going left. On the other side, the asteroid 2 destroys -1. Since 2 and 4 are both moving right, they never collide.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= asteroids.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-1000 &lt;= asteroids[i] &lt;= 1000</code></li>
	<li><code>asteroids[i] != 0</code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: C++ code with explanation (beats 95% in runtime)
**Author**: [@shreyanshjn](https://leetcode.com/shreyanshjn/)
**Upvotes**: 330 👍
**Link**: [View Original Post](https://leetcode.com/problems/asteroid-collision/solutions/904281/)

---

**Intuition**

According to the question, positive values are moving to the right and negative values are moving to the left. We can apply the concept of relative velocity and make positive values as fixed and negative values now moving with double velocity in the negative direction. But, magnitude of velocity does not matter only the direction matters.

**Idea**

Lets consider an example:-

```[8, 9, 6, -7, -9, 12, 50, -34]```

Start iterating from the beginning. Whenever we encounter a positive value, we don\'t have to do anything. Since they are fixed, they won\'t attack anyone. But the moment we sees a negative value, we are sure it is going to attack positive values.

Imagine ```[8, 9, 6]``` are happily sitting inside the array. The moment ```-7``` enters, it will start knocking out positive values. This gives an idea we can use a stack to solve this problem.

**Explanation**

Lets see how to use this idea to code.

Consider the same example ```[8, 9, 6, -7, -9, 12, 50, -34]```
Initially ```i = 0```.

1. Whenever we encounter a positive value, we will simply push it to the stack.
2. The moment we encounter a negative value, we know some or all or zero positive values will be knocked out of the stack. The negative value may itself be knocked out or it may enter the stack.
We will keep on poping the elements from the stack while the ```asteroids[i] > s.top()```. But remember, negative asteroids can never pop another negative asteroids, since they will never meet them. So, the final condition is ```while(!s.empty() and s.top() > 0 and s.top() < abs(ast[i]))```, we will pop the elements.
3. We have to take care of the case when ```s.top() == asteroids[i]```. In this case one positive element will pop out and negative asteroid won\'t enter the stack.
4. If after knocking out elements stack becomes empty() or s.top() becomes negative, that means the current asteroids[i] will enter the stack.

**Code**
```
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        stack<int> s;
        for(int i = 0; i < n; i++) {
            if(ast[i] > 0 || s.empty()) {
                s.push(ast[i]);
            }
            else {
                while(!s.empty() and s.top() > 0 and s.top() < abs(ast[i])) {
                    s.pop();
                }
                if(!s.empty() and s.top() == abs(ast[i])) {
                    s.pop();
                }
                else {
                    if(s.empty() || s.top() < 0) {
                        s.push(ast[i]);
                    }
                }
            }
        }
		// finally we are returning the elements which remains in the stack.
		// we have to return them in reverse order.
        vector<int> res(s.size());
        for(int i = (int)s.size() - 1; i >= 0; i--) {
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};
```

**Do upvote if this post is helpful to you**

**Edit** - Thanks for the upvote and comments, do follow me on twitter https://twitter.com/DevTalesShrey where I regularly post coding articles.

</details>

# Actors and Directors Who Cooperated At Least Three Times

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | mysql |
| **Solved On** | August 27, 2026 |
| **Tags** | Database |
| **Link** | [View Problem](https://leetcode.com/problems/actors-and-directors-who-cooperated-at-least-three-times/) |
| **Runtime** | 93 ms |
| **Memory** | 0B |

## Problem Description

<p>Table: <code>ActorDirector</code></p>

<pre>+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| actor_id    | int     |
| director_id | int     |
| timestamp   | int     |
+-------------+---------+
timestamp is the primary key (column with unique values) for this table.
</pre>

<p>&nbsp;</p>

<p>Write a solution to find all the pairs <code>(actor_id, director_id)</code> where the actor has cooperated with the director at least three times.</p>

<p>Return the result table in <strong>any order</strong>.</p>

<p>The result format is in the following example.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> 
ActorDirector table:
+-------------+-------------+-------------+
| actor_id    | director_id | timestamp   |
+-------------+-------------+-------------+
| 1           | 1           | 0           |
| 1           | 1           | 1           |
| 1           | 1           | 2           |
| 1           | 2           | 3           |
| 1           | 2           | 4           |
| 2           | 1           | 5           |
| 2           | 1           | 6           |
+-------------+-------------+-------------+
<strong>Output:</strong> 
+-------------+-------------+
| actor_id    | director_id |
+-------------+-------------+
| 1           | 1           |
+-------------+-------------+
<strong>Explanation:</strong> The only pair is (1, 1) where they cooperated exactly 3 times.
</pre>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: MY SQL || SOLUTION
**Author**: [@_himanshu_12](https://leetcode.com/_himanshu_12/)
**Upvotes**: 253 👍
**Link**: [View Original Post](https://leetcode.com/problems/actors-and-directors-who-cooperated-at-least-three-times/solutions/2645533/)

---

***GROUP BY:***
```
select actor_id, director_id 
from(
select actor_id,director_id, 
count(timestamp) as cooperated 
from ActorDirector 
group by actor_id,director_id) 
table1
where cooperated>=3;
```

***GROUP WITH HAVING CLAUSE:***
```
select actor_id,director_id
from ActorDirector 
group by actor_id,director_id
Having count(timestamp)>=3;
```

**EXPLANATION:**
```
+-------------+-------------+-------------+
| actor_id    | director_id | timestamp   |
+-------------+-------------+-------------+
| 1           | 1           | 0           |
| 1           | 1           | 1           |
| 1           | 1           | 2           |
| 1           | 2           | 3           |
| 1           | 2           | 4           |
| 2           | 1           | 5           |
| 2           | 1           | 6           |
+-------------+-------------+-------------+

Group by actor_id, director_id:
+-------------+-------------+-------------+
| actor_id    | director_id | timestamp   |
+-------------+-------------+-------------+
| 1           | 1           | 0, 1, 2    |
| 1           | 2           | 3, 4        |
| 2           | 1           | 5. 6        |
+-------------+-------------+-------------+

Group by actor_id, director_id
Having count(timestamp)>=3

| actor_id    | director_id | count(timestamp)  |
+-------------+-------------+-------------+
| 1           | 1           |                3                         |
| 1           | 2           |                2                         |
| 2           | 1           |                2                         |
+-------------+-------------+-------------+

select actor_id, director_id from:

| actor_id    | director_id  
+-------------+---------+
| 1           | 1                    |
+-------------+---------+

```

***PLEASE UPVOTE IF YOU FIND IT A LITTLE BIT HELPFUL, MEANS A LOT ;)***

</details>

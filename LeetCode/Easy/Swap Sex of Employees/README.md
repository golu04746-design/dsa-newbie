# Swap Sex of Employees

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | mysql |
| **Solved On** | August 27, 2026 |
| **Tags** | Database |
| **Link** | [View Problem](https://leetcode.com/problems/swap-sex-of-employees/) |
| **Runtime** | 274 ms |
| **Memory** | 0B |

## Problem Description

<p>Table: <code>Salary</code></p>

<pre>+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| id          | int      |
| name        | varchar  |
| sex         | ENUM     |
| salary      | int      |
+-------------+----------+
id is the primary key (column with unique values) for this table.
The sex column is ENUM (category) value of type ('m', 'f').
The table contains information about an employee.
</pre>

<p>&nbsp;</p>

<p>Write a solution to swap all <code>'f'</code> and <code>'m'</code> values (i.e., change all <code>'f'</code> values to <code>'m'</code> and vice versa) with a <strong>single update statement</strong> and no intermediate temporary tables.</p>

<p>Note that you must write a single update statement, <strong>do not</strong> write any select statement for this problem.</p>

<p>The result format is in the following example.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> 
Salary table:
+----+------+-----+--------+
| id | name | sex | salary |
+----+------+-----+--------+
| 1  | A    | m   | 2500   |
| 2  | B    | f   | 1500   |
| 3  | C    | m   | 5500   |
| 4  | D    | f   | 500    |
+----+------+-----+--------+
<strong>Output:</strong> 
+----+------+-----+--------+
| id | name | sex | salary |
+----+------+-----+--------+
| 1  | A    | f   | 2500   |
| 2  | B    | m   | 1500   |
| 3  | C    | f   | 5500   |
| 4  | D    | m   | 500    |
+----+------+-----+--------+
<strong>Explanation:</strong> 
(1, A) and (3, C) were changed from 'm' to 'f'.
(2, B) and (4, D) were changed from 'f' to 'm'.
</pre>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: ✔️ MySQL solution
**Author**: [@coding_menance](https://leetcode.com/coding_menance/)
**Upvotes**: 534 👍
**Link**: [View Original Post](https://leetcode.com/problems/swap-sex-of-employees/solutions/2755326/)

---

Solution using cases in MySQL:

```
UPDATE salary SET sex =
CASE sex
    WHEN \'m\' THEN \'f\'
    ELSE \'m\'
END;
```

![kitty.jpeg](https://assets.leetcode.com/users/images/541b8e36-5eb3-4283-b953-6067480389c3_1675058399.1742556.jpeg)


</details>

# Managers with at Least 5 Direct Reports

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | mysql |
| **Solved On** | September 1, 2026 |
| **Tags** | Database |
| **Link** | [View Problem](https://leetcode.com/problems/managers-with-at-least-5-direct-reports/) |
| **Runtime** | 337 ms |
| **Memory** | 0B |

## Problem Description

<p>Table: <code>Employee</code></p>

<pre>+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| department  | varchar |
| managerId   | int     |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table indicates the name of an employee, their department, and the id of their manager.
If managerId is null, then the employee does not have a manager.
No employee will be the manager of themself.
</pre>

<p>&nbsp;</p>

<p>Write a solution to find managers with at least <strong>five direct reports</strong>.</p>

<p>Return the result table in <strong>any order</strong>.</p>

<p>The result format is in the following example.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> 
Employee table:
+-----+-------+------------+-----------+
| id  | name  | department | managerId |
+-----+-------+------------+-----------+
| 101 | John  | A          | null      |
| 102 | Dan   | A          | 101       |
| 103 | James | A          | 101       |
| 104 | Amy   | A          | 101       |
| 105 | Anne  | A          | 101       |
| 106 | Ron   | B          | 101       |
+-----+-------+------------+-----------+
<strong>Output:</strong> 
+------+
| name |
+------+
| John |
+------+
</pre>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: ♻️Solved in 5 different ways! | 🔝TOP 2023🤝
**Author**: [@komronabdulloev](https://leetcode.com/komronabdulloev/)
**Upvotes**: 506 👍
**Link**: [View Original Post](https://leetcode.com/problems/managers-with-at-least-5-direct-reports/solutions/4177373/)

---

## Intuition

**We need to find managers with at least five direct reports, which can be done by counting the number of employees who have a particular manager**.

*There might be several approaches to solve this problem, but the logic behind all is similar *

# Code
```
SELECT E1.name
FROM Employee E1
JOIN (
    SELECT managerId, COUNT(*) AS directReports
    FROM Employee
    GROUP BY managerId
    HAVING COUNT(*) >= 5
) E2 ON E1.id = E2.managerId;

```
```
SELECT e.name
FROM Employee AS e 
INNER JOIN Employee AS m ON e.id=m.managerId 
GROUP BY m.managerId 
HAVING COUNT(m.managerId) >= 5
```
```
SELECT name 
FROM Employee 
WHERE id IN (
    SELECT managerId 
    FROM Employee 
    GROUP BY managerId 
    HAVING COUNT(*) >= 5)
```
```
SELECT a.name 
FROM Employee a 
JOIN Employee b ON a.id = b.managerId 
GROUP BY b.managerId 
HAVING COUNT(*) >= 5
```
```
SELECT e1.name
FROM employee e1
LEFT JOIN employee e2 ON e1.id=e2.managerId
GROUP BY e1.id
HAVING COUNT(e2.name) >= 5;
```
# **Hello, fellow LeetCode enthusiasts,**

*I\'ve provided a solution to the problem  (570. Managers with at Least 5 Direct Reports) above. 
If you find it useful or informative, 
I kindly request your support.
Your `upvotes` encourage me and others who are`working hard` to improve their problem-solving skills.*






</details>

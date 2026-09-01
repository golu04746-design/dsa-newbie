# Duplicate Emails

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | mysql |
| **Solved On** | September 1, 2026 |
| **Tags** | Database |
| **Link** | [View Problem](https://leetcode.com/problems/duplicate-emails/) |
| **Runtime** | 89 ms |
| **Memory** | 0B |

## Problem Description

<p>Table: <code>Person</code></p>

<pre>+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| email       | varchar |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table contains an email. The emails will not contain uppercase letters.
</pre>

<p>&nbsp;</p>

<p>Write a solution to report all the duplicate emails. Note that it's guaranteed that the email&nbsp;field is not NULL.</p>

<p>Return the result table in <strong>any order</strong>.</p>

<p>The&nbsp;result format is in the following example.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> 
Person table:
+----+---------+
| id | email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
<strong>Output:</strong> 
+---------+
| Email   |
+---------+
| a@b.com |
+---------+
<strong>Explanation:</strong> a@b.com is repeated two times.
</pre>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: ⭐3 different solutions || Easy to understand⭐
**Author**: [@123_tripathi](https://leetcode.com/123_tripathi/)
**Upvotes**: 324 👍
**Link**: [View Original Post](https://leetcode.com/problems/duplicate-emails/solutions/2385937/)

---

```
# Please upvote, if you like my solution
# 1
SELECT email from Person
group by email
having count(email) > 1;

# 2.
SELECT DISTINCT(p1.email) from Person p1, Person p2
where p1.id <> p2.id AND p1.email = p2.email;

#3. 
SELECT DISTINCT(p1.email) from 
Person p1 JOIN Person p2 ON
p1.email = p2.email AND p1.id <> p2.id;
# feel free to ask anything, if have any doubts
```

</details>

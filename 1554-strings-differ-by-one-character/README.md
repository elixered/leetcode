<h2><a href="https://leetcode.com/problems/strings-differ-by-one-character/">1554. Strings Differ by One Character</a></h2><h3>Medium</h3><hr><div><p>Given a list of strings <code>dict</code> where all the strings are of the same length.</p>

<p>Return <code>true</code> if there are 2 strings that only differ by 1 character in the same index, otherwise return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> dict = ["abcd","acbd", "aacd"]
<strong>Output:</strong> true
<strong>Explanation:</strong> Strings "a<strong>b</strong>cd" and "a<strong>a</strong>cd" differ only by one character in the index 1.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> dict = ["ab","cd","yz"]
<strong>Output:</strong> false
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> dict = ["abcd","cccc","abyd","abab"]
<strong>Output:</strong> true
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of characters in <code>dict &lt;= 10<sup>5</sup></code></li>
	<li><code>dict[i].length == dict[j].length</code></li>
	<li><code>dict[i]</code> should be unique.</li>
	<li><code>dict[i]</code> contains only lowercase English letters.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you solve this problem in <code>O(n * m)</code> where n is the length of <code>dict</code> and <code>m</code> is the length of each string.</p>
</div>
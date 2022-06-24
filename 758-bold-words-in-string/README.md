<h2><a href="https://leetcode.com/problems/bold-words-in-string/">758. Bold Words in String</a></h2><h3>Medium</h3><hr><div><p>Given an array of keywords <code>words</code> and a string <code>s</code>, make all appearances of all keywords <code>words[i]</code> in <code>s</code> bold. Any letters between <code>&lt;b&gt;</code> and <code>&lt;/b&gt;</code> tags become bold.</p>

<p>Return <code>s</code> <em>after adding the bold tags</em>. The returned string should use the least number of tags possible, and the tags should form a valid combination.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["ab","bc"], s = "aabcd"
<strong>Output:</strong> "a&lt;b&gt;abc&lt;/b&gt;d"
<strong>Explanation:</strong> Note that returning <code>"a&lt;b&gt;a&lt;b&gt;b&lt;/b&gt;c&lt;/b&gt;d"</code> would use more tags, so it is incorrect.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["ab","cb"], s = "aabcd"
<strong>Output:</strong> "a&lt;b&gt;ab&lt;/b&gt;cd"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>0 &lt;= words.length &lt;= 50</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>s</code> and <code>words[i]</code> consist of lowercase English letters.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Note:</strong> This question is the same as 616: <a href="https://leetcode.com/problems/add-bold-tag-in-string/" target="_blank">https://leetcode.com/problems/add-bold-tag-in-string/</a></p>
</div>
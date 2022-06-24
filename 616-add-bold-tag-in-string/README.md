<h2><a href="https://leetcode.com/problems/add-bold-tag-in-string/">616. Add Bold Tag in String</a></h2><h3>Medium</h3><hr><div><p>You are given a string <code>s</code> and an array of strings <code>words</code>. You should add a closed pair of bold tag <code>&lt;b&gt;</code> and <code>&lt;/b&gt;</code> to wrap the substrings in <code>s</code> that exist in <code>words</code>. If two such substrings overlap, you should wrap them together with only one pair of closed bold-tag. If two substrings wrapped by bold tags are consecutive, you should combine them.</p>

<p>Return <code>s</code> <em>after adding the bold tags</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abcxyz123", words = ["abc","123"]
<strong>Output:</strong> "&lt;b&gt;abc&lt;/b&gt;xyz&lt;b&gt;123&lt;/b&gt;"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aaabbcc", words = ["aaa","aab","bc"]
<strong>Output:</strong> "&lt;b&gt;aaabbc&lt;/b&gt;c"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>0 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 1000</code></li>
	<li><code>s</code> and <code>words[i]</code> consist of English letters and digits.</li>
	<li>All the values of <code>words</code> are <strong>unique</strong>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Note:</strong> This question is the same as 758: <a href="https://leetcode.com/problems/bold-words-in-string/" target="_blank">https://leetcode.com/problems/bold-words-in-string/</a></p>
</div>
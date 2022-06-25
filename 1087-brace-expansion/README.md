<h2><a href="https://leetcode.com/problems/brace-expansion/">1087. Brace Expansion</a></h2><h3>Medium</h3><hr><div><p>You are given a string <code>s</code> representing a list of words. Each letter in the word has one or more options.</p>

<ul>
	<li>If there is one option, the letter is represented as is.</li>
	<li>If there is more than one option, then curly braces delimit the options. For example, <code>"{a,b,c}"</code> represents options <code>["a", "b", "c"]</code>.</li>
</ul>

<p>For example, if <code>s = "a{b,c}"</code>, the first character is always <code>'a'</code>, but the second character can be <code>'b'</code> or <code>'c'</code>. The original list is <code>["ab", "ac"]</code>.</p>

<p>Return all words that can be formed in this manner, <strong>sorted</strong> in lexicographical order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> s = "{a,b}c{d,e}f"
<strong>Output:</strong> ["acdf","acef","bcdf","bcef"]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> s = "abcd"
<strong>Output:</strong> ["abcd"]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 50</code></li>
	<li><code>s</code> consists of curly brackets <code>'{}'</code>, commas&nbsp;<code>','</code>, and lowercase English letters.</li>
	<li><code>s</code> is guaranteed to be a valid input.</li>
	<li>There are no nested curly brackets.</li>
	<li>All characters inside a pair of consecutive opening and ending curly brackets are different.</li>
</ul>
</div>
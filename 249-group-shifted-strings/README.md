<h2><a href="https://leetcode.com/problems/group-shifted-strings/">249. Group Shifted Strings</a></h2><h3>Medium</h3><hr><div><p>We can shift a string by shifting each of its letters to its successive letter.</p>

<ul>
	<li>For example, <code>"abc"</code> can be shifted to be <code>"bcd"</code>.</li>
</ul>

<p>We can keep shifting the string to form a sequence.</p>

<ul>
	<li>For example, we can keep shifting <code>"abc"</code> to form the sequence: <code>"abc" -&gt; "bcd" -&gt; ... -&gt; "xyz"</code>.</li>
</ul>

<p>Given an array of strings <code>strings</code>, group all <code>strings[i]</code> that belong to the same shifting sequence. You may return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> strings = ["abc","bcd","acef","xyz","az","ba","a","z"]
<strong>Output:</strong> [["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> strings = ["a"]
<strong>Output:</strong> [["a"]]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= strings.length &lt;= 200</code></li>
	<li><code>1 &lt;= strings[i].length &lt;= 50</code></li>
	<li><code>strings[i]</code> consists of lowercase English letters.</li>
</ul>
</div>
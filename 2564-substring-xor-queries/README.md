<h2><a href="https://leetcode.com/problems/substring-xor-queries/">2564. Substring XOR Queries</a></h2><h3>Medium</h3><hr><div><p>You are given a <strong>binary string</strong> <code>s</code>, and a <strong>2D</strong> integer array <code>queries</code> where <code>queries[i] = [first<sub>i</sub>, second<sub>i</sub>]</code>.</p>

<p>For the <code>i<sup>th</sup></code> query, find the <strong>shortest substring</strong> of <code>s</code> whose <strong>decimal value</strong>, <code>val</code>, yields <code>second<sub>i</sub></code> when <strong>bitwise XORed</strong> with <code>first<sub>i</sub></code>. In other words, <code>val ^ first<sub>i</sub> == second<sub>i</sub></code>.</p>

<p>The answer to the <code>i<sup>th</sup></code> query is the endpoints (<strong>0-indexed</strong>) of the substring <code>[left<sub>i</sub>, right<sub>i</sub>]</code> or <code>[-1, -1]</code> if no such substring exists. If there are multiple answers, choose the one with the <strong>minimum</strong> <code>left<sub>i</sub></code>.</p>

<p><em>Return an array</em> <code>ans</code> <em>where</em> <code>ans[i] = [left<sub>i</sub>, right<sub>i</sub>]</code> <em>is the answer to the</em> <code>i<sup>th</sup></code> <em>query.</em></p>

<p>A <strong>substring</strong> is a contiguous non-empty sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "101101", queries = [[0,5],[1,2]]
<strong>Output:</strong> [[0,2],[2,3]]
<strong>Explanation:</strong> For the first query the substring in range <code>[0,2]</code> is <strong>"101"</strong> which has a decimal value of <strong><code>5</code></strong>, and <strong><code>5 ^ 0 = 5</code></strong>, hence the answer to the first query is <code>[0,2]</code>. In the second query, the substring in range <code>[2,3]</code> is <strong>"11",</strong> and has a decimal value of <strong>3</strong>, and <strong>3<code> ^ 1 = 2</code></strong>.&nbsp;So, <code>[2,3]</code> is returned for the second query. 

</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "0101", queries = [[12,8]]
<strong>Output:</strong> [[-1,-1]]
<strong>Explanation:</strong> In this example there is no substring that answers the query, hence <code>[-1,-1] is returned</code>.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "1", queries = [[4,5]]
<strong>Output:</strong> [[0,0]]
<strong>Explanation:</strong> For this example, the substring in range <code>[0,0]</code> has a decimal value of <strong><code>1</code></strong>, and <strong><code>1 ^ 4 = 5</code></strong>. So, the answer is <code>[0,0]</code>.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= first<sub>i</sub>, second<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
</ul>
</div>
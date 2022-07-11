<h2><a href="https://leetcode.com/problems/path-with-maximum-minimum-value/">1102. Path With Maximum Minimum Value</a></h2><h3>Medium</h3><hr><div><p>Given an <code>m x n</code> integer matrix <code>grid</code>, return <em>the maximum <strong>score</strong> of a path starting at </em><code>(0, 0)</code><em> and ending at </em><code>(m - 1, n - 1)</code> moving in the 4 cardinal directions.</p>

<p>The <strong>score</strong> of a path is the minimum value in that path.</p>

<ul>
	<li>For example, the score of the path <code>8 → 4 → 5 → 9</code> is <code>4</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/05/maxgrid1.jpg" style="width: 244px; height: 245px;">
<pre><strong>Input:</strong> grid = [[5,4,5],[1,2,6],[7,4,6]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The path with the maximum score is highlighted in yellow. 
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/05/maxgrid2.jpg" style="width: 484px; height: 165px;">
<pre><strong>Input:</strong> grid = [[2,2,1,2,2,2],[1,2,2,2,1,2]]
<strong>Output:</strong> 2
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/05/maxgrid3.jpg" style="width: 404px; height: 485px;">
<pre><strong>Input:</strong> grid = [[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 10<sup>9</sup></code></li>
</ul>
</div>
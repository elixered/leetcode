<h2><a href="https://leetcode.com/problems/delete-tree-nodes/">1273. Delete Tree Nodes</a></h2><h3>Medium</h3><hr><div><p>A tree rooted at node 0 is given as follows:</p>

<ul>
	<li>The number of nodes is <code>nodes</code>;</li>
	<li>The value of the <code>i<sup>th</sup></code> node is <code>value[i]</code>;</li>
	<li>The parent of the <code>i<sup>th</sup></code> node is <code>parent[i]</code>.</li>
</ul>

<p>Remove every subtree whose sum of values of nodes is zero.</p>

<p>Return <em>the number of the remaining nodes in the tree</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/07/02/1421_sample_1.PNG" style="width: 403px; height: 347px;">
<pre><strong>Input:</strong> nodes = 7, parent = [-1,0,0,1,2,2,2], value = [1,-2,4,0,-2,-1,-1]
<strong>Output:</strong> 2
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nodes = 7, parent = [-1,0,0,1,2,2,2], value = [1,-2,4,0,-2,-1,-2]
<strong>Output:</strong> 6
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nodes &lt;= 10<sup>4</sup></code></li>
	<li><code>parent.length == nodes</code></li>
	<li><code>0 &lt;= parent[i] &lt;= nodes - 1</code></li>
	<li><code>parent[0] == -1</code> which indicates that <code>0</code> is the root.</li>
	<li><code>value.length == nodes</code></li>
	<li><code>-10<sup>5</sup> &lt;= value[i] &lt;= 10<sup>5</sup></code></li>
	<li>The given input is <strong>guaranteed</strong> to represent a <strong>valid tree</strong>.</li>
</ul>
</div>
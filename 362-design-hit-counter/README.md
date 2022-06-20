<h2><a href="https://leetcode.com/problems/design-hit-counter/">362. Design Hit Counter</a></h2><h3>Medium</h3><hr><div><p>Design a hit counter which counts the number of hits received in the past <code>5</code> minutes (i.e., the past <code>300</code> seconds).</p>

<p>Your system should accept a <code>timestamp</code> parameter (<strong>in seconds</strong> granularity), and you may assume that calls are being made to the system in chronological order (i.e., <code>timestamp</code> is monotonically increasing). Several hits may arrive roughly at the same time.</p>

<p>Implement the <code>HitCounter</code> class:</p>

<ul>
	<li><code>HitCounter()</code> Initializes the object of the hit counter system.</li>
	<li><code>void hit(int timestamp)</code> Records a hit that happened at <code>timestamp</code> (<strong>in seconds</strong>). Several hits may happen at the same <code>timestamp</code>.</li>
	<li><code>int getHits(int timestamp)</code> Returns the number of hits in the past 5 minutes from <code>timestamp</code> (i.e., the past <code>300</code> seconds).</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["HitCounter", "hit", "hit", "hit", "getHits", "hit", "getHits", "getHits"]
[[], [1], [2], [3], [4], [300], [300], [301]]
<strong>Output</strong>
[null, null, null, null, 3, null, 4, 3]

<strong>Explanation</strong>
HitCounter hitCounter = new HitCounter();
hitCounter.hit(1);       // hit at timestamp 1.
hitCounter.hit(2);       // hit at timestamp 2.
hitCounter.hit(3);       // hit at timestamp 3.
hitCounter.getHits(4);   // get hits at timestamp 4, return 3.
hitCounter.hit(300);     // hit at timestamp 300.
hitCounter.getHits(300); // get hits at timestamp 300, return 4.
hitCounter.getHits(301); // get hits at timestamp 301, return 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= timestamp &lt;= 2 * 10<sup>9</sup></code></li>
	<li>All the calls are being made to the system in chronological order (i.e., <code>timestamp</code> is monotonically increasing).</li>
	<li>At most <code>300</code> calls will be made to <code>hit</code> and <code>getHits</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> What if the number of hits per second could be huge? Does your design scale?</p>
</div>
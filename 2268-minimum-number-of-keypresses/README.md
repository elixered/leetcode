<h2><a href="https://leetcode.com/problems/minimum-number-of-keypresses/">2268. Minimum Number of Keypresses</a></h2><h3>Medium</h3><hr><div><p>You have a keypad with <code>9</code> buttons, numbered from <code>1</code> to <code>9</code>, each mapped to lowercase English letters. You can choose which characters each button is matched to as long as:</p>

<ul>
	<li>All 26 lowercase English letters are mapped to.</li>
	<li>Each character is mapped to by <strong>exactly</strong> <code>1</code> button.</li>
	<li>Each button maps to <strong>at most</strong> <code>3</code> characters.</li>
</ul>

<p>To type the first character matched to a button, you press the button once. To type the second character, you press the button twice, and so on.</p>

<p>Given a string <code>s</code>, return <em>the <strong>minimum</strong> number of keypresses needed to type </em><code>s</code><em> using your keypad.</em></p>

<p><strong>Note</strong> that the characters mapped to by each button, and the order they are mapped in cannot be changed.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/05/05/image-20220505184346-1.png" style="width: 300px; height: 293px;">
<pre><strong>Input:</strong> s = "apple"
<strong>Output:</strong> 5
<strong>Explanation:</strong> One optimal way to setup your keypad is shown above.
Type 'a' by pressing button 1 once.
Type 'p' by pressing button 6 once.
Type 'p' by pressing button 6 once.
Type 'l' by pressing button 5 once.
Type 'e' by pressing button 3 once.
A total of 5 button presses are needed, so return 5.
</pre>

<p><strong>Example 2:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/05/05/image-20220505203823-1.png" style="width: 300px; height: 288px;">
<pre><strong>Input:</strong> s = "abcdefghijkl"
<strong>Output:</strong> 15
<strong>Explanation:</strong> One optimal way to setup your keypad is shown above.
The letters 'a' to 'i' can each be typed by pressing a button once.
Type 'j' by pressing button 1 twice.
Type 'k' by pressing button 2 twice.
Type 'l' by pressing button 3 twice.
A total of 15 button presses are needed, so return 15.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>
</div>
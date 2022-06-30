<h2><a href="https://leetcode.com/problems/design-search-autocomplete-system/">642. Design Search Autocomplete System</a></h2><h3>Hard</h3><hr><div><p>Design a search autocomplete system for a search engine. Users may input a sentence (at least one word and end with a special character <code>'#'</code>).</p>

<p>You are given a string array <code>sentences</code> and an integer array <code>times</code> both of length <code>n</code> where <code>sentences[i]</code> is a previously typed sentence and <code>times[i]</code> is the corresponding number of times the sentence was typed. For each input character except <code>'#'</code>, return the top <code>3</code> historical hot sentences that have the same prefix as the part of the sentence already typed.</p>

<p>Here are the specific rules:</p>

<ul>
	<li>The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.</li>
	<li>The returned top <code>3</code> hot sentences should be sorted by hot degree (The first is the hottest one). If several sentences have the same hot degree, use ASCII-code order (smaller one appears first).</li>
	<li>If less than <code>3</code> hot sentences exist, return as many as you can.</li>
	<li>When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.</li>
</ul>

<p>Implement the <code>AutocompleteSystem</code> class:</p>

<ul>
	<li><code>AutocompleteSystem(String[] sentences, int[] times)</code> Initializes the object with the <code>sentences</code> and <code>times</code> arrays.</li>
	<li><code>List&lt;String&gt; input(char c)</code> This indicates that the user typed the character <code>c</code>.
	<ul>
		<li>Returns an empty array <code>[]</code> if <code>c == '#'</code> and stores the inputted sentence in the system.</li>
		<li>Returns the top <code>3</code> historical hot sentences that have the same prefix as the part of the sentence already typed. If there are fewer than <code>3</code> matches, return them all.</li>
	</ul>
	</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["AutocompleteSystem", "input", "input", "input", "input"]
[[["i love you", "island", "iroman", "i love leetcode"], [5, 3, 2, 2]], ["i"], [" "], ["a"], ["#"]]
<strong>Output</strong>
[null, ["i love you", "island", "i love leetcode"], ["i love you", "i love leetcode"], [], []]

<strong>Explanation</strong>
AutocompleteSystem obj = new AutocompleteSystem(["i love you", "island", "iroman", "i love leetcode"], [5, 3, 2, 2]);
obj.input("i"); // return ["i love you", "island", "i love leetcode"]. There are four sentences that have prefix "i". Among them, "ironman" and "i love leetcode" have same hot degree. Since ' ' has ASCII code 32 and 'r' has ASCII code 114, "i love leetcode" should be in front of "ironman". Also we only need to output top 3 hot sentences, so "ironman" will be ignored.
obj.input(" "); // return ["i love you", "i love leetcode"]. There are only two sentences that have prefix "i ".
obj.input("a"); // return []. There are no sentences that have prefix "i a".
obj.input("#"); // return []. The user finished the input, the sentence "i a" should be saved as a historical sentence in system. And the following input will be counted as a new search.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == sentences.length</code></li>
	<li><code>n == times.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= sentences[i].length &lt;= 100</code></li>
	<li><code>1 &lt;= times[i] &lt;= 50</code></li>
	<li><code>c</code> is a lowercase English letter, a hash <code>'#'</code>, or space <code>' '</code>.</li>
	<li>Each tested sentence will be a sequence of characters <code>c</code> that end with the character <code>'#'</code>.</li>
	<li>Each tested sentence will have a length in the range <code>[1, 200]</code>.</li>
	<li>The words in each input sentence are separated by single spaces.</li>
	<li>At most <code>5000</code> calls will be made to <code>input</code>.</li>
</ul>
</div>
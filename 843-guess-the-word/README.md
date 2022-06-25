<h2><a href="https://leetcode.com/problems/guess-the-word/">843. Guess the Word</a></h2><h3>Hard</h3><hr><div><p>This is an <strong><em>interactive problem</em></strong>.</p>

<p>You are given an array of <strong>unique</strong> strings <code>wordlist</code> where <code>wordlist[i]</code> is <code>6</code> letters long, and one word in this list is chosen as <code>secret</code>.</p>

<p>You may call <code>Master.guess(word)</code> to guess a word. The guessed word should have type <code>string</code> and must be from the original list with <code>6</code> lowercase letters.</p>

<p>This function returns an <code>integer</code> type, representing the number of exact matches (value and position) of your guess to the <code>secret</code> word. Also, if your guess is not in the given wordlist, it will return <code>-1</code> instead.</p>

<p>For each test case, you have exactly <code>10</code> guesses to guess the word. At the end of any number of calls, if you have made <code>10</code> or fewer calls to <code>Master.guess</code> and at least one of these guesses was <code>secret</code>, then you pass the test case.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> secret = "acckzz", wordlist = ["acckzz","ccbazz","eiowzz","abcczz"], numguesses = 10
<strong>Output:</strong> You guessed the secret word correctly.
<strong>Explanation:</strong>
master.guess("aaaaaa") returns -1, because "aaaaaa" is not in wordlist.
master.guess("acckzz") returns 6, because "acckzz" is secret and has all 6 matches.
master.guess("ccbazz") returns 3, because "ccbazz" has 3 matches.
master.guess("eiowzz") returns 2, because "eiowzz" has 2 matches.
master.guess("abcczz") returns 4, because "abcczz" has 4 matches.
We made 5 calls to master.guess and one of them was the secret, so we pass the test case.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> secret = "hamada", wordlist = ["hamada","khaled"], numguesses = 10
<strong>Output:</strong> You guessed the secret word correctly.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= wordlist.length &lt;= 100</code></li>
	<li><code>wordlist[i].length == 6</code></li>
	<li><code>wordlist[i]</code> consist of lowercase English letters.</li>
	<li>All the strings of <code>wordlist</code> are <strong>unique</strong>.</li>
	<li><code>secret</code> exists in <code>wordlist</code>.</li>
	<li><code>numguesses == 10</code></li>
</ul>
</div>
* find how many rounds to move
* initialize startrow and endrow, startcol and endcol
* for all round simulate the movement, after change in any of startrow and endrow, endcol or startcol, check if condition is satisfied else break
​
​
* here is better method
* we move in 4 directions until bottom<=top and left<=right
* each time we increase dir circularily by 1
* for each direction assign one movement
class Solution {
public:
    int racecar(int target) {
        queue<vector<int>> todo;
        todo.push({0, 1, 0}); // {pos, speed, steps}
        while (!todo.empty()) {
            vector<int> cur = todo.front();
            todo.pop();
            int pos = cur[0];
            int speed = cur[1];
            int steps = cur[2];
            // If our position is target
            if (pos == target) {
                return steps;
            }
            // Try A
            if ((pos + speed <= 10000 && pos + speed > 0)) {
                todo.push({pos + speed, speed * 2, steps + 1});
            }
            // Try R
            if (speed > 0 && (pos + speed > target)) {
                todo.push({pos, -1, steps + 1});
            }
            if (speed < 0 && (pos + speed < target)) {
                todo.push({pos, 1, steps + 1});
            }
        }
        return -1;
    }
};
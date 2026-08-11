class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Count frequency of each task
        vector<int> freq(26, 0);

        for (char c : tasks) {
            freq[c - 'A']++;
        }

        // Max heap:
        // {frequency, task}
        priority_queue<pair<int, char>> pq;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push({freq[i], 'A' + i});
            }
        }

        // Queue:
        // {time when task becomes available,
        //  {remaining frequency, task}}
        queue<pair<int, pair<int, char>>> q;

        int time = 0;

        while (!pq.empty() || !q.empty()) {

            time++;

            // Move tasks whose cooldown has finished
            // from queue back into the heap.
            if (!q.empty() && q.front().first == time) {

                auto task = q.front().second;
                q.pop();

                pq.push(task);
            }

            // If there is an available task
            if (!pq.empty()) {

                auto [count, task] = pq.top();
                pq.pop();

                // Execute this task once
                count--;

                // If task still has remaining occurrences,
                // put it into cooldown.
                if (count > 0) {
                    q.push({time + n + 1, {count, task}});
                }
            }
        }

        return time;
    }
};


// @author: Amremad719
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> knight_moves(pair<int, int> start, pair<int, int> finish)
{
    auto is_valid = [](pair<int, int> p)
    {
        return p.first <= 8 && p.first >= 1 && p.second <= 8 && p.second >= 1;
    };

    int dx[8] = { -2, -2, -1, -1, 1,  1, 2,  2};
    int dy[8] = {  1, -1,  2, -2, 2, -2, 1, -1};

    pair<int, int> path[9][9];
    queue<pair<int, int>> q;
    bool vis[9][9] = {};

    q.push(start);
    vis[start.first][start.second] = 1;
    path[start.first][start.second] = { -1, -1 };
    
    pair<int, int> cur;

    while (!q.empty())
    {
        cur = q.front();
        q.pop();

        if (cur == finish) break;

        for (int i = 0; i < 8; i++)
        {
            pair<int, int> next = { cur.first + dx[i], cur.second + dy[i] };
            
            if (is_valid(next) && !vis[next.first][next.second])
            {
                vis[next.first][next.second] = 1;
                path[next.first][next.second] = cur;
                q.push(next);
            }
        }
    }

    vector<pair<int, int>> answer;

    while (path[finish.first][finish.second].first != -1)
    {
        answer.push_back(finish);

        finish = path[finish.first][finish.second];
    }
    answer.push_back(finish);

    reverse(answer.begin(), answer.end());

    return answer;
}

int main() {
    io();
    pair<int, int> a, b;
    cin >> a.first >> a.second >> b.first >> b.second;

    vector<pair<int, int>> vec = knight_moves(a, b);

    cout << "The shortest way for a knight to move from point [" << a.first << ", " << a.second
        << "] to the point [" << b.first << ", " << b.second << "] done in " << vec.size() - 1
        << " moves is:\n";

    for (auto i : vec) cout << '[' << i.first << ", " << i.second << "]\n";
    
    return 0;
}

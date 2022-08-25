#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

void print(map<pii, pii> path, pii node) {
	if (node.first == 0 && node.second == 0) {
		cout << "\nSolution :\n";
		cout << 0 << " " << 0 << endl;
		return;
	}
	print(path, path[node]);
	cout << node.first << " " << node.second << endl;
}

// void printQueue(queue<pii> q) {
// 	if(q.empty()) return;
// 	auto first = q.front();
// 	do {
// 		auto temp = q.front();
// 		cout << temp.first << " " << q.front().second << endl;
// 		q.pop(); q.push(temp);
// 	} while (q.front() != first);
// }

void BFS(int a, int b, int goal1, int goal2, int &count) {
	if(a < goal1 || b < goal2) {
		cout << "No solution" << endl;
		return;
	}

	map<pii, pii> path;         // to store the path
	map<pii, int> visited;      // to check if a node is visited or not
	queue<pii> q;               // For implementing queue in BFS
	bool flag = false;          // To check if the problem is solvable
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		auto node = q.front();
		//cout << "Examining State : " << node.first << " " << node.second << endl;
        q.pop();
		if (visited[node] == 1)
			continue;

		if (node.first > a || node.second > b || node.first < 0 || node.second < 0)
			continue;

		visited[{ node.first, node.second }] = 1; count++;
		
        //Case 1 : completely fill the jug 1
		if (visited[{ a, node.second }] != 1) {
			if(a == goal1 && node.second == goal2) {
				flag = true; print(path, node);
				cout << a << " " << node.second << endl;
			}
			else {
				q.push({ a, node.second });
				path[{ a, node.second }] = node;
			}
		}
		//Case 2 : completely fill the jug 2
		if (visited[{ node.first, b }] != 1) {
			if(node.first == goal1 && b == goal2) {
				flag = true; print(path, node);
				cout << node.first << " " << b << endl;
			}
			else {
				q.push({ node.first, b });
				path[{ node.first, b }] = node;
			}
		}
        //Case 3 : empty the jug 1
		if (visited[{ 0, node.second }] != 1) {
			if(0 == goal1 && node.second == goal2) {
				flag = true; print(path, node);
				cout << 0 << " " << node.second << endl;
			}
			else {
				q.push({0, node.second});
				path[{ 0, node.second }] = node;
			}
		}
        //Case 4 : empty the jug 2
		if (visited[{ node.first, 0 }] != 1) {
			if(node.first == goal1 && 0 == goal2) {
				flag = true; print(path, node);
				cout << node.first << " " << 0 << endl;
			}
			else {
				q.push({ node.first, 0 });
				path[{ node.first, 0 }] = node;
			}
		}

		//Case 5 & 6 : transfer jug 1 -> jug 2
		int d = b - node.second;
		if (node.first >= d) {
			int c = node.first - d;
			if (visited[{ c, b }] != 1) {
				if(c == goal1 && b == goal2) {
					flag = true; print(path, node);
					cout << c << " " << b << endl;
				}
				else {
					q.push({ c, b });
					path[{ c, b }] = node;
				}
			}
		}
		else {
			int c = node.first + node.second;
			if (visited[{ 0, c }] != 1) {
				if(0 == goal1 && c == goal2) {
					flag = true; print(path, node);
					cout << 0 << " " << c << endl;
				}
				else {
					q.push({ 0, c });
					path[{ 0, c }] = node;
				}
			}
		}
		//Case 7 & 8 : transfer jug 2 -> jug 1
		d = a - node.first;
		if (node.second >= d) {
			int c = node.second - d;
			if (visited[{ a, c }] != 1) {
				if(a == goal1 && c == goal2) {
					flag = true; print(path, node);
					cout << a << " " << c << endl;
				}
				else {
					q.push({ a, c });
					path[{ a, c }] = node;
				}
			}
		}
		else {
			int c = node.first + node.second;
			if (visited[{ c, 0 }] != 1) {
				if(c == goal1 && 0 == goal2) {
					flag = true; print(path, node);
					cout << c << " " << 0 << endl;
				}
				else {
					q.push({ c, 0 });
					path[{ c, 0 }] = node;
				}
			}
		} 
		//cout << "\nQ : " << endl; printQueue(q); 
	}
	if (!flag)
		cout << "No solution" << endl;
}

int main() {
	int jug1, jug2, goal1, goal2, count = 0;
    cout << "Enter Capacity of jug 1 : ";
    cin >> jug1;
    cout << "Enter Capacity of jug 2 : ";
    cin >> jug2;
    cout << "Enter Goal State of Jug 1 : ";
    cin >> goal1;
    cout << "Enter Goal State of Jug 2 : ";
    cin >> goal2;

	cout << "Path from initial state to solution state :\n";
	BFS(jug1, jug2, goal1, goal2, count);
    cout << "No. of nodes created : " << count << endl;
	return 0;
}
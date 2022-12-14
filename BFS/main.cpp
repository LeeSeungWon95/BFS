#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;
vector<bool> discovered;

void CreateGraph()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6);
	// 인접 리스트 version
	//adjacent[0].push_back(1);
	//adjacent[0].push_back(3);
	//adjacent[1].push_back(0);
	//adjacent[1].push_back(2);
	//adjacent[0].push_back(3);
	//adjacent[3].push_back(4);
	//adjacent[5].push_back(4);

	// 인접 행렬 version
	adjacent = vector<vector<int>>
	{
		{ 0, 1, 0, 1, 0, 0 },
		{ 1, 0, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0 },
	};
}

void Bfs(int here)
{
	queue<int> q;

	// 어디서 왔는지?
	vector<int> parent(6, -1);

	// 얼만큼 걸리는지?
	vector<int> distance(6, -1);

	// 발견
	q.push(here);
	discovered[here] = true;

	parent[here] = here;
	distance[here] = 0;

	while (q.empty() == false)
	{
		// 방문
		here = q.front();
		q.pop();


		cout << "Visited : " << here << endl;

		// 인접 리스트 version
		//for (int there : adjacent[here])
		//{
		//	if (discovered[there])
		//	{
		//		continue;
		//	}

		//	q.push(there);
		//	discovered[there] = true;

		//	parent[there] = here;
		//	distance[there] = distance[here] + 1;
		//}

		// 인접 행렬 version
		for (int there = 0; there < 6; ++there)
		{
			if (adjacent[here][there] == 0)
			{
				continue;
			}
			if (discovered[there])
			{
				continue;
			}
			q.push(there);
			discovered[there] = true;

			parent[there] = here;

			distance[there] = distance[here] + 1;
		}
	}
}

int main()
{
	discovered = vector<bool>(6, false);

	CreateGraph();

	Bfs(0);

	return 0;
}
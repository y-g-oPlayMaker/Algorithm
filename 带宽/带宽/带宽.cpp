/*还是没怎么搞明白。。先交了，下周继续搞*/

/*Bandwidth

Given a graph(V, E) where V is a set of nodes and E is a set of arcs in VxV, and an ordering on the elements in V, then thebandwidth of a node v is defined as the maximum distance in the ordering between v and any node to which it is connected in the graph.The bandwidth of the ordering is then defined as the maximum of the individual bandwidths.For example, consider the following graph :



This can be ordered in many ways, two of which are illustrated below :



For these orderings, the bandwidths of the nodes(in order) are 6, 6, 1, 4, 1, 1, 6, 6 giving an ordering bandwidth of 6, and 5, 3, 1, 4, 3, 5, 1, 4 giving an ordering bandwidth of 5.

Write a program that will find the ordering of a graph that minimises the bandwidth.

Input
Input will consist of a series of graphs.Each graph will appear on a line by itself.The entire file will be terminated by a line consisting of a single #.For each graph, the input will consist of a series of records separated by `;'. Each record will consist of a node name (a single upper case character in the the range `A' to `Z'), followed by a `:' and at least one of its neighbours. The graph will contain no more than 8 nodes.

Output
Output will consist of one line for each graph, listing the ordering of the nodes followed by an arrow(->) and the bandwidth for that ordering.All items must be separated from their neighbours by exactly one space.If more than one ordering produces the same bandwidth, then choose the smallest in lexicographic ordering, that is the one that would appear first in an alphabetic listing.

Sample input

A : FB; B:GC; D:GC; F:AGH; E:HD
#

	Sample output

	A B C F G D H E -> 3
	题目大意：给出一些点，以及所有必须相连的两点，然后每个排序中，找出必须连接的距离最大值，然后在所有序列中找出连接所需最短的。
	解题思路：将关系存成邻接表，然后对所有德 排序进行检查（注意输出字典序最小的）。

*/


/*#include <stdio.h>

#include <string.h>

#include <algorithm>

using namespace std;

#define N 1000

#define M 30



int Min, g[M][M], bir[M], son[N];

int n, num[N], rec[N];

char str[N];



bool judge(int u, int v) {

	for (int i = 0; i < son[u]; i++)

		if (v == g[u][i])

			return false;

	return true;

}



int find(int k) {

	for (int i = 0; i < n; i++)

		if (num[i] == k)

			return i;

}



void handle() {

	char f = str[0], s;

	bir[f - 'A'] = 1;

	int len = strlen(str);

	for (int i = 1; i < len; i++) {

		if (str[i] == ';')

		{

			f = str[++i];

			bir[f - 'A'] = 1;

		}

		else if (str[i] == ':')

			continue;

		else {

			s = str[i];

			int a = f - 'A', b = s - 'A';

			if (judge(a, b)) {

				g[a][son[a]++] = b;

				g[b][son[b]++] = a;

			}

			bir[b] = 1;

		}

	}

}



void count() {

	int Max = 0;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < son[num[i]]; j++) {

			int t = abs(find(g[num[i]][j]) - i);

			if (Max < t)

				Max = t;

		}

	}

	if (Max < Min) {

		memcpy(rec, num, sizeof(num));

		Min = Max;

	}

}



int main() {

	while (1) {

		scanf("%s", str);

		if (strcmp(str, "#") == 0)

			break;

		// Init.

		memset(g, 0, sizeof(g));

		memset(bir, 0, sizeof(bir));

		memset(num, 0, sizeof(num));

		memset(rec, 0, sizeof(rec));

		memset(son, 0, sizeof(son));

		Min = 0x7fffffff;

		n = 0;



		// Handle.

		handle();

		for (int i = 0; i < M; i++)

			if (bir[i])

				num[n++] = i;



		sort(num, num + n);

		do {

			count();

		} while (next_permutation(num, num + n));

		for (int i = 0; i < n; i++)

			printf("%c ", 'A' + rec[i]);

		printf("-> %d\n", Min);

		sizeof(str, 0, sizeof(str));

	}

	return 0;

}
*/		
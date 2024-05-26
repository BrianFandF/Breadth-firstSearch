#include <iostream>
#include <queue>
#include <vector>
#include<Windows.h>
using namespace std;

const int MAX_SIZE = 15; // Максимальний розмір матриці

// Функція для виконання пошуку в ширину
void BFS(int graph[MAX_SIZE][MAX_SIZE], int start, int numNodes) {
    vector<bool> visited(numNodes, false); // Масив для відстеження відвіданих вузлів
    queue<int> q; // Черга для обробки вузлів

    // Починаємо з початкового вузла
    visited[start] = true;
    q.push(start);

    cout << "Результат пошуку в ширину з початкового вузла " << start + 1 << ":" << endl;

    while (!q.empty()) {
        int currentNode = q.front();
        cout << currentNode + 1<< " "; // Виводимо поточний вузол
        q.pop();

        // Обробка сусідніх вузлів
        for (int i = 0; i < numNodes; ++i) {
            if (graph[currentNode][i] != 0 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    cout << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int graph[MAX_SIZE][MAX_SIZE] = {
        {0, 5, 3, 7, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 8, 0, 0, 0, 0, 0, 0, 0},
        {0, 5, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 4, 9, 8, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 3, 6, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 8, 0, 1, 2, 0, 4, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4, 9, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    int numNodes = 14; // Кількість вузлів у графі

    for (int i = 0; i < numNodes; i++)
    {
        BFS(graph, i, numNodes); // Виконуємо пошук в ширину
    }

    return 0;
}
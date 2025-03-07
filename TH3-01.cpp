#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <stdlib.h>


using namespace std;

const int MAX_N = 1000;
const int INF = INT_MAX;

int n, start, totalCost = 0;
int cost[MAX_N][MAX_N];
bool visited[MAX_N];
vector<int> tour;

void GTS1(int u){
    int v = u;
    tour.push_back(v);
    visited[v] = true;

    for(int i = 1; i<n; i++){
        int minCost = INF, nextCity = -1;

    for(int j = 1; j<=n; j++){
        if(!visited[j] && cost[v][j] < minCost){
            minCost = cost[v][j];
            nextCity = j;
        }
    }
    totalCost += minCost;
    tour.push_back(nextCity);
    visited[nextCity] = true;
    v = nextCity;
    }

    tour.push_back(u);
    totalCost += cost[v][u];
}

int main(){
    FILE* inFile = fopen("C:\\vs code\\.vscode\\31-3123410126-NguyenTranNhatHuy-baitaptuan3\\GTS1a.txt", "rt");
    if (!inFile) {
        cout << "Khong the mo file!" << endl;
        return 1;
    }

    FILE* outFile = fopen("C:\\vs code\\.vscode\\31-3123410126-NguyenTranNhatHuy-baitaptuan3\\GTS1a_out.txt", "wt");
    if (!outFile) {
        cout<<"khong the mo file dau ra!"<<endl;
        return 1;
    }
    fscanf(inFile, "%d %d", &n, &start);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            fscanf(inFile, "%d", &cost[i][j]);

    fill(visited, visited + MAX_N, false);
    GTS1(start);

    fprintf(outFile, "%d\n", totalCost);
    for(int x : tour) fprintf(outFile, "%d ", x);
    fclose(inFile);
    fclose(outFile);
    cout << "Chuong trinh da ghi ket qua vao GTS1_out.txt\n";
    return 0;
}

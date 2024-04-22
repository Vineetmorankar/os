#include <iostream>
// #include <queue>
#include <vector>
#include <cmath>
using namespace std;

void fcfs(vector<int> tracks, int n, int head)
{
    int count = 0;
    int curr, diff;

    for (int i = 0; i < n; i++)
    {
        curr = tracks[i];

        diff = abs(curr - head);

        count += diff;

        head = curr;
    }

    cout << "count is: " << count;
}

int main()
{
    int n;
    cout << "Enter number of tracks: ";
    cin >> n;
    vector<int> tracks(n);
    cout << "Enter tracks: ";
    for (int i = 0; i < n; i++)
    {
        cin >> tracks[i];
    }
    int head;
    cout << "Enter Head: ";
    cin >> head;
    fcfs(tracks, n, head);
}
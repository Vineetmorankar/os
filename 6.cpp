#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void ffit(vector<int> process, vector<int> blocks, int p, int b)
{
    vector<int> bcopy = blocks;
    vector<int> allocp(p, -1);
    vector<int> allocb(b, -1);

    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (bcopy[j] >= process[i] && allocb[j] == -1)
            {
                allocp[i] = j;
                allocb[j] = 1;
                bcopy[j] -= process[i];
                break;
            }
        }
    }

    cout << "P No.\tProcess Size\tBlock no. \t Block Size\n";
    for (int i = 0; i < p; i++)
    {
        cout << "p" << i << " \t" << process[i] << "\t";
        if (allocp[i] != -1)
            cout << "B" << allocp[i] << "\t\t" << blocks[allocp[i]] << "\n";
        else
            cout << "Not Allocated\n";
    }
}

void bfit(vector<int> process, vector<int> blocks, int p, int b)
{
    vector<int> bcopy = blocks;
    vector<int> allocp(p, -1);
    vector<int> allocb(b, -1);

    for (int i = 0; i < p; i++)
    {
        int bi = -1;
        for (int j = 0; j < b; j++)
        {
            if (bcopy[j] >= process[i] && allocb[j] == -1)
            {
                if (bi == -1)
                {
                    bi = j;
                }
                else if (bcopy[bi] > bcopy[j])
                {
                    bi = j;
                }
            }
        }

        if (bi != -1)
        {
            allocp[i] = bi;
            allocb[bi] = 1;
            bcopy[bi] -= process[i];
        }
    }

    cout << "P No.\tProcess Size\tBlock no. \t Block Size\n";
    for (int i = 0; i < p; i++)
    {
        cout << "p" << i << " \t" << process[i] << "\t";
        if (allocp[i] != -1)
            cout << "B" << allocp[i] << "\t\t" << blocks[allocp[i]] << "\n";
        else
            cout << "Not Allocated\n";
    }
}

void wfit(vector<int> process, vector<int> blocks, int p, int b)
{
    vector<int> bcopy = blocks;
    vector<int> allocp(p, -1);
    vector<int> allocb(b, -1);

    for (int i = 0; i < p; i++)
    {
        int wi = -1;
        for (int j = 0; j < b; j++)
        {
            if (bcopy[j] >= process[i] && allocb[j] == -1)
            {
                if (wi == -1)
                {
                    wi = j;
                }
                else if (bcopy[wi] < bcopy[j])
                {
                    wi = j;
                }
            }
        }

        if (wi != -1)
        {
            allocp[i] = wi;
            allocb[wi] = 1;
            bcopy[wi] -= process[i];
        }
    }

    cout << "P No.\tProcess Size\tBlock no. \t Block Size\n";
    for (int i = 0; i < p; i++)
    {
        cout << "p" << i << " \t" << process[i] << "\t";
        if (allocp[i] != -1)
            cout << "B" << allocp[i] << "\t\t" << blocks[allocp[i]] << "\n";
        else
            cout << "Not Allocated\n";
    }
}

void nfit(vector<int> process, vector<int> blocks, int p, int b)
{
    vector<int> bcopy = blocks;
    vector<int> allocp(p, -1);
    vector<int> allocb(b, -1);

    int j = 0;
    for (int i = 0; i < p; i++)
    {
        int start = j;
        do
        {
            if (bcopy[j] >= process[i] && allocb[j] == -1)
            {
                allocp[i] = j;
                allocb[j] = 1;
                bcopy[j] -= process[i];
                break;
            }
            j = (j + 1) % b;
        } while (j != start);
    }

    cout << "P No.\tProcess Size\tBlock no. \t Block Size\n";
    for (int i = 0; i < p; i++)
    {
        cout << "p" << i << " \t" << process[i] << "\t";
        if (allocp[i] != -1)
            cout << "B" << allocp[i] << "\t\t" << blocks[allocp[i]] << "\n";
        else
            cout << "Not Allocated\n";
    }
}

int main()
{
    vector<int> process(5);
    cout << "Enter process: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> process[i];
    }
    vector<int> blocks(5);
    cout << "Enter blocks: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> blocks[i];
    }

    nfit(process, blocks, process.size(), blocks.size());
}
// 100 500 200 300 600
// 200 400 300 250 150
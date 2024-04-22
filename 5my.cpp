#include <iostream>
using namespace std;

const int MAX_PROCESSES = 10;
const int MAX_RESOURCES = 10;

int main()
{
    int p, r, al[MAX_PROCESSES][MAX_RESOURCES], max[MAX_PROCESSES][MAX_RESOURCES], av[MAX_RESOURCES], need[MAX_PROCESSES][MAX_RESOURCES], rcnt, pcnt, completed, no_progress;

    cout << "Enter Processes: ";
    cin >> p;
    cout << "Enter Resources: ";
    cin >> r;

    cout << "\nCurrent Allocation " << endl;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout << "Enter instances for al[" << i << "][" << j << "]: ";
            cin >> al[i][j];
        }
    }

    cout << "\nMax Need" << endl;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout << "Enter instances for max[" << i << "][" << j << "]: ";
            cin >> max[i][j];
        }
    }
    cout << "\nResources " << endl;
    for (int i = 0; i < r; i++)
    {
        cout << "Enter instances for max[" << i << "]: ";
        cin >> av[i];
    }

    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - al[i][j];
        }
    }

    cout << "Allocation: " << endl;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout << "\t" << al[i][j];
        }
        cout << endl;
    }

    cout << "Max Need: " << endl;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout << "\t" << max[i][j];
        }
        cout << endl;
    }

    cout << "Requirement: " << endl;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout << "\t" << need[i][j];
        }
        cout << endl;
    }

    cout << "\nSafe Sequence -> " << endl;
    completed = 1;
    pcnt = 0;
    no_progress = 0; // Initialize no_progress flag
    while (completed != 0)
    {
        no_progress = 1; // Assume no progress is made at the beginning of each iteration
        for (int i = 0; i < p; i++)
        {
            rcnt = 0;
            for (int j = 0; j < r; j++)
            {
                if (need[i][j] <= av[j] && (need[i][0] != -1))
                {
                    rcnt++;
                }
            }

            if (rcnt == r)
            {
                no_progress = 0; // Progress is made, so reset the flag
                for (int k = 0; k < r; k++)
                {
                    av[k] += al[i][k];
                }
                cout << "\nProcess " << i;
                need[i][0] = -1;
                pcnt++;
            }
        }
        if (pcnt == p)
        {
            completed = 0;
        }
        if (no_progress == 1) // If no progress is made in the loop, break the while loop
        {
            cout << "\nNo Safe Sequence Found!";
            break;
        }
    }
    cout << endl;
    return 0;
}
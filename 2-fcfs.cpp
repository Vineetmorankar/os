#include <bits/stdc++.h>
using namespace std;

struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

bool compat(process p1, process p2)
{
    if (p1.at == p2.at)
        return p1.pid < p2.pid;
    return p1.at < p2.at;
}

bool comppid(process p1, process p2)
{
    return p1.pid < p2.pid;
}

int main()
{
    int n;
    cout << "Enter no of processes: " << endl;
    cin >> n;

    int ttat = 0, twat = 0;
    float atat = 0, awt = 0;
    process p[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter at and bt of p" << i + 1 << " : ";
        p[i].pid = i + 1;
        cin >> p[i].at >> p[i].bt;
    }

    sort(p, p + n, compat);

    int start = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            start = p[i].at + p[i].bt;
        }
        else if (p[i - 1].ct < p[i].at)
        {
            start = p[i].at + p[i].bt;
        }
        else
        {
            start = p[i - 1].ct + p[i].bt;
        }
        p[i].ct = start;
    }

    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }

    for (int i = 0; i < n; i++)
    {
        ttat += p[i].tat;
        twat += p[i].wt;
    }

    sort(p, p + n, comppid);

    // for printing the table
    cout << "pid\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << p[i].pid << " \t" << p[i].at << " \t" << p[i].bt << "\t " << p[i].ct << " \t" << p[i].tat << " \t" << p[i].wt << endl;
    }

    atat = float(ttat) / n;
    awt = float(twat) / n;

    cout << "Average turnaround time : \t" << atat << endl;
    cout << "Average waiting time : \t" << awt << endl;
}
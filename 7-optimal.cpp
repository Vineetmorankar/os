#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

int optimalPageReplacement(const vector<int> &pages, int capacity)
{
    unordered_map<int, int> nextOccurrence; // Map to store next occurrence of each page
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); ++i)
    {
        // Check if page is already in memory
        if (nextOccurrence.find(pages[i]) == nextOccurrence.end())
        {
            // Page fault
            ++pageFaults;

            // If memory is full, find the page that won't be used for the longest time
            if (nextOccurrence.size() == capacity)
            {
                int farthest = -1, farthestPage;
                for (const auto &entry : nextOccurrence)
                {
                    if (entry.second == INT_MAX)
                    { // If a page will not occur again, remove it
                        farthestPage = entry.first;
                        break;
                    }
                    if (entry.second > farthest)
                    {
                        farthest = entry.second;
                        farthestPage = entry.first;
                    }
                }
                nextOccurrence.erase(farthestPage);
            }
        }

        // Update next occurrence of current page
        nextOccurrence[pages[i]] = INT_MAX;
        for (int j = i + 1; j < pages.size(); ++j)
        {
            if (pages[j] == pages[i])
            {
                nextOccurrence[pages[i]] = j;
                break;
            }
        }
    }

    return pageFaults;
}

int main()
{
    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2}; // Page references
    int capacity = 4;                                            // Capacity of memory frames

    int pageFaults = optimalPageReplacement(pages, capacity);

    cout << "Total Page Faults: " << pageFaults << endl;

    return 0;
}
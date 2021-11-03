#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> hpmin;
priority_queue<int, vector<int>> hpmax;

double findMedian()
{
    if (hpmin.size() == hpmax.size())
    {
        return (hpmin.top() + hpmax.top()) / 2.0;
    }
    else if (hpmin.size() < hpmax.size())
    {
        return hpmax.top();
    }
    else
    {
        return hpmin.top();
    }
}

void insert(int x)
{
    if (hpmin.size() == hpmax.size())
    {
        if (hpmax.size() == 0)
        {
            hpmax.push(x);
            return;
        }
        if (x < hpmax.top())
        {
            hpmax.push(x);
        }
        else
        {
            hpmin.push(x);
        }
    }
    else
    {
        if (hpmax.size() > hpmin.size())
        {
            if (x > hpmax.top())
            {
                hpmin.push(x);
            }
            else
            {
                int temp = hpmax.top();
                hpmax.pop();
                hpmin.push(temp);
                hpmax.push(x);
            }
        }
        else
        {
            if (x <= hpmin.top())
            {
                hpmax.push(x);
            }
            else
            {
                int temp = hpmin.top();
                hpmin.pop();
                hpmax.push(temp);
                hpmin.push(x);
            }
        }
    }
}

int main()
{
    insert(10);
    cout << findMedian() << endl;
    insert(16);
    cout << findMedian() << endl;
    insert(13);
    cout << findMedian() << endl;
    insert(19);
    cout << findMedian() << endl;
    insert(15);
    cout << findMedian() << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

int main()
{
    std::vector<int> que;
    int head, seak = 0;
    std::cin >> head;
    int val;
    while(std::cin >> val)
        que.push_back(val);

    int curr = head;
    for(int i = 0; i < que.size(); i++)
    {
        int index, min = 10000;
        for(int j = 0; j != que.size(); j++)
        {
            int temp = abs(curr - que[j]);
            if(min > temp)
            {
                min = temp;
                index = j;
            }
        }
        std::cout << "Move from " << curr << " to " << que[index] << std::endl;
        seak += abs(curr - que[index]);
        curr = que[index];
        que[index] = INT_MAX;
    }
    std::cout << seak << std::endl;
}

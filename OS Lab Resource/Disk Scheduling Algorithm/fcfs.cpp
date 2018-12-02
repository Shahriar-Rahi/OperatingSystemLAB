#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main()
{
    std::vector<int> que;
    int head, seak = 0;

    std::cin >> head;
    que.push_back(head);
    //std::cin >> seak;

    int val;
    while(std::cin >> val)
        que.push_back(val);
    
    for(auto it = que.begin(); it != que.end() - 1; it++)
    {
        int diff = abs((*it) - (*(it + 1)));
        seak += diff;
        std::cout << "move from " << (*it) << " to " << (*(it + 1)) << " with seak " << seak << std::endl;
    }

    int avg = seak /(float) que.size();
    std::cout << "avg = " << avg << " total = " << seak << std::endl;
}
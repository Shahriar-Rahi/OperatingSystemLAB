#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

int main()
{
    int alpha = 20;
    int max_track = 256;
    std::vector<int> que;
    int head, seak = 0;
    std::cin >> head;
    int val;
    while(std::cin >> val)
        que.push_back(val);
    int curr = head;
    std::sort(que.begin(), que.end());
    que.insert(que.begin(), 0);
    que.push_back(max_track);
    int index = -1;
    for(int i = 0; i != que.size() && index == -1; i++)
        if(que[i] > head)
            index = i;
    for(int i = index - 1; i >= 0; i--)
    {
        std::cout << "Move from " << curr << " to " << que[i] << std::endl;
        curr = que[i];
    }
    for(int i = que.size() - 1; i >= index; i--)
    {
        std::cout << "Move from " << curr << " to " << que[i] << std::endl;
        curr = que[i];
    }        

    seak = head + abs(max_track - que[index]) + alpha;
    std::cout << seak << std::endl;
}
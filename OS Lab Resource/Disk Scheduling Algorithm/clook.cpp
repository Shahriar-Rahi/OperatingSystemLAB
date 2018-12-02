#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

int main()
{
    int alpha = 20;
    std::vector<int> que;
    int head, seak = 0;
    std::cin >> head;
    int val;
    while(std::cin >> val)
        que.push_back(val);
    int curr = head;
    std::sort(que.begin(), que.end());
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
    //std::cout << que[index - 1] << " " << que[0] << std::endl;        
    seak = abs(head - que[0]);
    seak += abs(que[index] - que[que.size() - 1]) + alpha;
    //std::cout << que[index] << " " << que[que.size()-1] << std::endl;        

    std::cout << seak;


}

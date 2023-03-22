#ifndef SINGLENUMBER_H
#define SINGLENUMBER_H
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
    
public:
    /*
    [0,1,0,2,1,0,1,3,2,1,2,1]
    1 пришел 0, поскольку стек пустой, просто кладем его [0]
    2 пришла 1, в стеке что-то лежит и правая граница выше левой(возможно это можно заполнить водой)
    3 вытаскиваем 0 из стека, если стек пуст, то значит левой границы нет, продолжаем. в стек после кладем 1 [0]->[]->[1]
    4 пришел 0, 0 меньше того что лежит в стеке, то в цикл не войдем, просто положим его в стек [1]->[1,0]
    5 пришла 2, 2 больше того что лежит в стеке, вытаскиваем 0 [1,0] ->[1], ага есть левая граница, лежит на вершине стека
    6 вычисляем размер куба, как минимальная высота левой и правой границы - высота пола(то что выташили из стека в начале цикла)
    7 кладем 2 стек
    */
    int trap(vector<int>& height) {
                
        stack<int> point;
        int res = 0;
        for(size_t x = 0; x < height.size(); ){
             while(!point.empty() && height[point.top()] <= height[x]){
                        auto leftPoint = point.top();
                        cout << "lp " << leftPoint << " " << height[leftPoint] << " x " << x << endl;
                        point.pop();
                            if(point.empty()){
                            break;
                            }
                        auto distance = x - point.top() - 1;
                        auto minHeight = min(height[point.top()], height[x]) - height[leftPoint];
                        res += distance * minHeight;
                        cout << "distance " << distance << " minheight " << minHeight << " res " << res << endl;

                    }
            point.push(x++);
            
            
        }
        
        
        return res;
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
 #endif // SINGLENUMBER_H

#include <iostream>
#include <vector>
#include <limits>
#include <stack>
#include <queue>
#include <list>

using namespace std;


enum class GrafP: size_t{};


int deikstra(const vector<vector<int>> graf, GrafP start, GrafP end){

    if (graf.empty())
        return 0;

    vector<bool> visited(graf.size(), false);


    vector<int> weight(graf.size(), std::numeric_limits<int>::max());

    weight.at((int)start) = 0;

    //stack <GrafP> st;
    //st.emplace(start);
    auto cur = start;
    vector <GrafP> result;
    result.emplace_back(start);
    cout << std::endl;

    while(cur != end){
        auto nextPoint = end;
        int minWeight = std::numeric_limits<int>::max();
        //GrafP minPoint =
        for(size_t i = 0; i < graf[(int)cur].size(); ++i){
            if (graf[(int)cur][i] != 0 and !visited[(int)i]){
                //cout << "i " << i << " w " << weight[i] << " " << weight[(int)cur] + graf[(int)cur][i] << std::endl;
                if (weight[i] > weight[(int)cur] + graf[(int)cur][i]){
                    weight[i] = weight[(int)cur] + graf[(int)cur][i];
                }
                if (minWeight > weight[i]){
                    minWeight = weight[i];
                    nextPoint = GrafP(i);
                }
            }
        }
        visited.at((int)cur) = true;
        result.emplace_back(nextPoint);
        cur = nextPoint;
    }

    int i = 0;
    for(auto &gp: weight){
        std::cout << "gp " << i++ << " " << (int)gp << std::endl;
    }

    std::cout << "W ";
    for(auto &p: result){
        std::cout << " " << weight.at((int)p) ;
    }
    std::cout << std::endl;

    std::cout << "Path ";
    for(auto &p: result){
        std::cout << " " << (int)p ;
    }
    std::cout << std::endl;

    return 0;
}


struct PInfo{
    GrafP point;
    int weight;
    PInfo(GrafP point, int weight): point(point), weight(weight){}
};

void convertToMatrixAndCheck(const vector<list<PInfo>> &inputgraf,const vector<vector<int>> &checkGraf){
    vector<vector<int>> result(inputgraf.size());
    for(auto &r: result){
        r.resize(inputgraf.size(), 0);
    }

    size_t point = 0;
    for (const auto &l: inputgraf){
        for(const auto &p: l){
            result[point][(int)p.point] = p.weight;
        }
        point++;
    }

    bool ok = true;
    for(size_t i = 0; i < checkGraf.size() && ok; ++i){
        for(size_t j = 0; j < checkGraf[i].size() && ok; ++j){
            if (result[i][j] != checkGraf[i][j]){
                ok = false;
            }
        }
    }
    cout << "convertToMatrixAndCheck " << ok << endl;
}

void deikstraList(const vector<list<PInfo>> &lgraf, GrafP start, GrafP end){
    if(lgraf.empty() and lgraf.size() > int(start) and lgraf.size() > int(end))
        return;

    vector <bool> visited(lgraf.size());

    vector<int> weight(lgraf.size(), std::numeric_limits<int>::max());

    weight[(int)start] = 0;

    vector <GrafP> result;
    result.emplace_back(start);

    auto cur = lgraf.at((int)start);
    auto curIndex = start;
    while(curIndex != end){
        auto nextPoint = end;
        decltype (PInfo::weight) minWeight = std::numeric_limits<int>::max();
        cout << "curindex " << (int)curIndex << endl;
        for(auto &l: cur){
            if (weight[(int)l.point] > weight[(int)curIndex] + l.weight and !visited.at(int(l.point))){
                weight[(int)l.point] = weight[(int)curIndex] + l.weight;

            }
            if (minWeight > weight[(int)l.point] and !visited.at(int(l.point))){
                minWeight = weight[(int)l.point];
                nextPoint = l.point;

            }

        }

        visited.at((int)curIndex) = true;
        curIndex = nextPoint;
        cur = lgraf.at((int)curIndex);
        result.emplace_back(curIndex);
    }

    int i = 0;
    for(auto &gp: weight){
        std::cout << "gp " << i++ << " " << (int)gp << std::endl;
    }

    std::cout << "W ";
    for(auto &p: result){
        std::cout << " " << weight.at((int)p) ;
    }
    std::cout << std::endl;

    std::cout << "Path ";
    for(auto &p: result){
        std::cout << " " << (int)p ;
    }
    std::cout << std::endl;

}


int main()
{

    //матрица смежности
    vector<vector<int>> mgraf = {{0, 7, 9, 0, 0,14},
                                {7, 0, 10,15,0,0},
                                {9, 10,0, 11,0,2},
                                {0, 15,11,0, 6,0},
                                {0, 0, 0, 6, 0,9},
                                {14,0, 2, 0, 9,0}};
    std::cout << "deikstra 0-4 " << deikstra(mgraf, GrafP(0), GrafP(4)) << std::endl;


    //список смежности
        vector<list<PInfo>> lgraf = {{{GrafP(1),7}, {GrafP(2),9}, {GrafP(5),14}},
                                 {{GrafP(0),7}, {GrafP(2),10}, {GrafP(3),15}},
                                 {{GrafP(0),9}, {GrafP(1),10}, {GrafP(3),11}, {GrafP(5), 2}},
                                 {{GrafP(1),15}, {GrafP(2),11}, {GrafP(4),6}},
                                 {{GrafP(3),6}, {GrafP(5),9}},
                                 {{GrafP(0),14}, {GrafP(2),2}, {GrafP(4),9}}};


    convertToMatrixAndCheck(lgraf, mgraf);
    std::cout << "deikstra 0-4 " << endl;
    deikstraList(lgraf, GrafP(0), GrafP(4));
    return 0;
}

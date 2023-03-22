#include <iostream>
#include <vector>


using namespace std;


vector< vector<int> > matrix = {{15, 20, 70, 85},
                                {20, 35, 79, 95},
                                {30, 55, 95, 105},
                                {40, 80, 100, 120}};

bool binarySearch(vector< vector<int> > &matrix, int startR, int endR, int startC, int endC , int searchVal){
    if(startR > endR || startC > endC){
        return false;
    }
        auto midR = startR + (endR - startR) / 2;
        auto midC = startC + (endC - startC) / 2;

        if (matrix[midR][midC] == searchVal){
            return true;
        }
        if (matrix[midR - 1][midC - 1] > searchVal){
            return binarySearch(matrix, 0, midR - 1, 0, midC - 1, searchVal);
        }
        else if(matrix[midR][midC] < searchVal){
            return binarySearch(matrix, midR, endR, midC, endC, searchVal);
        }
        else{
            return binarySearch(matrix, startR, midR - 1, midC, endC, searchVal) ||
                    binarySearch(matrix, midR + 1, endR, startC, midC, searchVal);

        }

}

void func() {
    int32_t a = 0x400;
    uint8_t *b = reinterpret_cast<uint8_t*>(&a);
    for (size_t i=0; i<sizeof(int32_t); ++i) {
        printf("0x%02x ", b[i]);
    }
}


int main()
{
func();
    //bool result = binarySearch(matrix, 0, matrix.size(), 0 , matrix.size(), 100);
    //cout << "Hello World! " << result << endl;
    return 0;
}

#include <iostream>
#include <string>
#include "vector.h"
#include "vector_alloc.h"
#include <vector>

#include "unordered_set.h"

#include <unordered_set>

#include "allocator.h"

#include <memory>

#include "var_temp.h"
#include <list>

using std::string;

class TestClass{
    std::string value;
public:

    static inline int16_t counter = 0;

    //TestClass(){cout << "constr def " << value << endl; counter++;}

    TestClass(const std::string& value):value(value) {cout << "constr " << value << endl; counter++;}

    TestClass(const TestClass &t){
        value = t.value;
        cout << "copy " << value << endl;
        counter++;
    }

    TestClass(TestClass &&t): value(std::move(t.value)){

        cout << "move " << value << endl;
    }

    bool operator!=(TestClass &t){
        return t.value == value;
    }

    ~TestClass(){
        cout << "destructor " << value << endl;
        counter--;
    }

    std::string get() const{
        return value;
    }

    void set(std::string value){
        this->value = value;
    }
    friend class std::hash<TestClass>;
};


template <>
struct std::hash<TestClass>
{

    std::size_t operator()(const TestClass& k) const
    {
        using std::size_t;
        using std::hash;
        using std::string;

        // Compute individual hash values for first,
        // second and third and combine them using XOR
        // and bit shifting:

        return hash<string>{}(k.value);
    }
};

struct List{
    int val;
    List *next;
    List(int val): val(val){}
};

List* merge(List *list1, List *list2){
    if (list1 == nullptr){
        return list2;
    }
    if (list2 == nullptr){
        return list1;
    }

    List * ptr = list1;
    if(list1->val > list2->val)
    {
        ptr = list2;
        list2 = list2 -> next;
    }
    else
    {
        list1 = list1 -> next;
    }
    List *curr = ptr;

    // till one of the list doesn't reaches NULL
    while(list1 &&  list2)
    {
        if(list1->val < list2->val){
            curr->next = list1;
            list1 = list1 -> next;
        }
        else{
            curr->next = list2;
            list2 = list2 -> next;
        }
        curr = curr -> next;

    }

    // adding remaining elements of bigger list.
    if(!list1)
        curr -> next = list2;
    else
        curr -> next = list1;

    return ptr;

}

#include <fstream>
#include <algorithm>
#include <ctime>

const string testFileName = "test_file.txt";

std::string generateString(){
    auto res = (std::rand() % 256) + 1;
    std::string str(res, ' ');

    for(auto &c: str){
        c = (std::rand() % 26) + 'a';
    }
    return str;
}

void generateFile(uint8_t gb){
    std::srand(std::time(nullptr));

    std::ofstream outfile;
    outfile.open(testFileName);

    if (outfile.is_open()) {
        cout << "file " << testFileName << " start generate" << endl;
        const uint64_t sizeInBytes = gb * 1024 * 1024 * 1024;
        uint64_t currentSizeInBytes = 0;

        while (currentSizeInBytes < sizeInBytes) {
            auto writeStr = generateString();
            outfile << writeStr << "\n";
            currentSizeInBytes += writeStr.size() + 1;
        }
    }
    else{
        cout << "file " << testFileName << " not open" << endl;
    }

}

int main() {


    //generateFile(1);

    std::vector<string> inList;

    inList.resize(1000);

    std::ifstream myfile;
    myfile.open(testFileName.);

    size_t counter = 0;
    while(myfile) {
        size_t iter = 0;

        while (myfile or iter < inList.size()) {

            std::string tmp;
            myfile >> tmp;
            inList[iter] = std::move(tmp);
            ++iter;
        }
        std::sort(inList.begin(), inList.end());
        std::ofstream outfile;
        outfile.open(testFileName + "_" + std::to_string(++counter));

        for(auto &str: inList) {
            outfile << str;
        }
    }*/



/*    List *first = new List(3);
    List *second = new List(4);

    first->next = new List(27);
    second->next = new List(28);

    first = merge(first, second);

*/
    /*mvector_alloc::Vector<TestClass, Moya::Allocator<TestClass>> vec;

    vec.push_back(TestClass("my string"));
    vec.push_back(TestClass("my string2"));
    vec.push_back(TestClass("my string3"));


    std::cout << vec[0].get() << std::endl;
    std::cout << vec[1].get() << std::endl;
    std::cout << vec[2].get() << std::endl;


    cout << "-----------\n" ;

    var_temp::tfunc<int, int>(3, 4.0);*/

   /* std::vector<TestClass> vec2;


    vec2.push_back(TestClass("my string"));
    vec2.push_back(TestClass("my string2"));
    vec2.push_back(TestClass("my string3"));


    std::cout << vec2[0].get() << std::endl;
    std::cout << vec2[1].get() << std::endl;
    std::cout << vec2[2].get() << std::endl;*/
    //vec2.resize(2);*/

    /*Unorderded_set<string, TestClass> us;

    std::string yeksd = "yeksd";
    auto mstr3 = TestClass("my string3");

    us.insert("key", TestClass("my string"));
    us.insert("eyk", TestClass("my string2"));


    std::cout << "key " << us["key"].get() << endl;
    std::cout << "eyk " << us["eyk"].get() << endl;
    std::cout << "yeksd " << us["yeksd"].get() << endl;


    std::unordered_set<string, TestClass> us2;*/

    //us2.insert("eyk", TestClass("my string2"));

   /* Unorderded_set<TestClass, string> us;

    us.insert(TestClass("key"), "my string");

    std::cout << "key " << us[TestClass("key")] << endl;*/

    return 0;
}

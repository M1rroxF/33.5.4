#include <iostream>
#include <vector>
#include <string>
//#include "boost/asio.hpp"

using namespace std;
//using namespace boost::asio;

template<typename T>
class MyVec {
    vector<T> vec;

  public:

    void push_back(T n) {
        vec.push_back(n);
    }

    void print() {
        T sum;
        for (auto& i : vec) sum += i;
        if (vec.size()!=0) cout << sum/vec.size() << endl;
        else cout << "Error size" << endl;
    }
};

int main() {
    MyVec<double> vec;
    vec.print();

    vec.push_back(10);
    vec.push_back(8);
    vec.print(); // 18/2
}
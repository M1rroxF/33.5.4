#include <iostream>
#include <vector>
#include <string>
//#include "boost/asio.hpp"

using namespace std;
//using namespace boost::asio;

template<typename T1, typename T2>
struct MyMapIterator {
    T1 key;
    T2 value;
};

template<typename T1, typename T2>
class MyMap {
    vector<T1> key;
    vector<T2> value;

  public:

    void add(T1 n1, T2 n2) {
        key.push_back(n1);
        value.push_back(n2);
    }

    void remove(T1 _key) {
        for (int i = 0; i < key.size(); i++) {
            if (key[i] == _key) {
                for (int j = i; j < key.size()-1; i++) {
                    key[j] = key[j+1];
                    value[j] = value[j+1];
                }
                key.resize(key.size()-1);
                value.resize(value.size()-1);
            }
        }
    }

    MyMapIterator<T1, T2> find(T1 _key) {
        MyMapIterator<T1, T2> s;
        for (int i = 0; i < key.size(); i++) {
            if (key[i] == _key) {
                s.key = key[i];
                s.value = value[i];
            }
        }
        return s;
    }

    void print() {
        for (int i = 0; i < key.size(); i++) {
            cout << key[i] << " - " << value[i] << endl;
        }
    }
};

int main() {
    MyMap<int, string> s;
    s.add(1, "hello");
    s.add(2, "privet");

    s.print();

    auto it = s.find(2);
    cout << "!" << it.value << endl;

    s.remove(2);
    s.print();
}
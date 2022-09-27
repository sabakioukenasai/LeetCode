#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class OrderedStream{
private:
    vector<string> box;
    const int cap;
    int ptr;

public :
    OrderedStream(int n) : cap(n) {
        box = vector<string>(n);
        ptr = 0;
        for (int i = 0; i < cap; ++i)
            box[i] = "";
    }
    vector<string> insert(int idKey, string value){
        box[idKey - 1] = value;
        if (ptr + 1 == idKey){
            int begin = ptr;
            while(ptr < cap && box[ptr] != "")
                ++ptr;
            cout << "id: " << idKey << ", begin: " << begin << ", end: " << ptr << endl;
            return vector<string> (box.begin() + begin, box.begin() + ptr);
        }
        return vector<string>(0);
    }
};

int main(){
    OrderedStream os= OrderedStream(5);
    vector<string> a1 = os.insert(3, "ccccc"); // 插入 (3, "ccccc")，返回 []
    for (int i = 0; i < a1.size(); ++i)
        cout << a1[i] << ", ";
    cout << endl;

    vector<string> a2 = os.insert(1, "aaaaa"); // 插入 (1, "aaaaa")，返回 ["aaaaa"]
    for (int i = 0; i < a2.size(); ++i)
        cout << a2[i] << ", ";
    cout << endl;

    vector<string> a3 = os.insert(2, "bbbbb"); // 插入 (2, "bbbbb")，返回 ["bbbbb", "ccccc"]
    for (int i = 0; i < a3.size(); ++i)
        cout << a3[i] << ", ";
    cout << endl;

    vector<string> a4 = os.insert(5, "eeeee"); // 插入 (5, "eeeee")，返回 []
    for (int i = 0; i < a4.size(); ++i)
        cout << a4[i] << ", ";
    cout << endl;

    vector<string> a5 = os.insert(4, "ddddd"); // 插入 (4, "ddddd")，返回 ["ddddd", "eeeee"]
    for (int i = 0; i < a5.size(); ++i)
        cout << a5[i] << ", ";
    cout << endl;
}
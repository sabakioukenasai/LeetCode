#include <vector>
#include <queue>

using std::pair;
using std::queue;
using std::vector;

class AnimalShelf {
private:
    int type;
    queue<pair<int, int>> oneType;
    queue<pair<int, int>> bothTypes;

public:
    AnimalShelf() {
        type = 0;
    }
    
    void enqueue(vector<int> animal) {
        bothTypes.emplace(animal[0], animal[1]);
    }
    
    vector<int> dequeueAny() {
        vector<int> animal;
        if (!oneType.empty()){
            animal.push_back(oneType.front().first);
            animal.push_back(oneType.front().second);
            oneType.pop();
        }
        else if (!bothTypes.empty()){
            animal.push_back(bothTypes.front().first);
            animal.push_back(bothTypes.front().second);
            bothTypes.pop();
        }
        else
        {
            animal.push_back(-1);
            animal.push_back(-1);
        }
        return animal;
    }
    
    vector<int> dequeueDog() {
        vector<int> animal;
        if (oneType.empty() || !type){
            // 跳过所有猫猫
            while(!bothTypes.empty() && !bothTypes.front().second){
                oneType.push(bothTypes.front());
                bothTypes.pop();
            }
            if (bothTypes.empty()){
                animal.push_back(-1);
                animal.push_back(-1);
            }
            else
            {
                animal.push_back(bothTypes.front().first);
                animal.push_back(bothTypes.front().second);
                bothTypes.pop();
            }
            
        }
        else {
            animal.push_back(oneType.front().first);
            animal.push_back(oneType.front().second);
            oneType.pop();
        }

        // 更新 oneType 队列中储存的动物的种类
        if (!oneType.empty())
            type = oneType.front().second;
        return animal;
    }
    
    vector<int> dequeueCat() {
        vector<int> animal;
        if (oneType.empty() || type){
            // 跳过所有狗狗
            while(!bothTypes.empty() && bothTypes.front().second){
                oneType.push(bothTypes.front());
                bothTypes.pop();
            }
            if (bothTypes.empty()){
                animal.push_back(-1);
                animal.push_back(-1);
            }
            else
            {
                animal.push_back(bothTypes.front().first);
                animal.push_back(bothTypes.front().second);
                bothTypes.pop();
            }
            
        }
        else {
            animal.push_back(oneType.front().first);
            animal.push_back(oneType.front().second);
            oneType.pop();
        }

        // 更新 oneType 队列中储存的动物的种类
        if (!oneType.empty())
            type = oneType.front().second;
        return animal;
    }
};
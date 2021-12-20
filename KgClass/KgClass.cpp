#include <iostream>
#include <algorithm>
#include <vector>

// #include "FindPrimitiveRoot/FindPrimitiveRoot.cpp"

using namespace std;

template <typename T>
bool contains(vector<T> vec, const T & elem)
{
    bool result = false;
    if( find(vec.begin(), vec.end(), elem) != vec.end() )
    {
        result = true;
    }
    return result;
}

struct KgClass {
    int GroupOrder;
    int variant;
    int PrimitiveRoot;

    int findPrimitiveRoot() {
        vector<int> groupElems;
        int result = -1;

        vector<int> ptr;

        //Инициализировали группу
        for (int i = 0; i < this->GroupOrder; i++)
        {
            groupElems.push_back(i);
        }

        //Находим первообразный корень
        for (int i = 2; i < this->GroupOrder; i++)  
        {
            int deg = i;
            for (int j = 0; j < this->GroupOrder; j++) {
                //Првоеряем лежит ли элемент внутри массива ptr
                if (contains(ptr, deg)) {
                    //Если лежит, смотрим порождает ли элемент группу
                    if (ptr.size() == this->GroupOrder - 1) 
                    { 
                        result = i;
                        break;
                    } 
                    //Нет, тогда чистим масиив и переходим на следующий i
                    else {
                        if (i == 7) {
                            cout << ptr.size() << endl;
                        }
                        ptr.clear();
                        break;
                    }
                }
                ptr.push_back(deg % this->GroupOrder);   
                // for (int l = 0; l < ptr.size(); l++)
                // {
                //     cout << ptr[l] << " ";
                // } 
                // cout << endl;
                deg *= i;      
                deg %= this->GroupOrder;
            }
            if (result != -1) break;
        }
        return result;
    }

    KgClass(int variant, int GroupOrder) {
        this->variant = variant;
        this->GroupOrder = GroupOrder;
        this->PrimitiveRoot = this->findPrimitiveRoot();
    }

    int RoMethodPolarda() {
        
    }

};
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "./KgClass/KgClass.h"

using namespace std;

int main() {
    int variant;
    int GroupOrder;

    fstream fin("FilesData/kg.txt");
    fin >> variant >> GroupOrder;
    fin.close();
    
    KgClass Kg(variant, GroupOrder);

    cout << Kg.RoMethodPolarda();

    return 0;
}
#include <iostream>
#include <vector>


void selectionSort(std::vector<float>& a,std::vector<float>& b,std::vector<float>& c) {
    for (int i = 0; i < a.size(); i++) {
        float min = a.at(i);
        for (int j = 0; j < a.size(); j++) {
            if (min > a.at(j)) {
                std::swap(a.at(i), a.at(j));
                std::swap(b.at(i), b.at(j));
                std::swap(c.at(i), c.at(j));
                min = a.at(i);
            }
        }
    }
}

int main() {
    int numberOfItems;
    float totalWeight,temp;
    std::vector<float> profit, weightValue,ratio;
    std::cin >> numberOfItems;

    for (int i = 0; i < numberOfItems; i++) {
        std::cin >> temp;
        weightValue.push_back(temp);
    
    }
    for (int i = 0; i < numberOfItems; i++) {
        std::cin >> temp;
        profit.push_back(temp);
    }
    
    std::cin >> totalWeight;

    for (int i = 0; i < numberOfItems; i++) {
        ratio.push_back(profit.at(i) / weightValue.at(i));
    }
 
    selectionSort(ratio,profit,weightValue);
    float output = 0.0;
    int count = 0;

     while (totalWeight > 0) {
            if (totalWeight > weightValue.at(count)){
                output += profit.at(count);
                std::cout << weightValue.at(count) << " " << profit.at(count) << std::endl;
                totalWeight -= weightValue.at(count);
            } else {
                output = output + (totalWeight/weightValue.at(count))*profit.at(count);
                std::cout << totalWeight << " " << (totalWeight/weightValue.at(count))*profit.at(count) << std::endl;
                totalWeight = 0;  
            }
            count++;
    }

    std::cout << "Total Profit:" << output;
    return 0;
}


// Output in the form of :
// A 001
// B 010
// C 0011
//
//  main.cpp
//  functionTest
//
//  Created by Carlos on 23/5/21.
//

#include <iostream>
#include <vector>

std::vector<std::function<void(void)>> actions;

void funcA(void) {
    std::cout << "A" << std::endl;
}

void funcB(void) {
    std::cout << "B" << std::endl;
}

void funcC(std::vector<int> v) {
    for (auto d : v) {
        std::cout << d << std::endl;
    }
}

void dispatch(std::function<void(void)> a) {
    actions.push_back(a);
}

void performActions() {
    for (auto a : actions) {
        a();
    }
}

int main(int argc, const char * argv[]) {
    
    dispatch(funcA);
    
    dispatch(funcB);
    
    std::vector<int> v = {1,2,3,4,5};
    dispatch([=]{
        funcC(v);
    });
    
    std::cout << "Hello, World!\n";
    
    performActions();
    return 0;
}

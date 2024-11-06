//
//  main.cpp
//  dynamic-array-implementation
//
//  Created by Godswill Adigwe on 06/11/2024.
//

#include <iostream>
#include <optional>

class DynamicArray {
public:
    int arraycapacity;
    int* dynamicArray;
    
    DynamicArray(int capacity) {
        
        arraycapacity = capacity;
        
        dynamicArray = new int[capacity];
        
        for(int i = 0; i < capacity; i++) {
            dynamicArray[i] = 0;
        }
        
    }
    
    ~DynamicArray() {
        delete [] dynamicArray;
    }
    
    void insert(int value, std::optional<int>index = std::nullopt) {
       
        if(index){
            int i = index.value();
            if(i < arraycapacity && i >= 0){
                dynamicArray[i] = value;
            }
        }else{
            
            int* newArray = new int[arraycapacity+1];
            
            for(int j = 0; j < arraycapacity+1; j++ ){
                
                if(j == arraycapacity){
                    newArray[j] = value;
                    
                }else{
                    newArray[j] = dynamicArray[j];
                }
                
            }
            
            delete[] dynamicArray;
            
            dynamicArray = newArray;
            
            arraycapacity += 1;
 
        }
    }
    
    void print() const {
        for (int i = 0; i < arraycapacity; i++) {
            std::cout << dynamicArray[i] << " ";
        }
        
        std::cout << std::endl;
    }
    
    void remove(int index) {
        if(index < 0 || index >= arraycapacity) {
            
            std::cout << "Index out of bounds." << std::endl;
            
            return;
            
        }
        
        int* newArray = new int[arraycapacity-1];
        
        for(int i = 0, j = 0; i < arraycapacity; i++){
            
            if(i != index) {
               
                newArray[j] = dynamicArray[i];
                j++;
            }
            
        }
        
        delete[] dynamicArray;
        
        dynamicArray = newArray;
        arraycapacity -= 1;
    }
    
    std::optional<int> get(int index) const {
        
        if(index < 0 || index >= arraycapacity) {
            return std::nullopt;
        }
        
        return dynamicArray[index];
    }
    
    
    int size() const {
        
        return arraycapacity;
        
    }
    
};

int main(int argc, const char * argv[]) {
    
    DynamicArray arr(5);
    std::cout << arr.size() << std::endl;
    arr.insert(10);
    std::cout << arr.size() << std::endl;
    arr.print();
    return 0;
}

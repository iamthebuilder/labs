#include <iostream>
#include "DynamicArray.h"
#include "Outerwear.h"
#include "Sportswear.h"
#include "Underwear.h"
#include "Footwear.h"
#include "Product.h"

//нужно было бы по-хорошему прописать что-то по типу using std::endl и так далее,а не std:: везде

int main() {
    DynamicArray arr;
    DynamicArray load;
    std::string filename = "products.txt";
    setlocale(LC_ALL, "ru");

    Outerwear* jacket =new Outerwear("курточка", 300, 5, "лето", true);
    std::cout << jacket->getName()<<std::endl;
    jacket->setName("джинсовочка");
    arr.addObject(jacket);
    arr.addObject(new Sportswear("костюм", 99, 5, "футболь"));
    arr.addObject(new Underwear("бельё", 49, 5, "лён"));
    arr.addObject(new Footwear("сапог", 187, 5, "женский", true));

    
    std::cout << "товаы:" << std::endl;
    arr.displayArray();
    arr.removeObject(1);

     
   arr.saveToFile(filename);
   load.loadFromFile(filename);
   std::cout << "after loading"<<std::endl;
   load.displayArray();
 
   return 0;
}

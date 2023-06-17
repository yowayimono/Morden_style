/*
 * @Author: yowayimono
 * @Date: 2023-06-16 10:57:51
 * @LastEditors: yowayimono
 * @LastEditTime: 2023-06-17 14:40:21
 * @Description: nothing
 */

#include "Morden_style.hpp"

#include <iostream>


class A{
public:
    A(){
        std::cout<<"A 构造完成~"<<std::endl;
    }

    ~A(){
        std::cout<<"A 销毁~"<<std::endl;
    }
private:

};

auto main() ->int {
    auto ptr = Rc<A>();
    
}
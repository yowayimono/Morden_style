/*
 * @Author: yowayimono
 * @Date: 2023-06-16 10:57:51
 * @LastEditors: yowayimono
 * @LastEditTime: 2023-06-16 11:16:44
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
    std::string str="hello,覃文敏!";
    std::string str2=m(str);
    std::cout<<str2<<' '<<str<<' ';
    auto ptr = Box<A>();
}
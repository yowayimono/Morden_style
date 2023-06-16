
/*
 *                        _oo0oo_
 *                       o8888888o
 *                       88" . "88
 *                       (| -_- |)
 *                       0\  =  /0
 *                     ___/`---'\___
 *                   .' \\|     |// '.
 *                  / \\|||  :  |||// \
 *                 / _||||| -:- |||||- \
 *                |   | \\\  - /// |   |
 *                | \_|  ''\---/''  |_/ |
 *                \  .-\__  '-'  ___/-. /
 *              ___'. .'  /--.--\  `. .'___
 *           ."" '<  `.___\_<|>_/___.' >' "".
 *          | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *          \  \ `_.   \_ __\ /__ _/   .-` /  /
 *      =====`-.____`.___ \_____/___.-`___.-'=====
 *                        `=---='
 * 
 * 
 *      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 *            佛祖保佑     永不宕机     永无BUG
 */
#pragma once
#ifndef MORDEN_STYLE_HPP
#define MORDEN_STYLE_HPP

#include <memory>
#include <iostream>
#include <string>
#include <utility>


#define m(x) std::move(x)

template<typename T, typename... Args>
std::unique_ptr<T> Box(Args&&... args) {
    T* obj = new T(std::forward<Args>(args)...);
    return std::unique_ptr<T>(obj);
}



template<typename T,typename... Args>
std::shared_ptr<T> Arc(Args&&... args) {
         T* obj = new T(std::forward<Args>(args)...);
        return std::shared_ptr<T>(obj);
}



#endif

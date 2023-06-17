
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

#define ref(type,name) const type& name 
#define m(x) std::move(x)
#define i32 int32_t
#define i64 int64_t
#define i128 int128_t

#define ref(type,name) const type& name

#define _mut(type,name) type& name

#define _Str(name) char* name  



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



template <typename T>
class SharedPtr {
public:
    SharedPtr(T* ptr = nullptr) : data_(ptr), refCount_(new int(1)) {}

    ~SharedPtr() {
        if (--(*refCount_) == 0) {
            delete data_;
            delete refCount_;
        }
    }

    SharedPtr(const SharedPtr& other) : data_(other.data_), refCount_(other.refCount_) {
        ++(*refCount_);
    }

    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            if (--(*refCount_) == 0) {
                delete data_;
                delete refCount_;
            }
            data_ = other.data_;
            refCount_ = other.refCount_;
            ++(*refCount_);
        }
        return *this;
    }

    T& operator*() const {
        return *data_;
    }

    T* operator->() const {
        return data_;
    }

private:
    T* data_;
    int* refCount_;
};



template <typename T, typename... Args>
SharedPtr<T> Rc(Args&&... args) {
    return SharedPtr<T>(new T(std::forward<Args>(args)...));
}

#endif

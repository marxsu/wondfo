/**********************************************************************
 * @file singleton.h
 * @brief   单例模版类（多线程下、谨慎使用）
 * @details
 * @mainpage  404
 * @author sushaobin
 * @version 0.1
 * @date 2022-10-09
 * @license MIT
 **********************************************************************/
#ifndef SINGLETON_H
#define SINGLETON_H
#include <pthread.h>

template <typename T>
class CSingleton
{
public:
    static T &GetInstance()
    {
        pthread_mutex_lock(&mutex);
        if(instance==nullptr)
        {
            instance = new T();
        }
        pthread_mutex_unlock(&mutex);
        return *instance;
    }
protected:
    CSingleton()
    {
    }

    ~CSingleton()
    {

    }

    CSingleton(const CSingleton &) = delete;

    CSingleton &operator=(const CSingleton &) = delete;

    static pthread_mutex_t mutex;

    static T* instance;
};

template<typename T>
T* CSingleton<T>::instance = nullptr;

template<typename T>
pthread_mutex_t CSingleton<T>::mutex = PTHREAD_MUTEX_INITIALIZER;

/* demo
#include "singleton/singleton.h"

class Test : public CSingleton<Test>
{
    friend class CSingleton;
private:
        Test()
        {

        }
public:
        int data;
};
*/

#endif  

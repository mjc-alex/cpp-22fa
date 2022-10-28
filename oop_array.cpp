//include the headers that you need here.
#include <memory.h>
#include<cstdlib>
#include<assert.h>
#include<iostream>
class CArray
{
public:
    typedef int Element;

public:
    CArray():num(0),cap(0),buff(NULL){ }
    ~CArray(){
        delete []buff;
    }

    int capacity() const{
        return cap;
    };
    int size() const{
        return num;
    };

    void recap(int capacity){
        if (capacity == cap) return;
        int* p = new int[capacity];
        num = num > capacity ? capacity : num;
        for (int i = 0; i < num; ++i){
            p[i] = buff[i];
        }
        delete []buff;
        buff = p;
        cap = capacity;
    };

    Element &at(int index){
        return buff[index];
    }
    //Element at(int index) const;

    void append(Element element){
        if (num >= cap){
            int capacity = (int)cap * 2;
            recap(capacity < num ? num : capacity);
        }
        buff[num] = element;
        ++num;
    }
    void insert(int index, Element element){
        if (num >= cap){
            int capacity = (int)cap * 2;
            recap(capacity < num ? num : capacity);
        }
        for(int i = num; i > index; --i){
            buff[i] = buff[i-1];
        }
        buff[index] = element;
        ++num;
    }

    void copy(const CArray &rhs){
        if(rhs.cap > cap)
        recap(rhs.cap);
        for(int i=0; i< rhs.num; ++i){
        buff[i] = rhs.buff[i];
        }
        num = rhs.num;
    }

    bool compare(const CArray &rhs) const{
        if(num != rhs.num)    return false;
        for(int i = 0; i < num; ++i){
            if(buff[i] != rhs.buff[i])
                return false;
        }
        return true;
    }

private:
    /*data*/
    int cap = 0;
    int num = 0;
    int *buff = NULL;
};



int main(int argc, char *argv[])
{
    CArray array;
    // 不再需要initial，但应该有正确的初始化
    // array_initial(array);
    array.recap(10);
    assert(array.capacity() == 10);
    //////////////////////////////////////////////////////////////////////////
    for (int i = 0; i < 20; ++i)
    {
        array.append(i);
    }
    assert(array.size() == 20);
    for (int i = 0; i < array.size(); ++i)
    {
        assert(array.at(i) == i);
    }
    //////////////////////////////////////////////////////////////////////////
    CArray array2, array3;
    // array_initial(array2);
    // array_initial(array3);
    array2.copy(array);
    assert(array.compare(array2) == true);
    array3.copy(array);
    assert(array.compare(array3) == true);
    //////////////////////////////////////////////////////////////////////////
    array2.insert(2, 3);
    assert(array.compare(array2) == false);
    //////////////////////////////////////////////////////////////////////////
    array3.at(2) = 5;
    assert(array.compare(array3) == false);
    //////////////////////////////////////////////////////////////////////////
    // 不再需要destroy，但应该有正确的内存释放
    // array_destroy(array);
    // array_destroy(array2);
    // array_destroy(array3);
    std::cout<<"YES"<<std::endl;
	return 0;
}


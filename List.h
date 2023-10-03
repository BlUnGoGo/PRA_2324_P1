#ifndef LIST_H
#define LIST_H

template <typename T> 
class List {
    public:
       virtual void insert(int pos, T e);
       virtual void append(T e);
       virtual void prepend(T e);
       virtual T remuve(int pos);
       virtual T get(int pos);
       virtual int seaarch(T e);
       virtual bool empty();
       virtual int size();

};

#endif

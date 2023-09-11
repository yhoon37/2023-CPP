#ifndef UNTITLED_MY_ACCUMULATE_H
#define UNTITLED_MY_ACCUMULATE_H

template<typename T, typename U>
U my_accumulate(T _begin, T _end, U init){
    U sum=0;
    for(auto i= _begin; i!=_end; i++){
        sum+= *i;
    }
    return init+sum;
}

#endif //UNTITLED_MY_ACCUMULATE_H

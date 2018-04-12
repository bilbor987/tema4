#include <iostream>

using namespace std;

///tema: o functie templatizata variadic care sa preia n argumente si sa gaseasca maximul din ele
///cine implementeaza si iterativ si recursiv un +

template <class Arg, class ... Args>
auto sum(Arg arg, Args ... args) ->Arg{
    Arg aux = arg;
    for(auto it : {args...})
        aux += it;
    return aux;

};
///iterativ
template <class Arg, class ... Args>
auto myMax(Arg arg, Args ... args)->Arg{
    Arg max = arg;
    for(auto it: {args...})
        if(it > max)
            max = it;

    return max;
};
///recursiv
template<class T>
T myMax2(T a, T b)
{
    return a > b ? a : b;
}

template<class Arg, class... Args>
auto myMax2(Arg arg1, Arg arg2, Args&&... args)->Arg {///fiecare argument variabil e pasat ca referinta (primul &) iar al doilea & e ca sa poata itera functia pe lista de argumente
    if (arg1 > arg2) {
        return myMax2(arg1, forward<Args>(args)...);///forward imi extrage urmatorul argument
    } else {
        return myMax2(arg2, forward<Args>(args)...);
    }
}


int main() {
    //cout<<sum(5,6,7,8,9);
    cout<<myMax(1,2,3,0,5,4)<<endl;
    cout<<myMax2(1,2,3,0,5,4)<<endl;
    cout<<myMax2(1,2,3,4,5,6,7,8);

    return 0;
}
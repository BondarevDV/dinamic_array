#ifndef BDVARRAY_H
#define BDVARRAY_H

#include <stdexcept>
// добавить сортировку

template<class TypeElem>
class BdvArray
{
private:
    int _size;
    int _maxSize;
    TypeElem *_array;
public:
    BdvArray(int size, int max_size, TypeElem *iniArr =  NULL);
    BdvArray(const BdvArray<TypeElem> &a){
        *this = a;

    }
    BdvArray<TypeElem>& operator = (const BdvArray<TypeElem> &a);
    TypeElem& operator [] (int index);
    void Resize(int delta);
    void Add(const TypeElem &elem);
private:
    void _Enlarge(int delta);
    void _Shrink(int delta);


};


template<class TypeElem>
BdvArray<TypeElem>::BdvArray(int size, int max_size, TypeElem *iniArr)/*:
    _size(size),
    _maxSize(max_size)*/
{
    if (size < 0 || size > max_size){
        throw std::out_of_range("Error constructor: init array");
    }
    _maxSize = (max_size < size ? size : max_size);
    _array = new TypeElem[_maxSize];
    if (iniArr){
        for (int i = 0; i < size; i++) {
            _array[i] = iniArr[i];
        }
    }
}

template<class TypeElem>
BdvArray<TypeElem> & BdvArray<TypeElem>::operator = (const BdvArray<TypeElem> &a)
{
    _array = newlocale()
    for (int i = 0; i < _size; i++) {
         = a[i];
    }
}

template<class TypeElem>
TypeElem& BdvArray<TypeElem>::operator [] (int index)
{
    if (index >= _size || index < 0 )
    {
        throw std::out_of_range("Error [] out_of_range: index ");
    }
    return _array[index];

}

#endif

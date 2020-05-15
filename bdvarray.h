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
    BdvArray(int size = 0, int max_size = 0, TypeElem *iniArr =  NULL);
    BdvArray(const BdvArray<TypeElem> &a){
        *this = a;
    }
    BdvArray<TypeElem>& operator = (const BdvArray<TypeElem> &a);
    TypeElem& operator [] (int index);
    int size();
    void Resize(int delta);
    void Add(const TypeElem &elem);
private:
    void _Enlarge(int delta);
    void _Shrink(int delta);


};


template<class TypeElem>
BdvArray<TypeElem>::BdvArray(int size, int max_size, TypeElem *iniArr)
{
    _maxSize = (max_size < size ? size : max_size);
    _size = size;
    if (_size < 0 || _size > _maxSize){
        throw std::out_of_range("Error constructor: init array 2222");
    }

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
    _array = new TypeElem[a._maxSize];
    for (int i = 0; i < a._maxSize; i++) {
        _array[i] = a[i];
    }
    return *this;
}

template<class TypeElem>
TypeElem& BdvArray<TypeElem>::operator [] (int index)
{
    if (index >= _size || index < 0 ){
        throw std::out_of_range("Error [] out_of_range: index ");
    }
    return _array[index];

}

template<class TypeElem>
int BdvArray<TypeElem>::size()
{
    return _size;

}

template<class TypeElem>
void BdvArray<TypeElem>::Resize(int delta)
{
    if (delta > 0){
        _Enlarge(delta);
    } else if (delta < 0){
        _Shrink(delta);
    }
}

template<class TypeElem>
void BdvArray<TypeElem>::Add(const TypeElem &elem)
{
    Resize(1);
    _array[_size - 1] = elem;

}

template<class TypeElem>
void BdvArray<TypeElem>::_Enlarge(int delta)
{
    _size += delta;
    TypeElem* tmp_array = new TypeElem [_size];
    for (int i = 0; i < _size - delta; i++) {
        tmp_array[i] = _array[i];
    }
    _array = tmp_array;
    if ( _size > _maxSize) _maxSize = _size;
}

template<class TypeElem>
void BdvArray<TypeElem>::_Shrink(int delta)
{
    _size = (delta > _size ? 0 : _size - delta);
    TypeElem* tmp_array = new TypeElem [_size];
    for (int i = 0; i < _size; i++) {
        tmp_array[i] = _array[i];
    }
    _array = tmp_array;
}

#endif

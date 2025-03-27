/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_BinarySearch_hpp)
#define Apoxi_BinarySearch_hpp



/*template<class T1,class T2> class Less {
    public:
        inline INT Compare(const T1 &e1, const T2 &e2) const { return e1 < e2 ? -1 : (e1 == e2 ? 0 : 1); }
};
*/

template<class T> class CArray {
    public:
        typedef T ElemType;

        inline CArray(const T *arr, INT size) : m_size(size), m_arr(arr) {};

        inline INT Size() const { return m_size; };
        inline const T& operator[](INT i) const { return m_arr[i]; };

    private:
        INT m_size;
        const T *m_arr;
};


/*  ------------------------------------------------------------------------
    BinarySearch
    ------------------------------------------------------------------------ */
template<class Collection, class Key, class Pred> inline
    INT BinarySearch(const Collection &arr, const Key &key)
{
    return BinarySearch(arr, key, Pred(), 0);
}   // BinarySearch


/*  ------------------------------------------------------------------------
    BinarySearch
    ------------------------------------------------------------------------ */
template<class Collection, class Key, class Pred> inline
    INT BinarySearch(const Collection &arr, const Key &key, const Pred &pred)
{
    return BinarySearch(arr, key, pred, 0);
}   // BinarySearch


/*  ------------------------------------------------------------------------
    BinarySearch
    ------------------------------------------------------------------------ */
template<class Collection, class Key, class Pred> inline
    INT BinarySearch(const Collection &arr, const Key &key, const Pred &pred, INT *insert)
{
    INT left = 0;
    INT right = arr.Size() - 1;
    INT middle = 0;

    while (right >= left) {
        middle = (left + right) / 2;
        INT result = pred.Compare(key, arr[middle]);

        if (result == 0)
            return middle;

        if (result < 0)
            right = middle - 1;
        else
            left = middle + 1;
    }

    if (insert != 0)
        *insert = middle;

    return -1;
}   // BinarySearch

#endif  // Apoxi_BinarySearch_hpp



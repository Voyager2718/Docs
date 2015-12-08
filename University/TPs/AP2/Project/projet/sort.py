#!/usr/bin/python3
# -*- coding: utf-8 -*-

"""
:mod:`cercles` module

:author: YANG_ZINGOUCAI

:date: 19 novembre 2015

File sort
"""
def compare_circle(c1,c2):
    """
    :param c1:
    :type c1:
    :param c2:
    :type c2:
    :return: 
    """
    if c1[2]<c2[2]:
        return -1
    elif c1[2]>c2[2]:
        return 1
    else:
        return 0

def partition (x, l,f):
    """
    return a couple (l1,l2) of lists with elements of l1 <= x
    and elements of l2 > x.

    :param x: a pivot
    :param l:
    :type l: list
    :return: a couple of two lists with elements de l1 <= l[0] 
             and elements of l2 > l[0]
    :rtype: tuple
    :UC: x must be comparable with elements
    """
    if l == []:
        return ([],[])
    else:
        l1,l2 = partition (x,l[1:],f)
        if f(l[0],x)==1:
            return ([l[0]]+l1,l2)
        else:
            return (l1,[l[0]]+l2)


def quicksort (l,f):
    """
    return a new list containing elements of l sorted by ascending order.

    :param l: a list to sort
    :type l: list
    :return: a new list containing elements of l in ascending order
    :rtype: list
    :UC: elements of l are comparable
    """
    n = len (l)
    if n <= 1:
        return l.copy ()
    else:
        l1,l2 = partition (l[0],l[1:],f)
        l1s = quicksort (l1,f)
        l2s = quicksort (l2,f)
        return l1s + [l[0]] + l2s

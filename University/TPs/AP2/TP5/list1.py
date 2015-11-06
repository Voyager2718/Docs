#!/usr/bin/python3
# -*- coding: utf-8 -*-

"""
:mod:`list1` module

:author: ̀FIL - IEEA - Univ. Lille1.fr <http://portail.fil.univ-lille1.fr>`_

:date: 2015, october

Provides constructor, selectors and modifiers for non mutable lists.

Lists are either empty, either essentially objects with two fields :

#. a *head* field which represent the head value  of the list,
#. and a *tail* field which is represent the tail of the list

"""

from collections import namedtuple

__List = namedtuple ('List',['head','tail'])


class ListEmptyError (Exception):
    """
    Exception for empty lists
    """
    def __init__ (self,msg):
        self.message = msg


def empty_list ():
    """
    
    :return: an empty list
    :rtype: list
    :UC: none
    """
    return None

def cons (x,l):
    """
    
    :param x: 
    :type x: any
    :param l: 
    :type l: list
    :return: a new list with head x, and tail l
    :rtype: list
    :UC: l must be a list
    """
    assert is_list (l), 'l must be a list'
    return __List (head=x,tail=l)


def head (l):
    """
    
    :param l:
    :type l: list
    :return: the content of head of l
    :rtype: any
    :UC: l must be non empty
    """
    try:
        return l.head
    except AttributeError:
        raise ListEmptyError ('list has no head')
    
def tail (l):
    """
    
    :param l:
    :type l: list
    :return: the tail of list l
    :rtype: list
    :UC: l must be non empty
    """
    try:
        return l.tail
    except AttributeError:
        raise ListEmptyError ('list has no tail')
    

def is_empty (l):
    """
    
    :param l:
    :return: - True if l is empty
             - False otherwise
    :rtype: bool
    :UC: none
    """
    return l == empty_list ()

def is_list (x):
    """
    
    :param x: object to test
    :type x: any
    :return: - True if x is a list
             - False otherwise
    :rtype: bool
    :UC: none
    """
    return (x == empty_list ()
            or (type (x) == type (cons (1,empty_list()))))


##########################
# Non primitive operations
##########################

def length (l):
    """

    :param l: 
    :type l: list
    :return: the length of l
    :rtype: int
    :UC: none
    """
    if is_empty (l):
        return 0
    else:
        return 1 + length (tail (l))


def __reverse_aux (l1,l2):
    if is_empty (l1):
        return l2
    else:
        return __reverse_aux (tail (l1), cons (head (l1),l2))

def reverse (l):
    """
    
    :param l:
    :type l: list
    :return: a new list with elements of l in reverse order
    :rtype: list
    :UC: none
    """
    return __reverse_aux (l,empty_list())
    
def __concat_aux (l1,l2):
    if is_empty (l1):
        return l2
    else:
        return __concat_aux (tail (l1), cons (head (l1),l2))

    
def concat (l1,l2):
    """

    :param l1: 
    :type l1: list
    :param l2: 
    :type l2: list
    :return: a new list obtained by concatenation of l1 and l2
    :rtype: list
    :UC: none
    """
    return __concat_aux (reverse (l1), l2)    

    
if __name__ == '__main__':
    pass    



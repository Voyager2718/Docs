#!/usr/bin/python3
# -*- coding: utf-8 -*-

"""
:mod:`point_plan` module
:author: YANG_ZINGOUCAI
:date: 19 novembre 2015
"""
import os
def get_rayons(triplet):
    """
    En prenant un triplet de cercles, elle renvoie leur rayon.
    :param triplet: liste de trois cercles
    :type triplet: list
    :return: le rayon
    :rtype: tuple
    """
    return [triplet[0][2],triplet[1][2],triplet[2][2]]

def get_centres(triplet):
    """
    En prenant un triplet de cercles, elle renvoie le centre du cercle.
    :param triplet: liste de trois cercles
    :type triplet: list
    :return: le centre du cercle
    :rtype: tuple
    """
    return [(triplet[0][0],triplet[0][1]),(triplet[1][0],triplet[1][1]),(triplet[2][0],triplet[2][1])]




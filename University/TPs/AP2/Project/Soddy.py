#!/usr/bin/python3
# -*- coding: utf-8 -*-

"""
:mod:`Soddy` module
:author: YANG_ZINGOUCAI
:date: 19 novembre 2015
"""
import os 
from tkinter import *
from math import *
from cercles import *
from point_plan import * 

################################
#   TKINTER                    #
################################
fenetre = Tk()
cercle = Canvas(fenetre,bg='white',height=600,width=800)
cercle.pack()
l=create_cercles((0,0,250),3)
h= triplet(l)
c=soddy_f(h)[0]
c1=new_draw(soddy_f(h)[1])
################################
#         Dessins               #
################################
def draw_cercle1(l,color):
    """
    Dessine le cercle de la liste l
    :param l: list of all cercles
    :type l: list
    :param color: choix de la couleur du dessin
    :return: 
    """
    for i in l:
        cercle.create_oval(i[0]-i[2],i[1]-i[2],i[0]+i[2],i[1]+i[2],width=1,outline=color)

def draw_cercle2():
    """
    Dessine les cercles tangents à un triplet de Soddy.
    """
    draw_cercle1(c,"blue")
    draw_cercle1(c1,"red")




	




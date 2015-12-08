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

########################
N=7
l=create_cercles((0,0,300),N)
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
        cercle.create_oval(i[0]-i[2]-400,i[1]-i[2]-300,i[0]+i[2]-400,i[1]+i[2]-300,width=1,outline=color)

def draw__cercle1():
    """
    we make this fuction because command in button dont
    take fuction with param
    """
    draw_cercle1(l,"lightblue")


def draw_cercle2():
	"""
	Dessine les cercles tangents à un triplet de Soddy.

    """
	draw_cercle1(c1,"lightblue")

def draw_cercle3(l):
    for i in l:
        draw_cercle1(i,"lightblue")


h=l
b=draw_empty_circles(h,N)
rec_two(h,N)
def draw_cercle4():
    draw_cercle1(c,"lightblue")
    draw_cercle1(b,"lightblue")

def draw_cercle5():
    for i in all_cer:
        draw_cercle1(i,"lightblue")

def draw_cercle6():
    for i in all_cer:
        draw_cercle1(i,"lightblue")


from datetime import datetime
maintenant = datetime.now()
temps=str(maintenant.day)+"-"+str(maintenant.month)+"-"+str(maintenant.year)+" "+str(maintenant.hour)+":"+str(maintenant.minute)


def sauvegarder(path="images/circles.eps"):
    """
    fonction de sauvegarde des images grace qu module PIL de python.
    
    """
    cercle.postscript(file=path, colormode='color')
    from PIL import Image
    img = Image.open("images/circles.eps")
    img.save("images/"+temps+".png", "png")

def flashback():
    cercle.delete('all')


###########################################################
#  TKINTER          
#######################################################

fenetre = Tk()
fenetre.title(" La baderne d’Apollonius fractale")
cercle = Canvas(fenetre,bg='white',height=600,width=800,)
cercle.pack(side=LEFT, padx=5, pady=5)
bout = Button(fenetre,text='Première Etape', command=draw__cercle1)
bout.pack(side=TOP, padx=10, pady=5)
bout2 = Button(fenetre,text='Deuxième Etape', command=draw_cercle2)
bout2.pack(side=TOP, padx=10, pady=5)
bout3 = Button(fenetre,text='Troisième Etape', command=draw_cercle4)
bout3.pack(side=TOP, padx=10, pady=5)
bout4 = Button(fenetre,text='Quartième Etape', command=draw_cercle5)
bout4.pack(side=TOP, padx=10, pady=5)
bout4 = Button(fenetre,text='Dernière Etape', command=draw_cercle6)
bout4.pack(side=TOP, padx=10, pady=5)
bout5 = Button(fenetre,text='Sauver', command=sauvegarder)
bout5.pack(side=BOTTOM, padx=5, pady=5)
bout5 = Button(fenetre,text='Retour',command=flashback)
bout5.pack(side=BOTTOM, padx=5, pady=5)
entree=Entry(fenetre, bd=5)
entree.pack(side=BOTTOM, padx=5,pady=5)

 
fenetre.mainloop()
fenetre.destroy()

os.system('pause')

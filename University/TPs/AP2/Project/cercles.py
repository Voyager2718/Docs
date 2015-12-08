#!/usr/bin/python3
# -*- coding: utf-8 -*-

"""
:mod:`cercles` module
:author: YANG_ZINGOUCAI
:date: 19 novembre 2015
Un cercle sera representé par un tuple de longueur 3, 
les deux premiers sont les coordonées du centre du cercle et le troisième est le rayon.
"""
import os 
from math import *
import cmath 
T=350

def create_cercles(cercle,N):
    """
    Dessine le grand et le cercle du milieu et les trois autres cercles tangents, il retourne une liste de cercle.    
    :param cercle: 
    :type cercle: 
    :param N: 
    :type N: 
    :return: 
    :rtype:
    """
    R=cercle[2]
    # calcule du rayon du petit cercle au milieu
    r=R*((1-sin(pi/N))/(1+sin(pi/N)))
    # les rayons des autres cercles tengents
    r1=R*((sin(pi/N))/(1+sin(pi/N)))
    list_cercles=[]
    T = 350
    # le grand cercle
    list_cercles.append((cercle[0]+T,cercle[1]+T,R))
    # le cercle du milieu
    list_cercles.append((cercle[0]+T,cercle[1]+T,r))
    for i in range(0,N):
        new_centre= ((r + r1) * cos((2*i*pi)/N),(r + r1) * sin((2*i*pi)/N))
        # les autres cercles
        list_cercles.append((new_centre[0]+T,new_centre[1]+T,r1))
    return list_cercles

def draw_circle1(l,c):
    try:
        for i in l:
            cercle.create_oval(i[0]-i[2], i[1]-i[2], i[0]+i[2], i[1]+i[2], width=1, outline=c)
    except NameError:
        print('Should create a canvas first.')

def triplet(liste):
    """
    Renvoie tous les triplets par rapport a la liste .    
    :param liste: the list of cercles
    :type liste: list
    :return: list triplets
    :rtype: list
    """
    triplets=[]
    list_ten=liste[1:]
    for i in range(0,len(list_ten)-2):
    	triplets.append([list_ten[0],list_ten[i+1],list_ten[i+2]])
    	triplets.append([liste[0],list_ten[i+1],list_ten[i+2]])
    triplets.append([list_ten[0],list_ten[-1],list_ten[1]])
    triplets.append([liste[0],list_ten[-1],list_ten[1]])
    return triplets

def soddy(triplet):
    """
    Calcule le rayon et le centre du cercle de Soddy, en prenant en paramètre un triplet de cercle.
    :param triplet: list of three circles
    :type triplet: list
    :return: circle of soddy
    :rtype: tuple
    """
    rayon = get_rayons(triplet)
    centre= get_centres(triplet)
    k2=1/rayon[1]
    k3=1/rayon[2]
    z1=complex(centre[0][0],centre[0][1])
    z2=complex(centre[1][0],centre[1][1])
    z3=complex(centre[2][0],centre[2][1])
    # on calcule la corbure k4 du cercle de soddy
    if  rayon[0]<rayon[1] and rayon[0]<rayon[2]:
        k1 = 1/rayon[0]
        k4 = (k1+k2+k3)+(2*sqrt((k1*k2)+(k1*k3)+(k2*k3)))
        # on récupére les centres des trois cercles
        # on calcule le centre du cercle de soddy sous forme d'un complexe z4
        z4 = (z1*k1+z2*k2+z3*k3+2*cmath.sqrt(k1*k2*z1*z2+k2*k3*z2*z3+k1*k3*z1*z3))/k4
        return ( z4.real, z4.imag, 1/k4)
    else:
        k1= -1/rayon[0]
        k4= (k1+k2+k3)+(2*sqrt((k1*k2)+(k1*k3)+(k2*k3)))
        # on récupére les centres des trois cercles
        # Idem que precedemment 
        z4 = (z1*k1+z2*k2+z3*k3+2*cmath.sqrt(k1*k2*z1*z2+k2*k3*z2*z3+k1*k3*z1*z3))/k4
        return (z4.real, z4.imag, 1/k4)

def new_t(c1,c2,c3,c4):
    """
    Prend en parametre trois cercles et un cercle de Soddy et va renvoyer une nouvelle liste de triplet.
    :param c1: cercle de Soddy
    :type c1: triplet
    :param c2,c3,c4: cercles tangents
    :type c2,c3,c4: triplet
    :return: nouvelle liste de triplets 
    """
    new=[]
    new.append([c1,c2,c3])
    new.append([c1,c3,c4])
    new.append([c1,c4,c2])
    return new

def soddy_f(list_triplet):
    """
    :param list_triplet: 
    :type list_triplet: 
    :return: all circle of soddy
    :rtype: list    
    """
    all_soddy=[] # tous les nouveau cercles de soddy
    get_tri=[]   #les nouveau triplets
    new=[]
    for i in list_triplet:
        all_soddy.append(soddy(i))
        new.append(new_t(soddy(i),i[0],i[1],i[2]))
    for j in new:
        for k in j:
            #all_triplets(liste)
            get_tri.append(k)
    return (all_soddy,get_tri)

def new_draw(l):
    """
    :param l: nouvelle liste
    :type l : list
    :return: 
    """
	return soddy_f(l)[0]
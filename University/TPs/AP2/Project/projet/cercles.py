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
import sort
import sys
sys.setrecursionlimit(10000)

T=(800,600) #translation
        
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
	# le grand cercle
	list_cercles.append((cercle[0]+T[0],cercle[1]+T[1],R))
	# le cercle du milieu
	list_cercles.append((cercle[0]+T[0],cercle[1]+T[1],r))
	for i in range(0,N):
		new_centre= ((r + r1) * cos((2*i*pi)/N),(r + r1) * sin((2*i*pi)/N))
		# les autres cercles
		list_cercles.append((new_centre[0]+T[0],new_centre[1]+T[1],r1))
	return list_cercles

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

def Distance(z1,z2):
	x1=z1.real
	x2=z2.real
	y1=z1.imag
	y2=z2.imag
	return sqrt((y2-y1)**2+(x2-x1)**2)

def soddy(triplet):
	"""
	Calcule le rayon et le centre du cercle de Soddy, en prenant en paramètre un triplet de cercle.

	:param triplet: list of three circles
	:type triplet: list
	:return: circle of soddy
	:rtype: tuple

	"""
	k1=1/triplet[0][2]
	k2=1/triplet[1][2]
	k3=1/triplet[2][2]
	k4=(k1+k2+k3)+(2*sqrt((k1*k2)+(k1*k3)+(k2*k3)))
	z1=complex(triplet[0][0], triplet[0][1])
	z2=complex(triplet[1][0], triplet[1][1])
	z3=complex(triplet[2][0], triplet[2][1])
	z4=(z1*k1+z2*k2+z3*k3+2*cmath.sqrt(k1*k2*z1*z2+k2*k3*z2*z3+k1*k3*z1*z3))/k4
    # on calcule la corbure k4 du cercle de soddy
	a=int(Distance(z4,z1)),int((triplet[0][2]+1/k4)),triplet[0][2]  ,int(Distance(z4,z2)),int((triplet[1][2]+1/k4)),triplet[1][2],int(Distance(z4,z3)),int((triplet[2][2]+1/k4)), triplet[2][2]
	if  int(Distance(z4,z1))==int((triplet[0][2]+1/k4)) and int(Distance(z4,z2))==int((triplet[1][2]+1/k4)) and int(Distance(z4,z3))==int((triplet[2][2]+1/k4)):
		return (z4.real,z4.imag,1/k4,True)
	else:
		#print(a)
		k1=-1/triplet[0][2]
		k4=(k1+k2+k3)+(2*sqrt((k1*k2)+(k1*k3)+(k2*k3)))
		z4=(z1*k1+z2*k2+z3*k3+2*cmath.sqrt(k1*k2*z1*z2+k2*k3*z2*z3+k1*k3*z1*z3))/k4
		return (z4.real,z4.imag,1/k4,False)
 

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
    new.append([c1,c2,c4])
    new.append([c2,c3,c4])
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
		new.append(new_t(i[0],soddy(i),i[1],i[2]))
	for j in new:
		for k in j:
			get_tri.append(k)
	return (all_soddy,get_tri)

#####################################################################

def new_draw(l):
    """
    
    :param l: nouvelle liste
    :type l : list
    :return: 
    """
    n=soddy_f(l)[0]
    n2=sort.quicksort (n,sort.compare_circle)
    if n2[0][2]<=4:
        return []
    else:
        return n2+new_draw(soddy_f(l)[1])


def draw_empty_circles(list_circles,N):
    """
    :param list_circles:
    :type:
    :param N:
    :type:
    :return:
    """
    k=[]
    for cer in list_circles:
        inter_x=cer[0]-T[0]
        inter_y=cer[1]-T[1]
        create_new=create_cercles(cer,N)
        create_new[0]=(0+T[0],0+T[1],create_new[0][2])
        create_new[1]=(0+T[0],0+T[1],create_new[1][2])
        h=triplet(create_new)
        c=soddy_f(h)[0]
        s=new_draw(soddy_f(h)[1])
        for i in create_new[1:]:
            k.append((i[0]+inter_x,i[1]+inter_y,i[2]))
        for d in c:
            k.append((d[0]+inter_x,d[1]+inter_y,d[2]))
        for v in s:
            k.append((v[0]+inter_x,v[1]+inter_y,v[2]))
    return k

all_cer=[]
def rec_two(liste, N):
    lon=len(all_cer)
    if lon>=2:
            return all_cer
    else:
        all_cer.append(draw_empty_circles(liste,N))
        rec_two(all_cer[-1],N)

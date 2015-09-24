#!/usr/bin/python3
# -*- coding: utf-8 -*-

"""
	A program using card module. Type ``usage()``.
	
"""

import sys
import random 

def createCardSet():
	"""
		Create a set of card(52 cards)
		
		:returns: *(element of ``card and color``)* --return a list contain 52 cards
	"""
	card = [] 
	v = ("2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace") 
	c = ("club", "diamond", "heart", "spade")
	for i in range(0,13): 
		for j in range(0,4): 
			card += [{"value":v[i],"color":c[j]}]
	return card
	
def shuffle(cardSet):
	"""
		Shuffle all elements.
		
		:param cardSet: a set of card
		:param type: card
		:returns: *(a set of ``card``)* --Return and modify the object entered.
	"""
	random.shuffle(cardSet)
	return cardSet
		

def distributeCard(cardSet):
	"""
		Distribute cards to 2 players.
		
		:param cardSet: a set of card
		:param type: card
		:returns: *(a set of ``card``)* --Return a list contains 2 lists of cards.([[Cards of player 1],[Cards of player 2]])
		
	"""
	c = [[],[]]
	for i in range(0,16):
		c[0] += [cardSet[i]]
	for i in range(16,32):
		c[1] += [cardSet[i]]
	return c

def getPlayer1FirstCard(cardSet):
	"""
		Get first card of player 1.
		
		:param cardSet: a set of card
		:param type: card
		:returns: The first card from the pile of player 2 cards

			
	"""
	return cardSet[0][0]
	
def getPlayer2FirstCard(cardSet):
	"""
		Get first card of player 2.
		
		:param cardSet: a set of card
		:param type: card
		:returns: The first card from the pile of player 2 cards
	"""
	return cardSet[1][0]
	
def getWinner(cardSet):
	"""
		Get winner. If player 1 won, return 0. If player 2, return 1. If there's not a winner, return -1. If there're errors, return -99
		
		:param type: card
		:returns: return 0, if player 1 won 
		return 1, if player 2 won
		return -1, if there's not a winner
		return -99, if there're errors
			
	"""
		
	if(len(cardSet[0])==0 and len(cardSet[1])==0): 
		return -99
	if(len(cardSet[1])==0):
		return 0
	elif(len(cardSet[0])==0): 
		return 1 
	else: 
		return -1
		
def deletePLayer1FirstCard(CardSet):
	"""
		Remove the first card of player 1.
		
		:param cardSet: a set of card
		:param type: card
	"""
	cardSet[0][0:1] = []
	
def deletePlayer2FirstCard(cardSet):
	"""
		Remove the first card of player 2.
		
		:param cardSet: a set of card
		:param type: card
	"""
	cardSet[0][0:1] = []

	
def winner_to_string(integer):
	"""
		Convert a integer to string. If parameter equals to 0, return "Player 1 won the game."
		if 1, return "Player 2 won the game", if -1, return "No result.", else return "Error".
		
		:param integer: -1 if the cards are of identical heights, and 0 or 1 if player 1 or player 2 won the game.
		:param type: int
		:returns: *(string)* -- Return a string, giving the winner or not.
		
	"""
	if(integer == 0):
		return "Player 1 won the game."
	elif(integer == 1):
		return "Player 2 won the game."
	elif(integer == -1):
		return "No result."
	else:
		return "Error."
		
if __name__ == '__main__':
	import doctest
	doctest.testmod ()

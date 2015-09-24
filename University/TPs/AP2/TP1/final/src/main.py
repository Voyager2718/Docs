#!/usr/bin/python3
# -*- coding: utf-8 -*-

"""
	A program using card module.
"""

import sys 

import bataille
import card


def play():
	"""
		In the game, each player an equal number of cards that have been mixed. Each turn, players play the first card of their pile.
		The player with the highest value wins all the cards on the table and put away at the end of his pile of cards. 
		If both cards are equals heights, then there are "War" and these cards are left on the table. The next round can begin ..
		
		The game ends when a player no have cards, in this case it has lost the game.
	"""
	cs = distributeCard(shuffle(createCardSet()))
	i = 0
	while(getWinner(cs)==-1):
		cmp = compare(getPlayer1FirstCard(cs),getPlayer2FirstCard(cs))
		i += 1
		print("Turn {}".format(i))
		print("Player1:"+to_string(getPlayer1FirstCard(cs))+"\nPlayer2:"+to_string(getPlayer2FirstCard(cs)))
		if(cmp==0):
			print("Draw.\n")
			tmp = []
			while(cmp==0):#If 2 players have 2 same cards, put them into a temp list. If finally they have a winner, give all cards to the winner.
				tmp+=getPlayer1FirstCard(cs)
				tmp+=getPlayer2FirstCard(cs)
				deletePlayer1FirstCard(cs)
				deletePlayer2FirstCard(cs)
				cmp = compare(getPlayer1FirstCard(cs),getPlayer2FirstCard(cs))
				i += 1
				print("Turn {}".format(i))
				print("Player1:"+to_string(getPlayer1FirstCard(cs))+"\nPlayer2:"+to_string(getPlayer2FirstCard(cs)))
		elif(cmp==1):#Case if player 1 won.
			print("Player 1 won.\n")
			cs[0] += [getPlayer2FirstCard(cs)]
			deletePlayer2FirstCard(cs)
			cs[0] = shuffle(cs[0])
		else:#Case if player 2 won.
			print("Player 2 won.\n")
			cs[1] += [getPlayer1FirstCard(cs)]
			deletePlayer1FirstCard(cs)
			cs[0] = shuffle(cs[0])
	print(winner_to_string(getWinner(cs)))
	
	

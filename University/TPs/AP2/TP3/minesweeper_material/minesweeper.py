#!/usr/bin/python3
# -*- coding: utf-8 -*-

"""
DOCUMENTATION A FOURNIR
"""

import random
from enum import Enum


################################################
# Type declaration
################################################

class GameState (Enum):
    """
    A class to define an enumerated type with three values :

    * ``winning``
    * ``losing``
    * ``unfinished``
    
    for the three state of minesweeper game.
    """
    winning = 1
    losing = 2
    unfinished = 3



################################################
# Functions for cell's management
################################################
def __make_cell ():
    """
    :return: a new hidden cell of a minesweeper's grid. 
             existence of a bomb, number of bombs in neigh_borhood 
             have to be stated later.
    :rtype: cell
    :UC: none
    """
    return {'bomb' : False,
            'hypothetic_bomb' : False,
            'nbombs_neighborhood' : 0,
            'hidden' : True}


def is_bomb (cell):
    """
    :param cell: a cell of a minesweeper's grid
    :type cell: cell
    :return: 
       * ``True`` if cell contains a bomb
       * ``False`` otherwise
    :rtype: bool
    :UC: none
    """
    return cell['bomb']

def is_hypothetic_bomb (cell):
    """
    :param cell: a cell of a minesweeper's grid
    :type cell: cell
    :return: 
       * ``True`` if cell is marked as containing a hypothetic bomb
       * ``False`` otherwise
    :rtype: bool
    :UC: none
    """
    return cell['hypothetic_bomb']

def is_revealed (cell):
    """
    :param cell: a cell of a minesweeper's grid
    :type cell: cell
    :return: 
       * ``True`` if cell is revealed
       * ``False`` otherwise
    :rtype: bool
    :UC: none
    """
    return not cell['hidden']

def number_of_bombs_in_neighborhood (cell):
    """
    :param cell: a cell of a minesweeper's grid
    :type cell: cell
    :return: the number of bomb in the cell's neighborhood 
    :rtype: int
    :UC: none
    """
    return cell['nbombs_neighborhood']

def reveal(cell):
    """
    :param cell: a cell of a minesweeper's grid
    :type cell: cell
    :return: None 
    :rtype: NoneType
    :Side effect: set the state of cell cell as revealed
    :UC: none
    """
    cell['hidden'] = False

def set_hypothetic (cell):
    """
    :param cell: a cell of a minesweeper's grid
    :type cell: cell
    :return: None 
    :rtype: NoneType
    :Side effect: mark the cell as containing a (hypothetic) bomb
    :UC: none    
    """
    if not is_revealed (cell):
        cell['hypothetic_bomb'] = True

def unset_hypothetic (cell):
    """
    :param cell: a cell of a minesweeper's grid
    :type cell: cell
    :return: None 
    :rtype: NoneType
    :Side effect: unmark the cell as containing a (hypothetic) bomb
    :UC: none    
    """
    if not is_revealed (cell):
        cell['hypothetic_bomb'] = False
        
def neighborhood (x,y,height,width):
    """
    return the list of coordinates of the neighbors de cell (x,y) in a
    grid of size width*height

    :param x: x-coordinate of a cell
    :type x: int
    :param y: y-coordinate of a cell
    :type y: int
    :return:
    :rtype: list of tuple
    :UC: 0 <= x < height and 0 <= y < width
    """
    pass

##############################################
# Functions for game's setup and management
##############################################

def __make_grid (width,height,nbombs):
    """
    return a minesweeper grid of size width*height cells
    with nbombs bombs.

    :param width: horizontal size of game (default = 30)
    :type width: int
    :param height:  vertical size of game (default = 20)
    :type height: int
    :param nbombs:  number of bombs (default = 99)
    :type nbombs: int
    :return: a fresh grid of  width*height cells
    :rtype: list of list of cells
    """
    assert 0 < width , 'width must be a positive integer'
    assert 0 < height , 'height must be a positive integer'
    assert 0 <= nbombs <= width*height, "nbombs must don't exceed width*height"
    coords = [(x,y) for y in range (width) for x in range (height)]
    random.shuffle (coords)
    grid =  [[__make_cell () for y in range (width)] for x in range (height)]
    for i in range (nbombs):
        x,y = coords[i]
        grid[x][y]['bomb'] = True
        for neighbor in neighborhood (x,y,height,width):
            x1,y1 = neighbor
            grid[x1][y1]['nbombs_neighborhood'] += 1
    return grid

def make_game (width=30,height=20,nbombs=99):
    """
    return a minesweeper game  of size width*height cells
    with nbombs bombs.

    :param width: [optional] horizontal size of game (default = 30)
    :type width: int
    :param height: [optional] vertical size of game (default = 20)
    :type height: int
    :param nbombs: [optional] number of bombs (default = 99)
    :type nbombs: int
    :return: a fresh grid of  width*height cells
    :UC: 0 < width, height and 0 <= nbombs <= width*height
    """
    return {'width' : width,
            'height' : height,
            'nbombs' : nbombs,
            'grid' : __make_grid (width,height,nbombs)}

def get_height (game):
    """
    :param game: a minesweeper game
    :type game: game
    :return: height of the grid in game
    :rtype: int
    :UC: none
    """
    return game['height']

def get_width (game):
    """
    :param game: a minesweeper game
    :type game: game
    :return: width of the grid in game
    :rtype: int
    :UC: none
    """
    return game['width']

def get_cell (game, x, y):
    """
    :param game: a minesweeper game
    :type game: game
    :param x: x-coordinate of a cell
    :type x: int
    :param y: y-coordinate of a cell
    :type y: int
    :return: the cell of coordinates (x,y) in the game's grid
    :type: cell
    :UC: 0 <= x < height of game and O <= y < width of game 
    """
    return game['grid'][x][y]

def get_state (game):
    """
    :param game: a minesweeper game
    :type game: game
    :return: the state of the game (winning, losing or unfinished)
    :rtype: GameState
    :UC: none
    """
    pass

def reveal_all_cells_from (game, x, y):
    """
    :param game: 
    :type game: game
    :param x: 
    :return: none
    :Side effect: reveal all cells of game game from the initial cell (x,y).
    :UC: 0 <= x < height of game and O <= y < width of game 
    """
    pass

if __name__ == '__main__':
    pass    



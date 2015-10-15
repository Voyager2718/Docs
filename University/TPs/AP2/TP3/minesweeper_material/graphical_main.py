import sys
import minesweeper as mines
import graphicalboard as graph

if __name__ == "__main__":
	assert len(sys.argv)==4, "Give me more arguments, please."
	assert (int(sys.argv[1])>0 and int(sys.argv[2])>0 and int(sys.argv[3])>0), "All these arguments should be positive."
	graph.create(mines.make_game(int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3])))
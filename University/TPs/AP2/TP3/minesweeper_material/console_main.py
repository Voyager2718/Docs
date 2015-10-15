import sys
import minesweeper as msp

if __name__ == "__main__":
    assert len(sys.argv)==4, "Give me more arguments, please."
    assert (int(sys.argv[1])>0 and int(sys.argv[2])>0 and int(sys.argv[3])>0), "All these arguments should be positive."
    g = msp.make_game(int(sys.argv[1]),int(sys.argv[2]),int(sys.argv[2]))
    while(msp.get_state(g)==msp.GameState(3)):
        msp.draw(g)
        tmp = input("Your play x,y,C (C=(R)eval,(S)et,(U)nset):")
        str = tmp.split(" ")
        print(str)
        if(str[2]=="R"):
            msp.reveal(msp.get_cell(g,int(str[0]),int(str[1])))
            continue
        if(str[2]=="S"):
            msp.set_hypothetic(msp.get_cell(g,int(str[0]),int(str[1])))
    if(get_state(g)==msp.GameState(1)):
        print("You won.")
    else:
        print("You lost.")
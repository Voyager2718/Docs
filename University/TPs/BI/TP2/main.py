from TP2 import *
if __name__ == '__main__':
    while True:
        print('Welcome, please type:\n1.windows int int string\n2.list_spaced_kmers int string\n3.common_spaced_kmers int string string\n4.ratio_common_spaced_kmers int string string\nExample: windows 10 5 test.txt')
        i = input('Enter the function that you want to execute please:\n')
        cmd = i.split()
        try:
            print('----Result----')
            if cmd[0] == 'windows':
                windows(int(cmd[1]), int(cmd[2]), cmd[3])
            elif cmd[0] == 'common_spaced_kmers':
                common_spaced_kmers(int(cmd[1]), cmd[2], cmd[3])
            elif cmd[0] == 'list_spaced_kmers':
                list_spaced_kmers(int(cmd[1]), cmd[2])
            elif cmd[0] == 'ratio_common_spaced_kmers':
                ratio_common_spaced_kmers(int(cmd[1]), cmd[2], cmd[3])
            else : print('Input illegal2.')
            print('----Result End----', end = '\n\n')
        except Exception : print('Input illegal.\n')
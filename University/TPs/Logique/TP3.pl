grille([[_,_,_,_,_,_,_,_,_],
        [_,_,_,_,_,3,_,8,5],
        [_,_,1,_,2,_,_,_,_],
        [_,_,_,5,_,7,_,_,_],
        [_,_,4,_,_,_,1,_,_],
        [_,9,_,_,_,_,_,_,_],
        [5,_,_,_,_,_,_,7,3],
        [_,_,2,_,1,_,_,_,_],
        [_,_,_,_,4,_,_,_,9]]).

%Q1
printline([]) :- write('|').
printline([A|B]) :- integer(A), !, write('|'),write(A), printline(B).
printline([_|B]) :- write('|'),write(' '), printline(B).

%Q2
mprint([]) :- printline([]), !.
mprint([A|B]) :- printline(A), writeln(' '), mprint(B).

%Q3
bonnelongueur([], C) :- C is 0.
bonnelongueur([_|B], C) :- bonnelongueur(B, X), C is X + 1.

%Q4
bonnetaille(A, B, C) :- bonnelongueur(A, C), bonnelongueur(B, C).

verifier([]).
verifier([X | L]) :- X >= 1, X =< 9, verifier(L).



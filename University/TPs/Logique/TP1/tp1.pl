%Q1
contenu(tigre).
contenu(princesse).

%Q2
pancarte1(tigre,Y) :- contenu(Y).
pancarte1(X,princesse) :- contenu(X).
pancarte2(princesse,Y) :- contenu(Y).

%Q3
salle(X,Y) :- contenu(X), contenu(Y), pancarte1(X,Y), pancarte2(X,Y).
salle(X,Y) :- contenu(X), contenu(Y), not(pancarte1(X,Y)), not(pancarte2(X,Y)).

%Q4


%Q5


%Q6
pancarte3(princesse,tigre).
pancarte4(tigre,princesse).
pancarte4(princesse,tigre).

salle2(X,Y) :- contenu(X), contenu(Y), pancarte3(X,Y), pancarte4(X,Y).
salle2(X,Y) :- contenu(X), contenu(Y), not(pancarte3(X,Y)), not(pancarte4(X,Y)).

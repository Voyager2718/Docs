var a binary;
param b binary;
param c binary;
subject to ou_1 : a >= b;
subject to ou_2 : a >= c;
subject to ou_3 : b + c >= a;
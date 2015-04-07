bool a = true;
int n = 0;
for(int i = 0; i < marqueurs.length -1; i++){
	for(int j = 0; j < positifs.length -1; j++){
		if( marqueur[i] == positifs[j])
			a = false;
	}	
	if ( a == true ){
		l[n] = marqueur[i];
		n ++;
	}
}


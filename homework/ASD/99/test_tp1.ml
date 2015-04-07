open Experience
open Tris

let cpt = ref 0
let cmp2 m1 m2 =
  cpt := !cpt + 1;
  cmp m1 m2;;

(** 
    strategie 1
*)
let liste_des_marqueurs_negatifs_1 marqueurs positifs =
	let l = ref [] and
	est_trouve = ref false
	in
	for i = 0 to (Array.length marqueurs)-1 do
		est_trouve := false;
		let j = ref (Array.length positifs - 1) in
		while (!j >= 0) && (!est_trouve = false) do 
			if 0 = (cmp2 (marqueurs.(i)) (positifs.(!j))) then begin
				est_trouve:= true;
			end;
			j := !j - 1;
		done;
		
		if !est_trouve = false then begin
		  l := !l @ [marqueurs.(i)];
		  end;
	done;
	!l;;

(*c1 = m*p*)

(** 
    strategie 2
*)
let liste_des_marqueurs_negatifs_2 marqueurs positifs =
  let marqueurs2 = trier marqueurs cmp2 in
  liste_des_marqueurs_negatifs_1 marqueurs2 positifs;;


(** 
    strategie 3
*)
let liste_des_marqueurs_negatifs_3 marqueurs positifs =
  let marqueurs2 = trier marqueurs cmp2 in
  let positifs2 = trier positifs cmp2 in
  
  let l = ref []
  and i = ref (Array.length marqueurs2 - 1)
  and j = ref (Array.length positifs2 - 1) in
  
  while !i >= 0 && !j >= 0 do 
    if 0 = (cmp2 (marqueurs2.(!i)) (positifs2.(!j))) then begin
      i := !i - 1;
      j := !j - 1;
    end else begin
      i := !i - 1;
      l := !l @ [marqueurs2.(!i)];
    end;
  done;
  !l;;

(*m*)
(**
   [imprimer_liste_marqueurs l] imprime les marqueurs de la liste l
*)
let rec imprimer_liste_marqueurs l =
  match l with
    | [] -> 
      Printf.printf "\n"
    | m::r -> 
      Printf.printf "%s " m;
      imprimer_liste_marqueurs r

let _ = 
  let p = int_of_string Sys.argv.(1) (* nombre de marqueurs positifs *)
  and m = int_of_string Sys.argv.(2) (* nombre de marqueurs total *)
  in
  let mtab = marqueurs m
  in
  let etab = experience p mtab
  in

  (* impression des marqueurs *)
  Printf.printf "Marqueurs          : ";
  for i = 0 to m-1 do
    Printf.printf "%s " mtab.(i)
  done;
  Printf.printf "\n";

  (* impression des marqueurs positifs *)
  Printf.printf "Marqueurs positifs : ";
  for i = 0 to p-1 do
    Printf.printf "%s " etab.(i)
  done;
  Printf.printf "\n";


  (* test methode 1 *)
  cpt := 0;
  Printf.printf "Marqueurs negatifs : ";
  imprimer_liste_marqueurs (liste_des_marqueurs_negatifs_1 mtab etab);
  Printf.printf "M1: %d\n" !cpt;


  (* test methode 2 *)
  cpt := 0;
  Printf.printf "Marqueurs negatifs : ";
  imprimer_liste_marqueurs (liste_des_marqueurs_negatifs_2 mtab etab);
  Printf.printf "M2 : %d\n" !cpt;


  (* test methode 3 *)
  cpt := 0;
  Printf.printf "Marqueurs negatifs : ";
  imprimer_liste_marqueurs (liste_des_marqueurs_negatifs_3 mtab etab);
  Printf.printf "M3 : %d\n" !cpt;


  
      

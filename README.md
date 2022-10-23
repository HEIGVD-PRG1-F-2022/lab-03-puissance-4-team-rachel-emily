# Puissance 4
Le Puissance 4 est un célèbre jeu de société où s'affrontent 2 joueurs. <br>
Pour pouvoir gagner, l'un des joueurs doit aligner au minimum 4 de ses jetons de manière horizontale, verticale ou diagonale.

## À propos
Ce projet a été écrit en c++ dans le cadre de la classe **PROG1** par Rachel Tranchida et Emily Baquerizo.

## Extrait du jeu

![image_1](https://user-images.githubusercontent.com/114154989/197401436-1058ae21-57b4-47ff-af18-e39d437bd544.png)
<br>*Exemple d'une initialisation d'une partie de 2 joueurs avec une grille de 6 x 7*
  
<br>

![image_2](https://user-images.githubusercontent.com/114154989/197401409-a4eae6de-3a79-42ba-b5e6-9dfe02821842.png)
<br>*Exemple d'une partie*

## Comment jouer
### Initialisation d'une partie
  1. Choisir si l'on veut jouer contre l'ordinateur ou contre une autre joueur (Entrer 0 pour jouer contre un autre joueur et n'importe quel chiffre pour jouer contre l'ordinateur)
  2. Entrer le nombre de lignes voulues
  3. Entrer le nombre de colonnes voulues

#### ATTENTION
Le plateau doit avoir une taille minimale de 4x2 ou de 2x4 pour pouvoir être validé par le programme. Sinon, ce dernier vous demandera d'entrer de nouvelles dimensions jusqu'à ce que le plateau soit "jouable", c'est-à-dire qu'il y ait la possiblité d'avoir une victoire.
  
### Jouer une partie
 1. Le premier joueur choisit un chiffre entre 0 et n, n étant le nombre de colonnes choisies au début moins 1, puis appuie sur *Enter* pour valider le coup.
 Le coup sera joué uniquement si la colonne choisie n'est pas pleine. Sinon, le joueur doit rejouer jusqu'à rentrer un chiffre valide.
 2. S'il s'agit de l'ordinateur, le coup va être placé de manière aléatoire à moins qu'il existe une possibilité de gagner pour l'ordinateur ou de bloquer le joueur si ce dernier peut gagner lors de son prochain tour.
 En revanche, s'il s'agit d'une autre personne, cette dernière va effectuer les mêmes étapes que le premier joueur.
 C'est-à-dire, qu'elle devra choisir un chiffre entre 0 et n, n étant le nombre de colonnes choisies au début moins 1, puis appuyer sur *Enter* pour valider le coup.
 Le coup sera uniquement joué si la colonne choisie n'est pas pleine. Sinon, le joueur devra rejouer jusqu'à rentrer un chiffre valide.
 3. La partie se termine lorsque l'un des joueurs réussit à aligner au moins 4 de ses jetons horizontalement, verticalement ou diagonalement.

<br>

 ![Exemple grille](https://user-images.githubusercontent.com/114154989/197405656-237bd990-957b-4ef6-917f-3550104450fe.png)
<br>*Exemple d'un numérotage de colonne pour une grille de 6 lignes pour 7 colonnes*

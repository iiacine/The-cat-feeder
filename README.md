# The-cat-feeder
Documentation Cat feeder – Arduino
Concept

Aujourd’hui en France, on compte près de 10 millions de chats domestiques, seulement nos boules de poils ne peuvent se nourrir seules en l’absence de le leur maitre. Ainsi beaucoup de propriétaire de chats n’hésitent pas à faire appel à des connaissances ou à rémunéré des personnes pouvant nourrir leur chats en leur absence.
Cependant cette solution se révèle être couteuse en cas de vacances prolongée, ainsi, afin de faciliter la vie aux possesseurs de chats, nous avons mis au point un un dispositif permettant de nourrir de manière automatique et autonome n’importe quel chat domestique :  le « cat feeder ». Un distributeur de nourriture automatique.
Ce système repose sur un arduino et permet à l’aide d’un capteur de délivrer de la nourriture automatiquement en détectant les mouvements de notre animal. 

Principe de fonctionnement

Le cat feeder repose sur le principe de la détection de mouvement, lorsque le chat s’approche du boitier en y plaçant sa tête le système le détecte et délivre en conséquence la nourriture. Un entonnoir contenant la nourriture est placé au-dessus du boitier avec à son extrémité un bouchon piloté par un servo-moteur rotatif permettant à celle-ci de s’écouler. Le moteur effectue une rotation de 180 degrés en cas de détection de mouvement puis revient à sa position initiale.
Une interface Web est accessible en wifi et permet d’afficher les horaires de passages du chat en les stockant localement, ceci permettra de déterminer la fréquence d’alimentation de notre félin afin de mieux cerner ces habitudes et comprendre comment celui-ci se nourrit .

Les fonctionnalités de notre système sont les suivantes.
-Délivrer automatiquement de la nourriture aux chats.
-Disponibilité d’une interface WEB
•	Affiche les heures de passage du chat à proximité du cat feeder
•	Bloquer / Autoriser le délivrement de nourriture 




SCHEMA  : 

![alt text](https://github.com/iiacine/The-cat-feeder/blob/master/Untitled%20Sketch%202_bb.png)

TOOLS : 
1 - Servo :
![alt text](https://raw.githubusercontent.com/iiacine/The-cat-feeder/3641049310824dd578f488399951d71eaf3cc496/servo.png)

1 - Resistance :
![alt text](https://raw.githubusercontent.com/iiacine/The-cat-feeder/3641049310824dd578f488399951d71eaf3cc496/resis.png)

1 - Capteur : 
![alt text](https://raw.githubusercontent.com/iiacine/The-cat-feeder/3641049310824dd578f488399951d71eaf3cc496/capteur.png)

1 - ESP : 
![alt text](https://raw.githubusercontent.com/iiacine/The-cat-feeder/3641049310824dd578f488399951d71eaf3cc496/wifi.png)


Team project :
1er Jour : Idéation du projet, définir un poc./n
2eme Jour: Recherche,documentation,coding . /n
3eme jour : Fin du premier MVP.
4eme jour : Finalisation de la documentation 

Méthodologie agile : 
Programmation en paire programming.
Ahmed.K : Web server / servo  / capteur
Yacine.d : Web server / servo  / capteur
Hamidou.B:  Web server / servo  / capteur



Voir : => Description.docx

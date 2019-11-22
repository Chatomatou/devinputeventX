# devinputeventX

Dans le fichier /dev/input/ nous retrouvons des fichier qui communique avec touts les périphérique d'entrée, clavier, souris...
Vu que sur linux tout est fichier, il y'a alors moyen de lire ce fichier aisément, dans la documentation linux on nous dit : 

You can use blocking and nonblocking reads, also select() on the
/dev/input/eventX devices, and you'll always get a whole number of input
events on a read. Their layout is:

```c
struct input_event {
	struct timeval time;
	unsigned short type;
	unsigned short code;
	unsigned int value;
};
```

A partir de la nous pouvons aisément lire ce fichier. C'est ce que ce programme effectue, en adaptant les code de touche a celui d'un clavier français azerty.

Source: 
  
  https://www.kernel.org/doc/Documentation/input/input.txt
  
  https://thehackerdiary.wordpress.com/2017/04/21/exploring-devinput-1/

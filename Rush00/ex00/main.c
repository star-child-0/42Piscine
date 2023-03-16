/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:04:29 by kichkiro          #+#    #+#             */
/*   Updated: 2022/07/19 19:17:44 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	ft_pseudo_atoi(char *str)//questa e' la funzione pseudo_atoi, il senso del nome e' che non ha il comportamento esatto di una funzoine di atoi, visto che la logica e' separata tra la funzione e il main, ma il riultato e' lo stesso: inserisco una stringa (in questo caso il valore che ho messo in input prima di eseguire il programma) preceduta da un numero qualsiasi di - e +, dopo inizio a scorrere la stringa fino a che non incontro un carattere che non e' un numero, a quel punto smetto la lettura e ritorno il numero letto fino a qual punto
{
	int	neg; //una variabile di appoggio, unicamente per conservare un 1, che sara' positivo o negativo alla fine dell'esecuzione
	int	i; //l'indice con cui scorro la stringa
	int	num; //qui conservero' il numero

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == '-' || str[i] == '+') //fino a che l'inizio della stringa e' preceduta da caratteri + o - scorro
	{
		if (str[i] == '-') //nel caso in cui sia un - cambio il segno della variabile di appoggio
			neg = -neg;
		i++;
	}	
	while (str[i] >= 48 && str[i] <= 57) //adesso che ho finito di leggere i + e i - controllo che il carattere sia un numero, in tal caso
	{
		num = num * 10 + (str[i] - 48); //moltiplico num per 10 ogni volta, poi diminuisco il carattere della stringa di 48 per trovare il suo corrispettivo decimale e lo sommo a num
		i++;
	}
	return (num * neg); //infine ritorno il numero trovato, con il segno
}

int	main(int argc, char *argv[]) //questi sono gli argomenti del main, possono essere utilizzati per eseguire il file cambiando l'esito in base a cosa scrivo, senza dover scrivere le variabili nella chiamata di funzione
//argc e' il numero degli armomenti passati, di base e' almeno uno, visto che ./a.out e' il primo argomento
{
	int	x; //queste sono le mie coordinate, le utilizzero' per disegnare la cornice
	int	y;

	if (argc == 3) //se il numero degli argomenti e' 3, quindi ./a.out, ascisse, ordinate allora provera' a disegnare la cornice
	{
		if ((*argv[1] >= 'A' && *argv[1] <= 'Z')
			|| (*argv[1] >= 'a' && *argv[1] <= 'z')
			|| (*argv[2] >= 'A' && *argv[2] <= 'Z')
			|| (*argv[2] >= 'a' && *argv[2] <= 'z')) //nel caso in cui i primi caratteri del primo o del secondo argomento sono delle lettere stampo il messaggio di errore, ma non si interrompe l'esecuzione, perche' quando chiamero' la funzione psudo_atoi mi ritornera' 0, quindi non stampera' nulla lo stesso, ma non necessito di interrompere l'esecuzione 
			write(1, "Please insert a number", 22);
		x = ft_pseudo_atoi(argv[1]);
		y = ft_pseudo_atoi(argv[2]);
		if (x >= 0 && y >= 0) //la funzione psudo_atoi ha ritornato 2 numeri positivi, quindi posso disegnare correttamente la cornice, nel caso pero' in cui uno dei 2 numeri sia 0, chiamo lo stesso la funzione rush, e non avro' nessun messaggio di errore, ma moltiplicando per 0 non apparira' nulla 
			rush(x, y);
		else //la funzione pseudo_atoi mi ha ritornato un numero negativo, quindi stampo un messaggio di errore
			write(1, "Please insert a positive number", 31);
	}
	else if (argc < 3) //in questo caso ho inserito solo una coordinata oppure nessuna coordinata, quindi stampo un messaggio di errore
		write(1, "Too few arguments", 17);
	else //in questo caso ho piu' di 3 argomenti, quindi stampo un messaggio di errore
		write(1, "Too many arguments", 18);
	return (0);
}

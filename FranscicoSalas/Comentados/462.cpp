// Problema 462 comentado

#include <cstdio>
#include <map>

int main()
{

// Se hace el mapeo de suit - int para determinar orden al hacer el bid
    std::map<char, int> suitConversion;
    suitConversion['S'] = 0;
    suitConversion['H'] = 1;
    suitConversion['D'] = 2;
    suitConversion['C'] = 3;
    
// se define el suit de las cartas
    char back[4] = {'S', 'H', 'D', 'C'};
    
// Se definen bools las cartas que representan cuales cartas hay
    bool ace[4], king[4], queen[4], jack[4], trump[4];
// se definen el contador de cartas por suit, los puntos, puntos especiales (para las regla 5,6 y 7) y pos como variable para guiarse por el mapa
    int count[4], points, specialPoints, pos;
    
    char temp[3];
    
// Se leen las cartas
    while (scanf("%s", temp) == 1)
    {

// Se dejan todas las variables booleanas falsas ya que todavía no hay cartas
        for (int i = 0; i < 4; ++i)
        {
            ace[i] = king[i] = queen[i] = jack[i] = trump[i] = false;
            count[i] = 0;
        }
        
// Se dejan los puntajes en 0
        points = specialPoints = 0; 
            
// Se escanean el resto de cartas y se guardan en temp
// Y se aplican las reglas para sumar puntos
        for (int i = 0; i < 13; ++i)
        {
            if (i != 0)
                scanf("%s", temp);
// Se lee la carta y se almacena en temp
// Recordar que tiene forma 'CARD-SUIT', por lo que si la carta ingresada es temp = 'KS', se tiene temp[0] = 'K', temp[1] = 'S'
// Se define pos usando el mapeo suitConversion sobre su suit temp[1]         
            pos = suitConversion[temp[1]];
            
// Ahora, dependiendo de la carta
            switch (temp[0])
            {
// Si es un A => es de tipo ace, por lo que ace[pos] = true y se suman 4 puntos
            case 'A':
                ace[pos] = true;
                points += 4;
                break;
// Si es un K => es de tipo king, por lo que king[pos] = true y se suman 3 puntos                
            case 'K':
                king[pos] = true;
                points += 3;
                break;
// Si es un Q => es de tipo queenpor lo que queen[pos] = true y se suman 2 puntos              
            case 'Q':
                queen[pos] = true;
                points += 2;
                break;
// Si es un J => es de tipo jack, por lo que jack[pos] = true y se suma 1 punto               
            case 'J':
                jack[pos] = true;
                points += 1;
            }
// Aumenta el contador de suits
            ++count[pos];
        }
        
// Sustracción y adición de puntos
        for (int i = 0; i < 4; ++i)
        {
            if (ace[i])
                trump[i] = true;
// Regla 2:  Subtract a point for any king of a suit in which the hand holds no other cards
            if (king[i] && count[i] < 2)
                --points;

            else if (king[i])
                trump[i] = true;
// regla 3:  Subtract a point for any queen in a suit in which the hand holds only zero or one other cards.                
            if (queen [i] && count[i] < 3)
                --points;
            
            else if (queen[i])
                trump[i] = true;
                
 // regla 4: Subtract a point for any jack in a suit in which the hand holds only zero, one, or two other cards.
            if (jack[i] && count[i] < 4)
                --points;

// regla 5: Add a point for each suit in which the hand contains exactly two cards.
            if (count[i] == 2)
                ++specialPoints;

// regla 6: Add two points for each suit in which the hand contains exactly one card.  
            else if (count[i] < 2)
                specialPoints += 2;
        }
        
// Una vez conocidos los puntos se decide la mejor posibilidad

// Si se tienen 4 suits y mas de 16 puntos sin contar las reglas 5,6 y 7 (por eso se consideran puntos especiales)
// Se hace biding NO-TRUMP
        if (trump[0] && trump[1] && trump[2] && trump[3] && points >= 16)
            printf("BID NO-TRUMP\n");

// One may open bidding in a suit if the hand evaluates to 14 or more points. Bidding is always
// opened in one of the suits with the most cards.
        else if (points + specialPoints >= 14)
        {
            char output = 'S';
            int max = 0;
            for (int i = 1; i < 4; ++i)
            {
                if (count[i] > count[max])
                {
                    max = i;
                    output = back[i];
                }
                
                
            }
            printf("BID %c\n", output);
        }
        else
// Si no tiene 14 puntos se pasa
            printf("PASS\n");
    }
    
    
}
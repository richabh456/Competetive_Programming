def main() :

    n = int(input())

    p = int(input())
    s = int(input())
    snakes = dict()
    for i in range(s) :
        x = [int(i) for i in input().split()]
        snakes[(x[0],x[1])] = (x[-2],x[-1])
        
    l = int(input())
    ladders = dict()
    for i in range(s) :
        x = [int(i) for i in input().split()]
        ladders[(x[0],x[1])] = (x[-2],x[-1])

    k = int(input())
    moves = list() 
    #print (snakes) 
    #print (ladders)
    positions = dict()
    for i in range(p) :
        positions[i +1] = [0,1]
    
    #print (positions)

    player = 0
    won = 0
    for i in range(k) :

        player = (player+1) % (p+1)
        if( player==0 ) :
            player = 1

        moves += [sum([int(i) for i in input().split()])]
        if (won == p) :
            continue 
        moved = 0
        #print ("\n","--"*50,"\nplayer no.",player,"is playing.")
        x = positions[player][0]
        y = positions[player][1]

        while ( x== 0 and y == n ) :
            player = (player+1) % (p+1)
            if( player==0 ) :
                player = 1

        #print ("\nplayer no.",player,"is at :  ",x,",",y)
        #print ("\nplayer no.",player,"will move",moves[-1],"times.")
        if( not (x== 0 and y == n) ) :

            #print ("  This player has not yet won.")

            y += moves[-1]/n
            
            if( y%2 == 0 ) :
                x = n - (x + moves[-1]%n ) + 1
            else :
                if( x + moves[-1]%n > n ) :
                    x = n - (x+moves[-1]%n)%n + 1 
                    y += 1 
                else :
                    x = (x+moves[-1]%n)%n

            if ( x==1 and y==n and moved + 1 <= moves[-1] ) :
                positions[player][0] = 0
                positions[player][1] = n
                #print ("\n  player no.",player,"won.")
                won += 1
                break

            """
            while( moved != moves[-1]) :

                #print ("\n      player no.",player,"has moved",moved,"steps.")
                if ( x != n and y%2 != 0) :
                    x += 1
                    
                    #print ("         - moved right")
                elif ( x != 1 and y%2 == 0) :
                    x -= 1
                    
                    #print ("         - moved left")
                    if ( x==1 and y==n and moved + 1 <= moves[-1] ) :
                        positions[player][0] = 0
                        positions[player][1] = n
                        #print ("\n  player no.",player,"won.")
                        won += 1
                        break
                        
                elif ( x == n and y != n) :
                    y += 1
                    
                    #print ("         - moved up")
                elif ( x == 1 and y != n) :
                    y += 1
                    
                    #print ("         - moved up")
                
                moved += 1

                #print ("\n          player no.",player,"moves to at :  ",x,",",y)
            """

            if  moved == moves[-1] :
                #print ("---------------here")
                try :
                    if ((x,y) in snakes) :
                        x1 = x
                        x = snakes[(x,y)][0]
                        y = snakes[(x1,y)][1]
                        #print ("             Saanp ne pakda")
                except :
                    continue
                try :
                    if ((x,y) in ladders) :
                        x1 = x
                        x = ladders[(x,y)][0]
                        y = ladders[(x1,y)][1]
                        #print ("             Saanp ne pakda")
                except :
                    continue

                positions[player][0] = x
                positions[player][1] = y
            
            

    for i in range(p) :
        if positions[i+1][0] == 0 and positions[i+1][1] == n :
            print (i+1,"winner")
        else :
            print (i+1,positions[i+1][0],positions[i+1][1])



    
    '''
    for i in moves :
        #print (i)
    for i in snakes :
        #print (i)
    for i in matrix :
        #print (i)
    '''






main()

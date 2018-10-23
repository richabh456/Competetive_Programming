def main() :
    
    n = int(input()) 
    l = list()
    indices = dict()
    count = 0 ;
    for i in range(n) :
        x = input().split()
        x[2] = int(x[2])
        l += [x]
        if x[0] not in indices :
            indices[x[0]] = count 
            count += 1
        if x[1] not in indices :
            indices[x[1]] = count 
            count += 1
    
    matrix = [ [ -1 for i in range(count) ] for y in range(count) ]
    
    #print (matrix)
    #print (l)
    
    for i in range(n) :
        #print ('i = ',i)
        #print ('matrix[',indices[l[i][0]],'][',indices[l[i][1]],'/]')
        matrix[indices[l[i][0]]][indices[l[i][1]]] = l[i][2]
        matrix[indices[l[i][1]]][indices[l[i][0]]] = 0

        x = indices[l[i][0]]
        y = indices[l[i][1]]
        count = 0
        while( x != 0 or y != 0) :
            #print (x,y)
            if matrix[x-1][y-1] not in [1,-1]  and i != y :
                matrix[x-1][y] = matrix[x-count][y-count] * matrix[x-1-count][y-1-count]
                matrix[y][x-1] = 1 / matrix[x-1][y]
                x -= 1
                count += 1
                continue 
            break

    #print ("\n\n")
    q = int(input()) 
    #for i in matrix :
        #print (i)
    #quer = list()
    #print ("\n\n")
    
    for i in range(q) :
        quer = input().split()
        if quer[0] == quer[1] :
            print (1)
            continue
        x = matrix[indices[quer[0]]][indices[quer[1]]]
        if( x != -1 ) :
            print ( x % 998244353)
        else :
            print (-1)
        '''
        if (matrix[quer[0]][quer[1]] != -1 and matrix[quer[1]][quer[0]] != -1 )  
        for y in range(count) :
            if( matrix[indices[quer[0]]][y] != -1 and matrix[indices[quer[1]]][y] != -1 ) :
                ans = y
                a = matrix[indices[quer[0]]][y]
                b = matrix[indices[quer[1]]][y]
                if( type(a) == float ) :
                    a = matrix[y][indices[quer[0]]]
                if( type(b) == float ) :
                    b = matrix[y][indices[quer[1]]]
                    print ( (a*b) % 998244353 )
                    break
                print ( (a/b) % 998244353 )
                break
        else :
            print (-1)
        '''
main() 

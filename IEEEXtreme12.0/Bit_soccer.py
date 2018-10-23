def main() :

    n = int(input())
    l = list()
    result = list()
    l = [int(i) for i in input().split()]

    for i in range(n) :
        for y in range(n) :
            result += [l[i] | l[y]]
    
    q = int(input())
    for i in range(q) :
        quer = int(input()) 
        if quer in result :
            print ("YES")
        else :
            print ("NO")
main()
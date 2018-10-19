def main() :

    l = ["ch","ef","he","che","hef","chef"]
    ans = 0
    n = int(input())
    for t in range( n ) :
        s = input()
        for i in l :
            if i in s :
                ans += 1
                break 
    print (ans)

main()
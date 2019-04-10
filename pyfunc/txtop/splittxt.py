def main():
    with open("/Users/c-ten/Desktop/Graduate/Graduate_sticks_standard.txt","r") as f:
        temp = f.readlines()
        words = []
        L = len(temp)
        for i in range(L):
            if "j" in temp[i] :
                words = temp[i]
                with open('/Users/c-ten/Desktop/Graduate/'+words[0:6]+'.txt', 'w') as g:
                    for j in range(i+1, L):

                        if "j" in temp[j]:
                            break
                        g.write(temp[j])
                

 
if __name__ == '__main__':

    main()

def main():
    with open("/Users/c-ten/Desktop/setlist.txt","r") as f:
        temp = f.readlines()
        L = len(temp)
        print(L)
    f.close()
                

 
if __name__ == '__main__':

    main()


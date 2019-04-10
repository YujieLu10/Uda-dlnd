def main():
    with open("/Users/c-ten/Desktop/setlist.txt","r") as f:
        with open("/Users/c-ten/Desktop/jpg2txt.txt","w") as g:
            while True:
                line = f.readline()
                print(line)
                if not line:
                    break
                g.write(line.replace("jpg","txt"))
if __name__ == '__main__':

    main()

